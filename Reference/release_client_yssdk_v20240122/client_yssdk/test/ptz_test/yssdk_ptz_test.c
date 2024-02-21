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

//#define USE_SNAPSHOT

#ifdef USE_SNAPSHOT
static IPSDK_Int _SnapshotCallBack(IPSDK_CPChar pDataBuf, IPSDK_Int nDataLen, IPSDK_PVoid pUser)
{
	IPSDK_DEBUG("Snapshot data len:%d", nDataLen);
	FILE* pFile = fopen("snapshot.jpg", "wb+");
	if (IPSDK_NULL != pFile && IPSDK_NULL != pDataBuf)
	{
		fwrite(pDataBuf, nDataLen, 1, pFile);
		fclose(pFile);
	}
	return IPSDK_SUCCESS;
}
#endif

static IPSDK_Int _ProductTestCallBack(IPSDK_Int nTestId, IPSDK_Int nCode, IPSDK_CPChar pResultJson, IPSDK_PVoid pUser)
{
	IPSDK_DEBUG("nTestId:%d,nCode:%d,pResultJson:%s", nTestId, nCode, (IPSDK_NULL == pResultJson) ? "" : pResultJson);
	return IPSDK_SUCCESS;
}


int main(int argc, char* argv[])
{
	IPSDK_Char cmd = 0;
	IPSDK_Int nTestId = 80;
	IPSDK_Int nSpeed = 10;
	IPSDK_Int nSessionPort = 9980;
	IPSDK_Int nStreamPort = 1680;
	IPSDK_Char strHostAddr[32] = {"192.168.1.123"};
	IPSDK_Char strUserName[64] = {"admin"};
	IPSDK_Char strPassword[64] = {""};
	IPSDK_Char strParamJson[128];
	IPSDK_PChar pDirection = IPSDK_NULL;
	IPSDK_Int nRet = NETSDK_Init();

	if (argc < 3)
	{
		printf("Usage:\n");
		printf("eg: %s host_addr [192.168.1.123] session_port [9980]\n", argv[0]);
		return 0;
	}

	snprintf(strHostAddr, sizeof(strHostAddr), "%s", argv[1]);
	printf("Test IPC IP address: %s\n", strHostAddr);

	nSessionPort = atoi(argv[2]);
	
	IPSDK_HLOGIN hLogin = NETSDK_Login(
		strHostAddr,
		nSessionPort,
		nStreamPort,
		strUserName,
		strPassword,
		IPSDK_NULL);
	CHECK_POINTER_ERR_RET(hLogin, IPSDK_FAILURE);

#ifdef USE_SNAPSHOT
	IPSDK_ChannelInfo stChannelInfo;
	stChannelInfo.nChannel = 0;
	stChannelInfo.nStream = 0;
	nRet = NETSDK_Snapshot(hLogin, &stChannelInfo, _SnapshotCallBack, IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		printf("Snapshot successfully!\r\n");
	}
#endif

	printf("Type \"q\" to exit,\n");
	printf("\"u\" to up direction of pan tilt,\n");
	printf("\"d\" to down direction of pan tilt,\n");
	printf("\"l\" to left direction of pan tilt,\n");
	printf("\"r\" to right direction of pan tilt,\n");
	printf("\"s\" to stop pan tilt.\n");

	while (1)
	{
		cmd = getchar();
		if ('q' == cmd)
		{
			break;
		}
		else if('u' == cmd)
		{
			nTestId = 80;
			pDirection = "up";
		}
		else if('d' == cmd)
		{
			nTestId = 80;
			pDirection = "down";
		}
		else if('l' == cmd)
		{
			nTestId = 80;
			pDirection = "left";
		}
		else if('r' == cmd)
		{
			nTestId = 80;
			pDirection = "right";
		}
		else if('s' == cmd)
		{
			nTestId = 81;
			strParamJson[0] = '\0';
		}
		else
		{
			continue;
		}
		if (80 == nTestId)
		{
			snprintf(strParamJson, sizeof(strParamJson),
			"{\"direction\":\"%s\",\"speed\":%d}", pDirection, nSpeed);
		}
		nRet = NETSDK_ProductTest(hLogin,
			nTestId,
			_ProductTestCallBack,
			strParamJson,
			IPSDK_NULL);
		if (IPSDK_FAILURE == nRet)
		{
			printf("Product Test failure! \r\n");
		}
	}

	NETSDK_Logout(hLogin);
	NETSDK_Cleanup();

	return 0;
}

