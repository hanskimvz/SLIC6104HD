
#ifndef _IPSDK_CLIENT_H_
#define _IPSDK_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ipsdk_def_type.h"
#include "ipsdk_data_def.h"

#ifdef WIN32
#ifdef IMPORT
#define IPSDK_API __declspec(dllimport)
#else
#define IPSDK_API __declspec(dllexport)
#endif
#else
#define IPSDK_API

#endif /* WIN32 */

#ifndef IPSDK_CALLBACK
#define IPSDK_CALLBACK
#endif /* CALLBACK */

typedef enum tag_IPSDK_EVENT_TYPE_
{
	EN_IPSDK_EVENT_CONNECTING = 0x10,
	EN_IPSDK_EVENT_CONNECT_OK,
	EN_IPSDK_EVENT_CONNECT_FAILED,
	EN_IPSDK_EVENT_REQLIVE_OK,
	EN_IPSDK_EVENT_REQLIVE_FAILED,
	EN_IPSDK_EVENT_ACKLIVE_OK,
	EN_IPSDK_EVENT_ACKLIVE_FAILED,
	EN_IPSDK_EVENT_STREAM_ERR,
	EN_IPSDK_EVENT_SOCKET_ERROR,
	EN_IPSDK_EVENT_HEADER_ERROR,

	EN_IPSDK_EVENT_LOGINOK,
	EN_IPSDK_EVENT_LOGINFAILED,
	EN_IPSDK_EVENT_STARTAUDIOOK,
	EN_IPSDK_EVENT_STARTAUDIOFAILED,
	EN_IPSDK_EVENT_STOPAUDIOOK,
	EN_IPSDK_EVENT_STOPAUDIOFAILED,
	EN_IPSDK_EVENT_SENDPTZOK,
	EN_IPSDK_EVENT_SENDPTZFAILED,
	EN_IPSDK_EVENT_SENDAUXOK,
	EN_IPSDK_EVENT_SENDAUXFAILED,
	EN_IPSDK_EVENT_UPLOADOK,
	EN_IPSDK_EVENT_UPLOADFAILED,
	EN_IPSDK_EVENT_DOWNLOADOK,
	EN_IPSDK_EVENT_DOWNLOADFAILED,
	EN_IPSDK_EVENT_REMOVEOK,
	EN_IPSDK_EVENT_REMOVEFAILED,
	EN_IPSDK_EVENT_SENDPTZERROR,
	EN_IPSDK_EVENT_PTZPRESETINFO,
	EN_IPSDK_EVENT_PTZALARM,
	EN_IPSDK_EVENT_RECVVIDEOPARAM,
	EN_IPSDK_EVENT_RECVAUDIOPARAM,
	EN_IPSDK_EVENT_CONNECTRTSPERROR,
	EN_IPSDK_EVENT_CONNECTRTSPOK,
	EN_IPSDK_EVENT_RTSPTHREADEXIT,
	EN_IPSDK_EVENT_URLERROR,
	EN_IPSDK_EVENT_RECVVIDEOAUDIOPARAM,
	EN_IPSDK_EVENT_LOGIN_USERERROR,
	EN_IPSDK_EVENT_LOGOUT_FINISH,
	EN_IPSDK_EVENT_LOGIN_RECONNECT,
	EN_IPSDK_EVENT_LOGIN_HEARTBEAT_LOST,
	EN_IPSDK_EVENT_STARTAUDIO_ISBUSY,
	EN_IPSDK_EVENT_STARTAUDIO_PARAMERROR,
	EN_IPSDK_EVENT_STARTAUDIO_AUDIODDISABLED,
	EN_IPSDK_EVENT_CONNECT_RTSPSERVER_ERROR,
	EN_IPSDK_EVENT_CREATE_RTSPCLIENT_ERROR,
	EN_IPSDK_EVENT_GET_RTSP_CMDOPTION_ERROR,
	EN_IPSDK_EVENT_RTSP_AUTHERROR,
	EN_IPSDK_EVENT_RECORD_FILEEND,
	EN_IPSDK_EVENT_RECORD_TASKEND,
	EN_IPSDK_EVENT_RECORD_DISKFREESPACE_TOOLOW,
	EN_IPSDK_EVENT_RECORD_INITAVIHEAD_ERROR,
	EN_IPSDK_EVENT_RECORD_MEDIA_PARAM_ERROR,
	EN_IPSDK_EVENT_SYSTEMREBOOT_ANDRELOGINOK,
	EN_IPSDK_EVENT_NETWORKRESET_ANDRELOGINOK,
	EN_IPSDK_EVENT_UPLOAD_PROCESS,
	EN_IPSDK_EVENT_DOWNLOAD_PROCESS,
	EN_IPSDK_EVENT_DOWNLOAD_RETRY_ANDRESTAR,
	EN_IPSDK_EVENT_LOGOUT_BYUSER,
	EN_IPSDK_EVENT_P2P_CONNECT_STATE_INFO,
	EN_IPSDK_EVNET_INITP2P_OK,
	EN_IPSDK_EVNET_INITP2P_ERROR,
	EN_IPSDK_EVENT_START_CONNECT_DEVICE,
	EN_IPSDK_EVENT_START_CONNECT_DEVICE_ERROR,
	EN_IPSDK_EVENT_P2PSERVER_LOGIN_OK,
	EN_IPSDK_EVENT_P2PSERVER_LOGOUT,
	EN_IPSDK_EVENT_P2PERROR_EVNETINFO,
	EN_IPSDK_EVENT_P2PCONNECT_DEVICEOK,
	EN_IPSDK_EVENT_P2PCONNECT_CLOSE,
	EN_IPSDK_EVENT_P2P_EXIT_CONNECT,
	EN_IPSDK_EVENT_CAPTURE_IMAGE_FINISH,
	EN_IPSDK_EVENT_RECVABLITY_INFO,
	EN_IPSDK_EVENT_P2P_CLINET_CHANNLEINFO,
	EN_IPSDK_EVENT_P2P_STARTSTREAM_ERROR11,
} EN_IPSDK_EVENT_TYPE;

/** 搜索设备信息回调 **/
/*
*   Name: fSearchDevCallBack
*            设备发现信息回调
*
*   Parameters:
*
*       [OUT] IPSDK_Int nStateCode
*            状态码（预留）
*       [OUT] IPSDK_SearchDevice* pSearchDevice
*            类型为 IPSDK_SearchDevice 的结构体指针，详细成员变量请查看 IPSDK_SearchDevice 定义。
*       [OUT] IPSDK_PVoid pUserParam
*            用户参数指针（预留）
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fSearchDevCallBack)(IPSDK_Int nStateCode, IPSDK_SearchDevice* pSearchDevice, IPSDK_PVoid pUserParam);
/** 播放码流获取回调 **/
typedef IPSDK_Int(IPSDK_CALLBACK *fRealStreamCallBack)(IPSDK_HANDLE lRealHandle, IPSDK_Int nChannl, IPSDK_Int nStream, IPSDK_Int nDataType, IPSDK_PChar pDataBuf, IPSDK_Int nDataLen, IPSDK_PVoid pUserBuf);
/** 固件升级进度回调 **/
/*
*   Name: fUpgradeRateCallBack
*            固件升级进度回调
*
*   Parameters:
*
*       [OUT] IPSDK_Int nUpgradeRate
*            设备升级进度（0-100）
*       [OUT] IPSDK_PChar pstrHostAddr
*            设备的IP地址（批量升级时可由该标志判断对应设备的升级进度）。
*       [OUT] IPSDK_PVoid pUserParam
*            用户参数指针（预留）
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fUpgradeRateCallBack)(IPSDK_Int nUpgradeRate, IPSDK_PChar pstrHostAddr, IPSDK_PVoid lParam);

/** 状态事件回调 **/
/*
*   Name: fStatusEventCallBack
*            状态事件回调
*
*   Parameters:
*
*       [OUT] IPSDK_Int nStateCode
*            状态码。详见 EN_IPSDK_EVENT_TYPE
*       [OUT] IPSDK_PChar pResponse
*            状态码对应的响应信息（预留）。
*       [OUT] IPSDK_PVoid pUserParam
*            用户参数指针（预留）
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fStatusEventCallBack)(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam);

/********************************SDK接口函数声明*********************************/

typedef		void*				IPSDK_HLOGIN;
typedef		void*				IPSDK_HCHANNEL;
typedef		void*				IPSDK_HINTERCOM;
typedef		void*				IPSDK_HOSDREFRESH;

//SDK初始化以及相关信息
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_Init();
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_Cleanup();
IPSDK_API IPSDK_PChar	IPSDK_CALLBACK	NETSDK_GetBuildVersion();
IPSDK_API IPSDK_PChar	IPSDK_CALLBACK	NETSDK_GetSdkVersion();
IPSDK_API IPSDK_PChar	IPSDK_CALLBACK	NETSDK_SetLogFile(IPSDK_Int bEnable, const IPSDK_PChar pstrLogFileDir, IPSDK_Int bAutoDel);
IPSDK_API IPSDK_PChar	IPSDK_CALLBACK	NETSDK_OpenLog(); //开启SDK LOG
IPSDK_API IPSDK_PChar	IPSDK_CALLBACK	NETSDK_CloseLog();//关闭SDK LOG

/*
*   Name: NETSDK_SearchDevice
*            设备发现
*
*   Parameters:
*
*       [IN] fSearchDevCallBack fSearchCallback
*            类型为 fSearchDevCallBack 的回调函数指针，详细成员变量请查看 fSearchDevCallBack 定义。
*       [INOUT] IPSDK_PVoid lParam
*            设置的参数值（预留）
*       [IN] IPSDK_Int nTimeout
*            回文接收超时时间。单位：秒
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       调用该 API 后会阻塞接收设备回文，直至设定的超时时间（nTimeout）后才返回。
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_SearchDevice(fSearchDevCallBack fSearchCallback,
	IPSDK_PVoid lParam, IPSDK_Int nTimeout, IPSDK_ULong ulBindAddr);
/*
*   Name: NETSDK_SetDeviceConfig
*            设置设备配置
*
*   Parameters:
*
*       [IN] fStatusEventCallBack fStatusEvent
*            类型为 fStatusEventCallBack 的回调函数指针，详细成员变量请查看 fStatusEventCallBack 定义。
*       [INOUT] IPSDK_PVoid lParam
*            设置的参数值（预留）
*       [OUT] IPSDK_SearchDevice* pSearchDevice
*            类型为 IPSDK_SearchDevice* 的结构体指针，详细成员变量请查看 IPSDK_SearchDevice 定义。
*       [IN] IPSDK_Int nDeviceNum
*            需要设置参数的设备数量。
*       [IN] IPSDK_Int nTimeout
*            回文接收超时时间。单位：秒
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       pSearchDevice 参数中的 strDeviceId 成员值为必需，其他成员值根据实际需求填写，否则置空。
*       调用该 API 后会阻塞接收设备回文，直至设定的超时时间（nTimeout）后才返回。
*/

IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetDeviceConfig(
	fStatusEventCallBack fStatusEvent,
	IPSDK_PVoid lParam,
	IPSDK_SearchDevice* pSearchDevice,
	IPSDK_Int nDeviceNum,
	IPSDK_Int nTimeout,
	IPSDK_ULong ulBindAddr);


typedef struct tag_ipsdk_license_info_
{
	IPSDK_Char strDeviceId[64];		/// 自动获取填充设备对像ID,用来标识设备端设备
	IPSDK_Char strCloudUuid[64];	/// 云UUID
	IPSDK_Char strSerialId[64];		/// 生产序列号
	IPSDK_Char strMacAddr[64];		/// 设备物理地址
	IPSDK_Char strReserved[64];		/// 预留
} IPSDK_LicenseInfo;

IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetLicenseConfig(
	fStatusEventCallBack fStatusEvent,
	IPSDK_PVoid lParam,
	IPSDK_PVoid pListLicense,
	IPSDK_Int	nListLen,
	IPSDK_Int	nTimeout,
	IPSDK_ULong ulBindAddr);

typedef struct tag_ipsdk_command_info_
{
	IPSDK_Char strDeviceId[64];		/// 自动获取填充设备对像ID,用来标识设备端设备
	EN_IPSDK_ProductCommand enProductCmd;	// 产测命令
	IPSDK_Char strReserved[64];		/// 预留
} IPSDK_CommandInfo;

IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_ProductCommand(
	fStatusEventCallBack fStatusEvent,
	IPSDK_PVoid lParam,
	IPSDK_PVoid pListCmd,
	IPSDK_Int	nListLen,
	IPSDK_Int	nTimeout,
	IPSDK_ULong ulBindAddr);

///<! 设备登陆与连接
IPSDK_API IPSDK_HLOGIN	IPSDK_CALLBACK	NETSDK_Login(const IPSDK_Char* pstrHostAddr, IPSDK_Int nSessionPort, IPSDK_Int nStreamPort, const IPSDK_Char* pstrUserName, const IPSDK_Char* pstrPassword, IPSDK_PVoid lParam);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_Logout(IPSDK_HLOGIN hUserId);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetAutoReconnect(IPSDK_HLOGIN hUserId, IPSDK_Int bAutoReconnect);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetReconnect(IPSDK_HLOGIN hUserId);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetStatusEvent(IPSDK_HLOGIN hUserId, fStatusEventCallBack fStatusEvent, IPSDK_PVoid lParam);

///<! 设备系统参数
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_SetParam(IPSDK_HLOGIN hUserId, const IPSDK_ChannelInfo* pChannelInfo, EN_IPSDK_DATA_PARAM enDataParam, IPSDK_PVoid pInDataParam, IPSDK_Int nInDataLen);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_GetParam(IPSDK_HLOGIN hUserId, const IPSDK_ChannelInfo* pChannelInfo, EN_IPSDK_DATA_PARAM enDataParam, IPSDK_PVoid pOutDataParam, IPSDK_Int nOutDataLen);

///<! 实时音视频预览
IPSDK_API IPSDK_HCHANNEL IPSDK_CALLBACK NETSDK_CreateRealPlay(IPSDK_HLOGIN hHandle, const IPSDK_ChannelInfo* pChannelInfo);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_DestoryRealPlay(IPSDK_HCHANNEL hChannel);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_StartRealPlay(IPSDK_HCHANNEL hChannel, fRealStreamCallBack cbRealDataCallBack, IPSDK_PVoid pUserData, IPSDK_Int bBlocked);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_StopRealPlay(IPSDK_HCHANNEL hChannel);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK	NETSDK_SetRealStreamStatus(IPSDK_HCHANNEL hStream, fStatusEventCallBack fStatusEvent, IPSDK_PVoid lParam);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_SetPlayRealPlay(IPSDK_HCHANNEL hStream);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_SetPauseRealPlay(IPSDK_HCHANNEL hStream);

IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_GetVideoParam(IPSDK_HCHANNEL hChannel, IPSDK_PVoid pOutDataParam, IPSDK_Int nOutDataLen);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_GetAudioParam(IPSDK_HCHANNEL hChannel, IPSDK_PVoid pOutDataParam, IPSDK_Int nOutDataLen);

///<! 录像文件回放
IPSDK_API IPSDK_HCHANNEL IPSDK_CALLBACK NETSDK_CreatePlayback(IPSDK_HLOGIN hHandle, const IPSDK_PlaybackInfo* pPlaybackInfo);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_StartPlayback(IPSDK_HCHANNEL hChannel, fRealStreamCallBack fPlaybackStream, fStatusEventCallBack fStatusEvent, IPSDK_PVoid pUserData);
IPSDK_API IPSDK_Int		 IPSDK_CALLBACK NETSDK_DestoryPlayback(IPSDK_HCHANNEL hChannel);

///<! 云台控制
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_PTZControl(IPSDK_HLOGIN hUserId, IPSDK_Int dwPTZCommand, IPSDK_Int nTspeed, IPSDK_Int nSpeed);
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_PTZPreset(IPSDK_HLOGIN hUserId, IPSDK_Int dwPTZPresetCmd, IPSDK_Int dwPresetIndex);

//系统控制

///<! 固件更新
/*
*   Name: NETSDK_UpgradeFirmware
*            升级固件
*
*   Parameters:
*
*       [IN] const IPSDK_PChar pstrHostIpaddr
*            需要升级的设备IP地址。
*       [IN] const IPSDK_PChar pstrFirmware
*            需要升级的设备固件文件名（带路径）。
*       [IN] fUpgradeRateCallBack cbUpgradeRate
*            类型为 fUpgradeRateCallBack 的回调函数指针，详细成员变量请查看 fUpgradeRateCallBack 定义。
*       [INOUT] IPSDK_PVoid lParam
*            设置的参数值（预留）
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_UpgradeFirmware(const IPSDK_Char* pstrHostIpaddr, const IPSDK_Char* pstrFirmware, fUpgradeRateCallBack cbUpgradeRate, IPSDK_PVoid lParam);
///<! 配置文件/音频文件上传
/*
*   Name: NETSDK_UploadFile
*            文件上传
*
*   Parameters:
*
*       [IN] IPSDK_HLOGIN hUserId
*            设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*       [IN] const IPSDK_PChar pstrFirmware
*            需要上传的文件名（不带路径）。
*       [IN] const IPSDK_PChar pstrFileData
*            需要上传的文件缓存地址。
*       [IN] IPSDK_Int nFileLen
*            需要上传的文件缓存地址长度。
*       [IN] EN_IPSDK_FileType enFileType
*            需要上传的文件类型。
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       目前只支持告警音频文件上传
*/
IPSDK_API IPSDK_Int		IPSDK_CALLBACK	NETSDK_UploadFile(IPSDK_HLOGIN hUserId, const IPSDK_Char* pstrFileName, const IPSDK_Char* pstrFileData, IPSDK_Int nFileLen, EN_IPSDK_FileType enFileType);


// 整机测试函数回调
/*
*   Name: fProductTestCallback
*            整机测试函数回调
*
*   Parameters:
*
*       [OUT] IPSDK_Int nTestId
*            给外部知道是哪个测试命令返回。
*       [OUT] IPSDK_Int nCode
*            用于快速检测。0为成功，非0为失败。
*       [OUT] const IPSDK_PChar pResultJson
*            返回给外部必要的参数（根据需要可设为IPSDK_NULL）。
*       [OUT] IPSDK_PVoid pUser
*            给外部使用的指针。
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fProductTestCallback)(
	IPSDK_Int nTestId,
	IPSDK_Int nCode,
	IPSDK_CPChar pResultJson,
	IPSDK_PVoid pUser);

// 整机测试
/*
*   Name: NETSDK_ProductTest
*            整机测试
*
*   Parameters:
*
*       [IN] IPSDK_HLOGIN hUserId
*            设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*       [IN] IPSDK_Int nTestId
*            用于区分各种测试命令。
*       [IN] fProductTestCallback cbProductTest
*            用于接收测试结果。
*       [IN] const IPSDK_PChar pParamJson
*            用于传递必要的参数（根据需要可设为IPSDK_NULL）。
*       [IN] IPSDK_PVoid pUser
*            给外部使用的指针。
*
*   Return:
*            IPSDK_SUCCESS(成功)
*            IPSDK_FAILURE(失败)
*   Note:
*       无
*/
IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ProductTest(
	IPSDK_HLOGIN hUserId,
	IPSDK_Int nTestId,
	fProductTestCallback cbProductTest,
	IPSDK_CPChar pParamJson,
	IPSDK_PVoid pUser);

typedef IPSDK_Int(IPSDK_CALLBACK *fJsonProtocolCallback)(
	IPSDK_Int nJsonId,
	IPSDK_Int nCode,
	IPSDK_CPChar pResultJson,
	IPSDK_PVoid pUser);

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_JsonProtocol(
	IPSDK_HLOGIN hUserId,
	IPSDK_Int nJsonId,
	IPSDK_Int nChannelId,
	IPSDK_Int nStreamId,
	fJsonProtocolCallback cbJsonProtocol,
	IPSDK_CPChar pParamJson,
	IPSDK_PVoid pUser);

///<! 广播音频相关(对讲)
/*
*	Name: NETSDK_IntercomCalled
*			 对讲呼叫
*
*	Parameters:
*
*       [IN] IPSDK_HLOGIN hLogin
*            设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*
*	Return:
*            设备的对讲句柄。
*			 不为 IPSDK_NULL(成功)
*			 IPSDK_NULL(失败)
*	Note:
*		无
*/
IPSDK_API IPSDK_HINTERCOM IPSDK_CALLBACK	NETSDK_IntercomCalled(IPSDK_HLOGIN hLogin);

/*
*	Name: NETSDK_IntercomSend
*			 对讲发送
*
*	Parameters:
*
*       [IN] IPSDK_HINTERCOM hIntercom
*            设备的对讲句柄，由调用 NETSDK_IntercomCalled() API的返回值获取。
*       [IN] IPSDK_CPChar pData
*            需要发送的语音数据，格式固定为 PCM/8k/16bit/单声道。
*       [IN] IPSDK_Int nLen
*            需要发送的语音数据长度。
*
*	Return:
*			 大于 0(成功发送的字节数)
*			 等于 0(发送超时)
*			 小于 0(错误)
*	Note:
*		出错后需要调用 NETSDK_IntercomHungUp() 接口释放资源
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_IntercomSend(IPSDK_HINTERCOM hIntercom, IPSDK_CPChar pData, IPSDK_Int nLen);

/*
*	Name: NETSDK_IntercomHungUp
*			 对讲挂起
*
*	Parameters:
*
*       [IN] IPSDK_HINTERCOM hIntercom
*            设备的对讲句柄，由调用 NETSDK_IntercomCalled() API的返回值获取。
*
*	Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	Note:
*		无
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_IntercomHungUp(IPSDK_HINTERCOM hIntercom);

// 直播抓图函数回调
/*
*	 Name: fSnapshotCallback
*			 直播抓图函数回调
*
*	 Parameters:
*
*		[OUT] IPSDK_CPChar pDataBuf
*			 抓图的数据缓存地址。
*		[OUT] IPSDK_Int nDataLen
*			 抓图的数据缓存长度。
*		[OUT] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fSnapshotCallback)(
	IPSDK_CPChar pDataBuf,
	IPSDK_Int nDataLen,
	IPSDK_PVoid pUser);

///<! 直播抓图
/*
*	 Name: NETSDK_Snapshot
*			 直播抓图
*
*	 Parameters:
*
*		[IN] IPSDK_HLOGIN hUserId
*			 设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*		[IN] const IPSDK_ChannelInfo* pChannelInfo
*			 直播抓图的通道信息。
*		[IN] fSnapshotCallback cbSnapshot
*			 函数回调用于接收抓图数据。
*		[IN] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_Snapshot(
	IPSDK_HLOGIN hUserId,
	const IPSDK_ChannelInfo* pChannelInfo,
	fSnapshotCallback cbSnapshot,
	IPSDK_PVoid pUser);


///<! OSD 刷新
/*
*	Name: NETSDK_OsdRefreshStart
*			 OSD 刷新开始
*
*	Parameters:
*
*		[IN] IPSDK_HLOGIN hLogin
*			 设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*
*	Return:
*			 设备的 OSD 刷新句柄。
*			 不为 IPSDK_NULL(成功)
*			 IPSDK_NULL(失败)
*	Note:
*		需要与 NETSDK_OsdRefreshStop() 接口配套使用
*/
IPSDK_API IPSDK_HOSDREFRESH IPSDK_CALLBACK	NETSDK_OsdRefreshStart(IPSDK_HLOGIN hLogin);

/*
*	Name: NETSDK_OsdRefreshSend
*			 OSD 刷新发送
*
*	Parameters:
*
*		[IN] IPSDK_HOSDREFRESH hOsdRefresh
*			 设备的 OSD 刷新句柄，由调用 NETSDK_OsdRefreshStart() API的返回值获取。
*		[IN] IPSDK_OsdRefresh *pOsdRefresh
*			 需要发送的 OSD 刷新数据。
*
*	Return:
*			 大于 0(成功发送的字节数)
*			 等于 0(发送超时)
*			 小于 0(错误)
*	Note:
*		1.在调用 NETSDK_OsdRefreshStart() 接口成功后可以连续调用该接口
*		2.出错后需要调用 NETSDK_OsdRefreshStop() 接口释放资源
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_OsdRefreshSend(IPSDK_HOSDREFRESH hOsdRefresh, IPSDK_OsdRefresh *pOsdRefresh);

/*
*	Name: NETSDK_OsdRefreshStop
*			 OSD 刷新停止
*
*	Parameters:
*
*		[IN] IPSDK_HOSDREFRESH hOsdRefresh
*			 设备的 OSD 刷新句柄，由调用 NETSDK_OsdRefreshStart() API的返回值获取。
*
*	Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	Note:
*		无
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_OsdRefreshStop(IPSDK_HOSDREFRESH hOsdRefresh);


// 设备端消息通知函数回调
/*
*	 Name: fNotifyCallback
*			 通知函数回调
*
*	 Parameters:
*
*		[OUT] const IPSDK_Notification *pNotif
*			 设备端消息通知的回调数据。
*		[OUT] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fNotifyCallback)(const IPSDK_Notification *pNotif, IPSDK_PVoid pUser);

///<! 注册设备端消息通知
/*
*	 Name: NETSDK_Notify
*			注册设备端消息通知
*
*	 Parameters:
*
*		[IN] IPSDK_HLOGIN hUserId
*			 设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*		[IN] fNotifyCallback cbNotify
*			 接收设备端消息通知数据。
*		[IN] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_Notify(IPSDK_HLOGIN hUserId, fNotifyCallback cbNotify, IPSDK_PVoid pUser);


// 设备端消息传输函数回调
/*
*	 Name: fNotifyCallback
*			 传输函数回调
*
*	 Parameters:
*
*		[OUT] EN_IPSDK_TransmissionType enTransType
*			 设备端消息传输的类型。
*		[OUT] IPSDK_CPChar pDataBuf
*			 设备端消息传输的回调数据。
*		[OUT] IPSDK_Int nDataLen
*			 设备端消息传输的回调数据长度。
*		[OUT] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
typedef IPSDK_Int(IPSDK_CALLBACK *fTransCallback)(EN_IPSDK_TransmissionType enTransType, IPSDK_CPChar pDataBuf, IPSDK_Int nDataLen, IPSDK_PVoid pUser);

///<! 注册设备端消息传输
/*
*	 Name: NETSDK_Trans
*			注册设备端消息传输
*
*	 Parameters:
*
*		[IN] IPSDK_HLOGIN hUserId
*			 设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*		[IN] fNotifyCallback cbTrans
*			 接收设备端传输消息数据。
*		[IN] IPSDK_PVoid pUser
*			 给外部使用的指针。
*
*	 Return:
*			 IPSDK_SUCCESS(成功)
*			 IPSDK_FAILURE(失败)
*	 Note:
*			 无
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_Trans(IPSDK_HLOGIN hUserId, fTransCallback cbTrans, IPSDK_PVoid pUser);

/*
*	Name: NETSDK_TransSend
*			消息传输发送
*
*	Parameters:
*
*		[IN] IPSDK_HLOGIN hUserId
*			 设备的登录句柄，由调用 NETSDK_Login() API的返回值获取。
*		[IN] EN_IPSDK_TransmissionType enTransType
*			 设备端消息传输的类型。
*		[IN] IPSDK_CPChar pDataBuf
*			 设备端消息传输的发送数据。
*		[IN] IPSDK_Int nDataLen
*			 设备端消息传输的发送数据长度。
*
*	Return:
*			 大于 0(成功发送的字节数)
*			 等于 0(发送超时)
*			 小于 0(错误)
*	Note:
*		1.在调用 NETSDK_OsdRefreshStart() 接口成功后可以连续调用该接口
*		2.出错后需要调用 NETSDK_OsdRefreshStop() 接口释放资源
*/
IPSDK_API IPSDK_Int IPSDK_CALLBACK	NETSDK_TransSend(IPSDK_HLOGIN hUserId, EN_IPSDK_TransmissionType enTransType, IPSDK_CPChar pDataBuf, IPSDK_Int nDataLen);

#ifdef __cplusplus
}
#endif

#endif

