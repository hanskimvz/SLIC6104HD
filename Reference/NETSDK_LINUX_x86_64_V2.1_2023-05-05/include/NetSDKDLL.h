// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 NETSDKDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// 符号视为是被导出的。
#ifndef __NETSDKDLL_20220304
#define __NETSDKDLL_20220304

#include "common_head.h"
#include "media_cfg.h"
#include "data_struct.h"

#define MAX_IPC_SERIALNUMBER	32
#define MAX_DEVICETYPE_LEN 32
#define MAX_TITLE_LEN 256
#define MAX_IPC_P2PID_LEN	48
#define MAX_INTERFACE_NAME_LEN 32

#define RECORD_DISTRIBUTE_LEN	1440// minute of one day
#define REC_TYPE_NO_RECORDING   'C'  // no record in this minute
#define REC_TYPE_UNCONDITIONAL  'A'  // recording, but no event/alarm.
#define REC_TYPE_DRIVEN			'B'  // event/alarm happend when recording

enum REPLAY_IPC_ACTION
{
	ACTION_PLAY=0,
	ACTION_PAUSE,
	ACTION_RESUME,
	ACTION_FAST,
	ACTION_SLOW,
	ACTION_SEEK,
	ACTION_FRAMESKIP,
	ACTION_STOP,
	ACTION_CAPIMG=10,
	ACTION_CHANGE_SOUND,
	ACTION_RECV_DECODEPARAM,
};

typedef struct
{
	char  szInterfaceName[MAX_INTERFACE_NAME_LEN];
	char  ipc_sn[MAX_IPC_SERIALNUMBER];
	char  deviceType[MAX_DEVICETYPE_LEN];
	char  p2p_id[MAX_IPC_P2PID_LEN];
	char  title[MAX_TITLE_LEN];
	UserConfig 	userCfg;
	MediaStreamConfig	streamCfg;
	LANConfig 	lanCfg;
	unsigned long long latest_timestamp;//最后搜索到的时间戳(本地时间)
}IPC_ENTRY;


typedef struct _FRAMNE_INFO
{
	int bIsVideo;
	int bIsKeyFrame;
	double TimeStamp;
}FRAMNE_INFO;


#define ALARM_ITEM ALARM_ENTRY

typedef struct
{
	LONG    lChannel;
	LONG    lLinkMode;
	HWND    hPlayWnd;
	char    *sMultiCastIP;
}*LPIP_NET_DVR_CLIENTINFO,IP_NET_DVR_CLIENTINFO;
//LPIP_NET_DVR_CLIENTINFO



#define 	SERIALNO_LEN 48
typedef struct
{
	BYTE     sSerialNumber[SERIALNO_LEN];
	BYTE     byAlarmInPortNum;
	BYTE     byAlarmOutPortNum;
	BYTE     byDiskNum;
	BYTE     byDVRType;
	BYTE     byChanNum;
	BYTE     byStartChan;
}*LPIP_NET_DVR_DEVICEINFO,IP_NET_DVR_DEVICEINFO;


typedef struct 
{

}IP_NET_DVR_ALARMER;


#define MAX_IPADDR_LEN	64
typedef struct
{
	int  nVideoPort;
	int  bIsTcp;
	int  nVideoChannle;
	void *pUserData;
}USRE_VIDEOINFO,* LPUSRE_VIDEOINFO;


enum ERROR_CODE
{
	ERR_NOT_FIND_DEVICE=-9000002,
	ERR_OPEN_AUDIOCAPTURE_FAIL,
	ERR_START_AUDIOCAPTURE_FAIL,
	ERR_AUDIO_PARAM_ERROR,//对讲参数不一致
	ERR_AUDIO_NOT_START,//对讲未启动
	ERR_DEV_NOT_CONNECTED,
	ERR_DEV_NOT_LOGIN,
	ERR_MSGTYPE_ERROR,
	ERR_OUTOFF_MEMORY,
	ERR_INIT_SOCKET_ERROR,
	ERR_PARAM_ERROR,
	ERR_NOT_DEV_EXIST,
	ERR_START_THREADERROR,
	ERR_NOT_FIND_STREAM,
	ERR_ISUPLOADING_ERROR,
	ERR_ISDOWNLOADING_ERROR,
	ERR_IS_STARTAUDIO_ERROR,
	ERR_ISFINISH_ERROR,
	ERR_NOT_DOWNLOAD_MODE_ERROR,
	ERR_PTZCMD_ACTION_ERROR,
	ERR_LOC_FILE_ERROR,
	ERR_NOT_REPLAY_MODE_ERROR,
	ERR_PLAY_ACTION_ERROR,
	ERR_NOT_ALLOW_REPLAY_ERROR,
	ERR_MEMORY_SIZE_ERROR,
	ERR_XML_FORMAT_ERROR,
	ERR_CREATE_SOCKET_ERROR,
	ERR_SEND_MODIFYCMD_ERROR,
	ERR_NOT_STARTTALK_MODE_ERROR,
	ERR_RECORD_MEDIA_PARAM_ERROR,
	ERR_RECORD_CREATEERROR,
	ERR_RECORD_ISRECORDING,
	ERR_RECORD_FILEMAXSECONDS_ERROR,
	ERR_RECORD_ALLRECORDSECONDS_ERROR,
	ERR_RECORD_NOTRUNNING,
	ERR_RECORD_STREAMPARAM_ERROR,
	ERR_RECORD_WRITETEMPBUFFER_ERROR,
	ERR_RECORD_ISNOTRECORDSTREAM_MODE,
	ERR_RECORD_NOTINPUTSTREAM_MODE,
	ERR_RECORD_FILEPATH_ERROR,
	ERR_SEARCH_THREAD_NOT_START,
	ERR_TIME_OUT,

	ERR_MEMORY_ERR = -8000000,
};



enum enumNetSatateEvent
{
	EVENT_CONNECTING,   //0
	EVENT_CONNECTOK,
	EVENT_CONNECTFAILED,
	EVENT_SOCKETERROR,
	EVENT_LOGINOK,
	EVENT_LOGINFAILED,   //5
	EVENT_STARTAUDIOOK,
	EVENT_STARTAUDIOFAILED,
	EVENT_STOPAUDIOOK,
	EVENT_STOPAUDIOFAILED,
	EVENT_SENDPTZOK,    //10
	EVENT_SENDPTZFAILED,
	EVENT_SENDAUXOK,
	EVENT_SENDAUXFAILED,
	EVENT_UPLOADOK,
	EVENT_UPLOADFAILED,  //15
	EVENT_DOWNLOADOK,
	EVENT_DOWNLOADFAILED,
	EVENT_REMOVEOK,
	EVENT_REMOVEFAILED,
	EVENT_SENDPTZERROR,   //20
	EVENT_PTZPRESETINFO,  
	EVNET_PTZNOPRESETINFO,
	EVENT_PTZALARM,
	EVENT_RECVVIDEOPARAM,
	EVENT_RECVAUDIOPARAM,  //25
	EVENT_CONNECTRTSPERROR,
	EVENT_CONNECTRTSPOK,
	EVENT_RTSPTHREADEXIT,
	EVENT_URLERROR,
	EVENT_RECVVIDEOAUDIOPARAM,  //30
	EVENT_LOGIN_USERERROR,
	EVENT_LOGOUT_FINISH, 	//登录线程已停止
	EVENT_LOGIN_RECONNECT, 	//进行重新登录   33
	EVENT_LOGIN_HEARTBEAT_LOST, //心跳丢失
	EVENT_STARTAUDIO_ISBUSY, //  35
	EVENT_STARTAUDIO_PARAMERROR,
	EVENT_STARTAUDIO_AUDIODDISABLED,
	EVENT_CONNECT_RTSPSERVER_ERROR,
	EVENT_CREATE_RTSPCLIENT_ERROR,
	EVENT_GET_RTSP_CMDOPTION_ERROR,     //40
	EVENT_RTSP_AUTHERROR,
	EVNET_RECORD_FILEBEGIN,
	EVENT_RECORD_FILEEND,
	EVENT_RECORD_TASKEND,
	EVENT_RECORD_DISKFREESPACE_TOOLOW,  //45
	EVNET_RECORD_FILEBEGIN_ERROR,
	EVNET_RECORD_WRITE_FILE_ERROR,
	EVENT_RECORD_INITAVIHEAD_ERROR,
	EVENT_RECORD_MEDIA_PARAM_ERROR,	   //49
};








enum PTZ_CMD_TYPE
{
	LIGHT_PWRON=2,
	WIPER_PWRON,
	FAN_PWRON,
	HEATER_PWRON,
	AUX_PWRON1,
	AUX_PWRON2,
	ZOOM_IN_VALUE= 11,
	ZOOM_OUT_VALUE, 
	FOCUS_NEAR, 
	FOCUS_FAR, 
	IRIS_OPEN, 
	IRIS_CLOSE,
	TILT_UP,
	TILT_DOWN,
	PAN_LEFT,
	PAN_RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT,
	PAN_AUTO,
	STOPACTION
};

#ifndef ZOOM_IN	
#define ZOOM_IN ZOOM_IN_VALUE
#define ZOOM_OUT	ZOOM_OUT_VALUE
#endif

enum PTZ_PRESET_TYPE
{
	SET_PRESET= 8 ,
	CLE_PRESET= 9,
	GOTO_PRESET= 39
};


typedef struct 
{
	char codec[256];
	int width;
	int height;
	int colorbits;
	int framerate;
	int bitrate;
	char vol_data[256];
	int vol_length;
}VIDEO_PARAM;


typedef struct 
{
	char codec[256];
	int samplerate;
	int bitspersample;
	int channels;
	int framerate;
	int bitrate;
}AUDIO_PARAM;



typedef struct  __STREAM_AV_PARAM
{
	unsigned char	ProtocolName[32];	//==AV_FALG
	short  bHaveVideo;//0 表示没有视频参数
	short  bHaveAudio;//0 表示没有音频参数
	VIDEO_PARAM videoParam;//视频参数
	AUDIO_PARAM audioParam;//audio param
	char  szUrlInfo[512];
}STREAM_AV_PARAM;


typedef struct __StateEventMsgInfo
{
	char szInfo[1024];
	char szUrlInfo[512];
}STATE_EVENT_MSGINFO;

typedef struct
{
	int bIsKey;
	double	timestamp;
	void    *pUserData;
}FRAME_EXTDATA,* LPFRAME_EXTDATA;

//playback data head info
typedef struct _updpackhead
{
	uint32_t frame_timestamp;
	uint32_t keyframe_timestamp;
	uint16_t pack_seq;
	uint16_t payload_size;
	uint8_t pack_type;//0x01 first packet閿熸枻鎷穢10 last packet, 0x11 first and last packet閿熸枻鎷穢00 middle packet
	uint8_t frame_type;
	uint8_t stream_type;//0: video, 1: audio
	uint8_t stream_index;
	uint32_t  frame_index;

}UpdPackHead;

typedef struct
{
	long 	stream_id;
	VIDEO_PARAM * video_param;
}VIDEO_STATE_MSG_PARAM;


typedef LONG(CALLBACK *MSGCallBack)(LONG lCommand,IP_NET_DVR_ALARMER *pAlarmer,char *pAlarmInfo,DWORD BufLen,void *pUser);
typedef LONG(CALLBACK *StatusEventCallBack)(LONG lUser,LONG nStateCode,char *pResponse,void *pUser);
typedef LONG(CALLBACK *AUXResponseCallBack)(LONG lUser,LONG nType,char *pResponse,void *pUser);


typedef LONG(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,LPFRAME_EXTDATA  pUser);
typedef LONG(CALLBACK *fRealDataCallBack)(LONG lRealHandle,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData);


typedef LONG(CALLBACK *fPlayActionEventCallBack)(LONG lUser,LONG nType,LONG nFlag,char * pData,void * pUser);


typedef LONG(CALLBACK *fExceptionCallBack)(DWORD dwType,LONG lUserID,LONG lHandle,void *pUser);




enum FILE_TYPE
{
	LOG_FILE,
	RECORD_FILE,
	CONFIG_FILE,
	UPDATE_FILE
};



#ifdef IPCCONFIGDLL
#undef IPCCONFIGDLL	
#define IPCCONFIGDLL
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

	//SDK初始化以及相关信息
	LONG IP_NET_DVR_Init();
	LONG IP_NET_DVR_Cleanup();
	LONG IP_NET_DVR_GetSDKBuildVersion();
	LONG IP_NET_DVR_Get_Timestamp();
	LONG IP_NET_DVR_GetSDKVersion();
	LONG IP_NET_DVR_SetLogToFile(DWORD bLogEnable,char *strLogDir,BOOL bAutoDel);
	LONG IP_NET_DVR_LOG_OPEN();	//开启SDK LOG
	LONG IP_NET_DVR_LOG_CLOSE();//关闭SDK LOG


	//全局callback
	LONG IP_NET_DVR_SetExceptionCallBack(UINT nMessage,HWND hWnd,fExceptionCallBack cbExceptionCallBack,void *pUser);
	LONG IP_NET_DVR_SetAUXResponseCallBack(AUXResponseCallBack fAUXCallBack,void * pUser);
	LONG IP_NET_DVR_SetStatusEventCallBack(StatusEventCallBack fStatusEventCallBack,void * pUser);


	//设备登陆与连接
	LONG IP_NET_DVR_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPIP_NET_DVR_DEVICEINFO lpDeviceInfo);
	LONG IP_NET_DVR_Logout(LONG lUserID);
	LONG IP_NET_DVR_LogoutAll();
	LONG IP_NET_DVR_SetAutoReconnect(LONG lUserID,int bAutoReconnect);
	LONG IP_NET_DVR_Reconnect(LONG lUserID);
	LONG IP_NET_DVR_Login_Encrypt(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPIP_NET_DVR_DEVICEINFO lpDeviceInfo, const char *szKeyValue);
	LONG IP_NET_DVR_EXCHANGE_Encrypt(LONG lUserID);

	//设备搜索功能
	LONG IP_NET_DVR_SetSearchInterval(UINT nBroadcastInterval);
	LONG IP_NET_DVR_Set_Search_ROOTNAME(const char *pXmlRootName);//设置搜索协议根节点，用于定制厂商的型号搜索
	LONG IP_NET_DVR_StartSearchIPC();
	LONG IP_NET_DVR_StopSearchIPC();
	LONG IP_NET_DVR_GetSearchIPCCount();
	LONG IP_NET_DVR_GetIPCInfo(LONG index, IPC_ENTRY * pIPCInfo);
	LONG IP_NET_DVR_SearchIPCReleaseInfo();
	LONG IP_NET_DVR_ModifyIPCByIndex(LONG index, IPC_ENTRY * pIPCInfo);
	LONG IP_NET_DVR_ModifyIPCBySN(char *pSN, LANConfig 	*p_lanCfg, MediaStreamConfig* pMediaStreamCfg);
	LONG IP_NET_DVR_GetIPCInfoXML(LONG index, char * pXMLInfo,int maxLen);
	LONG IP_NET_DVR_ModifyIPCXML(LONG index, const char * strXML);
	LONG IP_NET_DVR_GetOneIPAddress(char * strResult,int nSize);
	LONG IP_NET_DVR_GetNetworkParam(ULONG nParamIndex, char * strResult,int nSize);
	LONG IP_NET_DVR_RebootIPCBySN(char *pSN);
	LONG IP_NET_DVR_RestoreIPCBySN(char *pSN);

	//实时音视频预览
	LONG IP_NET_DVR_RealPlay(LONG lUserID,LPIP_NET_DVR_CLIENTINFO lpClientInfo,fRealDataCallBack cbRealDataCallBack,LPUSRE_VIDEOINFO pUser,BOOL bBlocked);
	LONG IP_NET_DVR_RealPlayEx(char * serverip,char *user,char *pass,fRealDataCallBack cbRealDataCallBack,LPUSRE_VIDEOINFO pUser,BOOL bBlocked);
	LONG IP_NET_DVR_StopRealPlay(LONG lRealHandle);
	LONG IP_NET_DVR_StopAllRealPlay();
	LONG IP_NET_DVR_GetVideoParam(LONG  lRealHandle,VIDEO_PARAM *pParam);
	LONG IP_NET_DVR_GetAudioParam(LONG lRealHandle,AUDIO_PARAM *pParam);
	LONG IP_NET_DVR_SetRealDataCallBack(fRealDataCallBack cbRealDataCallBack,void * dwUser);


	//云台控制
	LONG IP_NET_DVR_PTZControl(LONG lUser,DWORD dwPTZCommand,DWORD nTspeed,DWORD nSpeed);
	LONG IP_NET_DVR_PTZPreset(LONG lUser,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
	LONG IP_NET_DVR_PTZControlEx(LONG lUser, const char *pXml);

	LONG IP_NET_DVR_SEND_ENCRYPPT_RAWDATA(LONG lUserID, const char* pData);
	
	//IPC系统控制
	LONG IP_NET_DVR_FormatDisk(LONG lUserID,LONG lDiskNumber);
	LONG IP_NET_DVR_GetFormatProgress(LONG lFormatHandle,LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
	LONG IP_NET_DVR_Upgrade(LONG lUserID,char *sFileName);
	LONG IP_NET_DVR_GetUpgradeProgress(LONG lUserID);
	LONG IP_NET_DVR_GetUpgradeState(LONG lUserID);
	LONG IP_NET_DVR_CloseUpgradeHandle(LONG lUserID);
	LONG IP_NET_DVR_FindDVRLogFile(LONG lUserID);
	LONG IP_NET_DVR_RestoreConfig(LONG lUserID);	
	LONG IP_NET_DVR_Ircut_switch_daynight(LONG lUserID, int day);//手动切换IRCUT，需要先设置IRCUT模式为MANUAL模式
	LONG IP_NET_DVR_GetConfigFile(LONG lUserID,char *sFileName);
	LONG IP_NET_DVR_SetConfigFile(LONG lUserID,char *sFileName);
	LONG IP_NET_DVR_RebootDVR(LONG lUserID);
	LONG IP_NET_DVR_ShutDownDVR(LONG lUserID);
	LONG IP_NET_DVR_GetDVRConfig(LONG lUserID,DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned);
	LONG IP_NET_DVR_SystemControl(LONG lUserID,DWORD nCmdValue,LONG flag, const char * pXml);
	LONG IP_NET_DVR_SetDVRConfig(LONG lUserID,DWORD dwCommand,LONG lChannel,const LPVOID pXml,DWORD dwInBufferSize);
	LONG IP_NET_DVR_GetDeviceAbility(LONG lUserID);
	LONG IP_NET_DVR_WriteAUXStringEx(LONG lUserID,char * pMsgType,LONG nCode,LONG flag,const char * pXml);
	LONG IP_NET_DVR_CreateIFrame(ULONG lUserId,int bIsSubStream);
	LONG IP_NET_DVR_GetUserData(ULONG lUserId,char * pOutBuffer,int* nInOutLen);
	LONG IP_NET_DVR_SetUserData(ULONG lUserId,char * pBuffer,int len);


	//文件上传下载
	LONG IP_NET_DVR_GetFileByName(LONG lUserID,LONG nFileType,char *sDVRFileName,char *saveDir);
	LONG IP_NET_DVR_StopGetFile(LONG lFileHandle);
	LONG IP_NET_DVR_GetDownloadState(LONG lFileHandle);
	LONG IP_NET_DVR_GetDownloadPos(LONG lFileHandle);

	//IPC录像文件回放
	LONG IP_NET_DVR_GetReplayAblity(LONG lUserID);
	/*获取某一个天的录像分布(通过异步消息返回这一天以1分钟为单位的录像分布)*/
	LONG IP_NET_DVR_GetReplay_OneDay_Distribute(LONG lUserID, int year, int month, int day);
	/*获取有录像的日期分布(通过异步消息返回摄像机的录像日期序列)*/
	LONG IP_NET_DVR_GetReplay_Dates_Distribute(LONG lUserID);
	LONG IP_NET_DVR_SetReplayDataCallBack(fRealDataCallBack cbReplayDataCallBack,void * dwUser);
	LONG IP_NET_DVR_SetReplayEventCallBack(fPlayActionEventCallBack cbActionCallback,void * dwUser);
	LONG IP_NET_DVR_PlayDeviceFile(LONG lUserID,char * filenme);
	LONG IP_NET_DVR_ReplayByTime(LONG lUserID, LONG timestampInMillis);
	LONG IP_NET_DVR_ControlReplay(LONG lUserID,LONG Action,LONG param);

	//广播音频相关(对讲)
	LONG IP_NET_DVR_StartTalk(int audiotype, int samplerate, int bitspersample, int channels);
	LONG IP_NET_DVR_StopTalk();
	LONG IP_NET_DVR_AddTalk(LONG lUserID);
	LONG IP_NET_DVR_RemoveTalk(LONG lUserID);



    LONG IP_NET_DVR_StartVoiceCom(LONG lUserID, int AudioType, int iSampleRate, int iChannel);
    LONG IP_NET_DVR_SetVoiceComClientVolume(LONG lVoiceComHandle,WORD wVolume);
    LONG IP_NET_DVR_StopVoiceCom(LONG lUserID);
    LONG IP_NET_DVR_InputAudioData(LONG lUserID, const char* pBuffer, int nSize);


	//录像相关
	LONG IP_NET_DVR_StartRecord(LONG lRealHandle,const char * filePath,int nFileMaxSeconds,int nAllRecordMaxSeconds);
	LONG IP_NET_DVR_StopRecord(LONG lRealHandle);

	LONG IP_NET_DVR_GetLastErrorCode(int nType);
	LONG IP_NET_DVR_StartRecordStream(STREAM_AV_PARAM * pAvParam,const char * filePath,int nFileMaxSeconds,int nAllRecordMaxSeconds);
	LONG IP_NET_DVR_InputRecordStream(LONG lRealHandle,const void * pBuffer,int nSize,int isVideo,int iskey,double timestamp);
	LONG IP_NET_DVR_StopRecordStream(LONG lRealHandle);

	LONG IP_NET_DVR_wzwTest();

	/*
	* 抓图保存在用户提供的文件名中
	* lUserID 登陆id
	* bsub, 是否子码流, 0,主码流, 1子码流
	* quality, 抓图质量, 0~100, 越高质量越好
	* filename 抓图要保存的文件全名称,如"test.jpeg", 不带路径则在当前目录下
	* timeout, 超时时间, 单位ms, 填0则非阻塞，需要在OnStateEvent回调中处理抓图报警。填其他值则等待相应的时间直到抓图成功。
	* 返回值, 0 ok, 其他错误码
	*/
	LONG IP_NET_DVR_SnapPic(LONG lUserID, int bsub, int quality, const char* filename, int timeout);
	
	//[内部使用]直接将xml发送到IPC，用于透明通道中转(可附带文件数据于xml之后)
	LONG IP_NET_DVR_SendRawMsg(LONG lUserID, const char *xmlBuf, const int len);

	/*
	驱赶
	play_sound:播放警铃音
	led_on:闪灯
	secons:持续时间
	*/
	LONG IP_NET_DVR_SCARE_OFF(LONG lUserID, int play_sound,  int led_on,	int seconds);

	typedef struct SnapPicTask_S
	{
		LONG userid[64]; // user id 列表
		int usercount;  // 实际用户个数
		int bsub;
		int quality;
		char* buf[64];   // 每个用户的抓图内存指针 , 
		int buflen[64]; // 内存实际长度, 最好要200k 左右

		int snapInterval;// 每个ipc 直接抓图间隔
	}SnapPicTask;

	/* 提交抓图任务后 回调函数在事件 EVENT_DOWNLOADOK 返回抓图结果, 数据指针转换成以下结构 */
	typedef struct SnapPicResult_S
	{
		char* picbuf;
		int piclen;
	}SnapPicResult;

	LONG IP_NET_DVR_SnapPicTaskStart(SnapPicTask* task);
	LONG IP_NET_DVR_SnapPicTaskStop();

	/*
	去XML，使用结构体来获取/设置
	设置前，请确保数据正确，否则可能导致设备无法启动(最好先获取一遍，然后修改需要修改的项目)
	*/

	/*
	从XML解析出结构体
	*/
	LONG IP_NET_DVR_GetNetworkCfgByXml(NetworkConfigNew *pNetworkCfg, char *xmlBuf);

	LONG IP_NET_DVR_Network_getLANCfgByXml(LANConfig *lanCfg,char *xmlBuf);
	LONG IP_NET_DVR_Network_getWIFICfgByXml(WIFIConfig *wifiCfg,char *xmlBuf);
	LONG IP_NET_DVR_Network_getADSLCfgByXml(ADSLConfigNew *adslCfg,char *xmlBuf);
	LONG IP_NET_DVR_Network_getDDNSCfgByXml(DDNSConfig *ddnsCfg,char *xmlBuf);
	LONG IP_NET_DVR_Network_getUPNPCfgByXml(UPNPConfig *upnpCfg,char *xmlBuf);
	LONG IP_NET_DVR_Network_getP2PCfgByXml(P2PConfig *p2pCfg,char *xmlBuf);

	LONG IP_NET_DVR_Server_getFtpsByXml(ServerConfig *pServerCfg, char *xmlBuf);
	LONG IP_NET_DVR_Server_getSmtpsByXml(ServerConfig *pServerCfg, char *xmlBuf);
	LONG IP_NET_DVR_GetServerCfgByXml(ServerConfig *pServerCfg, char *xmlBuf);


	LONG IP_NET_DVR_GetRecordCfgByXml(RecordConfig *pRecordCfg, char *xmlBuf);


	LONG IP_NET_DVR_Media_getAudioByXml(AudioConfig *pAudioCfg,  char *xmlBuf);
	LONG IP_NET_DVR_Media_getVideoByXml(VideoConfig *pVideoCfg, char *xmlBuf);
	LONG IP_NET_DVR_GetMediaCfgByXml(MediaConfig *pMediaCfg, char *xmlBuf);

	LONG IP_NET_DVR_Media_getVideoCaptureByXml(VideoCapture *pVideoCapture, char *xmlBuf);
	LONG IP_NET_DVR_Media_getVideoOverlayByXml(VideoOverlay *pVideoOverlay, char *xmlBuf);
	LONG IP_NET_DVR_Media_getVideoEncodeByXml(VideoEncode *pVideoEncode, char *xmlBuf);
	LONG IP_NET_DVR_Media_getJpegEncodeByXml(JpegEncodeCfg *pJpegCfg, char *xmlBuf);
	LONG IP_NET_DVR_Media_getVideoMaskByXml(VideoMaskConfig *pVideoMask, char *xmlBuf);

	LONG IP_NET_DVR_GetMediaStreamCfgByXml(MediaStreamConfig *pMediaStream, char *xmlBuf);
	LONG IP_NET_DVR_GetPlatformCfgByXml(PlatformConfig *pPlatform, char *xmlBuf);
	LONG IP_NET_DVR_GetGB28181CfgByXml(GB28181Config *pPlatformCfg, char *xmlBuf);


	LONG IP_NET_DVR_Alarm_getInputByXml(InputAlarm *pInputAlm, char *xmlBuf);
	LONG IP_NET_DVR_Alarm_getMotionDetectByXml(MotionDetectAlarm *pMDAlm, char *xmlBuf);
	LONG IP_NET_DVR_Alarm_getPersonDetectByXml(PdAlarm *pPDAlm, char *xmlBuf);
	LONG IP_NET_DVR_Alarm_getVideoLostByXml(VideoLostAlarm *pVideoLost, char *xmlBuf);
	LONG IP_NET_DVR_Alarm_getVideoCoverByXml(VideoCoverAlarm *pVideoCover, char *xmlBuf);
	LONG IP_NET_DVR_Alarm_getStorageFullByXml(StorageFullAlarm *pSFAlm, char *xmlBuf);
	LONG IP_NET_DVR_GetAlarmConfigByXml(AlarmConfig *pAlarmCfg, char *xmlBuf);

	LONG IP_NET_DVR_InputAlarm_getAlarmChannelCfgByXml(AlarmChannel *pAlarmChannel, char *xmlBuf);


	LONG IP_NET_DVR_System_getPTZCfgByXml(PTZConfig *pPtzCfg, char *xmlBuf);
	LONG IP_NET_DVR_System_getTimeCfgByXml(TimeConfig *pTimeCfg, char *xmlBuf);	
	LONG IP_NET_DVR_System_getUserCfgByXml(UserConfig *pUserCfg, char *xmlBuf);
	LONG IP_NET_DVR_System_getLogCfgByXml(SyslogConfig *pSyslogCfg, char *xmlBuf);
	LONG IP_NET_DVR_System_getMiscCfgByXml(MiscConfig *pMiscCfg, char *xmlBuf);
	LONG IP_NET_DVR_GetSystemConfigByXml(SystemConfig *pSystemCfg, char *xmlBuf);
	LONG IP_NET_DVR_GetSystemVersionByXml(SYSTEM_VERSION_DATA *pSystemVer, char *xmlBuf);


	LONG IP_NET_DVR_System_getPTZCommonCfgByXml(PTZCommonConfig *pPtzCommonCfg, char *xmlBuf);
	LONG IP_NET_DVR_System_getPTZAdvanceCfgByXml(PTZAdvanceConfig *pPtzAdvanceCfg, char *xmlBuf);

	
	enum SearchMode_e{
		SearchModeByFiles = 0, //查询录像文件列表
		SearchModeByTimeDistribute,//查询某日录像分布
		SearchModeByTimeInterval, //查询某日录像列表，按录像时间来返回多条记录
		SearchModeGetDateList = 10 //查询有录像的日期列表
	};
	//解析CMD_GET_RECORD_FILE_LIST返回消息的SearchMode，用于获取该消息是针对搜索录像文件、搜索录像日分布、搜索有录像的日期
	LONG IP_NET_DVR_GetReplay_SearchMode_ByXml(const char *xmlBuf);
	LONG IP_NET_DVR_GetReplay_OneDay_DistributeByXml(const char *xmlBuf, char *distribute, unsigned int buflen);
	LONG IP_NET_DVR_GetReplay_Dates_DistributeByXml(const char *xmlBuf, unsigned int*datearray, unsigned int buflen);

	/*
	将结构体转换成XML
	XML内存为动态malloc ，用完后需要调用者手动free，否则会造成内存泄漏
	*/
	char* IP_NET_DVR_XMLGET_SystemConfig(SystemConfig *pSystemCfg);
	char* IP_NET_DVR_XMLGET_UserConfig(UserConfig *pUserCfg);
	char* IP_NET_DVR_XMLGET_TimeConfig(TimeConfig *pTimeCfg);
	char* IP_NET_DVR_XMLGET_SyslogConfig(SyslogConfig *pSyslogCfg);
	char* IP_NET_DVR_XMLGET_SysMiscConfig(MiscConfig *pMiscCfg);
	char* IP_NET_DVR_XMLGET_PTZConfig(PTZConfig *pPtzCfg);

	char* IP_NET_DVR_XMLGET_AlarmConfig(AlarmConfig *pAlarmCfg);
	char* IP_NET_DVR_XMLGET_InputAlarmConfig(InputAlarm *pInputAlm);
	char* IP_NET_DVR_XMLGET_MDAlarmConfig(MotionDetectAlarm *pMDAlm);
	char* IP_NET_DVR_XMLGET_PDAlarmConfig(PdAlarm *pPDAlm);
	char* IP_NET_DVR_XMLGET_VlAlarmConfig(VideoLostAlarm *pVideoLost);
	char* IP_NET_DVR_XMLGET_VCAlarmConfig(VideoCoverAlarm *pVideoCover);
	char* IP_NET_DVR_XMLGET_SFAlarmConfig(StorageFullAlarm *pSFAlm);


	char* IP_NET_DVR_XMLGET_MediaStreamConfig(MediaStreamConfig *mediaStreamCfg);
	char* IP_NET_DVR_XMLGET_PlatformConfig(PlatformConfig *platformCfg);
	char* IP_NET_DVR_XMLGET_GB28181Config(GB28181Config *platformCfg);


	char* IP_NET_DVR_XMLGET_RecordConfig(RecordConfig *recordCfg);


	char* IP_NET_DVR_XMLGET_NetworkConfig(NetworkConfigNew *networkCfg);
	char* IP_NET_DVR_XMLGET_NetworkLANConfig(LANConfig *lanCfg);
	char* IP_NET_DVR_XMLGET_NetworkWIFIConfig(WIFIConfig *wifiCfg);
	char* IP_NET_DVR_XMLGET_NetworkADSLConfig(ADSLConfigNew *adslCfg);
	char* IP_NET_DVR_XMLGET_NetworkDDNSConfig(DDNSConfig *ddnsCfg);
	char* IP_NET_DVR_XMLGET_NetworkUPNPConfig(UPNPConfig *upnpCfg);
	char* IP_NET_DVR_XMLGET_NetworkP2PConfig(P2PConfig *pCfg);

	char* IP_NET_DVR_XMLGET_ServerConfig(ServerConfig *serverCfg);
	char* IP_NET_DVR_XMLGET_FtpConfig(FtpServerList *fptServerList);
	char* IP_NET_DVR_XMLGET_SmtpConfig(SmtpServerList *smtpServerList);


	char* IP_NET_DVR_XMLGET_MediaConfig(MediaConfig *mediaCfg);
	char* IP_NET_DVR_XMLGET_AudioConfig(AudioConfig *audioCfg);
	char* IP_NET_DVR_XMLGET_VideoConfig(VideoConfig *videoCfg);

	char* IP_NET_DVR_XMLGET_AudioCaptureConfig(AudioCapture* audioCfg);
	char* IP_NET_DVR_XMLGET_AudioEncodeConfig(AudioEncode *audioCfg);

	

	char* IP_NET_DVR_XMLGET_VideoOverlayConfig(VideoOverlay *pCfg);
	char* IP_NET_DVR_XMLGET_VideoMaskConfig(VideoMaskConfig *pCfg);
	char* IP_NET_DVR_XMLGET_VideoCaptureConfig(VideoCapture*pCfg);
	char* IP_NET_DVR_XMLGET_VideoEncodeConfig(VideoEncode*pCfg);

	/*detail system config get*/
	/*GET函数调用时仅仅发网络请求，返回结果在回调中进行处理*/
	LONG IP_NET_DVR_GET_AlarmConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_MotionDetectAlarm(LONG lUserID);
	LONG IP_NET_DVR_GET_PersonDetectAlarm(LONG lUserID);
	LONG IP_NET_DVR_GET_InputAlarm(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoLostAlarm(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoCoverAlarm(LONG lUserID);
	LONG IP_NET_DVR_GET_StorageFullAlarm(LONG lUserID);

	LONG IP_NET_DVR_GET_SystemConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_PtzConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_UserConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_SyslogConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_TimeConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_MiscConfig(LONG lUserID);

	LONG IP_NET_DVR_GET_RecordConfig(LONG lUserID);

	LONG IP_NET_DVR_GET_MediaConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoCaptureConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoEncodeConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoOverlayConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoMaskConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_VideoROIConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_AudioConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_AudioEncode(LONG lUserID);
	LONG IP_NET_DVR_GET_AudioCapture(LONG lUserID);

	LONG IP_NET_DVR_GET_MediaStreamConfig(LONG lUserID);

	LONG IP_NET_DVR_GET_PlatformConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_GB28181Config(LONG lUserID);

	LONG IP_NET_DVR_GET_NetworkConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkLANConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkWIFIConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkADSLConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkDDNSConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkUPNPConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_NetworkP2PConfig(LONG lUserID);

	LONG IP_NET_DVR_GET_ServerConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_FtpServerConfig(LONG lUserID);
	LONG IP_NET_DVR_GET_SmtpServerConfig(LONG lUserID);

	/*detail system config set*/
	LONG IP_NET_DVR_SET_ModuleConfig(LONG lUserID, int moduleid,char *xmlconfig);

	LONG IP_NET_DVR_SET_AlarmConfig(LONG lUserID, AlarmConfig *pAlarmCfg);
	LONG IP_NET_DVR_SET_InputAlarmConfig(LONG lUserID, InputAlarm *pInputAlm);
	LONG IP_NET_DVR_SET_MotionDetectAlarm(LONG lUserID, MotionDetectAlarm *pMDAlm);
	LONG IP_NET_DVR_SET_PersonDetectAlarm(LONG lUserID, PdAlarm *pPDAlm);
	LONG IP_NET_DVR_SET_VlAlarmConfig(LONG lUserID, VideoLostAlarm *pVideoLost);
	LONG IP_NET_DVR_SET_VCAlarmConfig(LONG lUserID, VideoCoverAlarm *pVideoCover);
	LONG IP_NET_DVR_SET_OutputAlarmConfig(LONG lUserID, OutPutAlarm *p_config);
	LONG IP_NET_DVR_SET_VideoGateAlarmConfig(LONG lUserID, VideoGateAlarm *p_vgconfig);

	
	LONG IP_NET_DVR_SET_MiscConfig(LONG lUserID, MiscConfig *pCfg);  
	LONG IP_NET_DVR_SET_MediaConfig(LONG lUserID, MediaConfig *pConfig);   
	
	LONG IP_NET_DVR_SET_VideoCaptureConfig(LONG lUserID, VideoCapture *pCaptureCfg); 
	LONG IP_NET_DVR_SET_VideoEncodeConfig(LONG lUserID, VideoEncode *pEncodeCfg);
	LONG IP_NET_DVR_SET_VideoOSDConfig(LONG lUserID, VideoOverlay *pCfg);	
	LONG IP_NET_DVR_SET_VideoUserOSDConfig(LONG lUserID, VideoUserOverlay *p_config);
	LONG IP_NET_DVR_SET_VideoMaskConfig(LONG lUserID, VideoMaskConfig *pCfg);
	LONG IP_NET_DVR_SET_VideoConfig(LONG lUserID, VideoConfig *pVideoCfg);   
	LONG IP_NET_DVR_SET_AudioConfig(LONG lUserID, AudioConfig *pAudioCfg);   
	LONG IP_NET_DVR_SET_MediaStreamConfig(LONG lUserID, MediaStreamConfig *config);  
	LONG IP_NET_DVR_SET_PlatformConfig(LONG lUserID, PlatformConfig *pPlatformCfg);  
	LONG IP_NET_DVR_SET_GB28181Config(LONG lUserID, GB28181Config *pPlatformCfg);
	LONG IP_NET_DVR_SET_UserConfig(LONG lUserID, UserConfig *pUserCfg);  
	LONG IP_NET_DVR_SET_TimeConfig(LONG lUserID, TimeConfig *pTimeCfg);  
	LONG IP_NET_DVR_SET_NetworkLANConfig(LONG lUserID, LANConfig *config);   
	LONG IP_NET_DVR_SET_NetworkWIFIConfig(LONG lUserID, WIFIConfig *config); 
	LONG IP_NET_DVR_SET_NetworkConfig(LONG lUserID, NetworkConfigNew *config);   

	//编码能力集XML解析API.需要调用者delete pOutVideoCap pOutAudioCap
	LONG IP_NET_DVR_GET_MediaCapability( LONG lUserID  ) ;
	LONG IP_NET_DVR_XMLGET_MediaCapability(char *pRespone, 
		int *pVideoCapCount, RESOLUTION_ENTRY **pOutVideoCap, 
		int *pAudioCapCount, AUDIO_CODEC_ENTRY **pOutAudioCap )  ;

///////////IPCAMERA时间相关API//////////////////
//	时区转换:-12~12时区转换成IPCAMERA的时区
#define TRANS_TIMEZONE_TO_IPCAMERA(tz)  ((tz + 12)*60)		
	typedef struct
	{
		int timezone ; //0~1500
		int year; 
		int month; 
		int day;
		int hour; 
		int min; 
		int second; 
	}AjTime;

	//获取IPCAMERA时间
	LONG IP_NET_DVR_GET_SYSTEMTIME( LONG lUserID  ) ;
	LONG IP_NET_DVR_XMLGET_SYSTEMTIME( char *pRespone, AjTime *pTime  ) ;	
	//设置IPCAMERA时间和时区
	LONG IP_NET_DVR_SET_SYSTEMTIME( LONG lUserID, AjTime *pTime ) ;


	
	const char* IP_NET_DVR_GET_EVENTNAME( LONG nEvent) ;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif


