
#ifndef _IPSDK_ERP_H_
#define _IPSDK_ERP_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "ipsdk_def_type.h"
#include "ipsdk_data_def.h"


#if WIN32
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

typedef enum tag_erp_err_code_type_
{
	EN_ERP_ERR_CODE_HTTP_RET_FAILURE = (-1),
	EN_ERP_ERR_CODE_HTTP_RET_SUCCESS = (0),
	EN_ERP_ERR_CODE_HTTP_ERR_HEADERS = (-1001),	/// Http头错误 Headers
	EN_ERP_ERR_CODE_HTTP_ERR_MATCHERS,			/// Http头错误 Headers
	EN_ERP_ERR_CODE_HTTP_ERR_BODYS,				/// Http bodys内容错误
	EN_ERP_ERR_CODE_HTTP_ERR_CREATE,			/// Http 创建失败
	EN_ERP_ERR_CODE_MAKE_ERR_HEADERS,			/// Http 创建失败
	EN_ERP_ERR_CODE_MAKE_ERR_MATCHERS,			/// Http头错误 Headers
	EN_ERP_ERR_CODE_MAKE_ERR_BIZOBJECT,			/// Http 创建失败
	EN_ERP_ERR_CODE_MAKE_ERR_FILTER,			/// Http 创建失败
	EN_ERP_ERR_CODE_SOCK_ERR_OPEN,				/// socket 打开错误
	EN_ERP_ERR_CODE_SOCK_ERR_CLOSE,				/// socket 关闭错误
	EN_ERP_ERR_CODE_SOCK_ERR_RECV,				/// socket 接收错误 
	EN_ERP_ERR_CODE_SOCK_ERR_SEND,				/// socket 发送错误
	EN_ERP_ERR_CODE_BTN,
} EN_ERP_ERR_CODE_TYPE;

/*
* 用户信息表单:手机号(Key) 用户名，密码，绑定MAC主机，公司信息，用户权限
* 烧录MAC表单: MAC地址(Key)，是否烧录，生产序列号，产品型号，手机号(索引Key)
* 烧录UUID表单:UUID(Key)，是否烧录，公司信息，手机号(索引Key)，mac地址(索引Key)
*/
typedef enum tag_ipsdk_erp_data_type_
{
	EN_IPSDK_ERP_DATA_TYPE_USER,	/// 对应于表单 IPSDK_ERP_UserInfo 
	EN_IPSDK_ERP_DATA_TYPE_MAC,		/// 对应于表单 IPSDK_ERP_MacInfo 
	EN_IPSDK_ERP_DATA_TYPE_UUID,	/// 对应于表单 IPSDK_ERP_UserInfo 
	EN_IPSDK_ERP_DATA_TYPE_COMPUTER,/// 对应于表单 IPSDK_ERP_ComputerBindInfo 
	EN_IPSDK_ERP_DATA_TYPE_DEVICE,	/// 对应于表单 IPSDK_ERP_DeviceInfo 
	EN_IPSDK_ERP_DATA_TYPE_LOG,		/// 对应于表单 IPSDK_ERP_LogInfo 
	EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE,		/// 对应于表单 IPSDK_ERP_UserDeviceIndexInfo 
	EN_IPSDK_ERP_DATA_TYPE_BTN,
} EN_IPSDK_ERP_DATA_TYPE;

/**
** 用户信息表单: 用户ID[SeqNo], 用户名[F0000001]，
密码[F0000002]，手机号码[F0000003]，公司信息[F0000004]
**/
typedef struct tag_ipsdk_erp_userinfo_
{
	IPSDK_Char strUserSeqNo[32];		/// 对应表单号[SeqNo]
	IPSDK_Char strUserName[32];			/// 对应表单号[F0000001] =>用户名
	IPSDK_Char strPassword[32];			/// 对应表单号[F0000002] =>用户密码
	IPSDK_Char strPhoneNumber[32];		/// 对应表单号[F0000003] =>手机号码
	IPSDK_Char strCompanyInfo[64];		/// 对应表单号[F0000004] =>公司信息
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_UserInfo;

/**
** 电脑绑定信息表单: ID[SeqNo], 地址绑定[F0000001]，是否激活[F0000002]，
最后登录时间[F0000003]，用户表ID[F0000004]
**/
typedef struct tag_ipsdk_erp_computer_bind_info_
{
	IPSDK_Char strBindSeqNo[32];	/// 对应表单号[SeqNo]
	IPSDK_Char strBindMacAddr[32];	/// 对应表单号[F0000001] =>绑定MAC主机
	IPSDK_Int  bUsed;				/// 对应表单号[F0000002] =>是否激活使用
	IPSDK_Char strLoginDate[32];	/// 对应表单号[F0000003] =>最近登录时间
	IPSDK_Char strUserSeqNo[32];	/// 对应表单号[F0000004] =>用户表ID号
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_ComputerBindInfo;

/**
** MAC信息表单: ID[SeqNo], mac地址[F0000001]，是否下载[F0000002]，是否烧录[F0000003]，
下载时间[F0000004]，烧录时间[F0000005]，设备序列号[F0000006]，用户表ID[F0000007]
**/
typedef struct tag_ipsdk_erp_macinfo_
{
	IPSDK_Char strMacSeqNo[32];		/// 对应表单号[SeqNo] => 烧录ID
	IPSDK_Char strMacAddr[24];		/// 对应表单号[F0000001] =>烧录MAC地址
	IPSDK_Int  bDownLoad;			/// 对应表单号[F0000002] =>是否已经下载
	IPSDK_Int  bBurn;				/// 对应表单号[F0000003] =>是否已经烧录
	IPSDK_Char strDownLoadDate[32];	/// 对应表单号[F0000004] =>下载时间
	IPSDK_Char strBurnDate[32];		/// 对应表单号[F0000005] =>烧录时间
	IPSDK_Char strDeviceSerial[32];	/// 对应表单号[F0000006] =>设备序列号
	IPSDK_Char strUserSeqNo[32];	/// 对应表单号[F0000007] =>用户表ID号
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_MacInfo;

/**
** UUID信息表单: ID[SeqNo], UUID号[F0000001]，UUID公司名称[F0000002]，是否下载[F0000003]，
下载时间[F0000004]，是否烧录[F0000005]，烧录时间[F0000006]，用户表ID[F0000007]，MAC表ID[F0000008]
**/
typedef struct tag_ipsdk_erp_uuid_info_
{
	IPSDK_Char strUuidSeqNo[32];		/// 对应表单号[SeqNo] => 烧录ID
	IPSDK_Char strUuid[64];				/// 对应表单号[F0000001] =>UUID号
	IPSDK_Char strUuidCompanyInfo[32];	/// 对应表单号[F0000002] =>提供uuid号公司名称
	IPSDK_Int  bDownLoad;				/// 对应表单号[F0000003] =>是否已经下载
	IPSDK_Char strDownLoadDate[32];		/// 对应表单号[F0000004] =>下载时间
	IPSDK_Int  bBurn;					/// 对应表单号[F0000005] =>是否已经烧录
	IPSDK_Char strBurnDate[32];			/// 对应表单号[F0000006] =>烧录时间
	IPSDK_Char strUserSeqNo[32];		/// 对应表单号[F0000007] =>用户表ID号
	IPSDK_Char strMacSeqNo[32];			/// 对应表单号[F0000008] =>Mac表ID
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_UuidInfo;

/**
** 设备型号信息表单: ID[SeqNo], 设备型号[F0000001]，用户表ID[F0000002]
**/
typedef struct tag_ipsdk_erp_device_info_
{
	IPSDK_Char strDeviceSeqNo[32];		/// 对应表单号[SeqNo]	 =>设备型号ID
	IPSDK_Char strDeviceModel[32];		/// 对应表单号[F0000001] =>设备型号
	IPSDK_Char strDeviceName[32];		/// 对应表单号[F0000002] =>设备名称
	IPSDK_Int  bDisableModel;			/// 对应表单号[F0000003] =>设备型号是否禁用
	IPSDK_Char strHardwareVersion[32];	/// 对应表单号[F0000004] =>硬件版本
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_DeviceInfo;

/**
 * 用户日志表
**/
typedef struct tag_ipsdk_erp_log_info_
{
	IPSDK_Char strLogSeqNo[32];		/// 对应表单号[SeqNo]	 =>ID
	IPSDK_Char strLogDate[32];		/// 对应表单号[F0000001] =>日志时间 (年-月-日)
	IPSDK_Char strProduceDate[32];	/// 对应表单号[F0000002] =>生产日期（年+周数）
	IPSDK_Char strUserSeqNo[32];	/// 对应表单号[F0000003] =>用户ID
	IPSDK_Int  nBurnMacCount;		/// 对应表单号[F0000004] =>当天烧录MAC统计
	IPSDK_Int  nBurnUuidCount;		/// 对应表单号[F0000005] =>当天烧录UUID统计
	IPSDK_Int  nBurnBadCount;		/// 对应表单号[F0000006] =>当天烧录不良品统计
	IPSDK_Char strDeviceSeqNo[32];	/// 对应表单号[F0000007] =>设备型号表ID号
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_LogInfo;

/**
** 设备型号与用户关联表
**/
typedef struct tag_ipsdk_erp_user_device_index_info_
{
	IPSDK_Char strIndexSeqNo[32];		/// 对应表单号[SeqNo]	 =>ID
	IPSDK_Char strUserSeqNo[32];		/// 对应表单号[F0000001] =>用户表ID序列号
	IPSDK_Char strDeviceSeqNo[32];		/// 对应表单号[F0000002] =>设备型号表ID号
/** 下面表单暂时隐藏部分，目前供表单更新及删除使用（通过查询自动获取） **/
	IPSDK_Char strBizObjectId[64]; /// 
	IPSDK_Char strCreatedBy[64];
	IPSDK_Char strOwnerId[64];
} IPSDK_ERP_UserDeviceIndexInfo;

typedef IPSDK_Int(IPSDK_CALLBACK *fQueryDbCallBack)(
	IPSDK_Int enDataType, 
	IPSDK_Int nIndex,
	IPSDK_PVoid pDataInfo, 
	IPSDK_PVoid lParam);

IPSDK_API IPSDK_PChar IPSDK_CALLBACK NETSDK_ERP_MakeMatchers(
	IPSDK_PChar pstrBuffer,
	IPSDK_Int   nLenBuffer,
	IPSDK_PChar pstrAndType,
	IPSDK_PChar pstrType,
	IPSDK_PChar pstrName,
	IPSDK_Int   nOperator,
	IPSDK_PChar pstrValue);

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_Init();
IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_Exit();

IPSDK_API IPSDK_PVoid	IPSDK_CALLBACK	NETSDK_ERP_Login(
	IPSDK_PChar pstrUserName,
	IPSDK_PChar pstrPassword,
	IPSDK_PChar pstrPhoneNumber);

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_Logout(IPSDK_PVoid hUserId);

IPSDK_ERP_UserInfo* IPSDK_CALLBACK	NETSDK_ERP_GetCurUserInfo(IPSDK_PVoid hUserId);

typedef struct tag_ipsdk_erp_upate_event_
{
	IPSDK_Int(*GetBizObject)(
		EN_IPSDK_ERP_DATA_TYPE enDataType,
		IPSDK_PVoid pDataInfo,
		IPSDK_Int nDataLen,
		IPSDK_PChar pstrOutBizObject,
		IPSDK_Int nOutLen,
		IPSDK_PVoid lParam);
	IPSDK_PVoid lParam;
}IPSDK_ERP_UPDATE_EVENT;

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_CreateDataBase(
	IPSDK_PVoid hUserId,
	IPSDK_Int   enDataType,
	IPSDK_PVoid pDataInfo,
	IPSDK_Int   nDataLen,
	IPSDK_ERP_UPDATE_EVENT* fUpdateEvent,
	IPSDK_PVoid lParam);

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_ModifyDataBase(
	IPSDK_PVoid hUserId,
	IPSDK_Int   enDataType,
	IPSDK_PVoid pDataInfo,
	IPSDK_Int   nDataLen,
	IPSDK_ERP_UPDATE_EVENT* fUpdateEvent,
	IPSDK_PVoid lParam);

typedef struct tag_ipsdk_erp_query_event_
{
	IPSDK_Int(*GetFilterValue)(
		EN_IPSDK_ERP_DATA_TYPE enDataType,
		IPSDK_Int* pOutFromRowNum,
		IPSDK_Int* pOutToRowNum,
		IPSDK_Int* pOutRequireCount,
		IPSDK_PVoid lParam);		/// 获取本机mac物理地址
	IPSDK_Int(*GetMatchers)(
		EN_IPSDK_ERP_DATA_TYPE enDataType, 
		IPSDK_PChar pstrOutMastchers, 
		IPSDK_Int nOutMaxLen,
		IPSDK_PVoid lParam);
	IPSDK_PVoid lParam;
}IPSDK_ERP_QUERY_EVENT;

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_QueryDataBase(
	IPSDK_PVoid hUserId,
	IPSDK_Int   enDataType,
	IPSDK_ERP_QUERY_EVENT* pQueryEvent,
	fQueryDbCallBack fOutQueryCallback,
	IPSDK_PVoid lParam);

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_QueryDataBaseEx(
	IPSDK_PVoid hUserId,
	IPSDK_Int   enDataType,
	IPSDK_ERP_QUERY_EVENT* pQueryEvent,
	IPSDK_PVoid pOutListData,
	IPSDK_Int   nOutListSize );

IPSDK_API IPSDK_Int	IPSDK_CALLBACK	NETSDK_ERP_DeleteDataBase(
	IPSDK_PVoid hUserId,
	IPSDK_Int   enDataType,
	IPSDK_PVoid pOutListData,
	IPSDK_Int   nListSize);

#ifdef __cplusplus
}
#endif

#endif
