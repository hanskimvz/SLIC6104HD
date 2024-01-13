#if defined(OS_WINDOWS)
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include "ipsdk_def_type.h"
#include "ipsdk_client.h"
#include "ipsdk_debug.h"
#include "ipsdk_erp.h"


typedef struct tag_erp_client_context_
{
#define CLINET_MAX_NODE		(20)
	IPSDK_ERP_MacInfo			stMacInfo[CLINET_MAX_NODE];
	IPSDK_ERP_UuidInfo			stUuidInfo[CLINET_MAX_NODE];
	IPSDK_ERP_DeviceInfo		stDeviceInfo[CLINET_MAX_NODE];
	IPSDK_ERP_ComputerBindInfo  stComputerBindInfo[CLINET_MAX_NODE];
	IPSDK_ERP_LogInfo			stLogInfo[CLINET_MAX_NODE];
	IPSDK_ERP_UserDeviceIndexInfo stUserDeviceIndexInfo[CLINET_MAX_NODE];
}ERP_CLIENT_CONTEXT;

static ERP_CLIENT_CONTEXT g_erp_client_context;

static IPSDK_Int _Erp_Read_QueryDbCallBack(
	IPSDK_Int enDataType,
	IPSDK_Int nIndex,
	IPSDK_PVoid pDataInfo,
	IPSDK_PVoid pUserParam)
{
	if (EN_IPSDK_ERP_DATA_TYPE_MAC == enDataType)
	{
		IPSDK_ERP_MacInfo* pMacInfo = (IPSDK_ERP_MacInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pMacInfo, IPSDK_FAILURE);
		printf("macaddr:%s,bUsed:%d \n", pMacInfo->strMacAddr, pMacInfo->bDownLoad);
		memcpy(&g_erp_client_context.stMacInfo[nIndex], pMacInfo, sizeof(IPSDK_ERP_MacInfo));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_UUID == enDataType)
	{
		IPSDK_ERP_UuidInfo* pUuidInfo = (IPSDK_ERP_UuidInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pUuidInfo, IPSDK_FAILURE);
		printf("strUuid:%s,bUsed:%d \n", pUuidInfo->strUuid, pUuidInfo->bDownLoad);
		memcpy(&g_erp_client_context.stUuidInfo[nIndex], pUuidInfo, sizeof(IPSDK_ERP_UuidInfo));

	}
	else if (EN_IPSDK_ERP_DATA_TYPE_DEVICE == enDataType)
	{
		IPSDK_ERP_DeviceInfo* pDeviceInfo = (IPSDK_ERP_DeviceInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pDeviceInfo, IPSDK_FAILURE);
		printf("strDevice_id:%s,strDeviceModel:%s,bDisableModel:%d \n", pDeviceInfo->strDeviceSeqNo, pDeviceInfo->strDeviceModel, pDeviceInfo->bDisableModel);
		memcpy(&g_erp_client_context.stDeviceInfo[nIndex], pDeviceInfo, sizeof(IPSDK_ERP_DeviceInfo));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_COMPUTER == enDataType)
	{
		IPSDK_ERP_ComputerBindInfo* pComputerBindInfo = (IPSDK_ERP_ComputerBindInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pComputerBindInfo, IPSDK_FAILURE);
		printf("strBindSeqNo:%s,strBindMacAddr:%s,strUserSeqNo:%s \n", pComputerBindInfo->strBindSeqNo, pComputerBindInfo->strBindMacAddr, pComputerBindInfo->strUserSeqNo);
		memcpy(&g_erp_client_context.stComputerBindInfo[nIndex], pComputerBindInfo, sizeof(IPSDK_ERP_ComputerBindInfo));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_LOG == enDataType)
	{
		IPSDK_ERP_LogInfo* pLogInfo = (IPSDK_ERP_LogInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pLogInfo, IPSDK_FAILURE);
		printf("strLogSeqNo:%s,strLogDate:%s,Produce Date:%s \n", pLogInfo->strLogSeqNo, pLogInfo->strLogDate, pLogInfo->strProduceDate);
		memcpy(&g_erp_client_context.stLogInfo[nIndex], pLogInfo, sizeof(IPSDK_ERP_LogInfo));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE == enDataType)
	{
		IPSDK_ERP_UserDeviceIndexInfo* pUserDeviceIndexInfo = (IPSDK_ERP_UserDeviceIndexInfo*)pDataInfo;
		CHECK_POINTER_ERR_RET(pUserDeviceIndexInfo, IPSDK_FAILURE);
		printf("strIndexSeqNo:%s,strUserSeqNo:%s,strDeviceSeqNo:%s \n", pUserDeviceIndexInfo->strIndexSeqNo, pUserDeviceIndexInfo->strUserSeqNo, pUserDeviceIndexInfo->strDeviceSeqNo);
		memcpy(&g_erp_client_context.stUserDeviceIndexInfo[nIndex], pUserDeviceIndexInfo, sizeof(IPSDK_ERP_UserDeviceIndexInfo));
	}
	return IPSDK_SUCCESS;
}

static IPSDK_Int _MacAddr_GetMaxIndex(EN_IPSDK_ERP_DATA_TYPE enDataType)	/// 获取本机mac物理地址
{
	if (EN_IPSDK_ERP_DATA_TYPE_MAC == enDataType)
	{
		return 10;
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_UUID == enDataType)
	{
		return 10;
	}
	return 10;
}
static IPSDK_Int _MacAddr_GetFilterValue(
	EN_IPSDK_ERP_DATA_TYPE enDataType,
	IPSDK_Int* pOutFromRowNum,
	IPSDK_Int* pOutToRowNum,
	IPSDK_Int* pOutRequireCount,
	IPSDK_PVoid lParam)
{
	static IPSDK_Int nFromRowNum = 0;
	switch (enDataType)
	{
		case EN_IPSDK_ERP_DATA_TYPE_MAC:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_USER:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_UUID:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_DEVICE:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_COMPUTER:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_LOG:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		case EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE:
		{
			*pOutFromRowNum = nFromRowNum;
			*pOutToRowNum = 10;
			*pOutRequireCount = 100;
		}
		break;
		default:
			return IPSDK_FAILURE;
	}
	nFromRowNum += 2;

	return IPSDK_SUCCESS;
}
static IPSDK_Int _MacAddr_GetMatchers(
	EN_IPSDK_ERP_DATA_TYPE enDataType,
	IPSDK_PChar pstrOutMastchers,
	IPSDK_Int nMaxLen,
	IPSDK_PVoid lParam)
{
	IPSDK_Char strMatch01[128] = { 0 };
	/// 指定查询mac未烧录的
	if (EN_IPSDK_ERP_DATA_TYPE_MAC == enDataType)
	{
		/// 查询条件:按是否下载条件查询
		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000002", 2, "false"));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_UUID == enDataType)
	{
		/// 查询条件:按是否下载条件查询
		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000003", 2, "false"));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_COMPUTER == enDataType)
	{
		IPSDK_ERP_UserInfo* pstUserInfo = (IPSDK_ERP_UserInfo*)lParam;
		CHECK_POINTER_ERR_RET(pstUserInfo, IPSDK_FAILURE);
		/// 查询条件:按是否下载条件查询
		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000004", 2, pstUserInfo->strUserSeqNo));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_DEVICE == enDataType)
	{
		/// 查询条件:是否指定设备型号是否禁用
		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000002", 2, "false"));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_LOG == enDataType)
	{
		IPSDK_ERP_UserInfo* pstUserInfo = (IPSDK_ERP_UserInfo*)lParam;
		CHECK_POINTER_ERR_RET(pstUserInfo, IPSDK_FAILURE);

		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000002", 2, pstUserInfo->strUserName));
	}
	else if (EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE == enDataType)
	{
		IPSDK_ERP_UserInfo* pstUserInfo = (IPSDK_ERP_UserInfo*)lParam;
		CHECK_POINTER_ERR_RET(pstUserInfo, IPSDK_FAILURE);
		memset(pstrOutMastchers, 0, nMaxLen);
		snprintf(pstrOutMastchers, nMaxLen, "%s",
			NETSDK_ERP_MakeMatchers(strMatch01, sizeof(strMatch01), "And", "Item", "F0000001", 2, pstUserInfo->strUserSeqNo));

	}
	return IPSDK_SUCCESS;
}

static IPSDK_Int _Create_GetBizObject(
	EN_IPSDK_ERP_DATA_TYPE enDataType,
	IPSDK_PVoid pDataInfo,
	IPSDK_Int nDataLen,
	IPSDK_PChar pstrOutBizObject,
	IPSDK_Int nOutLen,
	IPSDK_PVoid lParam)
{
	switch (enDataType)
	{
		case EN_IPSDK_ERP_DATA_TYPE_LOG:
		{
			IPSDK_ERP_LogInfo* pLogInfo = (IPSDK_ERP_LogInfo*)pDataInfo;
			CHECK_POINTER_ERR_RET(pLogInfo, IPSDK_FAILURE);
			/// 更新电脑mac信息
			snprintf(pstrOutBizObject, nOutLen,
				"{\"CreatedBy\":\"%s\","
				"\"OwnerId\":\"%s\","
				"\"F0000001\":\"%s\","
				"\"F0000002\":\"%s\","
				"\"F0000003\":\"%s\"}",
				pLogInfo->strCreatedBy,
				pLogInfo->strOwnerId,
				pLogInfo->strLogDate,
				pLogInfo->strProduceDate,
				pLogInfo->strUserSeqNo);
		}
		break;
	default:
		return IPSDK_FAILURE;
	}
	return IPSDK_SUCCESS;
}

static IPSDK_Int _GetBizObject(
	EN_IPSDK_ERP_DATA_TYPE enDataType,
	IPSDK_PVoid pDataInfo,
	IPSDK_Int nDataLen,
	IPSDK_PChar pstrOutBizObject,
	IPSDK_Int nOutLen,
	IPSDK_PVoid lParam)
{
	switch (enDataType)
	{
		case EN_IPSDK_ERP_DATA_TYPE_MAC:
			{
				IPSDK_ERP_MacInfo* pMacAddr = (IPSDK_ERP_MacInfo*)pDataInfo;
				CHECK_POINTER_ERR_RET(pMacAddr, IPSDK_FAILURE);
				/// 更新已经下载标识
				snprintf(pstrOutBizObject, nOutLen,
					"{\"CreatedBy\":\"%s\","
					"\"OwnerId\":\"%s\","
					"\"F0000002\":\"%s\","
					"\"F0000004\":\"%s\"}",
					pMacAddr->strCreatedBy,
					pMacAddr->strOwnerId,
					pMacAddr->bDownLoad ? "true" : "false",
					pMacAddr->strDownLoadDate);
			}
			break;
		case EN_IPSDK_ERP_DATA_TYPE_UUID:
			{
				IPSDK_ERP_UuidInfo* pUuidInfo = (IPSDK_ERP_UuidInfo*)pDataInfo;
				CHECK_POINTER_ERR_RET(pUuidInfo, IPSDK_FAILURE);
				/// 更新已经下载标识
				snprintf(pstrOutBizObject, nOutLen,
					"{\"CreatedBy\":\"%s\","
					"\"OwnerId\":\"%s\","
					"\"F0000003\":\"%s\","
					"\"F0000004\":\"%s\"}",
					pUuidInfo->strCreatedBy,
					pUuidInfo->strOwnerId,
					pUuidInfo->bDownLoad ? "true" : "false",
					pUuidInfo->strDownLoadDate);
			}
			break;
		case EN_IPSDK_ERP_DATA_TYPE_COMPUTER:
			{
				IPSDK_ERP_ComputerBindInfo* pComputerBindInfo = (IPSDK_ERP_ComputerBindInfo*)pDataInfo;
				CHECK_POINTER_ERR_RET(pComputerBindInfo, IPSDK_FAILURE);
				/// 更新电脑mac信息
				snprintf(pstrOutBizObject, nOutLen,
					"{\"CreatedBy\":\"%s\","
					"\"OwnerId\":\"%s\","
					"\"F0000001\":\"%s\","
					"\"F0000002\":\"%s\","
					"\"F0000003\":\"%s\"}",
					pComputerBindInfo->strCreatedBy,
					pComputerBindInfo->strOwnerId,
					pComputerBindInfo->strBindMacAddr,
					pComputerBindInfo->bUsed ? "true" : "false",
					pComputerBindInfo->strLoginDate);
			}
			break;
		case EN_IPSDK_ERP_DATA_TYPE_DEVICE:
			{
				IPSDK_ERP_DeviceInfo* pDeviceInfo = (IPSDK_ERP_DeviceInfo*)pDataInfo;
				CHECK_POINTER_ERR_RET(pDeviceInfo, IPSDK_FAILURE);
				/// 设备型号是固定的，不允许更新,删除，创建
			}
			break;
		case EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE:
			{
			}
			break;
		default:
			return IPSDK_FAILURE;
	}
	return IPSDK_SUCCESS;
}

int main(int argc, char* argv[])
{
	IPSDK_Int i = 0;
	IPSDK_Int ii = 0;
	IPSDK_Int nRet = NETSDK_Init();

	IPSDK_PVoid hLogin = NETSDK_ERP_Login("zeng","123456", "13460345743");
	CHECK_POINTER_ERR_RET(hLogin, IPSDK_FAILURE);

	IPSDK_ERP_UserInfo* pstUserInfo = NETSDK_ERP_GetCurUserInfo(hLogin);

/**
** 数据条件查询内容
**/
	{
		/// 获取MAC信息
		IPSDK_ERP_QUERY_EVENT stQueryEvent;
		memset(&stQueryEvent, 0, sizeof(IPSDK_ERP_QUERY_EVENT));
		stQueryEvent.GetFilterValue = _MacAddr_GetFilterValue;
		stQueryEvent.GetMatchers = _MacAddr_GetMatchers;
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_MAC,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);

		/// 获取UUID信息
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_UUID,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);

		/// 获取设备型号信息
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_DEVICE,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);

		/// 获取电脑绑定表信息
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_COMPUTER,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);

		/// 获取日志表信息
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_LOG,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);
#if 0
		/// 获取日志表信息
		nRet = NETSDK_ERP_QueryDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_INDEX_USER_DEVICE,
			&stQueryEvent,
			_Erp_Read_QueryDbCallBack,
			pstUserInfo);
		CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);
#endif
	}
/**
** 创建日志信息上传
**/
	{
#define UPLOAD_LOG_TABLE 1
#if 1 //UPLOAD_LOG_TABLE

		IPSDK_Int i = 0;
		for (i = 0; i < 5; i++)
		{
			IPSDK_ERP_UPDATE_EVENT stUpdateEvent;
			stUpdateEvent.GetBizObject = _Create_GetBizObject;
			IPSDK_ERP_LogInfo* pstLogInfo = &g_erp_client_context.stLogInfo[0];
			snprintf(pstLogInfo->strLogDate, sizeof(pstLogInfo->strLogDate), "2022-8-%d", i);

			IPSDK_ERP_UserInfo* pstUserInfo = NETSDK_ERP_GetCurUserInfo(hLogin);
			snprintf(pstLogInfo->strCreatedBy, sizeof(pstLogInfo->strCreatedBy), "%s", pstUserInfo->strCreatedBy);
			snprintf(pstLogInfo->strOwnerId, sizeof(pstLogInfo->strOwnerId), "%s", pstUserInfo->strOwnerId);

			nRet = NETSDK_ERP_CreateDataBase(
				hLogin,
				EN_IPSDK_ERP_DATA_TYPE_LOG,
				pstLogInfo,
				sizeof(IPSDK_ERP_LogInfo),
				&stUpdateEvent,
				IPSDK_NULL);
			CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);
		}
#endif
	}


/**
** 数据更新内容
**/
	{
#if 0
		/// 获取MAC信息
		IPSDK_ERP_UPDATE_EVENT stUpdateEvent;
		stUpdateEvent.GetBizObject = _GetBizObject;
		IPSDK_ERP_MacInfo* pstMacInfo = &g_erp_client_context.stMacInfo[0];
		pstMacInfo->bDownLoad = IPSDK_TRUE;
		snprintf(pstMacInfo->strDownLoadDate, sizeof(pstMacInfo->strDownLoadDate), "%s", "2022-6-29 22:37");
		NETSDK_ERP_ModifyDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_MAC,
			pstMacInfo,
			sizeof(IPSDK_ERP_MacInfo),
			&stUpdateEvent,
			IPSDK_NULL);

		/// 获取UUID信息
		IPSDK_ERP_UuidInfo* pstUuidInfo = &g_erp_client_context.stUuidInfo[0];
		pstUuidInfo->bDownLoad = IPSDK_TRUE;
		snprintf(pstUuidInfo->strDownLoadDate, sizeof(pstUuidInfo->strDownLoadDate), "%s", "2022-6-29 22:37");
		NETSDK_ERP_ModifyDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_UUID,
			pstUuidInfo,
			sizeof(IPSDK_ERP_UuidInfo),
			&stUpdateEvent,
			IPSDK_NULL);
		/// 获取电脑绑定表信息
		IPSDK_ERP_ComputerBindInfo* pstComputerBindInfo = &g_erp_client_context.stComputerBindInfo[0];
		pstComputerBindInfo->bUsed = IPSDK_TRUE;
		snprintf(pstComputerBindInfo->strBindMacAddr, sizeof(pstComputerBindInfo->strBindMacAddr), "%s", "00:01:02:03:04:05");
		snprintf(pstComputerBindInfo->strLoginDate, sizeof(pstComputerBindInfo->strLoginDate), "%s", "2022-6-29 22:37");
		NETSDK_ERP_ModifyDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_COMPUTER,
			pstComputerBindInfo,
			sizeof(IPSDK_ERP_ComputerBindInfo),
			&stUpdateEvent,
			IPSDK_NULL);
#endif
#if 0
		/// 获取Device信息
		IPSDK_ERP_DeviceInfo* pstDeviceInfo = &g_erp_client_context.stDeviceInfo[0];
		NETSDK_ERP_ModifyDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_DEVICE,
			pstDeviceInfo,
			sizeof(IPSDK_ERP_DeviceInfo),
			&stUpdateEvent,
			IPSDK_NULL);

		/// 获取电脑绑定表信息
		IPSDK_ERP_LogInfo* pstLogInfo = &g_erp_client_context.stLogInfo[0];
		NETSDK_ERP_ModifyDataBase(
			hLogin,
			EN_IPSDK_ERP_DATA_TYPE_LOG,
			pstLogInfo,
			sizeof(IPSDK_ERP_LogInfo),
			&stUpdateEvent,
			IPSDK_NULL);
#endif
		/// 更新MAC信息
		/// 更新UUID信息
		/// 更新MAC信息
	}

	while (1)
	{
#if defined(OS_WINDOWS)
		Sleep(2 * 1000);
#else
		sleep(2);
#endif
		break;
	}
	NETSDK_Cleanup();

	return 0;
}

