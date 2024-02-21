#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include<netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/prctl.h>  

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/vfs.h>
#include <errno.h>
#include <dirent.h>

#include <string>
#include <map>
using namespace std;

#include "NetSDKDLL.h"
#include "cmd_def.h"
#include "configlib.h"
#include "Mutex.h"
#include "tinyxml.h"

#pragma pack (4)

#define  CONFIG_FILE   "config.cfg"

//定义默认用户名密码
#define DEFAULT_USERNAME "admin"
#define DEFAULT_PASSWORD "123456"

static int g_LogonOk = 0 ;
static long gHandle_realplay = 0;
static LONG m_nLastCmdId;

static int g_newVidRecord = 0;
static int g_newAudRecord = 0;

//定义全局结构数组g_IPC_SET[] 存储 IPC_ENTRY
static IPC_ENTRY g_IPC_SET[256];

static char g_ip[20] = "" ;
static char g_user[20] = "";
static char g_pass[20] = "" ;
static int g_onMediaRecv = 0; 
static int g_port = 0;

static int g_bSearching = 0;
static pthread_t g_thread_show_searchresult = 0;

static char remotefilename[256];


static MediaConfig g_ipc_mediacfg;
static int g_bmediacfg_gotton = 0;
static int g_bAutoSearchAndRecord = 0;
static int g_bAutoSearchAndLogin = 0;

static FILE* g_fp_replay = NULL;
static CMutex g_mutex_replay;


static int g_bRun = 1;


typedef struct
{
	STREAM_AV_PARAM avParam;
	unsigned int m_nStartTime;
}MP4Write;

typedef struct
{
	LONG lUserID;
	LONG lRealHandle0;
	LONG lRealHandle1;
	IPC_ENTRY info;

	int bLoginOK;

	int bGetStreamConfig;
	MediaStreamConfig streamCfg;
	char szCapability[1024];

	int nVideoCapCount;
	int nAudioCapCount;
	RESOLUTION_ENTRY *pOutVideoCap ;			
	AUDIO_CODEC_ENTRY *pOutAudioCap;

	MP4Write mp4[2];
}MyIpcamera;



static map<string, MyIpcamera> mapIpcameraInstance;
static CMutex mutex_map;

static unsigned long getmstime()
{
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);

	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}


void ShowVideoParam(VIDEO_PARAM *pData)
{
	printf( "|%10s|%10s|%10s|%10s|%10s|%10s|\n",
		"videoenc","videobit", "videowidth", "videoheigh", "framerate", "bitrate");

	printf( "|%10s|%10u|%10u|%10u|%10u|%10u|\n",
		pData->codec, pData->bitrate, pData->width, 
		pData->height, pData->framerate, pData->bitrate);
}


void ShowAudioParam(AUDIO_PARAM *pData)
{
	printf( "|%10s|%10s|%10s|%10s|%10s|%10s|\n",
		"audioenc", "samplerate", "sampbit", "channels", "bitrate", "framerate");

	printf( "|%10s|%10u|%10u|%10u|%10u|%10u|\n",
		pData->codec, pData->samplerate, pData->bitspersample,
		pData->channels,	pData->bitrate, pData->framerate);
}


LONG  OnMediaRecv(LONG lRealHandle,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData)
{
	unsigned int nNowTime = IP_NET_DVR_Get_Timestamp();
	
	if ( lRealHandle == gHandle_realplay )
	{
		if( dwDataType == 0 )
		{
			printf("%lu: iskey: %d, timestamp: %f, length %lu\n", getmstime(), pExtData->bIsKey, pExtData->timestamp, dwBufSize);
		}
	}
	else
	{
		MyIpcamera *p = (MyIpcamera*)pExtData->pUserData;
		if( p == NULL )
		{
			printf("%#lx: OnMediaRecv pUserData=NULL!!!!\n", lRealHandle);
		}
		else if( p->lRealHandle0 != lRealHandle &&  p->lRealHandle1 != lRealHandle)
		{
			printf("%#lx: OnMediaRecv NOT my realplay handle!!!!\n", lRealHandle);
		}
		else
		{		
			int nStreamNo = 0;
			if(  p->lRealHandle1 == lRealHandle )
				nStreamNo = 1;

		
			STREAM_AV_PARAM &avParam = p->mp4[nStreamNo].avParam;
			unsigned int &m_nStartTime = p->mp4[nStreamNo].m_nStartTime;

			if(dwDataType == 0)
			{
				printf("%#lx: video len: %ld, iskey: %d, %p\n", lRealHandle, dwBufSize, pExtData->bIsKey, pExtData->pUserData);
			}
			else if(dwDataType == 1)
			{
				printf("%#lx: audio len %ld\n", lRealHandle, dwBufSize);
			}
			else if(dwDataType == 2)
			{
				STREAM_AV_PARAM *pavParam = (STREAM_AV_PARAM *)pBuffer;

				memcpy(&p->mp4[nStreamNo].avParam, pavParam, sizeof(STREAM_AV_PARAM));
				
				printf("########### %#lx: video audio param. bHaveVideo %d, bHaveAudio %d, url %s ################ \n", 
					lRealHandle,
					pavParam->bHaveVideo, pavParam->bHaveAudio,
					pavParam->szUrlInfo);

				if( pavParam->bHaveVideo > 0 )
					ShowVideoParam(&pavParam->videoParam);

				if( pavParam->bHaveAudio> 0 )
					ShowAudioParam(&pavParam->audioParam);		
				
				printf("################################################# \n");
			}
		}
	}

	return 0;
}

LONG  OnReplayMediaRecv(LONG lUser,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData)
{
	//pExtData->timestamp:距当天 0点的毫秒数。
	if(dwDataType == 0)//means pBuffer is video data
	{
		printf("-- video data lUser:%ld iskey: %d, timestamp: %f, length %u\n",
			   lUser, pExtData->bIsKey, pExtData->timestamp, dwBufSize);

		g_mutex_replay.Lock();
		if( g_fp_replay )
		{
			int ret = fwrite(pBuffer, 1, dwBufSize, g_fp_replay);
			printf("write %lu=%d\n", dwBufSize,  ret);
		}
		g_mutex_replay.Unlock();
	}
	else if(dwDataType == 1)//audio data
	{
/*		printf("-- audio data lUser:%ld iskey: %d, timestamp: %f, length %u\n",
			   lUser, pExtData->bIsKey, pExtData->timestamp, dwBufSize);
*/	}
	else if(dwDataType == 2)//video and audio params from ip camera.
	{
		//回放seek过程或播放下一个文件时，会再次发送参数过来。
		//用户需要对比前后参数，以决定是否重新初始化解码器(中途用户可能更改视频分辨率等)
		STREAM_AV_PARAM *pavParam = (STREAM_AV_PARAM *)pBuffer;
		printf("==== Replay params ==== video:%s %dx%d\n", pavParam->videoParam.codec, pavParam->videoParam.width, pavParam->videoParam.height);
	}
	return 0;
}

LONG PlayActionEventCallBack(LONG lUser,LONG nType,LONG nFlag, char * pData, void * pUser)
{
	printf("replay event lUser:%ld nType:%ld\n", lUser, nType);
	switch (nType) {
		case ACTION_STOP:
			//用户主动停止，或设备主动停止时会有此事件，设备主动发出此事件时，表明设备回放出错或到达结尾
			break;
		default:
			break;
	}
	return 0;
}


void ShowMediaCapability(int nVideoCapCount, RESOLUTION_ENTRY *pVideoCapability, 
	int nAudioCapCount, AUDIO_CODEC_ENTRY *pAudioCapability)
{
	int iIndex;
	printf("Video capabilities:\n");
	printf("|%10s|%10s|%10s|%10s|%10s|"
		"%10s|%10s|%10s|%10s|\n", 
		"stream", "format","resolution", "defbitrate", "minbitrate",
		"maxbitrate","deffrt","minfrt", "maxfrt");

	printf("nVideoCapCount:%d\n",nVideoCapCount);
	printf("nAudioCapCount:%d\n",nAudioCapCount);

	for( iIndex = 0; iIndex < nVideoCapCount && iIndex < 1000; iIndex++)
	{
		if( pVideoCapability[iIndex].res_name[0] == '\0' )
			break;
		
		printf("|%10d|%10s|%10s|%10d|%10d|"
			"%10d|%10d|%10d|%10d|\n", 	
			pVideoCapability[iIndex].stream_type, 
			pVideoCapability[iIndex].codec_name, 
			pVideoCapability[iIndex].res_name, 
			pVideoCapability[iIndex].def_bitrate, 
			pVideoCapability[iIndex].min_bitrate, 
			
			pVideoCapability[iIndex].max_bitrate, 		
			pVideoCapability[iIndex].def_framerate, 
			pVideoCapability[iIndex].min_framerate, 
			pVideoCapability[iIndex].max_framerate			
			);
	}


	printf("Audio capabilities:\n");
	printf("|%10s|%10s|%10s|%10s|%10s|\n", 
		"codename", "channels","bitspersamp", "samplerate", "bitrate");
	for( iIndex = 0; iIndex < nAudioCapCount&& iIndex < 1000; iIndex++)
	{
		if( pAudioCapability[iIndex].codec_name[0] == '\0' )
			break;
		
		printf("|%10s|%10d|%10d|%10d|%10d|\n", 	
			pAudioCapability[iIndex].codec_name, 
			pAudioCapability[iIndex].channels, 
			pAudioCapability[iIndex].bitspersample, 
			pAudioCapability[iIndex].samplerate, 
			pAudioCapability[iIndex].bitrate
			);
	}

}

LONG  OnStateEvent(LONG lUser,LONG nStateCode,char *pResponse,void *pUser)
{
	//IP_NET_DVR_PTZControl(lUser,UP_LEFT,5,5);

	int i=0 ; 
	printf("lUserID %#lx: OnStateEvent get state: \033[5;33m%ld\033[0m \033[33m(%s)\033[0m\n",lUser, nStateCode, IP_NET_DVR_GET_EVENTNAME(nStateCode));
	switch(nStateCode)
	{		
	case	EVNET_RECORD_FILEBEGIN:
	case	EVENT_RECORD_FILEEND:
	case	EVENT_RECORD_TASKEND:
	case	EVENT_RECORD_DISKFREESPACE_TOOLOW:
	case	EVNET_RECORD_FILEBEGIN_ERROR:
	case	EVNET_RECORD_WRITE_FILE_ERROR:
	case	EVENT_RECORD_INITAVIHEAD_ERROR:
	case	EVENT_RECORD_MEDIA_PARAM_ERROR:
		{

		}
		break;
	case EVENT_RECVVIDEOAUDIOPARAM:
		{
			printf(">>>>>>>>>>>>> EVENT_RECVVIDEOAUDIOPARAM <<<<<<<<<<< puser:%s\n",pUser == NULL ? "":(char *)pUser);
			STREAM_AV_PARAM * pParam=(STREAM_AV_PARAM*)pResponse;

			printf("########### video audio param. bHaveVideo %d, bHaveAudio %d, url %s ################ \n", 
				pParam->bHaveVideo, pParam->bHaveAudio,
				pParam->szUrlInfo);

			if( pParam->bHaveVideo > 0 )
				ShowVideoParam(&pParam->videoParam);

			if( pParam->bHaveAudio> 0 )
				ShowAudioParam(&pParam->audioParam);		
			
			printf("################################################# \n");
		}
		break;
	case EVENT_SOCKETERROR:
		{
			printf("\033[31m!!!!!!!!!! EVENT_SOCKETERROR !!!!!!!!!!\033[0m\n");

			mutex_map.Lock();				
			map<string, MyIpcamera>::iterator it ;
			for( it = mapIpcameraInstance.begin(); it != mapIpcameraInstance.end(); ++it )
			{
				const string &sn = it->first;
				MyIpcamera &cameraInfo = it->second;

				if( cameraInfo.lUserID == lUser )
				{
					cameraInfo.bLoginOK = 0;
					printf("\033[31msn: %s lUserID: %#lx %s:%u socket ERROR \033[0m\n",sn.c_str(), cameraInfo.lUserID, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort);
					break;
				}
			}

			mutex_map.Unlock();				
				
		}
		break;
	case EVENT_CONNECTING:
		{
			printf("lUserID\033[33m %#lx:!!!!!!!!!! EVENT_CONNECTING !!!!!!!!!!\033[0m\n", lUser);
		}
		break;
	case EVENT_CONNECTOK:
		{
			printf("lUserID\033[32m %#lx:!!!!!!!!!! EVENT_CONNECTOK !!!!!!!!!!\033[0m\n", lUser);
		}
		break;
	case EVENT_CONNECTFAILED:
		{
			printf("lUserID\033[31m %#lx:!!!!!!!!!! EVENT_CONNECTFAILED !!!!!!!!!!\033[0m\n",lUser);
		}
		break;
	case EVENT_LOGINOK:
		{
			printf("lUserID\033[32m %#lx: !!!!!!!!!! Login OK !!!!!!!!!! \033[0m\n", lUser);

			if( m_nLastCmdId == lUser )
				g_LogonOk =1 ;
			else
			{
				mutex_map.Lock();				
				map<string, MyIpcamera>::iterator it = mapIpcameraInstance.begin();
				for(; it != mapIpcameraInstance.end(); ++it )
				{
					const string &sn = it->first;
					MyIpcamera &cameraInfo = it->second;
					if( cameraInfo.lUserID == lUser )
					{
						cameraInfo.bLoginOK = 1;
						printf("\033[32msn: %s lUserID %#lx %s:%u login OK \033[0m\n", sn.c_str(), 
							cameraInfo.lUserID, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort);

						if( g_bAutoSearchAndRecord > 0 )
						{
							if( cameraInfo.lRealHandle0 == 0 )
							{
								USRE_VIDEOINFO userinfo;
								userinfo.bIsTcp=0;
								userinfo.nVideoPort=cameraInfo.info.streamCfg.rtspConfig.videoPort;
								userinfo.nVideoChannle=0;
								userinfo.pUserData=(void*)&cameraInfo;
								
								cameraInfo.lRealHandle0 = IP_NET_DVR_RealPlayEx(cameraInfo.info.lanCfg.IPAddress,
									cameraInfo.info.userCfg.accounts[0].userName, cameraInfo.info.userCfg.accounts[0].password,
									OnMediaRecv,&userinfo,0);
								if(cameraInfo.lRealHandle0	!=0 )
								{
									printf("realplay %s:%d retValue:%#lx\n",cameraInfo.info.lanCfg.IPAddress, userinfo.nVideoChannle, cameraInfo.lRealHandle0);
								}
							}
							
							if( cameraInfo.lRealHandle1 == 0 )
							{
								USRE_VIDEOINFO userinfo;
								userinfo.bIsTcp=0;
								userinfo.nVideoPort=cameraInfo.info.streamCfg.rtspConfig.videoPort;
								userinfo.nVideoChannle=1;
								userinfo.pUserData=(void*)&cameraInfo;
								
								cameraInfo.lRealHandle1 = IP_NET_DVR_RealPlayEx(cameraInfo.info.lanCfg.IPAddress,
									cameraInfo.info.userCfg.accounts[0].userName, cameraInfo.info.userCfg.accounts[0].password,
									OnMediaRecv,&userinfo,0);
								if(cameraInfo.lRealHandle1	!=0 )
								{
									printf("realplay %s:%d retValue:%#lx\n",cameraInfo.info.lanCfg.IPAddress, userinfo.nVideoChannle, cameraInfo.lRealHandle1);
								}
							}
						}

						break;
					}
				}

				mutex_map.Unlock();				
			}
#if 0
			IP_NET_DVR_GET_MediaStreamConfig(lUser);
			IP_NET_DVR_GET_MediaCapability(lUser);
			IP_NET_DVR_GET_MediaConfig(lUser);			
#endif			
		}
		break;
	case EVENT_PTZALARM:
		{
			ALARM_ITEM* pa = (ALARM_ITEM*)pResponse;
			char strAlarmTime[20];
			//sprintf() 将ALARM_TIME结构体int数据拼接为字符串strAlarmTime
			sprintf(strAlarmTime,"%04d-%02d-%02d %02d:%02d:%02d",pa->time.year,pa->time.month,pa->time.day,pa->time.hour,pa->time.minute,pa->time.second);
			printf("lUserID %#lx: time:%s, code:\033[33m %d \033[0m, Ai_type:\033[33m %d \033[0m, data:\033[33m %s \033[0m\n", lUser, strAlarmTime, pa->code, pa->level, pa->data);
			
#if 0//如果是主动调用IP_NET_DVR_SnapPic，已经自动下载，这里不需要再下载了
			if(pa->code == ALARM_CODE_JPEG_CAPTURED)
			{
				printf("snap pic done, we download it at, time:%lu .\n", getmstime());
				char tmp[256];
				snprintf(tmp, 256, "/tmp/%s", remotefilename);
				IP_NET_DVR_GetFileByName(lUser, 1, tmp, (char*)"./");
			}
#endif
		}
		break;
	case EVENT_PTZPRESETINFO:
		{

		}
		break;
	case EVENT_SENDPTZOK:
		{			

		}
		break;
	case EVENT_DOWNLOADOK:
		{
/*
XML内容：
<RESPONSE_PARAM
	RemoteFileName="/tmp/20191029161128.jpg"
	LocalFileName="test.jpg"
	StartPos="0"
	ErrorCode="0"
/>

*/
		
#if 0		
//
			char szDownloadFile[256] = "";
	
			const char *p = pResponse;
			TiXmlDocument  oDoc;
			oDoc.Parse( p );
			const TiXmlElement* root = oDoc.RootElement();
			if(root)
			{
				if ( root->Type() == TiXmlNode::ELEMENT && !strcmp(root->Value(), "RESPONSE_PARAM"))
				{				
					const TiXmlElement *pElement = (const TiXmlElement*)root;
					strcpy(szDownloadFile,	pElement->Attribute("LocalFileName"));
				}
			}
#endif	
			printf("EVENT_DOWNLOADOK: %s", pResponse);
		}
		break;
	case EVENT_UPLOADOK:
		{

		}
		break;
	case EVENT_UPLOADFAILED:
		{

		}
		break;
	case EVENT_DOWNLOADFAILED:
		{
			printf("download file fail\n");
		}
		break;
	case EVENT_STARTAUDIOFAILED:
		{

		}
		break;
	case EVENT_STARTAUDIOOK:
		{

		}
		break;
	default:
		{

		}
		break;
	}

	return 0;
}

// TO MAKE SURE SAME WITH NETSDK PRINT
static void ShowDataSize()
{
	printf("############################## COMMON ##############################\n");
	printf("|%30s:|%10ld|\n", "sizeof(SYSTEM_VERSION_DATA)", sizeof(SYSTEM_VERSION_DATA));
	printf("|%30s:|%10ld|\n", "sizeof(AlarmConfig)", sizeof(AlarmConfig));
	printf("|%30s:|%10ld|\n","sizeof(SystemConfig)", sizeof(SystemConfig));
	printf("|%30s:|%10ld|\n","sizeof(MediaConfig)", sizeof(MediaConfig));
	printf("|%30s:|%10ld|\n","sizeof(ServerConfig)", sizeof(ServerConfig));
	printf("|%30s:|%10ld|\n", "sizeof(MediaStreamConfig)", sizeof(MediaStreamConfig));
	printf("|%30s:|%10ld|\n", "sizeof(PlatformConfig)", sizeof(PlatformConfig));
	printf("|%30s:|%10ld|\n", "sizeof(RecordConfig)", sizeof(RecordConfig));
	printf("|%30s:|%10ld|\n", "sizeof(NetworkConfigNew)", sizeof(NetworkConfigNew));
	printf("|%30s:|%10ld|\n", "sizeof(GB28181Config)", sizeof(GB28181Config));
	printf("|%30s:|%10ld|\n", "sizeof(GlobalConfig)", sizeof(GlobalConfig));
	printf("|%30s:|%10ld|\n", "sizeof(TimeSpanList)", sizeof(TimeSpanList));


	printf("############################## AlarmConfig ##############################\n");
	printf("|%30s:|%10ld|\n", "sizeof(InputAlarm)", sizeof(InputAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(MotionDetectAlarm)", sizeof(MotionDetectAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(VideoLostAlarm)", sizeof(VideoLostAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(VideoCoverAlarm)", sizeof(VideoCoverAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(StorageFullAlarm)", sizeof(StorageFullAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(AudioAlarm)", sizeof(AudioAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(VideoGateAlarm)", sizeof(VideoGateAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(PdAlarm)", sizeof(PdAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(FaceDetectAlarm)", sizeof(FaceDetectAlarm));
	printf("|%30s:|%10ld|\n", "sizeof(OutPutAlarm)", sizeof(OutPutAlarm));	
	printf("|%30s:|%10ld|\n", "sizeof(TempHumidityAlarm)", sizeof(TempHumidityAlarm));

	printf("############################## MediaConfig ##############################\n");
	printf("|%30s:|%10ld|\n", "sizeof(VideoConfig)", sizeof(VideoConfig));
	printf("|%30s:|%10ld|\n", "sizeof(AudioConfig)", sizeof(AudioConfig));


	printf("############################## VideoConfig ##############################\n");
	printf("|%30s:|%10ld|\n", "sizeof(videoCapture)", sizeof(VideoCapture));
	printf("|%30s:|%10ld|\n", "sizeof(VideoEncode)", sizeof(VideoEncode));	
	printf("|%30s:|%10ld|\n", "sizeof(JpegEncodeCfg)", sizeof(JpegEncodeCfg));
	printf("|%30s:|%10ld|\n", "sizeof(VideoOverlay)", sizeof(VideoOverlay));
	printf("|%30s:|%10ld|\n", "sizeof(VideoMaskConfig)", sizeof(VideoMaskConfig));
	printf("|%30s:|%10ld|\n", "sizeof(VideoROI)", sizeof(VideoROI));
	printf("|%30s:|%10ld|\n", "sizeof(VideoUserOverlay)", sizeof(VideoUserOverlay));

}


LONG CALLBACK OnAUXResponse(LONG lUser,LONG nType,char *pResponse,void *pUser)
{

	int ErrorCode=nType & 0xff000000;
	int ActionCode=nType & 0xffffff;

	printf("############  CALLBACK OnAUXResponse()  #############\n");
	printf("func: \033[33m[%s] LINE: %d: AcitionCode:%d, ErrorCode %d \033[0m\n",__func__, __LINE__, ActionCode, ErrorCode);
	printf("\033[7;33m%s\033[0m\n",pResponse);

	switch(ActionCode)
	{
	case CMD_SYSTEM_MANAGE_BASE + 34:
		{
			int error=1;

		}
		break;
	case CMD_GET_SERIALNUMBER:
		{
			printf("%s\n", pResponse);
			TiXmlDocument doc;
			doc.Parse((pResponse));
			if(!doc.Error())
			{
				TiXmlElement * pItem=doc.RootElement();
				const char *pName = pItem->Value();
				if (strcmp("RESPONSE_PARAM",pName) == 0)
				{
					const char * strSn = pItem->Attribute("SerialNumber");
					if( NULL != strSn )
					{
						printf("%s\n", strSn);
					}
				}
			}
		}
		break;
	case CMD_GET_LOGFILE_LIST:
		{//日志返回信息

		}
		break;
	case CMD_GET_RECORD_FILE_LIST:
		{
//			printf("%s\n", pResponse);
			LONG nSearchMode = IP_NET_DVR_GetReplay_SearchMode_ByXml(pResponse);
			if( SearchModeGetDateList ==nSearchMode )
			{
				unsigned int datearray[365];
				if(IP_NET_DVR_GetReplay_Dates_DistributeByXml(pResponse, datearray, sizeof(datearray)/sizeof(datearray[0])) != 0)
				{
					printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
				}
				else
				{
					unsigned int iIndex = 0;
					for( iIndex = 0; iIndex < sizeof(datearray)/sizeof(datearray[0]); iIndex++)
					{
						if( datearray[iIndex] == 0 )
							break;


						time_t date = (time_t)datearray[iIndex];
						struct tm *ptm, tbuf;						
						ptm = localtime_r(&date, &tbuf);
						
						printf("%u: %u ", iIndex, datearray[iIndex]);
						if( ptm != NULL)
						{
							printf("\t\t[%04u-%02u-%02u]\n", 1900 + ptm->tm_year, 1 + ptm->tm_mon, ptm->tm_mday);
						}
					}
				}
			}
			else if( SearchModeByTimeDistribute ==nSearchMode )
			{
				char buffer[RECORD_DISTRIBUTE_LEN + 4];
				if(IP_NET_DVR_GetReplay_OneDay_DistributeByXml(pResponse, buffer, sizeof(buffer)) != 0)
				{
					printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
				}
				else
				{
					buffer[RECORD_DISTRIBUTE_LEN] = '\0';
					printf("Parse distribue :%s \n", buffer);
				}
			}
			break;
		}
	case CMD_GET_SYSTEMCONTROLSTRING:
		{//获取能力集
			mutex_map.Lock();				
			map<string, MyIpcamera>::iterator it = mapIpcameraInstance.begin();
			for(; it != mapIpcameraInstance.end(); ++it )
			{
				const string &sn = it->first;
				MyIpcamera &cameraInfo = it->second;
				if( cameraInfo.lUserID == lUser )
				{
					printf("\033[32msn: %s \033[0mlUserID %#lx \033[32m%s:%u\033[0m CMD_GET_SYSTEMCONTROLSTRINGOK \n",sn.c_str(), 
						cameraInfo.lUserID, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort);

					strncpy(cameraInfo.szCapability, pResponse, 1024-1);				
					break;
				}
			}

			mutex_map.Unlock();				

		}
		break;

	case CMD_SNAP_JPEG_PICTURE:
		{
#if 0		//收到消息回应的时候，抓图可能还未完成，这个时候去下载可能会下载不到
			//需要在OnStateEvent中收到alarm code为ALARM_CODE_JPEG_CAPTURED的报警时去下载
			char* fname = (char*)malloc(strlen(pResponse)+1);
			if(!fname)
			{
				printf("malloc fail\n");
				break;
			}

			if(1 == sscanf(pResponse, "%*[^\"]\"%[^\"]", fname))
			{
				printf("CMD_SNAP_JPEG_PICTURE, filename:%s, download it\n", fname);

				char tmp[256];
				snprintf(tmp, 256, "/tmp/%s", fname);
				IP_NET_DVR_GetFileByName(lUser, 1, tmp, (char*)"./");
			}
			free(fname);
#endif			
		}
		break;

	case CMD_GET_MEDIA_CAPABILITY:
		{
			printf("%s\n", pResponse);
			int nVideoCapCount = 0;
			int nAudioCapCount = 0;
			RESOLUTION_ENTRY *pOutVideoCap = NULL;			
			AUDIO_CODEC_ENTRY *pOutAudioCap = NULL;
			int ret = IP_NET_DVR_XMLGET_MediaCapability(pResponse, &nVideoCapCount, &pOutVideoCap, &nAudioCapCount, &pOutAudioCap);
			if( ret == 0 )
			{
				printf("Get capability video  count %d, audio count %d\n", nVideoCapCount, nAudioCapCount);
			}

			ShowMediaCapability(nVideoCapCount, pOutVideoCap, nAudioCapCount, pOutAudioCap);


			mutex_map.Lock();				
			map<string, MyIpcamera>::iterator it = mapIpcameraInstance.begin();
			for(; it != mapIpcameraInstance.end(); ++it )
			{
				const string &sn = it->first;
				MyIpcamera &cameraInfo = it->second;
				if( cameraInfo.lUserID == lUser )
				{
					printf("\033[32msn: %s \033[0m lUserID %#lx \033[32m%s:%u\033[0m GET media capability OK \n",sn.c_str(), 
						cameraInfo.lUserID, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort);


					if( cameraInfo.pOutVideoCap != NULL )
					{
						delete [] cameraInfo.pOutVideoCap;
						cameraInfo.pOutVideoCap = NULL;
					}
					if( cameraInfo.pOutAudioCap != NULL )
					{
						delete [] cameraInfo.pOutAudioCap;
						cameraInfo.pOutAudioCap = NULL;
					}

					cameraInfo.pOutVideoCap = new RESOLUTION_ENTRY[nVideoCapCount];
					memcpy(cameraInfo.pOutVideoCap, pOutVideoCap, sizeof(RESOLUTION_ENTRY)*(nVideoCapCount));

					cameraInfo.pOutAudioCap = new AUDIO_CODEC_ENTRY[nAudioCapCount];
					memcpy(cameraInfo.pOutAudioCap, pOutAudioCap, sizeof(AUDIO_CODEC_ENTRY)*(nAudioCapCount));	

					cameraInfo.nVideoCapCount = nVideoCapCount;
					cameraInfo.nAudioCapCount = nAudioCapCount;
				
					
					break;
				}
			}

			mutex_map.Unlock();				
			

			if( pOutVideoCap != NULL )
			{
				delete [] pOutVideoCap;
			}
			if( pOutAudioCap != NULL )
			{
				delete [] pOutAudioCap;
			}
			
		}
		break;

	case CMD_GET_SYSTEM_TIME:
		{
			AjTime nowtime;
			int ret = IP_NET_DVR_XMLGET_SYSTEMTIME(pResponse, &nowtime);
			if( ret == 0 )
			{
				printf("id %ld: timezone %d, time %04d-%02d-%02d %02d:%02d:%02d\n",
					lUser,
					nowtime.timezone,
					nowtime.year,
					nowtime.month,
					nowtime.day,
					nowtime.hour,
					nowtime.min,
					nowtime.second
					);
			}
			break;
		}
	
	case CMD_SET_SYSTEM_TIME:
		{
			printf("[%s] %d: code %d CMD_SET_SYSTEM_TIME.\n", __func__, __LINE__,ActionCode);
			break;
		}

		// config get
		// AlarmCONFIG:
	case CMD_GET_ALARM_CONFIG:
		{
			AlarmConfig *p_config = (AlarmConfig*)malloc(sizeof(AlarmConfig));
			if( IP_NET_DVR_GetAlarmConfigByXml(p_config, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}

			free(p_config);
			
			break;
		}

	case CMD_GET_ALARM_MOTIONDETECT_CONFIG:
		{
			MotionDetectAlarm cfg;
			if( IP_NET_DVR_Alarm_getMotionDetectByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_ALARM_INPUT_CONFIG:
		{
			InputAlarm cfg;
			if( IP_NET_DVR_Alarm_getInputByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_ALARM_VIDEOLOST_CONFIG:
		{
			VideoLostAlarm cfg;
			if( IP_NET_DVR_Alarm_getVideoLostByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_ALARM_VIDEOCOVER_CONFIG:
		{
			VideoCoverAlarm cfg;
			if( IP_NET_DVR_Alarm_getVideoCoverByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_ALARM_SF_CONFIG:
		{
			StorageFullAlarm cfg;
			if( IP_NET_DVR_Alarm_getStorageFullByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// SystemCONFIG:
	case CMD_GET_SYSTEM_CONFIG:
		{
			SystemConfig cfg;
			if( IP_NET_DVR_GetSystemConfigByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_PTZ_CONFIG:
		{
			PTZConfig cfg;
			if( IP_NET_DVR_System_getPTZCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_USER_CONFIG:
		{
			UserConfig cfg;
			if( IP_NET_DVR_System_getUserCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_LOG_CONFIG:
		{
			SyslogConfig cfg;
			if( IP_NET_DVR_System_getLogCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_TIME_CONFIG:
		{
			TimeConfig cfg;
			if( IP_NET_DVR_System_getTimeCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_VERSION_INFO:
		{
			SYSTEM_VERSION_DATA cfg;
			if( IP_NET_DVR_GetSystemVersionByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_SYSTEM_MISC_CONFIG:
		{
			MiscConfig cfg;
			if( IP_NET_DVR_System_getMiscCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// RecordCONFIG:
	case CMD_GET_RECORD_CONFIG:
		{
			RecordConfig cfg;
			if( IP_NET_DVR_GetRecordCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// MediaCONFIG:
	case CMD_GET_MEDIA_CONFIG:
		{
			MediaConfig cfg;
			if( IP_NET_DVR_GetMediaCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);

				g_bmediacfg_gotton = 1;
				memcpy(&g_ipc_mediacfg, &cfg, sizeof(MediaConfig));
			}
			break;
		}

	case CMD_GET_MEDIA_VIDEO_CONFIG:
		{
			VideoConfig cfg;
			if( IP_NET_DVR_Media_getVideoByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
				printf("********cfg.videoCapture.brightness=%d\n",cfg.videoCapture.brightness);
				printf("********cfg.videoCapture.contrast=%d\n",cfg.videoCapture.contrast);
				printf("********cfg.videoCapture.saturation=%d\n",cfg.videoCapture.saturation);
				printf("********cfg.videoCapture.sharpness=%d\n",cfg.videoCapture.sharpness);
				
				printf("********cfg.videoCapture.tvsystem=%d\n",cfg.videoCapture.tvsystem);
				printf("********cfg.videoCapture.hflip=%d\n",cfg.videoCapture.hflip);
				printf("********cfg.videoCapture.vflip=%d\n",cfg.videoCapture.vflip);
				printf("********cfg.videoCapture.rotate=%d\n",cfg.videoCapture.rotate);
				
				printf("********cfg.videoCapture.whitebalance=%d\n",cfg.videoCapture.whitebalance);
				printf("********cfg.videoCapture.backlight=%d\n",cfg.videoCapture.backlight);
				printf("********cfg.videoCapture.HLC=%d\n",cfg.videoCapture.HLC);
				printf("********cfg.videoCapture.tnf=%d\n",cfg.videoCapture.tnf);
				printf("********cfg.videoCapture.snf=%d\n",cfg.videoCapture.snf);				
				
				printf("********cfg.videoCapture.ircut_mode=%d\n",cfg.videoCapture.ircut_mode);
				printf("********cfg.videoCapture.ircut_sensitivity=%d\n",cfg.videoCapture.ircut_sensitivity);
				printf("********cfg.videoCapture.ircut_nighttime.startTime.hour=%d\n",cfg.videoCapture.ircut_nighttime.startTime.hour);
				printf("********cfg.videoCapture.ircut_nighttime.startTime.minute=%d\n",cfg.videoCapture.ircut_nighttime.startTime.minute);
				printf("********cfg.videoCapture.ircut_nighttime.startTime.sec=%d\n",cfg.videoCapture.ircut_nighttime.startTime.sec);
				printf("********cfg.videoCapture.ircut_nighttime.endTime.hour=%d\n",cfg.videoCapture.ircut_nighttime.endTime.hour);
				printf("********cfg.videoCapture.ircut_nighttime.endTime.minute=%d\n",cfg.videoCapture.ircut_nighttime.endTime.minute);
				printf("********cfg.videoCapture.ircut_nighttime.endTime.sec=%d\n",cfg.videoCapture.ircut_nighttime.endTime.sec);
				printf("********cfg.videoCapture.ircut_keepcolor=%d\n",cfg.videoCapture.ircut_keepcolor);

				printf("********cfg.videoCapture.wdr_mode=%d\n",cfg.videoCapture.wdr_mode);
				printf("********cfg.videoCapture.wdr_value=%d\n",cfg.videoCapture.wdr_value);
				printf("********cfg.videoEncode.wdr_worktime.startTime.hour=%d\n",cfg.videoCapture.wdr_worktime.startTime.hour);
				printf("********cfg.videoEncode.wdr_worktime.startTime.minute=%d\n",cfg.videoCapture.wdr_worktime.startTime.minute);
				printf("********cfg.videoEncode.wdr_worktime.startTime.sec=%d\n",cfg.videoCapture.wdr_worktime.startTime.sec);
				printf("********cfg.videoEncode.wdr_worktime.endTime.hour=%d\n",cfg.videoCapture.wdr_worktime.endTime.hour);
				printf("********cfg.videoEncode.wdr_worktime.endTime.minute=%d\n",cfg.videoCapture.wdr_worktime.endTime.minute);
				printf("********cfg.videoEncode.wdr_worktime.endTime.sec=%d\n",cfg.videoCapture.wdr_worktime.endTime.sec);
				
				printf("********cfg.videoCapture.dfrog_flag=%d\n",cfg.videoCapture.dfrog_flag);
				printf("********cfg.videoCapture.dfrog_value=%d\n",cfg.videoCapture.dfrog_value);

				
				printf("********cfg.videoEncode.encodeCfg[0].streamID=%d\n",cfg.videoEncode.encodeCfg[0].streamID);
				printf("********cfg.videoEncode.encodeCfg[0].resolution.name=%s\n",cfg.videoEncode.encodeCfg[0].resolution.name);
				printf("********cfg.videoEncode.encodeCfg[0].encodeFormat.name=%s\n",cfg.videoEncode.encodeCfg[0].encodeFormat.name);
				printf("********cfg.videoEncode.encodeCfg[0].bitRateControl.name=%s\n",cfg.videoEncode.encodeCfg[0].bitRateControl.name);
				printf("********cfg.videoEncode.encodeCfg[0].initQuant=%d\n",cfg.videoEncode.encodeCfg[0].initQuant);
				printf("********cfg.videoEncode.encodeCfg[0].bitRate=%d\n",cfg.videoEncode.encodeCfg[0].bitRate);
				printf("********cfg.videoEncode.encodeCfg[0].frameRate=%d\n",cfg.videoEncode.encodeCfg[0].frameRate);
				printf("********cfg.videoEncode.encodeCfg[0].display_frameRate=%d\n",cfg.videoEncode.encodeCfg[0].display_frameRate);
				printf("********cfg.videoEncode.encodeCfg[1].streamID=%d\n",cfg.videoEncode.encodeCfg[1].streamID);
				printf("********cfg.videoEncode.encodeCfg[1].resolution.name=%s\n",cfg.videoEncode.encodeCfg[1].resolution.name);
				printf("********cfg.videoEncode.encodeCfg[1].encodeFormat.name=%s\n",cfg.videoEncode.encodeCfg[1].encodeFormat.name);
				printf("********cfg.videoEncode.encodeCfg[1].bitRateControl.name=%s\n",cfg.videoEncode.encodeCfg[1].bitRateControl.name);
				printf("********cfg.videoEncode.encodeCfg[1].initQuant=%d\n",cfg.videoEncode.encodeCfg[1].initQuant);
				printf("********cfg.videoEncode.encodeCfg[1].bitRate=%d\n",cfg.videoEncode.encodeCfg[1].bitRate);
				printf("********cfg.videoEncode.encodeCfg[1].frameRate=%d\n",cfg.videoEncode.encodeCfg[1].frameRate);
				printf("********cfg.videoEncode.encodeCfg[1].display_frameRate=%d\n",cfg.videoEncode.encodeCfg[1].display_frameRate);
				printf("********cfg.videoEncode.encode_profile=%d\n",cfg.videoEncode.encode_profile);
				printf("********cfg.videoEncode.disable_private_data=%d\n",cfg.videoEncode.disable_private_data);
				printf("********cfg.jpegCfg.enable=%d\n",cfg.jpegCfg.enable);
				printf("********cfg.jpegCfg.quality=%d\n",cfg.jpegCfg.quality);
				printf("********cfg.overlay.enable=%d\n",cfg.overlay.enable);
				printf("********cfg.overlay.transparency=%d\n",cfg.overlay.transparency);
				printf("********cfg.overlay.timeOverlay.posX=%d\n",cfg.overlay.timeOverlay.posX);
				printf("********cfg.overlay.timeOverlay.posY=%d\n",cfg.overlay.timeOverlay.posY);
				printf("********cfg.overlay.timeOverlay.timeFormat.format=%s\n",cfg.overlay.timeOverlay.timeFormat.format);
				printf("********cfg.overlay.titleOverlay.posX=%d\n",cfg.overlay.titleOverlay.posX);
				printf("********cfg.overlay.titleOverlay.posY=%d\n",cfg.overlay.titleOverlay.posY);
				printf("********cfg.overlay.titleOverlay.title=%s\n",cfg.overlay.titleOverlay.title_utf8);
				printf("********cfg.overlay.style=%d\n",cfg.overlay.style);
				printf("********cfg.videoMask.mainStreamMaskList[0].xPos=%d\n",cfg.videoMask.mainStreamMaskList[0].xPos);
				printf("********cfg.videoMask.mainStreamMaskList[0].yPos=%d\n",cfg.videoMask.mainStreamMaskList[0].yPos);
				printf("********cfg.videoMask.mainStreamMaskList[0].width=%d\n",cfg.videoMask.mainStreamMaskList[0].width);
				printf("********cfg.videoMask.mainStreamMaskList[0].height=%d\n",cfg.videoMask.mainStreamMaskList[0].height);
				printf("********cfg.videoMask.mainStreamMaskList[1].xPos=%d\n",cfg.videoMask.mainStreamMaskList[1].xPos);
				printf("********cfg.videoMask.mainStreamMaskList[1].yPos=%d\n",cfg.videoMask.mainStreamMaskList[1].yPos);
				printf("********cfg.videoMask.mainStreamMaskList[1].width=%d\n",cfg.videoMask.mainStreamMaskList[1].width);
				printf("********cfg.videoMask.mainStreamMaskList[1].height=%d\n",cfg.videoMask.mainStreamMaskList[1].height);
				printf("********cfg.videoMask.mainStreamMaskList[2].xPos=%d\n",cfg.videoMask.mainStreamMaskList[2].xPos);
				printf("********cfg.videoMask.mainStreamMaskList[2].yPos=%d\n",cfg.videoMask.mainStreamMaskList[2].yPos);
				printf("********cfg.videoMask.mainStreamMaskList[2].width=%d\n",cfg.videoMask.mainStreamMaskList[2].width);
				printf("********cfg.videoMask.mainStreamMaskList[2].height=%d\n",cfg.videoMask.mainStreamMaskList[2].height);
				printf("********cfg.videoMask.mainStreamMaskList[3].xPos=%d\n",cfg.videoMask.mainStreamMaskList[3].xPos);
				printf("********cfg.videoMask.mainStreamMaskList[3].yPos=%d\n",cfg.videoMask.mainStreamMaskList[3].yPos);
				printf("********cfg.videoMask.mainStreamMaskList[3].width=%d\n",cfg.videoMask.mainStreamMaskList[3].width);
				printf("********cfg.videoMask.mainStreamMaskList[3].height=%d\n",cfg.videoMask.mainStreamMaskList[3].height);
				printf("********cfg.videoMask.subStreamMaskList[0].xPos=%d\n",cfg.videoMask.subStreamMaskList[0].xPos);
				printf("********cfg.videoMask.subStreamMaskList[0].yPos=%d\n",cfg.videoMask.subStreamMaskList[0].yPos);
				printf("********cfg.videoMask.subStreamMaskList[0].width=%d\n",cfg.videoMask.subStreamMaskList[0].width);
				printf("********cfg.videoMask.subStreamMaskList[0].height=%d\n",cfg.videoMask.subStreamMaskList[0].height);
				printf("********cfg.videoMask.subStreamMaskList[1].xPos=%d\n",cfg.videoMask.subStreamMaskList[1].xPos);
				printf("********cfg.videoMask.subStreamMaskList[1].yPos=%d\n",cfg.videoMask.subStreamMaskList[1].yPos);
				printf("********cfg.videoMask.subStreamMaskList[1].width=%d\n",cfg.videoMask.subStreamMaskList[1].width);
				printf("********cfg.videoMask.subStreamMaskList[1].height=%d\n",cfg.videoMask.subStreamMaskList[1].height);
				printf("********cfg.videoMask.subStreamMaskList[2].xPos=%d\n",cfg.videoMask.subStreamMaskList[2].xPos);
				printf("********cfg.videoMask.subStreamMaskList[2].yPos=%d\n",cfg.videoMask.subStreamMaskList[2].yPos);
				printf("********cfg.videoMask.subStreamMaskList[2].width=%d\n",cfg.videoMask.subStreamMaskList[2].width);
				printf("********cfg.videoMask.subStreamMaskList[2].height=%d\n",cfg.videoMask.subStreamMaskList[2].height);
				printf("********cfg.videoMask.subStreamMaskList[3].xPos=%d\n",cfg.videoMask.subStreamMaskList[3].xPos);
				printf("********cfg.videoMask.subStreamMaskList[3].yPos=%d\n",cfg.videoMask.subStreamMaskList[3].yPos);
				printf("********cfg.videoMask.subStreamMaskList[3].width=%d\n",cfg.videoMask.subStreamMaskList[3].width);
				printf("********cfg.videoMask.subStreamMaskList[3].height=%d\n",cfg.videoMask.subStreamMaskList[3].height);
				printf("**********************----------------**********\n");
			}
			break;
		}

	case CMD_GET_MEDIA_AUDIO_CONFIG:
		{
			AudioConfig cfg;
			if( IP_NET_DVR_Media_getAudioByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_MEDIA_VIDEO_OSD:
		{
			VideoOverlay cfg;
			if( IP_NET_DVR_Media_getVideoOverlayByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
				printf("@@@@@@@@cfg.enable=%d\n",cfg.enable);
				printf("@@@@@@@@cfg.transparency=%d\n",cfg.transparency);
				printf("@@@@@@@@cfg.timeOverlay.posX=%d\n",cfg.timeOverlay.posX);
				printf("@@@@@@@@cfg.timeOverlay.posY=%d\n",cfg.timeOverlay.posY);
				printf("@@@@@@@@cfg.timeOverlay.timeFormat.format=%s\n",cfg.timeOverlay.timeFormat.format);
				printf("@@@@@@@@cfg.titleOverlay.posX=%d\n",cfg.titleOverlay.posX);
				printf("@@@@@@@@cfg.titleOverlay.posY=%d\n",cfg.titleOverlay.posY);
			}
			break;
		}



		// MediaStreamCONFIG:
	case CMD_GET_MEDIASTREAM_CONFIG:
		{
			printf("[%s] CMD_GET_MEDIASTREAM_CONFIG return %d\n",__func__, ErrorCode);
			printf("%s\n", pResponse);

			MediaStreamConfig cfg;
			int ret = IP_NET_DVR_GetMediaStreamCfgByXml(&cfg, pResponse);
			if( ret == 0 )
			{
				printf("IP_NET_DVR_GetMediaStreamCfgByXml OK. lUser %#lx\n", lUser);

				mutex_map.Lock();				
				map<string, MyIpcamera>::iterator it = mapIpcameraInstance.begin();
				for(; it != mapIpcameraInstance.end(); ++it )
				{
					const string &sn = it->first;
					MyIpcamera &cameraInfo = it->second;
					if( cameraInfo.lUserID == lUser )
					{
						memcpy(&cameraInfo.streamCfg, &cfg, sizeof(cfg));
						cameraInfo.bGetStreamConfig = 1;
					
						printf("\033[32msn: %s \033[0m lUserID %#lx \033[32m%s:%u\033[0m GET MediaStreamConfig OK: %d %d %d %d %d\n",sn.c_str(), 
							cameraInfo.lUserID, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort,
							cameraInfo.streamCfg.rtspConfig.rtsp_auth, cameraInfo.streamCfg.rtspConfig.videoPort, cameraInfo.streamCfg.rtspConfig.rtpoverrtsp,cameraInfo.streamCfg.commConfig.ptzPort,cameraInfo.streamCfg.webConfig.webPort);
						
						break;
					}
				}

				mutex_map.Unlock();				
				
			}
			else
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			
			break;
		}



		// PlatformCONFIG:
	case CMD_GET_PLATFORM_CONFIG:
		{
			PlatformConfig cfg;
			if( IP_NET_DVR_GetPlatformCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// GB28181CONFIG:
	case CMD_GET_GB28181_CONFIG:
		{
			GB28181Config cfg;
			if( IP_NET_DVR_GetGB28181CfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// NetworkCONFIGNew:
	case CMD_GET_NETWORK_CONFIG:
		{
			NetworkConfigNew cfg;
			if( IP_NET_DVR_GetNetworkCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_NETWORK_LAN_CONFIG:
		{
			LANConfig cfg;
			if( IP_NET_DVR_Network_getLANCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_NETWORK_WIFI_CONFIG:
		{
			WIFIConfig cfg;
			if( IP_NET_DVR_Network_getWIFICfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}

	case CMD_GET_NETWORK_ADSL_CONFIG:
		{
			break;
		}

	case CMD_GET_NETWORK_DDNS_CONFIG:
		{
			break;
		}

	case CMD_GET_NETWORK_UPNP_CONFIG:
		{
			break;
		}

	case CMD_GET_NETWORK_P2P_CONFIG:
		{
			P2PConfig cfg;
			if( IP_NET_DVR_Network_getP2PCfgByXml(&cfg, pResponse ) != 0 )
			{
				printf("[%s] %d: code %d parse error.\n", __func__, __LINE__,ActionCode);
			}
			else
			{
				printf("[%s] %d: code %d parse OK.\n", __func__, __LINE__,ActionCode);
			}
			break;
		}


		// ServerCONFIG:
	case CMD_GET_SERVER_CONFIG:
		{
			break;
		}

	case CMD_GET_SERVER_FTP_CONFIG:
		{
			break;
		}

	case CMD_GET_SERVER_SMTP_CONFIG:
		{
			break;
		}

	case CMD_SET_MEDIA_AUDIO_CONFIG:
		{
			printf("[%s] CMD_SET_MEDIA_AUDIO_CONFIG return %d\n",__func__, ErrorCode);
			break;
		}

	}

	return 0;
}

int cfg_GetLogonInfo(char*ip , char*user, char* pass, int *port)
{
	char buf[20];
	int ret ;
	ret = ConfigGetKey( (void*)CONFIG_FILE, (void*)"Logon", (void*)"logon_ip", buf);
	sprintf(ip,"%s",buf);

	ret = ConfigGetKey( (void*)CONFIG_FILE, (void*)"Logon", (void*)"logon_user", buf);
	sprintf(user,"%s",buf);    

	ret = ConfigGetKey( (void*)CONFIG_FILE, (void*)"Logon", (void*)"logon_pass", buf);
	sprintf(pass,"%s",buf);

	ret = ConfigGetKey( (void*)CONFIG_FILE, (void*)"Logon", (void*)"logon_port", buf);
	//sprintf(port,"%s",buf);   
	*port = (int)atol(buf);

	printf("=========================================\n");
	printf("==========[%s]\n",CONFIG_FILE);
	printf("logon_ip:%s\n",ip);
	printf("logon_user:%s\n",user);
	printf("logon_pass:%s\n",pass);
	printf("logon_port:%d\n",*port);

	printf("==========press Ctrl+c to abort, Enter to continue ... \n");

	return 0;
}


int ptzControl(long lUserID)
{
	char cmdstr[100];

	char xmldata[1200];
	long nPspeed=5,nTspeed=5;

	printf("============================================\n");
	printf("enter  ptz control, input 'ptz esc' to quit ,'help' for detail \n");
	printf("============================================\n");
	while( fgets(cmdstr,sizeof(cmdstr),stdin) )
	{

		if( strlen(cmdstr) <2 )
		{
			continue;
		}

		if( !strncmp(cmdstr,"ptz esc",strlen("ptz esc") ) )
		{
			break;
		}
		else if( !strncmp(cmdstr,"esc",strlen("esc") ) )
		{
			break;
		}
		else if( !strncmp(cmdstr,"help",strlen("help") ) )
		{
			printf("============================================\n");
			printf("valid command :[up] [down] [left] [right] [stop] [esc]....\n");
			printf("See documents for more details\n");
			printf("============================================\n");
			continue;
		}

		if(strlen(cmdstr) >1)
		{
			cmdstr[strlen(cmdstr)-1]='\0';
		}

		printf("get ptzcmd ----%s--\n",cmdstr);

		sprintf(xmldata,"<xml>\n<cmd>%s</cmd><panspeed>%ld</panspeed><tiltspeed>%ld</tiltspeed></xml>",cmdstr,nPspeed,nTspeed);

		IP_NET_DVR_PTZControlEx(lUserID,(char *)xmldata);

		Sleep(1);

	}

	printf(" quit  ptz control! \n");

	return 0;

}



int waitforLogon()
{
	printf("\n##########Logon...");
	while(1)
	{
		if(g_LogonOk)
		{
			break;
		}
		printf(".");
		usleep(1000*1000*1);

	}

	printf(".\n");
	return 0;
}

static char* GetIpAddrStr(int nIp)
{
	struct in_addr addr;
	memcpy(&addr.s_addr, &nIp, sizeof(int));
	return 	inet_ntoa(addr);
}

static unsigned int GetIpFromName(const char* szName)
{
	unsigned int nSvrIp = 0;
	if( szName == NULL || szName[0] == 0 )
		return nSvrIp;

	struct addrinfo * res, *pt;   
	struct sockaddr_in *sinp;   
	const char *addr;   
	char abuf[32];   
	int succ=0,i=0;   

	succ = getaddrinfo(szName, NULL, NULL, &res);   
	if(succ == 0)   
	{   
		for(pt=res, i=0; pt != NULL; pt=pt->ai_next, i++)
		{   
			sinp = (struct sockaddr_in *)pt->ai_addr;   
			addr = (const char *)inet_ntop(AF_INET, &sinp->sin_addr, abuf, 32);   
			if( nSvrIp == 0 )
			{
				nSvrIp = sinp->sin_addr.s_addr;
			}
		}   
	}   
	else
	{
		printf("getaddrinfo failed with %d. errorno: %d (%s)\n", succ, errno, strerror(errno));   
	}


	return nSvrIp;
}

static int isValidNetMask(const char* szMask)
{
	unsigned int nMask = GetIpFromName(szMask);
	if( nMask == 0 )
		return 0;

	printf("%#x\n", nMask);

	int iIndex = 0;
	for( iIndex = 0 ; iIndex < 24; iIndex++)
	{
		if( ntohl(nMask) == ((0xffffffff << iIndex ) & 0xffffffff))
		{
			printf("%#x %d\n", nMask, iIndex);
			return 1;
		}
	}

	return 0;	 
}

void *ShowSearchThread(void *arg)
{
	prctl(PR_SET_NAME, __func__);  

	unsigned long nLastTick = IP_NET_DVR_Get_Timestamp();
	unsigned long nStartTick = nLastTick;
	while( g_bSearching )
	{
		int nNowTick = IP_NET_DVR_Get_Timestamp();

		if( nNowTick - nLastTick < 3000 )
		{
			usleep(1000*10);
			continue;
		}

		nLastTick = nNowTick;		

		if( g_bAutoSearchAndRecord && (nNowTick - nStartTick > 30 * 1000) )	// 启用自动搜索并录像，延时再搜索30秒 后停止搜索
		{
			printf("g_bAutoSearchAndRecord:%d, nNowTick - nStartTick = %ld\n", g_bAutoSearchAndRecord, nNowTick - nStartTick);
			printf("\033[33mRecord start and Search time threshold reached: %ld, stop all search thread.\033[0m\n",nNowTick - nStartTick);
			IP_NET_DVR_StopSearchIPC();
			IP_NET_DVR_SearchIPCReleaseInfo();
			g_thread_show_searchresult = 0;
			pthread_detach(pthread_self());
			return NULL;
		}

		long ipc_count = IP_NET_DVR_GetSearchIPCCount();
		printf("sizeof(IPC_ENTRY)=%lu\n", sizeof(IPC_ENTRY));
		printf("Now get IPC count:\033[7m %3ld\033[0m\n",ipc_count);
		
		for(int idx=0;idx<ipc_count;idx++)
		{
			IPC_ENTRY info;
			int ErrorCode=IP_NET_DVR_GetIPCInfo(idx,&info);

			if(!ErrorCode)
			{//读成功了,打印设备结构体信息
				printf("\033[33mDevice \033[0m\033[31m%3d\033[0m: timestamp:[%llu] NIC:[%s] mac=[%s], type=[%s], sn=[%s]\033[0m,\033[31m IP=[%s],\033[0m \033[33mdhcp=[%d], netmask=[%s], gw=[%s], dns1=[%s], dns2=[%s], onvifAllNet=[%d], userName=[%s], password=[%s], status=[%s], P2PID=[%s], title=[%s]\033[0m\n", 
					idx, \
					info.latest_timestamp, \
					info.szInterfaceName, \
					info.lanCfg.MACAddress, \
					info.deviceType, \
					info.ipc_sn, \
					info.lanCfg.IPAddress, \
					info.lanCfg.dhcpEnable, \
					info.lanCfg.netMask, \
					info.lanCfg.gateWay, \
					info.lanCfg.DNS1, \
					info.lanCfg.DNS2, \
					info.lanCfg.onvifAllnetEnable, \
					info.userCfg.accounts->userName, \
					info.userCfg.accounts->password, \
					info.userCfg.accounts->status, \
					info.p2p_id, \
					info.title);
				//将所有搜索到的设备存入全局数组g_IPC_SET[]
				g_IPC_SET[idx] = info;

				//默认只搜索不自动登陆
				printf("g_bAutoSearchAndRecord = %d\n", g_bAutoSearchAndRecord);
				printf("g_bAutoSearchAndLogin = %d\n", g_bAutoSearchAndLogin);
				if( g_bAutoSearchAndRecord == 0 && g_bAutoSearchAndLogin == 0 )	
				{
					continue;
				}
				mutex_map.Lock();
				map<string, MyIpcamera>::iterator it = mapIpcameraInstance.find(info.ipc_sn);
				if( it == mapIpcameraInstance.end() )
				{
					//若结构体不返回用户名密码就采用默认admin，123456
					//printf("info.userCfg.accounts[0].userName:%s\n",info.userCfg.accounts[0].userName);
					//printf("info.userCfg.accounts[0].password:%s\n",info.userCfg.accounts[0].password);
					if(!strcmp(info.userCfg.accounts[0].userName, ""))
						strcpy(info.userCfg.accounts[0].userName, DEFAULT_USERNAME);
					if(!strcmp(info.userCfg.accounts[0].password, ""))
						strcpy(info.userCfg.accounts[0].password, DEFAULT_PASSWORD);
					printf("Use the default username and password to login camera\n");
					printf("userName:%s\n",info.userCfg.accounts[0].userName);
					printf("password:%s\n",info.userCfg.accounts[0].password);

					LONG lUserID = IP_NET_DVR_Login(
					(char *)info.lanCfg.IPAddress,info.streamCfg.commConfig.ptzPort,
					(char *)info.userCfg.accounts[0].userName,
					(char *)info.userCfg.accounts[0].password,
					NULL);


					printf("IP_NET_DVR_Login: %s:%u return UserID: %#lx\n", 
						info.lanCfg.IPAddress, info.streamCfg.commConfig.ptzPort, lUserID);

					if( lUserID != 0 )
					{
						MyIpcamera cameraInfo;
						memset(&cameraInfo, 0, sizeof(cameraInfo));
						memcpy(&cameraInfo.info, &info, sizeof(info));
						cameraInfo.lUserID = lUserID;
						mapIpcameraInstance[info.ipc_sn] = cameraInfo;
					}
				}
				else
				{
					MyIpcamera &cameraInfo = it->second;
					if( strcmp(cameraInfo.info.lanCfg.IPAddress, info.lanCfg.IPAddress) != 0 
						|| cameraInfo.info.streamCfg.commConfig.ptzPort != info.streamCfg.commConfig.ptzPort )
					{
						printf("sn %s old %s:%u, new %s:%u\n",
							info.ipc_sn, cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort,
							info.lanCfg.IPAddress, info.streamCfg.commConfig.ptzPort);
						if( cameraInfo.lUserID != 0 )
						{
							printf("\033[31m IP_NET_DVR_Logout\033[0m %-15s:%u, lUserID %#lx\n", 
								cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
							IP_NET_DVR_Logout(cameraInfo.lUserID);
							
							cameraInfo.lUserID = IP_NET_DVR_Login(
							(char *)info.lanCfg.IPAddress,info.streamCfg.commConfig.ptzPort,
							(char *)info.userCfg.accounts[0].userName,
							(char *)info.userCfg.accounts[0].password,
							NULL);
							
							printf("IP_NET_DVR_Login %s:%u return UserID %#lx\n", 
								info.lanCfg.IPAddress, info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
						}
					}
				}

				mutex_map.Unlock();				
			}
		}
	}

	printf("[%s] %d: exit main loop.\n", __func__, __LINE__);

	return NULL;
}

typedef void (*P_HANDLE_FUNC)(char*);  

typedef struct
{
	char szCmd[64];
	P_HANDLE_FUNC pFunc;
}AjCmdStruct;


void handle_login(char *param)
{
	cfg_GetLogonInfo(g_ip,g_user,g_pass,&g_port);

	m_nLastCmdId=IP_NET_DVR_Login((char *)g_ip,g_port,(char *)g_user,(char *)g_pass,NULL);
	if(m_nLastCmdId==0)
	{
		printf("\033[31Read cfg and logon error 0 !\033[0m\n");
		return;
	}
}

void handle_logout(char *param)
{
	if(m_nLastCmdId == 0  )
		return;
	
	IP_NET_DVR_Logout(m_nLastCmdId);

	m_nLastCmdId = 0;
}


void handle_search_begin(char *param)
{
	int ret;

	ret = IP_NET_DVR_StartSearchIPC();
	if(ret)
	{
		printf("\033[32m#######call IP_NET_DVR_StartSearchIPC() fail\033[0m\n");
	}else
	{
		g_bSearching = 1;

		if( !g_thread_show_searchresult )
		{
			if(pthread_create(&g_thread_show_searchresult, NULL, ShowSearchThread, NULL))
			{
				printf("\033[32m Create new ShowSearchThread ok! %#lx \033[0m\n",g_thread_show_searchresult);
			}
			else
			{
				printf("\033[32m ShowSearchThread is running! %#lx \033[0m\n",g_thread_show_searchresult);
			}
		}
	}
}

void handle_autosearchandrecord(char *param)
{
	g_bAutoSearchAndRecord = 1;
	printf("g_bAutoSearchAndRecord = %d\n", g_bAutoSearchAndRecord);
	handle_search_begin(NULL);
}
void handle_autosearchandlogin(char *param)
{
	g_bAutoSearchAndLogin = 1;
	printf("g_bAutoSearchAndLogin = %d\n", g_bAutoSearchAndLogin);
	handle_search_begin(NULL);
}
	
void handle_search_stop(char *param)
{
	g_bSearching = 0;

	if ( g_thread_show_searchresult )
	{
		if ( pthread_join(g_thread_show_searchresult, NULL) )
		{
			printf("join failed\n");
		}
	}

	g_thread_show_searchresult = 0;

	IP_NET_DVR_StopSearchIPC();
	IP_NET_DVR_SearchIPCReleaseInfo();
}

void handle_ircutcontrol(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}

	char *p =  param;
	int day = 1;
	char szDay[128];
	int ret = sscanf(p, "%d", &day);

	if( ret < 1 )
	{
		printf("ircut control not found params!\n");
	}
	else
	{
		day = day > 0 ? 1:0;
		IP_NET_DVR_Ircut_switch_daynight(m_nLastCmdId, day);
	}
}

void handle_replay_dates_distribute(char *param)
{
	LONG ret;
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}

	IP_NET_DVR_GetReplay_Dates_Distribute(m_nLastCmdId);
}

void handle_replay_day_distribute(char *param)
{
	LONG ret;
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}

	time_t nowtime = time(NULL);
	struct tm *tm_time = localtime(&nowtime);
	int play_year	= tm_time->tm_year + 1900;
	int play_month	= tm_time->tm_mon + 1;
	int play_day	= tm_time->tm_mday;
	printf("Search record of day %04d%02d%02d.\n", play_year, play_month, play_day);
	IP_NET_DVR_GetReplay_OneDay_Distribute(m_nLastCmdId, play_year, play_month, play_day);
}


void handle_replaytest(char *param)
{
	LONG ret;
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}

	time_t nowtime = time(NULL);
	struct tm *tm_time = localtime(&nowtime);

	tm_time->tm_hour = 12;
	tm_time->tm_min  = 0;
	tm_time->tm_sec  = 0;
	time_t time_today = mktime(tm_time);


	g_mutex_replay.Lock();
	if( !g_fp_replay )
	{
		char szFileName[128];
		sprintf(szFileName, "replay_%04d%02d%02d_%02d%02d%02d.h265", 
			tm_time->tm_year+1900,
			tm_time->tm_mon+1,
			tm_time->tm_mday,
			tm_time->tm_hour,
			tm_time->tm_min,
			tm_time->tm_sec); 
		g_fp_replay = fopen(szFileName, "wb");
	}
	g_mutex_replay.Unlock();
	
	printf("===== Start replay %lu===== \n", time_today);
	ret = IP_NET_DVR_ReplayByTime(m_nLastCmdId, time_today);
	printf("IP_NET_DVR_ReplayByTime result:%ld \n", ret);
	Sleep(10 * 1000);


	

	g_mutex_replay.Lock();
	if( g_fp_replay )
	{
		fclose(g_fp_replay);
		g_fp_replay = NULL;
	}
	g_mutex_replay.Unlock();

	tm_time->tm_hour += 1;
	time_t time_seek = mktime(tm_time);
	printf("===== Seek to %lu===== \n", time_seek);

	IP_NET_DVR_ControlReplay(m_nLastCmdId, ACTION_SEEK, time_seek);
	g_mutex_replay.Lock();
	if( !g_fp_replay )
	{
		char szFileName[128];
		sprintf(szFileName, "replay_%04d%02d%02d_%02d%02d%02d.h265", 
			tm_time->tm_year+1900,
			tm_time->tm_mon+1,
			tm_time->tm_mday,
			tm_time->tm_hour,
			tm_time->tm_min,
			tm_time->tm_sec); 
		g_fp_replay = fopen(szFileName, "wb");
	}
	g_mutex_replay.Unlock();
	Sleep(10 * 1000);

	printf("===== Stop replay ===== \n");
	IP_NET_DVR_ControlReplay(m_nLastCmdId, ACTION_STOP, 0);
	
	g_mutex_replay.Lock();
	if( g_fp_replay )
	{
		fclose(g_fp_replay);
		g_fp_replay = NULL;
	}
	g_mutex_replay.Unlock();

	
}

void handle_upgrade_test(char *param)
{
	LONG ret;
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}

	printf("Begin test upgrade file\n");
	ret = IP_NET_DVR_Upgrade(m_nLastCmdId, (char *)"./firmware_MC200E6_V0-GLK-H5_V2.3.18_201907041415.bin");
	if(ret != 0)
	{
		printf("IP_NET_DVR_Upgrade fail:%ld.\n", ret);
		return;
	}
	while (true) {
		ret = IP_NET_DVR_GetUpgradeProgress(m_nLastCmdId);
		if(ret < 0)
		{
			printf("Upgrade error :%ld\n", ret);
			break;
		}
		else if(ret > 100)
		{
			printf("Firmware upload success.\n");//file upload finished, firmware start flash to device.
			break;
		}
		else
		{
			printf("Upload progress:%ld\n", ret);
		}
		Sleep(100);
	}

	IP_NET_DVR_CloseUpgradeHandle(m_nLastCmdId);
}

void handle_getsdkversion(char *param)
{
	printf("SDK version:%ld, built %ld\n",IP_NET_DVR_GetSDKVersion(),IP_NET_DVR_GetSDKBuildVersion());
	
}

void handle_ptz(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	ptzControl(m_nLastCmdId);
}

void handle_realplay_begin(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	g_onMediaRecv = 1;

	if( gHandle_realplay == 0 )
	{
		USRE_VIDEOINFO userinfo;
		userinfo.bIsTcp=1;
		userinfo.nVideoPort=554;
		userinfo.nVideoChannle=0;
		userinfo.pUserData=(void*)0x88888888;
		gHandle_realplay = IP_NET_DVR_RealPlayEx((char *)g_ip,(char *)g_user,(char *)g_pass,OnMediaRecv,&userinfo,1);
		if(gHandle_realplay!=0)
		{
			printf("realplay retValue:%#lx\n",gHandle_realplay);
		}
	}
}
void handle_realplay_stop(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	g_onMediaRecv =0 ;
	g_newVidRecord = 1;
	g_newAudRecord = 1;
	if( gHandle_realplay != 0 )
	{	
		IP_NET_DVR_StopRealPlay(gHandle_realplay); 
	}
	gHandle_realplay = 0;
}


void handle_show_debug(char *param)
{
	IP_NET_DVR_SetLogToFile(3,(char*)".",0);
}

void handle_hide_debug(char *param)
{
	IP_NET_DVR_SetLogToFile(0,(char*)".",0);
}
void handle_readsn(char *param)
{
	printf("m_nLastCmdId:%ld\n",m_nLastCmdId);
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	int ret;
	ret=IP_NET_DVR_SystemControl(m_nLastCmdId,(long)CMD_GET_SERIALNUMBER,0,(char*)"");
	if(ret<0)
	{
		printf("readsn error!\n");
	}
}

//handle_get_version
void handle_get_version(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	int ret;

	ret=IP_NET_DVR_SystemControl(m_nLastCmdId, CMD_GET_SYSTEM_VERSION_INFO,0,(char*)"");
	
	if(ret<0)
	{
		printf("get current firmware version error!\n");
	}
}
//handle_GetDeviceAbility
void handle_GetDeviceAbility(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	int ret;

	ret=IP_NET_DVR_GetDeviceAbility(m_nLastCmdId);
	
	if(ret<0)
	{
		printf("GetDeviceAbility error!\n");
	}
}
// reboot one device by input SN
void handle_reboot(char *param)
{
	char SN[MAX_IPC_SERIALNUMBER];
	printf("input SN to reboot it:");
	scanf(" %s",SN);

	int ret;

	ret=IP_NET_DVR_RebootIPCBySN(SN);
	
	if(ret<0)
	{
		printf("RebootIPCBySN error!\n");
	}
}
// reboot handle_rebootLoggedin
void handle_rebootLoggedin(char *param)
{
	int ret;

	ret=IP_NET_DVR_RebootDVR(m_nLastCmdId);
	
	if(ret<0)
	{
		printf("Reboot IPC by IP_NET_DVR_RebootDVR unicast error!\n");
	}
}

// reboot one device by input SN
void handle_restore(char *param)
{
	char SN[MAX_IPC_SERIALNUMBER];
	printf("input SN to reboot it:");
	scanf(" %s",SN);

	int ret;
	ret=IP_NET_DVR_RestoreIPCBySN(SN);
	if(ret<0)
	{
		printf("RestoreIPCBySN error!\n");
	}
}

// restore factory config
void handle_restore_config_Loggenin(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	printf("\033[31mrestore factory config\033[0m\n");
	int ret;

	ret=IP_NET_DVR_RestoreConfig(m_nLastCmdId);
	
	if(ret<0)
	{
		printf("\033[31mrestore factory config error!\033[0m\n");
	}
}
// reboot all device by SN in g_IPC_SET[]
void handle_reboot_all(char *param)
{
	printf("reboot all found device in 5 seconds!\n");
	sleep(5);
	long unsigned i;
	int ret ;
	for (i = 0; i < sizeof(g_IPC_SET)/sizeof(g_IPC_SET[0]); i++)
	{
		if (!strcmp(g_IPC_SET[i].ipc_sn,""))	break;
		
		printf("\033[31mreboot device: %s\033[0m\n",g_IPC_SET[i].ipc_sn);
		ret = IP_NET_DVR_RebootIPCBySN(g_IPC_SET[i].ipc_sn);

		if(ret<0)
		{
			printf("RebootIPCBySN error!\n");
		}
	}
}

// reboot all device by SN in g_IPC_SET[]
void handle_restore_all(char *param)
{
	printf("reboot all found device in 5 seconds!\n");
	sleep(5);
	long unsigned i;
	int ret ;
	for (i = 0; i < sizeof(g_IPC_SET)/sizeof(g_IPC_SET[0]); i++)
	{
		if (!strcmp(g_IPC_SET[i].ipc_sn,""))	break;
		
		printf("\033[31mreboot device: %s\033[0m\n",g_IPC_SET[i].ipc_sn);
		ret = IP_NET_DVR_RestoreIPCBySN(g_IPC_SET[i].ipc_sn);

		if(ret<0)
		{
			printf("RestoreIPCBySN error!\n");
		}
	}
}


//handle_get_osd
void handle_get_osd(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	int ret;

	ret=IP_NET_DVR_SystemControl(m_nLastCmdId, CMD_GET_MEDIA_VIDEO_OSD,0,(char*)"");
	
	if(ret<0)
	{
		printf("get osd overlay error!\n");
	}
}
//获取配置信息
void handle_get_config(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	IP_NET_DVR_GET_MediaCapability(m_nLastCmdId);
	IP_NET_DVR_GET_MediaConfig(m_nLastCmdId);
	IP_NET_DVR_GET_VideoConfig(m_nLastCmdId);
	IP_NET_DVR_GET_PersonDetectAlarm(m_nLastCmdId);

	IP_NET_DVR_GET_MediaCapability(m_nLastCmdId);
//	IP_NET_DVR_GET_VideoOSDConfig(m_nLastCmdId);
	IP_NET_DVR_GetDVRConfig(m_nLastCmdId, CMD_MEDIA_CONFIG_BASE,0,(void*)"",0,0);

	IP_NET_DVR_GET_AlarmConfig(m_nLastCmdId);
	IP_NET_DVR_GET_MotionDetectAlarm(m_nLastCmdId);
	IP_NET_DVR_GET_InputAlarm(m_nLastCmdId);
	IP_NET_DVR_GET_VideoLostAlarm(m_nLastCmdId);
	IP_NET_DVR_GET_VideoCoverAlarm(m_nLastCmdId);
	IP_NET_DVR_GET_StorageFullAlarm(m_nLastCmdId);

	IP_NET_DVR_GET_SystemConfig(m_nLastCmdId);
	IP_NET_DVR_GET_PtzConfig(m_nLastCmdId);
	IP_NET_DVR_GET_UserConfig(m_nLastCmdId);
	IP_NET_DVR_GET_SyslogConfig(m_nLastCmdId);
	IP_NET_DVR_GET_TimeConfig(m_nLastCmdId);
	IP_NET_DVR_GET_MiscConfig(m_nLastCmdId);

	IP_NET_DVR_GET_RecordConfig(m_nLastCmdId);

	IP_NET_DVR_GET_VideoConfig(m_nLastCmdId);
	IP_NET_DVR_GET_AudioConfig(m_nLastCmdId);
//	IP_NET_DVR_GET_VideoOSDConfig(m_nLastCmdId);

	IP_NET_DVR_GET_MediaStreamConfig(m_nLastCmdId);

	IP_NET_DVR_GET_PlatformConfig(m_nLastCmdId);
	IP_NET_DVR_GET_GB28181Config(m_nLastCmdId);

	IP_NET_DVR_GET_NetworkConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkLANConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkWIFIConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkADSLConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkDDNSConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkUPNPConfig(m_nLastCmdId);
	IP_NET_DVR_GET_NetworkP2PConfig(m_nLastCmdId);

	IP_NET_DVR_GET_ServerConfig(m_nLastCmdId);
	IP_NET_DVR_GET_FtpServerConfig(m_nLastCmdId);
	IP_NET_DVR_GET_SmtpServerConfig(m_nLastCmdId);		
}
void handle_snappic(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	int ret;
	printf("\n\033[32m Mainstream Snapshot:\033[0m\n");
	ret = IP_NET_DVR_SnapPic(m_nLastCmdId, 0, 100, "testMainStreamSnapshot.jpg", 0);
	sleep(2);
	printf("\n\033[32m Substream Snapshot:\033[0m\n");
	ret = IP_NET_DVR_SnapPic(m_nLastCmdId, 1, 100, "testSubStreamSnapshot.jpg", 0);
	printf("IP_NET_DVR_SnapPic, ret :%d\n", ret);
}
//下载设备配置文件
void handle_download_config(char *param)
{
	if( 0 == g_LogonOk )
	{
		printf("\033[31mplease login first.\033[0m\n");
		return;
	}
	
	int ret;
	ret = IP_NET_DVR_GetConfigFile(m_nLastCmdId,"conf.ipc.xml");
	if (!ret)
	{
		printf("\033[32mdownload_config at conf.ipc.xml ok\033[0m\n");
	}
}
void handle_modifyipc(char *param)
{ 
	int ret;
	char SN[MAX_IPC_SERIALNUMBER];
	char *p = param;
	LANConfig config;
	memset(&config, 0, sizeof(config));
	printf("Usage: \033[33mSN DHCP[0-1] IPAddress netMask gateWay DNS1 DNS2, at least two parameters\033[0m\n");
	printf("%s %hd %s %s %s %s %s\n", SN, config.dhcpEnable, config.IPAddress, config.netMask, config.gateWay, config.DNS1, config.DNS2);

	ret = sscanf(p, "%s %hd %s %s %s %s %s", SN, &config.dhcpEnable, config.IPAddress, config.netMask, config.gateWay, config.DNS1, config.DNS2);
	printf("Read %d parameters.\n",ret);

	if( strlen(SN) != 16 )
	{
		printf("SN %s error.\n", SN);
		return;
	}
	
	//设置DHCP Enable
	if ( config.dhcpEnable )
	{
		
		ret=IP_NET_DVR_ModifyIPCBySN(SN, &config, 0);// if do not change server ports, fill NULL in the third param
		if ( !ret )
		{
			printf("DHCP Enable: %d OK\n", config.dhcpEnable);
		}
		
		return ;
	}

	unsigned int nIP = GetIpFromName(config.IPAddress);
	if ( ret < 3 )
	{
		if( nIP == 0 || nIP == 0xffffffff)
		{
			printf("ip %s error.\n", config.IPAddress);
			return;
		}
	}

	if( ret < 4 )
	{
		strcpy(config.netMask, "255.255.255.0");
	}
	

	if( !isValidNetMask(config.netMask ) )
	{
		printf("mask %s error.\n", config.netMask);
		return;
	}

	unsigned int nMask = GetIpFromName(config.netMask);
	if( nMask == 0)
	{
		return;
	}
	
	if( ret < 5 )
	{
		int nDefaultGW;
		int network1 = nIP & nMask;
		if( nMask != 0xffffffff)					
			nDefaultGW = htonl(ntohl(network1) + 1 );
		else
			nDefaultGW = network1;

		strcpy(config.gateWay, GetIpAddrStr(nDefaultGW));
		printf("%#x %#x %s\n", network1, nDefaultGW, config.gateWay);
	}

	printf("%-10s:%s\n", "SN", SN);
	printf("%-10s:%s\n", "MAC", config.MACAddress);
	printf("%-10s:%d\n", "DHCP", config.dhcpEnable);
	printf("%-10s:%s\n", "IPAddress", config.IPAddress);
	printf("%-10s:%s\n", "netMask", config.netMask);
	printf("%-10s:%s\n", "gateWay", config.gateWay);
	printf("%-10s:%s\n", "DNS1", config.DNS1);
	printf("%-10s:%s\n", "DNS2", config.DNS2);	


	MediaStreamConfig serverConfig;
	serverConfig.rtspConfig.rtsp_auth = 1;
	serverConfig.rtspConfig.videoPort = 554;
	serverConfig.rtspConfig.rtpoverrtsp = 1;
	serverConfig.commConfig.ptzPort = 8091;
	serverConfig.webConfig.webPort = 80;
	
	
	ret=IP_NET_DVR_ModifyIPCBySN(SN, &config, &serverConfig);// if do not change server ports, fill NULL in the third param
	if(ret<0)
	{
		printf("modify %s error.\n", SN);
	}
}

void handle_record_start(char *param)
{
	int ret;
	if( gHandle_realplay == 0 )
	{
		printf("please start realplay first.\n");
		return;
	}
	ret = IP_NET_DVR_StartRecord(gHandle_realplay, "./", 1*60, 10*60);
	if(ret < 0)
	{
		printf("IP_NET_DVR_StartRecord fail, :%d\n", ret);
	}
}

void handle_record_stop(char *param)
{
	int ret;
	if( gHandle_realplay == 0 )
	{
		printf("please start realplay first.\n");
		return;
	}

	ret = IP_NET_DVR_StopRecord(gHandle_realplay);
	if(ret < 0)
	{
		printf("IP_NET_DVR_StopRecord fail, :%d\n", ret);
	}
}

void handle_setosd(char *param)
{
	int ret;
	if( g_bmediacfg_gotton == 0 )
	{
		printf("media config not gotton.\n");
	}
	else
	{
		char *p =  param;

		int bEnable = 1;
		char szOSD[128];
		int ret = sscanf(p, "%d %s", &bEnable, szOSD);

		if( ret < 2 )
		{
			printf("setosd not found params!\n");
		}
		else
		{
#if 0
			char szhex[256] = {0};
			int i;
			char* curPos = szhex;
			printf("len %d\n", strlen(szOSD));
			for(i = 0; i < strlen(szOSD); i++)
			{
				unsigned char a = szOSD[i];
				sprintf(curPos,"%02x", a);
				curPos+=2;
				printf("%d: %02x\n", i, a);
			}
			curPos[0] = '\0';
			printf("%s\n", szhex);
#endif
		
			g_ipc_mediacfg.videoConfig.overlay.enable = bEnable>0 ? 1:0;
			strncpy(g_ipc_mediacfg.videoConfig.overlay.titleOverlay.title_utf8, szOSD, TITLE_MAX_LEN-1);
			IP_NET_DVR_SET_VideoOSDConfig(m_nLastCmdId, &g_ipc_mediacfg.videoConfig.overlay);
		}
	}
}

void handle_setuserosd(char *param)
{
	int ret;
	if( g_bmediacfg_gotton == 0 )
	{
		printf("media config not gotton.\n");
	}
	else
	{
		char *p =  param;

		int bEnable = 1;
		int iIndex = 0;
		int xPos = 0;
		int yPos = 0;
		char szOSD[128];
		int ret = sscanf(p, "%d %d %d %d %s", &bEnable, &iIndex, &xPos,&yPos,szOSD);

		if( ret < 5 )
		{
			printf("setosd params error!\n");
			return;
			
		}

		if( iIndex < 0 || iIndex >= MAX_USER_OSD_NUM)
		{
			printf("user osd %d error!\n", iIndex);
			return;
		}
		if( xPos < 0 || xPos > 100)
		{
			printf("xPos %d error!\n", xPos);
			return;
		}
		if( yPos < 0 || yPos > 100)
		{
			printf("yPos %d error!\n", yPos);
			return;
		}
	
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].enable = bEnable>0 ? 1:0;
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].fontsize = 2;
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].pos_xscale = xPos;
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].pos_yscale = yPos;
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].posType = POSITION_TYPE_BY_SCALE;
		g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].titleType = TYPE_TYPE_BY_TEXT;
		strncpy(g_ipc_mediacfg.videoConfig.useroverlay.data[iIndex].title_utf8, szOSD, TITLE_MAX_LEN-1);
		
		IP_NET_DVR_SET_VideoUserOSDConfig(m_nLastCmdId, &g_ipc_mediacfg.videoConfig.useroverlay);
	}
}

void handle_setfps(char *param)
{
	int ret;
	if( g_bmediacfg_gotton == 0 )
	{
		printf("media config not gotton.\n");
	}
	else
	{
		char *p =  param;

		char szFramerate[128];
		int ret = sscanf(p, "%s", szFramerate);

		if( ret < 1 )
		{
			printf("setframerate not found params!\n");
		}
		else
		{
			g_ipc_mediacfg.videoConfig.videoEncode.encodeCfg[0].frameRate = atoi(szFramerate);
			IP_NET_DVR_SET_VideoEncodeConfig(m_nLastCmdId, &g_ipc_mediacfg.videoConfig.videoEncode);
		}
	}
}

void handle_setaudioenable(char *param)
{
	int ret;
	if( g_bmediacfg_gotton == 0 )
	{
		printf("media config not gotton.\n");
	}
	else
	{
		char *p =  param;

		int bEnable = 1;
		int ret = sscanf(p, "%d", &bEnable);

		if( ret < 1 )
		{
			printf("setframerate not found params!\n");
		}
		else
		{
			g_ipc_mediacfg.audioConfig.audioEncode.enable = bEnable > 0 ? 1:0;
			IP_NET_DVR_SET_AudioConfig(m_nLastCmdId, &g_ipc_mediacfg.audioConfig);
		}
	}
}
//取消自动重连(SDK默认会自动重连)
void handle_disableAutoReconnect(char *param)
{
	printf("Stop SDK auto login\n");
	int ret = IP_NET_DVR_SetAutoReconnect(m_nLastCmdId, 0);
	if ( ret ) 
	{
		printf("IP_NET_DVR_SetAutoReconnect(m_nLastCmdId, 0) error! ERR_NOT_FIND_DEVICE");
	}
}

//获取系统时间
void handle_gettime(char *param)
{
	if( g_LogonOk == 0 )
	{
		printf("\033[31m device not logined OK.\033[0m\n");
	}
	else
	{
		IP_NET_DVR_GET_SYSTEMTIME(m_nLastCmdId);
	}
}

void handle_settime(char *param)
{
	if( g_LogonOk == 0 )
	{
		printf("\033[31mdevice not login !\033[0m\n");
	}
	else
	{
		AjTime nowtime;
		struct tm localtime;
		time_t tsec = time(0);
		localtime_r(&tsec, &localtime);	

		nowtime.timezone = TRANS_TIMEZONE_TO_IPCAMERA(8);//1200;
		nowtime.year = localtime.tm_year + 1900;
		nowtime.month= localtime.tm_mon + 1;
		nowtime.day= 25;//localtime.tm_mday;
		nowtime.hour= localtime.tm_hour;
		nowtime.min= localtime.tm_min;
		nowtime.second= localtime.tm_sec;

		printf("Nowtime:%04d-%02d-%02d %02d:%02d:%02d\n", nowtime.year, nowtime.month, nowtime.day, nowtime.hour, nowtime.min, nowtime.second);
		
	
		IP_NET_DVR_SET_SYSTEMTIME(m_nLastCmdId, &nowtime);
	}
}

void handle_stopallautologin(char *param)
{
	g_bAutoSearchAndLogin = 0; //先设置标记，避免还未登录的又自动登录了

	mutex_map.Lock();				
	map<string, MyIpcamera>::iterator it = mapIpcameraInstance.begin();
	for(; it != mapIpcameraInstance.end(); ++it )
	{
		const string &sn = it->first;
		MyIpcamera &cameraInfo = it->second;
		if( cameraInfo.lRealHandle0 )
		{
			printf("IP_NET_DVR_StopRealPlay %s %-15s:%u, lUserID %#lx\n", sn.c_str(),
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_StopRealPlay(cameraInfo.lRealHandle0);		
			cameraInfo.lRealHandle0 = 0;
		}
		if( cameraInfo.lRealHandle1 )
		{
			printf("IP_NET_DVR_StopRealPlay %s %-15s:%u, lUserID %#lx\n", sn.c_str(),
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_StopRealPlay(cameraInfo.lRealHandle1);		
			cameraInfo.lRealHandle1 = 0;
		}

		if( cameraInfo.lUserID )
		{
			printf("\033[31mIP_NET_DVR_Logout\033[0m %s %-15s:%u, lUserID %#lx\n", sn.c_str(), 
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_Logout(cameraInfo.lUserID);		
			cameraInfo.lUserID = 0;
		}
		
		if( cameraInfo.pOutVideoCap != NULL )
			delete [] cameraInfo.pOutVideoCap;
		if( cameraInfo.pOutAudioCap!= NULL )
			delete [] cameraInfo.pOutAudioCap;				
	}

	mapIpcameraInstance.clear();
	mutex_map.Unlock();			


	handle_search_stop(NULL);
	
	
}


void handle_stopallrealplay(char *param)
{
	g_bAutoSearchAndRecord = 0; //先设置标记，避免还未开启录像的又自动开启了
	
	mutex_map.Lock();				
	map<string, MyIpcamera>::iterator it ;
	for(it = mapIpcameraInstance.begin(); it != mapIpcameraInstance.end(); ++it )
	{
		const string &sn = it->first;
		MyIpcamera &cameraInfo = it->second;
		if( cameraInfo.lRealHandle0 != 0 )
		{
			printf("IP_NET_DVR_StopRealPlay %s %-15s:%u, lUserID %#lx\n", sn.c_str(),
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_StopRealPlay(cameraInfo.lRealHandle0);		
			cameraInfo.lRealHandle0 = 0;
		}
		if( cameraInfo.lRealHandle1 != 0 )
		{
			printf("IP_NET_DVR_StopRealPlay %s %-15s:%u, lUserID %#lx\n", sn.c_str(),
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_StopRealPlay(cameraInfo.lRealHandle1);		
			cameraInfo.lRealHandle1 = 0;
		}
		
		if( cameraInfo.lUserID != 0 )
		{
			printf("\033[31mIP_NET_DVR_Logout\033[0m %s %-15s:%u, lUserID %#lx\n", sn.c_str(),
				cameraInfo.info.lanCfg.IPAddress, cameraInfo.info.streamCfg.commConfig.ptzPort, cameraInfo.lUserID);
			IP_NET_DVR_Logout(cameraInfo.lUserID);		
			cameraInfo.lUserID = 0;
		}
		

		if( cameraInfo.pOutVideoCap != NULL )
			delete [] cameraInfo.pOutVideoCap;
		if( cameraInfo.pOutAudioCap!= NULL )
			delete [] cameraInfo.pOutAudioCap;				
	}

	mapIpcameraInstance.clear();
	mutex_map.Unlock();				
}

void handle_logoutall(char *param)
{
	IP_NET_DVR_LogoutAll();
}
//Show logged in IPC
void handle_showAllAutoLogin(char *param)
{		
	unsigned idx = 0;
	if (mapIpcameraInstance.empty())
	{
		printf("\033[31m mapIpcameraInstance is empty, please start auto search and login at first.\033[0m\n");
		return ;
	}
	mutex_map.Lock();
	map<string, MyIpcamera>::iterator it;

	for(it = mapIpcameraInstance.begin(); it != mapIpcameraInstance.end(); ++it, ++idx )
	{
		
		const string &sn = it->first;
		MyIpcamera &cameraInfo = it->second;

		printf("----------------------- handle_showAllAutoLogin -------------------------\n");
		printf("Device \033[0m\033[31m%3d\033[0m: \033[33mLUserID:%#lx\033[0m timestamp:[%llu] NIC:[%s] mac=[%s], type=[%s], sn=[%s]\033[0m,\033[31m IP=[%s],\033[0m \033[33mdhcp=[%d], netmask=[%s], gw=[%s], dns1=[%s], dns2=[%s], onvifAllNet=[%d], userName=[%s], password=[%s], status=[%s], P2PID=[%s], title=[%s]\033[0m\n", 
					idx, \
					cameraInfo.lUserID, \
					cameraInfo.info.latest_timestamp, \
					cameraInfo.info.szInterfaceName, \
					cameraInfo.info.lanCfg.MACAddress, \
					cameraInfo.info.deviceType, \
					cameraInfo.info.ipc_sn, \
					cameraInfo.info.lanCfg.IPAddress, \
					cameraInfo.info.lanCfg.dhcpEnable, \
					cameraInfo.info.lanCfg.netMask, \
					cameraInfo.info.lanCfg.gateWay, \
					cameraInfo.info.lanCfg.DNS1, \
					cameraInfo.info.lanCfg.DNS2, \
					cameraInfo.info.lanCfg.onvifAllnetEnable, \
					cameraInfo.info.userCfg.accounts->userName, \
					cameraInfo.info.userCfg.accounts->password, \
					cameraInfo.info.userCfg.accounts->status, \
					cameraInfo.info.p2p_id, \
					cameraInfo.info.title);

		printf("\033[33m%s\033[0m\n", cameraInfo.szCapability);
		ShowMediaCapability(cameraInfo.nVideoCapCount, cameraInfo.pOutVideoCap, cameraInfo.nAudioCapCount, cameraInfo.pOutAudioCap);
		
	}

	mutex_map.Unlock();				
}


void test_parse_md(char *param)
{
	char szXmlBuffer[] =
"<?xml version=\"1.0\"?>"\
"<MotionDetectAlarm Enable=\"1\" BlockCount=\"1441810\" BlockConfig=\"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\" Sensitivity=\"80\" AlarmThreshold=\"20\" DayNightSwitch=\"1\" NightSensitivity=\"20\" NightAlarmThreshold=\"50\" NightStartTime=\" 0: 0: 0\" NightEndTime=\"24: 0: 0\">"\
"	<EnableTimeList>"\
"		<Workday Day=\"0\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"1\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"2\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"3\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"4\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"5\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"		<Workday Day=\"6\">"\
"			<TimeSpan StartTime=\" 0: 0: 0\" EndTime=\"23:59: 0\"/>"\
"		</Workday>"\
"	</EnableTimeList>"\
"	<AlarmAction>"\
"		<AlarmOutputAction Enable=\"0\" PortIndex=\"1\" ChannelType=\"1\" TriggerType=\"HIGH\" Duration=\"10\"/>"\
"		<PTZAction Enable=\"0\" ActionType=\"PositionWalk\">"\
"			<PositionWalk Interval=\"2\" WalkCount=\"1\">"\
"				<PTZPosition PositionIndex=\"1\"/>"\
"				<PTZPosition PositionIndex=\"2\"/>"\
"				<PTZPosition PositionIndex=\"3\"/>"\
"			</PositionWalk>"\
"		</PTZAction>"\
"		<AudioPlayAction Enable=\"0\" Times=\"0\" FileName=\"\"/>"\
"	</AlarmAction>"\
"</MotionDetectAlarm>";

	MotionDetectAlarm MDAlm;
	IP_NET_DVR_Alarm_getMotionDetectByXml(&MDAlm, szXmlBuffer);
	printf("parse finished:\n");

	char *p = IP_NET_DVR_XMLGET_MDAlarmConfig(&MDAlm);
	printf("%s\n", p);
	free(p);
}


void handle_exit(char *param)
{
	g_bRun = 0;
}


extern void handle_help(char *param);
AjCmdStruct g_cmd[] =
{
	{"Login by config.cfg", handle_login },
	{"Logout", handle_logout },
	{"Start searchIPC", handle_search_begin },
	{"Stop searchIPC", handle_search_stop },
	{"Auto search and login", handle_autosearchandlogin},//这里是自动搜索设备，然后自动登录
	{"Stop all search and autologin", handle_stopallautologin},	//停止自动登录和搜索设备
	{"Stop auto login", handle_disableAutoReconnect },	//禁用自动重连设备
	{"Show all auto logged in", handle_showAllAutoLogin },
	{"Read SN", handle_readsn },
	{"Snapshot", handle_snappic },
	{"Reboot one by SN (broadcast)", handle_reboot },
	{"Reboot logged in (unicast ptz_port)", handle_rebootLoggedin },
	{"Restore one by SN (broadcast)", handle_restore },
	{"Reboot all by SN (broadcast)", handle_reboot_all },
	{"Restore logged in (unicast ptz_port)", handle_restore_config_Loggenin },
	{"Restore one by SN (broadcast)", handle_restore },
	{"Restore all by SN (broadcast)", handle_restore_all },
	{"Get device time", handle_gettime },
	{"Sync nowtime", handle_settime},
	{"Get current version", handle_get_version },
	{"Get sdk version", handle_getsdkversion },
	{"Get overlay OSD", handle_get_osd },
	{"Set OSD", handle_setosd},
	{"Set user OSD", handle_setuserosd},
	{"PTZ begin", handle_ptz },
	{"Start realplay", handle_realplay_begin},
	{"Stop realplay", handle_realplay_stop },
	{"Show debug", handle_show_debug },
	{"Hide debug", handle_hide_debug },
	{"Get handle_GetDeviceAbility", handle_GetDeviceAbility },
	{"Get config", handle_get_config },
	{"Download config", handle_download_config },
	{"Network config ModifyIPCBySN", handle_modifyipc},
	{"Start record", handle_record_start},//这里是SDK内部的录像
	{"Stop record", handle_record_stop},//这里是SDK内部的录像
	{"Set FPS", handle_setfps},
	{"Set audio enable", handle_setaudioenable},
	{"Auto search and record", handle_autosearchandrecord},//这里是自动搜索设备，然后自动登录收流并对音视频进行录像，不是SDK内部的录像
	{"Stop all realplay", handle_stopallrealplay},	//停止自动登录的设备的取流和录像
	{"Logoutall", handle_logoutall},
	{"Parse xml", test_parse_md },
	{"Ircut control", handle_ircutcontrol },
	{"Replay_dates_distribute", handle_replay_dates_distribute },
	{"Replay_day_distribute", handle_replay_day_distribute },
	{"Replay test", handle_replaytest },
	{"Upgrade test", handle_upgrade_test },
	
	{"help", handle_help },
	{"q", handle_exit },
};

void handle_help(char *param)
{
	printf("\n#====================================  Commands  Menu  =======================================#\n");
	long unsigned int iIndex;
	printf("-----------------------------------------------------------------------------------------------\n");
	for( iIndex = 0; iIndex < sizeof(g_cmd) / sizeof(g_cmd[0]); iIndex++)
	{
		printf("|");
		printf("\033[5;32m%3ld\033[0m | \033[33m%-40s\033[0m", iIndex, g_cmd[iIndex].szCmd);
		
		if ( iIndex % 2 )
		{
			printf("|\n");
			printf("-----------------------------------------------------------------------------------------------\n");
		}
		
	}
	
	if ( iIndex % 2 )
		{
			printf("|\n");
			printf("-----------------------------------------------------------------------------------------------\n");
		}
	
	printf("Enter \033[5;32mnumber\033[0m, 'ctrl+c' to quit ,'help' or Enter for menu\n");
	printf("===============================================================================================\n");
	
}

int commandProcess()
{

	char inStr[300];

	while(fgets(inStr, sizeof(inStr), stdin))
	{
		if( strlen(inStr) < 2 )
		{
			handle_help(NULL);
			continue;
		}

		inStr[strlen(inStr)-1]='\0';
		printf("Your input str: %s\n",inStr);


		char *p = NULL;
		P_HANDLE_FUNC pFunc = NULL;
		long unsigned int iIndex = 0;
		for( iIndex = 0; iIndex < sizeof(g_cmd)/sizeof(g_cmd[0]); iIndex++ )
		{
			p = strstr(inStr, g_cmd[iIndex].szCmd);
			if( NULL != p)
			{
				p = p + strlen(g_cmd[iIndex].szCmd ) + 1;
				pFunc = g_cmd[iIndex].pFunc;
				break;
			}
		}

		if( NULL == pFunc )
		{
			long unsigned int nCmdNo = 0;
			if( 1 !=  sscanf( inStr, "%ld", &nCmdNo) )
				continue;
			
			if( nCmdNo >= 0  && nCmdNo < sizeof(g_cmd)/sizeof(g_cmd[0]) )
			{
				char tmp[16];
				sprintf(tmp, "%ld", nCmdNo );
				p = inStr + strlen(tmp) + 1;//跳过命令标记，直奔参数
				pFunc = g_cmd[nCmdNo].pFunc;
			}
		}

		if( NULL != pFunc && p != NULL)
		{
			pFunc(p);
		}
		else
		{
			handle_help(NULL);
		}

		if( g_bRun == 0 )
			break;

		sleep(1);       
	}

	return 0;
}

/*
demo包括2部分功能:
1、根据config.cfg的配置,启动后输入相应命令登录、播放、取配置等演示功能
2、可以自动搜索设备、自动登录、取流、录像。自动搜索线程会在启动10秒钟后停止搜索(录像不会自动停止)
*/
int main(int argc, char **argv)
{
	printf("####### start main ########\n");

	IP_NET_DVR_Init();    
	//IP_NET_DVR_LOG_OPEN();

	IP_NET_DVR_SetStatusEventCallBack(OnStateEvent,NULL);  
	IP_NET_DVR_SetAUXResponseCallBack(OnAUXResponse,NULL); 

	IP_NET_DVR_SetReplayDataCallBack(OnReplayMediaRecv, NULL);
	IP_NET_DVR_SetReplayEventCallBack(PlayActionEventCallBack, NULL);

	IP_NET_DVR_SetSearchInterval(1000);

	ShowDataSize();	

	handle_help(NULL);

	commandProcess();
	
	g_bSearching = 0;
	printf("g_thread_show_searchresult:%#lx\n",g_thread_show_searchresult);
	if ( g_thread_show_searchresult )
	{
		if (0 != pthread_join(g_thread_show_searchresult, NULL))
		{
			printf("\033[31m join failed \033[0m\n");
		}
	}


	handle_stopallrealplay(NULL);
	handle_stopallautologin(NULL);
	IP_NET_DVR_StopSearchIPC();
	IP_NET_DVR_SearchIPCReleaseInfo();

	return 0;
}

#pragma pack()

