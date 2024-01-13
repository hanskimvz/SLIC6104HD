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
#include "ipsdk_media_def.h"

#include "sys/system.h"


static IPSDK_SearchDevice g_stSearchDevice[32];
static IPSDK_Int g_nCnt = 0;

IPSDK_Int _SearchDevCallBack(IPSDK_Int nStateCode, IPSDK_SearchDevice* pSearchDevice, IPSDK_PVoid pUser)
{
	CHECK_POINTER_ERR_RET(pSearchDevice, IPSDK_FAILURE);

	printf("SessionPort:%d,StreamPort=%d\n", pSearchDevice->stLanInfo.nSessionPort, pSearchDevice->stLanInfo.nStreamPort);
	printf("DevHardVer:%s\n", pSearchDevice->stDeviceInfo.strDevHardVer);
	printf("DevCloudId:%s\n", pSearchDevice->stDeviceInfo.strDevCloudId);
	printf("DeviceId:%s\n", pSearchDevice->strDeviceId);
	printf("DeviceMode:%d\n", pSearchDevice->nDeviceMode);
	printf("AllNetConnect:%s\n", (EN_IPSDK_ALL_NET_CONNECT_ON == pSearchDevice->stLanInfo.Lan[0].enAllNetConnect) ? "true" : "false");
	printf("UserName:%s,Password:%s\n", pSearchDevice->stUserInfo.strUserName, pSearchDevice->stUserInfo.strPassword);

	memcpy(&g_stSearchDevice[g_nCnt], pSearchDevice, sizeof(g_stSearchDevice[g_nCnt]));
	g_nCnt++;
	if (g_nCnt >= sizeof(g_stSearchDevice) / sizeof(g_stSearchDevice[0]))
	{
		g_nCnt = 0;
	}

	return IPSDK_SUCCESS;
}
IPSDK_Int _SearchStatusEvent(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam)
{
	IPSDK_DEBUG("[_SearchStatusEvent] nStateCode:%d,DeviceId:%s", nStateCode, (IPSDK_NULL == pResponse) ? "" : pResponse);

	return IPSDK_SUCCESS;
}
IPSDK_Int SetLicenseStatusEvent(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam)
{
	IPSDK_DEBUG("[SetLicenseStatusEvent] nStateCode:%d,DeviceId:%s", nStateCode, (IPSDK_NULL == pResponse) ? "" : pResponse);

	return IPSDK_SUCCESS;
}
IPSDK_Int ProductCmdStatusEvent(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam)
{
	IPSDK_DEBUG("[ProductCmdStatusEvent] nStateCode:%d,DeviceId:%s", nStateCode, (IPSDK_NULL == pResponse) ? "" : pResponse);

	return IPSDK_SUCCESS;
}

static FILE* g_RecordFile[5];
static IPSDK_UInt32 g_FrameSeq[5];
static IPSDK_Int g_FrameFirst[5];
static IPSDK_Int _RealStreamCallBack(IPSDK_HANDLE lRealHandle, IPSDK_Int nChannel, IPSDK_Int nStream, IPSDK_Int nDataType,  IPSDK_PChar pDataBuf, IPSDK_Int nDataLen, IPSDK_PVoid pUserBuf)
{
	static IPSDK_Int nFrameFirst = 0;
	if (NULL == pDataBuf)
	{
		return IPSDK_FAILURE;
	}
	// 2:直播流 6:回放流
	if (2 == nDataType || 6 == nDataType)
	{
		IPSDK_MediaFrame* pMediaFrame = (IPSDK_MediaFrame*)pDataBuf;
		IPSDK_PChar pMediaBuf = IPSDK_NULL;
		if (EN_IPSDK_MEDIA_DATA_H264 == pMediaFrame->enMediaType)
		{
			if (0 == nFrameFirst && EN_IPSDK_FRAME_TYPE_I == pMediaFrame->h264.u32FrameType)
			{
				if (IPSDK_NULL == g_RecordFile[nChannel])
				{
					char strFile[16] = { 0 };
					snprintf(strFile, sizeof(strFile), "%s_%d_%d.h264", "H264", nChannel, nStream);
					g_RecordFile[nChannel] = fopen(strFile, "wb");
					g_FrameSeq[nChannel] = 0;
					nFrameFirst = 1;
				}
			}

			if (1 == nFrameFirst)
			{
				printf("[h264]u32FrameSeq:%d,u32DataLen:%d,media_frame_len:%lu\n", pMediaFrame->h265.u32FrameSeq, pMediaFrame->u32DataLen,sizeof(IPSDK_MediaFrame));
				printf("type:%d,u32FrameSeq:%d,u32FrameRate:%d, w:%d,h:%d \n", 
					pMediaFrame->h265.u32FrameType,
					pMediaFrame->h265.u32FrameSeq,
					pMediaFrame->h265.u32FrameRate,
					pMediaFrame->h265.u32Width, pMediaFrame->h265.u32Height);

				pMediaBuf = pDataBuf + sizeof(IPSDK_MediaFrame);
				fwrite(pMediaBuf, 1, pMediaFrame->u32DataLen, g_RecordFile[nChannel]);
			}
		}
		else if (EN_IPSDK_MEDIA_DATA_H265 == pMediaFrame->enMediaType)
		{
			if (0 == nFrameFirst && EN_IPSDK_FRAME_TYPE_I == pMediaFrame->h265.u32FrameType)
			{
				if (IPSDK_NULL == g_RecordFile[nChannel])
				{
					char strFile[16] = { 0 };
					snprintf(strFile, sizeof(strFile), "%s_%d_%d.H265", "H265", nChannel, nStream);
					g_RecordFile[nChannel] = fopen(strFile, "wb");
					g_FrameSeq[nChannel] = 0;
					nFrameFirst = 1;
				}
			}
			if (1 == nFrameFirst)
			{
				printf("[h265]u32FrameSeq:%d,u32DataLen:%d,media_frame_len:%lu\n", pMediaFrame->h265.u32FrameSeq, pMediaFrame->u32DataLen, sizeof(IPSDK_MediaFrame));
				printf("type:%d,u32FrameSeq:%d,u32FrameRate:%d, w:%d,h:%d \n",
					pMediaFrame->h265.u32FrameType,
					pMediaFrame->h265.u32FrameSeq,
					pMediaFrame->h265.u32FrameRate,
					pMediaFrame->h265.u32Width, pMediaFrame->h265.u32Height);
				pMediaBuf = pDataBuf + sizeof(IPSDK_MediaFrame);
				fwrite(pMediaBuf, 1, pMediaFrame->u32DataLen, g_RecordFile[nChannel]);
#if 0
				int i = 0;
				printf("vvps_buf:start\n");
				for (i = 0; i < pMediaFrame->media_info.vvps_len; i++)
				{
					printf("0x%x ", pMediaFrame->media_info.vvps_buf[i]);
				}
				printf("\n vvps_buf:end\n");
				printf("vsps_buf:start\n");
				for (i = 0; i < pMediaFrame->media_info.vsps_len; i++)
				{
					printf("0x%x ", pMediaFrame->media_info.vsps_buf[i]);
				}
				printf("\n vsps_buf:end\n");
				printf("vpss:start\n");
				for (i = 0; i < pMediaFrame->media_info.vpps_len; i++)
				{
					printf("0x%x ", pMediaFrame->media_info.vpps_buf[i]);
				}
				printf("\n vpss:start\n");
#endif 
			}
		}
		else if (EN_IPSDK_MEDIA_DATA_G711U == pMediaFrame->enMediaType ||
			EN_IPSDK_MEDIA_DATA_G711A == pMediaFrame->enMediaType ||
			EN_IPSDK_MEDIA_DATA_AAC == pMediaFrame->enMediaType)
		{
			//printf("pMediaFrame->enMediaType:0x%x\n", pMediaFrame->enMediaType);
			printf("[audio]media_frame_len:%u\n", pMediaFrame->u32DataLen);

		}
	}
	return IPSDK_SUCCESS;
}
static IPSDK_Int _UpgradeRateCallBack(IPSDK_Int nUpgradeRate, IPSDK_PChar pstrHostAddr, IPSDK_PVoid lParam)
{
	IPSDK_DEBUG("nUpgradeRate:%d,HostAddr:%s", nUpgradeRate, (IPSDK_NULL == pstrHostAddr) ? "" : pstrHostAddr);
	return IPSDK_SUCCESS;
}
static IPSDK_Int _Stream_StatusEventCallBack(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam)
{
	printf("[_Stream_StatusEventCallBack] nStateCode:%d \n", nStateCode);
	return IPSDK_SUCCESS;
}
static IPSDK_Int _ProductTestCallBack(IPSDK_Int nTestId, IPSDK_Int nCode, IPSDK_CPChar pResultJson, IPSDK_PVoid pUser)
{
	IPSDK_DEBUG("nTestId:%d,nCode:%d,pResultJson:%s", nTestId, nCode, (IPSDK_NULL == pResultJson) ? "" : pResultJson);
	return IPSDK_SUCCESS;
}
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

static IPSDK_Int _NotifyCallback(const IPSDK_Notification *pNotif, IPSDK_PVoid pUser)
{
	CHECK_POINTER_ERR_RET(pNotif, IPSDK_FAILURE);
	IPSDK_DEBUG("type:%#x, utc=%llu", pNotif->enType, pNotif->u64UTC);
	return IPSDK_SUCCESS;
}


int main(int argc, char* argv[])
{
	IPSDK_Int i = 0;
	IPSDK_Int ii = 0;
	IPSDK_Int nRet = NETSDK_Init();

#if 1
	// 接受命令行第一个参数为目标IPC的IP地址，便于测试
	char test_ipc[30] = {"192.168.13.136"};
	if (argc > 1){
		strncpy (test_ipc, argv[1], sizeof(test_ipc)/sizeof(char));
	}
	printf("Test IPC IP address: %s\n", test_ipc);

#if 1
	IPSDK_ULong bindAddr = 0; // 2365696192 == 192.168.1.141
	NETSDK_SearchDevice(_SearchDevCallBack, NULL, 5, bindAddr);
#else
	for (i = 0; i < g_nCnt; i++)
	{
		snprintf(g_stSearchDevice[i].stLanInfo.Lan[0].strMask, sizeof(g_stSearchDevice[i].stLanInfo.Lan[0].strMask), "%s", "255.255.0.0");
		g_stSearchDevice[i].stLanInfo.Lan[0].enAllNetConnect = EN_IPSDK_ALL_NET_CONNECT_ON;
		if (0 == strcmp(g_stSearchDevice[i].stLanInfo.Lan[0].strIpAddr, "192.168.1.123"))
		{
			NETSDK_SetDeviceConfig(_SearchStatusEvent, NULL, &g_stSearchDevice[i], 1, 5, bindAddr);

			IPSDK_LicenseInfo stLicenseInfo;
			memset(&stLicenseInfo, 0, sizeof(stLicenseInfo));
			snprintf(stLicenseInfo.strDeviceId, sizeof(stLicenseInfo.strDeviceId), "%s", g_stSearchDevice[i].strDeviceId);
			snprintf(stLicenseInfo.strCloudUuid, sizeof(stLicenseInfo.strCloudUuid), "%s", "YYDSNOTHINGISIMPOSSIBLE");
			snprintf(stLicenseInfo.strSerialId, sizeof(stLicenseInfo.strSerialId), "%s", "1234567890ABCDEFG");
			snprintf(stLicenseInfo.strMacAddr, sizeof(stLicenseInfo.strMacAddr), "%s", "12:34:56:78:9A:BC");
			NETSDK_SetLicenseConfig(SetLicenseStatusEvent, NULL, &stLicenseInfo, 1, 5, bindAddr);

			IPSDK_CommandInfo stCmdInfo;
			memset(&stCmdInfo, 0, sizeof(stCmdInfo));
			snprintf(stCmdInfo.strDeviceId, sizeof(stCmdInfo.strDeviceId), "%s", g_stSearchDevice[i].strDeviceId);
			stCmdInfo.enProductCmd = EN_IPSDK_PRODUCT_CMD_DELETE_LICENSE;
			NETSDK_ProductCommand(ProductCmdStatusEvent, NULL, &stCmdInfo, 1, 5, bindAddr);
		}
	}
#endif

#if 1
	IPSDK_Char DataBuf[2*1024] = {0};
	IPSDK_Int nDataLen = sizeof(DataBuf);

	IPSDK_ChannelInfo stChannelInfo;
	stChannelInfo.nChannel = 0;
	stChannelInfo.nStream = 0;

	IPSDK_HLOGIN hLogin = NETSDK_Login(
		test_ipc,

		g_stSearchDevice[0].stLanInfo.nSessionPort,
		g_stSearchDevice[0].stLanInfo.nStreamPort,
		g_stSearchDevice[0].stUserInfo.strUserName,
		g_stSearchDevice[0].stUserInfo.strPassword,

		IPSDK_NULL);
	CHECK_POINTER_ERR_RET(hLogin, IPSDK_FAILURE);
#if 1
	IPSDK_Int nOsdCnt = 0;
	IPSDK_OsdRefresh stOsdRefresh;
	IPSDK_HOSDREFRESH hOsdRefresh = NULL;
	hOsdRefresh = NETSDK_OsdRefreshStart(hLogin);
	if (IPSDK_NULL != hOsdRefresh)
	{
		memset(&stOsdRefresh, 0, sizeof(stOsdRefresh));
		stOsdRefresh.enType = EN_IPSDK_OSDREFRESH_TYPE_TEXT;
		while (nOsdCnt++ < 100)
		{
			stOsdRefresh.nIndex = nOsdCnt % 3;
			if (nOsdCnt % 2)
			{
				snprintf(stOsdRefresh.strText, sizeof(stOsdRefresh.strText), "%s", "12345678909876543210");
			}
			else
			{
				snprintf(stOsdRefresh.strText, sizeof(stOsdRefresh.strText), "%s", "ASCIIforChineseNo peace");
			}
			if ((nRet = NETSDK_OsdRefreshSend(hOsdRefresh, &stOsdRefresh)) < 0)
			{
				printf("intercom send data failed,ret=%d\n", nRet);
				break;
			}
			printf("osdrefresh total length of send data=%d\n", nRet);
			system_sleep(400);
		}
		NETSDK_OsdRefreshStop(hOsdRefresh);
	}
#endif
#if 1
	nRet = NETSDK_Snapshot(hLogin, &stChannelInfo, _SnapshotCallBack, IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		printf("Snapshot successfully!\n\n");
	}
	nRet = NETSDK_Notify(hLogin, _NotifyCallback, IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		printf("Notify successfully!\r\n");
	}
#if 0
	nRet = NETSDK_ProductTest(hLogin,
		70,
		_ProductTestCallBack,
		IPSDK_NULL,
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		printf("Product Test successfully! \n\n");
	}
#endif 

	IPSDK_HCHANNEL hStream = NETSDK_CreateRealPlay(hLogin, &stChannelInfo);
	CHECK_POINTER_ERR_RET(hStream, IPSDK_FAILURE);

	nRet = NETSDK_StartRealPlay(hStream, _RealStreamCallBack, IPSDK_NULL, 0);
	NETSDK_SetPlayRealPlay(hStream);
	nRet = NETSDK_SetRealStreamStatus(hStream, _Stream_StatusEventCallBack, IPSDK_NULL);

#else
	IPSDK_PlaybackInfo stPlaybackInfo;
	memset(&stPlaybackInfo, 0, sizeof(stPlaybackInfo));
	stPlaybackInfo.nChannel = 0;
	stPlaybackInfo.nStream = 0;
	stPlaybackInfo.u64StartTime = 1670314868;
	snprintf(stPlaybackInfo.strSessionId, sizeof(stPlaybackInfo.strSessionId), "%s", "uniqueid");

	IPSDK_HCHANNEL hStream = NETSDK_CreatePlayback(hLogin, &stPlaybackInfo);
	CHECK_POINTER_ERR_RET(hStream, IPSDK_FAILURE);

	nRet = NETSDK_StartPlayback(hStream, _RealStreamCallBack, _Stream_StatusEventCallBack, IPSDK_NULL);
#endif
#define INTERCOM_FILE "./finding_nemo.pcm"
	long len = 0;
	long rlen = 0;
	long off = 0;
	int pksize = 640;
	uint8_t* ptr = NULL;
	IPSDK_HINTERCOM hIntercom = NULL;
	FILE* fp = fopen(INTERCOM_FILE, "rb");
	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		len = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		ptr = (uint8_t*)malloc(len);
		if (NULL != ptr)
		{
			if (len != (rlen = fread(ptr, 1, len, fp)))
			{
				printf("fread(%ld bytes) failed(%ld)\n", len, rlen);
			}
		}
		fclose(fp);
		hIntercom = NETSDK_IntercomCalled(hLogin);
		if (IPSDK_NULL != hIntercom)
		{
			while (off < rlen)
			{
				if ((nRet = NETSDK_IntercomSend(hIntercom, ptr + off, pksize)) < 0)
				{
					printf("intercom send data failed,ret=%d\n", nRet);
					break;
				}
				off += nRet;
				printf("intercom total length of send data=%ld\n", off);
				system_sleep(40);
			}
			NETSDK_IntercomHungUp(hIntercom);
		}
	}

	{
#if 0
		/* 网络配置 */
		IPSDK_Char strHwAddr[24];
		IPSDK_Char strIpv4Addr[24];
		IPSDK_Char strNetMask[24];
		IPSDK_Char strGateway[24];
		IPSDK_NetConfig stNetConfig;
		memset(&stNetConfig, 0, sizeof(stNetConfig));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_CONFIG, &stNetConfig, sizeof(stNetConfig));
		if (IPSDK_SUCCESS == nRet)
		{
			IPSDK_PROP_HWADDR_STR(&stNetConfig.HwAddr, strHwAddr, sizeof(strHwAddr));
			IPSDK_PROP_IPV4_STR(&stNetConfig.IPAddress, strIpv4Addr, sizeof(strIpv4Addr));
			IPSDK_PROP_IPV4_STR(&stNetConfig.Netmask, strNetMask, sizeof(strNetMask));
			IPSDK_PROP_IPV4_STR(&stNetConfig.Gateway, strGateway, sizeof(strGateway));
			printf("strHwAddr:%s \n", strHwAddr);
			printf("bEnableDHCP.val:%d \n", stNetConfig.bEnableDHCP.val);
			printf("strIpv4Addr:%s \n", strIpv4Addr);
			printf("strNetMask:%s \n", strNetMask);
			printf("strGateway:%s \n", strGateway);
			IPSDK_PROP_IPV4_ATON(&stNetConfig.Netmask, "255.255.0.0");
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_CONFIG, &stNetConfig, sizeof(stNetConfig));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set network card configuration successfully! \n\n");
			}
		}

		/* DNS配置 */
		IPSDK_Char strDns1[24];
		IPSDK_Char strDns2[24];
		IPSDK_NetDns stNetDns;
		memset(&stNetDns, 0, sizeof(stNetDns));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_DNS, &stNetDns, sizeof(stNetDns));
		if (IPSDK_SUCCESS == nRet)
		{
			IPSDK_PROP_IPV4_STR(&stNetDns.Preferred, strDns1, sizeof(strDns1));
			IPSDK_PROP_IPV4_STR(&stNetDns.Alternative, strDns2, sizeof(strDns2));
			printf("strDns1:%s \n", strDns1);
			printf("strDns2:%s \n", strDns2);
			IPSDK_PROP_IPV4_ATON(&stNetDns.Preferred, "114.114.114.114");
			IPSDK_PROP_IPV4_ATON(&stNetDns.Alternative, "180.76.76.76");
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_DNS, &stNetDns, sizeof(stNetDns));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set network dns configuration successfully! \n\n");
			}
		}

		/* IP自适应 */
		IPSDK_NetIpAdaption stNetIpadaption;
		memset(&stNetIpadaption, 0, sizeof(stNetIpadaption));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_IPADAPT, &stNetIpadaption, sizeof(stNetIpadaption));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("ipAdapt.val:%d \n", stNetIpadaption.bAutoAdaption.val);
			stNetIpadaption.bAutoAdaption.val = !stNetIpadaption.bAutoAdaption.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_IPADAPT, &stNetIpadaption, sizeof(stNetIpadaption));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set network ipadapt configuration successfully! \n\n");
			}
		}

		/* GB28181配置 */
		IPSDK_NetGB28181 stGB28181;
		memset(&stGB28181, 0, sizeof(stGB28181));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_GB28181, &stGB28181, sizeof(stGB28181));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Gb28181.bEnable.val:%d \n", stGB28181.bEnable.val);
			printf("strServerHost:%u \n", stGB28181.nDevPort);
			printf("strServerID:%s \n", stGB28181.strServerID);
			printf("strServerName:%s \n", stGB28181.strServerName);
			printf("strServerHost:%s \n", stGB28181.strServerHost);
			printf("nServerPort:%u \n", stGB28181.nServerPort);
			printf("strDevName:%s \n", stGB28181.strDevName);
			printf("strDevID:%s \n", stGB28181.strDevID);
			printf("strPasswd:%s \n", stGB28181.strPasswd);
			printf("nExpires:%u \n", stGB28181.nExpires);
			printf("nKeepAlive:%u \n", stGB28181.nKeepAlive);
			printf("nKeepAliveNum:%u \n", stGB28181.nKeepAliveNum);
			printf("nStreamIdx:%u \n", stGB28181.nStreamIdx);
			printf("strVideoID:%s \n", stGB28181.strVideoID[0]);
			printf("strAudioID:%s \n", stGB28181.strAudioID[0]);
			printf("strAlarmID:%s \n", stGB28181.strAlarmID[0]);
			stGB28181.bEnable.val = IPSDK_FALSE;
			stGB28181.nDevPort = 5070;
			stGB28181.nExpires = 3600;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_GB28181, &stGB28181, sizeof(stGB28181));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set network gb28181 configuration successfully! \n\n");
			}
		}

		/* 视频采集配置 */
		IPSDK_VideoIspConfig stVideoIspConfig;
		memset(&stVideoIspConfig, 0, sizeof(stVideoIspConfig));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ISPCONFIG, &stVideoIspConfig, sizeof(stVideoIspConfig));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Vcapture.nBrightness.val:%d \n", stVideoIspConfig.stImageConfig.nBrightness.val);
			printf("nContrast.val:%d \n", stVideoIspConfig.stImageConfig.nContrast.val);
			printf("nSaturation.val:%d \n", stVideoIspConfig.stImageConfig.nSaturation.val);
			printf("nSharpness.val:%d \n", stVideoIspConfig.stImageConfig.nSharpness.val);
			printf("nBacklight.val:%d \n", stVideoIspConfig.stImageConfig.nBacklight.val);
			for (i = 0; i < stVideoIspConfig.stImageConfig.enVideoStandard._Option.entries; i++)
			{
				printf("enVideoStandard.opt[%d]:%d \n", i, stVideoIspConfig.stImageConfig.enVideoStandard._Option.opt[i]);
			}
			printf("enVideoStandard.val:%d \n", stVideoIspConfig.stImageConfig.enVideoStandard.val);
			printf("bHFlip.val:%d \n", stVideoIspConfig.stImageConfig.bHFlip.val);
			printf("bVFlip.val:%d \n", stVideoIspConfig.stImageConfig.bVFlip.val);
			printf("ae.nStep.val:%d \n", stVideoIspConfig.stAdvacedIsp.ae.nStep.val);
			printf("ae.nTolerance.val:%d \n", stVideoIspConfig.stAdvacedIsp.ae.nTolerance.val);
			stVideoIspConfig.stImageConfig.bHFlip.val = !stVideoIspConfig.stImageConfig.bHFlip.val;
			stVideoIspConfig.stImageConfig.bVFlip.val = !stVideoIspConfig.stImageConfig.bVFlip.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ISPCONFIG, &stVideoIspConfig, sizeof(stVideoIspConfig));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video image configuration successfully! \n\n");
			}
		}

		/* OSD配置 */
		IPSDK_VideoOsd stVideoOsd;
		memset(&stVideoOsd, 0, sizeof(stVideoOsd));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_OSD, &stVideoOsd, sizeof(stVideoOsd));
		if (IPSDK_SUCCESS == nRet)
		{
			for (i = 0; i < IPSDK_MAX_EXPAND_TITLE; i++)
			{
				printf("Osd.Title[%d].bEnabled.val:%d \n", i, stVideoOsd.Title[i].bEnabled.val);
				printf("Title[%d].coordinate(%.2f, %.2f) \n", i, stVideoOsd.Title[i].x.val, stVideoOsd.Title[i].y.val);
				printf("Title[%d].strText:%s \n", i, stVideoOsd.Title[i].strText.val);
			}
			printf("Time.bEnabled.val:%d \n", stVideoOsd.Time.bEnabled.val);
			printf("Time.coordinate(%.2f, %.2f) \n", stVideoOsd.Time.x.val, stVideoOsd.Time.y.val);
			printf("Time.bDisplayWeekday.val:%d \n", stVideoOsd.Time.bDisplayWeekday.val);
			printf("Time.bDisplayChinese.val:%d \n", stVideoOsd.Time.bDisplayChinese.val);
			printf("Time.bTimeFormt12HRs.val:%d \n", stVideoOsd.Time.bTimeFormt12HRs.val);
			for (i = 0; i < stVideoOsd.Time.enDateFormat._Option.entries; i++)
			{
				printf("enDateFormat.opt[%d]:%d \n", i, stVideoOsd.Time.enDateFormat._Option.opt[i]);
			}
			printf("Time.enDateFormat.val:%d \n", stVideoOsd.Time.enDateFormat.val);
			for (i = 0; i < stVideoOsd.Time.enTimeFormat._Option.entries; i++)
			{
				printf("enTimeFormat.opt[%d]:%d \n", i, stVideoOsd.Time.enTimeFormat._Option.opt[i]);
			}
			printf("Time.enDateFormat.val:%d \n", stVideoOsd.Time.enTimeFormat.val);
			stVideoOsd.Title[0].x.val = 2;
			stVideoOsd.Title[0].y.val = 92;
			snprintf(stVideoOsd.Title[0].strText.val, sizeof(stVideoOsd.Title[0].strText.val), "%s", "This is a test title.");
			stVideoOsd.Time.x.val = 66;
			stVideoOsd.Time.y.val = 3;
			stVideoOsd.Time.enDateFormat.val = EN_IPSDK_DATEFMT_SLASH_YYYYMMDD;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_OSD, &stVideoOsd, sizeof(stVideoOsd));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video osd configuration successfully! \n\n");
			}
		}

		/* 视频编码参数配置 */
		IPSDK_VideoEncoder stVideoEncoder;
		memset(&stVideoEncoder, 0, sizeof(stVideoEncoder));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ENCODER, &stVideoEncoder, sizeof(stVideoEncoder));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Venc.enCodec:%u \n", stVideoEncoder.enCodec.val);
			printf("enResolution:%u \n", stVideoEncoder.H264.enResolution.val);
			printf("enBitRateCtrlMode:%u \n", stVideoEncoder.H264.enBitRateCtrlMode.val);
			printf("nKeyFrameInterval:%u \n", stVideoEncoder.H264.nKeyFrameInterval.val);
			printf("nBitRate:%d \n", stVideoEncoder.H264.nBitRate.val);
			printf("nFrameRate:%d \n", stVideoEncoder.H264.nFrameRate.val);
			stVideoEncoder.H264.nBitRate.val = 768;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ENCODER, &stVideoEncoder, sizeof(stVideoEncoder));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video encode configuration successfully! \n\n");
			}
		}

		/* 音频输入输出配置 */
		IPSDK_AudioAiao stAudioAiao;
		memset(&stAudioAiao, 0, sizeof(stAudioAiao));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_AIAO, &stAudioAiao, sizeof(stAudioAiao));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Aiao.nSampleRate.val:%d \n", stAudioAiao.nSampleRate.val);
			printf("nSampleBitWidth.val:%d \n", stAudioAiao.nSampleBitWidth.val);
			printf("nInputVolume.val:%d \n", stAudioAiao.nInputVolume.val);
			printf("nOutputVolume.val:%d \n", stAudioAiao.nOutputVolume.val);
			printf("enInputMode.val:%d \n", stAudioAiao.enInputMode.val);
			stAudioAiao.nInputVolume.val = 50;
			stAudioAiao.nOutputVolume.val = 60;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_AIAO, &stAudioAiao, sizeof(stAudioAiao));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set audio aiao configuration successfully! \n\n");
			}
		}

		/* 音频编码器配置 */
		IPSDK_AudioEncoder stAudioEncoder;
		memset(&stAudioEncoder, 0, sizeof(stAudioEncoder));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_ENCODER, &stAudioEncoder, sizeof(stAudioEncoder));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("AEnc.bEnabled.val:%d \n", stAudioEncoder.bEnabled.val);
			printf("enPayload.val:%d \n", stAudioEncoder.enPayload.val);
			stAudioEncoder.bEnabled.val = !stAudioEncoder.bEnabled.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_ENCODER, &stAudioEncoder, sizeof(stAudioEncoder));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set audio encode configuration successfully! \n\n");
			}
		}

		/* 音频解码器配置 */
		IPSDK_AudioDecoder stAudioDecoder;
		memset(&stAudioDecoder, 0, sizeof(stAudioDecoder));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_DECODER, &stAudioDecoder, sizeof(stAudioDecoder));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("ADec.bEnabled.val:%d \n", stAudioDecoder.bEnabled.val);
			printf("enPayload.val:%d \n", stAudioDecoder.enPayload.val);
			stAudioDecoder.bEnabled.val = !stAudioDecoder.bEnabled.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_DECODER, &stAudioDecoder, sizeof(stAudioDecoder));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set audio decode configuration successfully! \n\n");
			}
		}

		/* 视频遮盖配置 */
		IPSDK_VideoMask stVideoMask;
		memset(&stVideoMask, 0, sizeof(stVideoMask));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MASK, &stVideoMask, sizeof(stVideoMask));
		if (IPSDK_SUCCESS == nRet)
		{
			for (i = 0; i < 4; i++)
			{
				printf("Mask.bEnabled.val:%d \n", stVideoMask.Mask[i].bEnabled.val);
				printf("nColor.val:%06X \n", stVideoMask.Mask[i].nColor.val);
				printf("coordinate:(%.2f, %.2f, %.2f, %.2f) \n",
					stVideoMask.Mask[i].x.val,
					stVideoMask.Mask[i].y.val,
					stVideoMask.Mask[i].width.val,
					stVideoMask.Mask[i].height.val);
			}
			stVideoMask.Mask[0].bEnabled.val = !stVideoMask.Mask[0].bEnabled.val;
			stVideoMask.Mask[0].x.val = 25;
			stVideoMask.Mask[0].y.val = 25;
			stVideoMask.Mask[0].width.val = 25;
			stVideoMask.Mask[0].height.val = 25;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MASK, &stVideoMask, sizeof(stVideoMask));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video mask configuration successfully! \n\n");
			}
		}

		/* 人形识别配置 */
		IPSDK_VideoHuman stVideoHuman;
		memset(&stVideoHuman, 0, sizeof(stVideoHuman));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_HUMAN, &stVideoHuman, sizeof(stVideoHuman));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("VideoHuman.bEnable.val:%d \n", stVideoHuman.bEnable.val);
			printf("nSensitivity.val:%d \n", stVideoHuman.nSensitivity.val);
			stVideoHuman.nSensitivity.val = 66;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_HUMAN, &stVideoHuman, sizeof(stVideoHuman));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video human configuration successfully! \n\n");
			}
		}

		/* ROI配置 */
		IPSDK_RoiConfig stRoiConfig;
		memset(&stRoiConfig, 0, sizeof(stRoiConfig));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ROICONFIG, &stRoiConfig, sizeof(stRoiConfig));
		if (IPSDK_SUCCESS == nRet)
		{
			for (i = 0; i < IPSDK_ROI_MAX_ENT; i++)
			{
				printf("RoiConfig.bEnable.val:%d \n", stRoiConfig.RoiCfg[i].bEnable.val);
				printf("nDefaultColor.val:%06X \n", stRoiConfig.RoiCfg[i].nDefaultColor.val);
				printf("nAlarmColor.val:%06X \n", stRoiConfig.RoiCfg[i].nAlarmColor.val);
				printf("nDotTotal.val:%d \n", stRoiConfig.RoiCfg[i].nDotTotal.val);
				for (ii = 0; ii < IPSDK_ROI_DOT_MAX_ENT; ii++)
				{
					printf("coordinate(%.2f, %.2f) \n", stRoiConfig.RoiCfg[i].stDot[ii].x.val, stRoiConfig.RoiCfg[i].stDot[ii].y.val);
				}
			}
			stRoiConfig.RoiCfg[0].bEnable.val = !stRoiConfig.RoiCfg[0].bEnable.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ROICONFIG, &stRoiConfig, sizeof(stRoiConfig));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video roi configuration successfully! \n\n");
			}
		}

		/* 告警提示音配置 */
		IPSDK_AlarmTone stAlarmTone;
		memset(&stAlarmTone, 0, sizeof(stAlarmTone));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ALARMTONE, &stAlarmTone, sizeof(stAlarmTone));
		if (IPSDK_SUCCESS == nRet)
		{
			for (i = 0; i < IPSDK_ALARM_TONE_MAX_ENT; i++)
			{
				printf("AlarmTone.bDisplay.val:%d \n", stAlarmTone.AlarmTone[i].bDisplay.val);
				printf("nRepeatTimes.val:%d \n", stAlarmTone.AlarmTone[i].nRepeatTimes.val);
				printf("nRoiIndex.val:%d \n", stAlarmTone.AlarmTone[i].nRoiIndex.val);
				printf("enToneType.val:%d \n", stAlarmTone.AlarmTone[i].enToneType.val);
				printf("stSchedule.bEnable.val:%d \n", stAlarmTone.AlarmTone[i].stSchedule.bEnable.val);
				printf("stSchedule.nStartTime.val:%d \n", stAlarmTone.AlarmTone[i].stSchedule.nStartTime.val);
				printf("stSchedule.nStopTime.val:%d \n", stAlarmTone.AlarmTone[i].stSchedule.nStopTime.val);
				printf("stSchedule.nWeekday.val:%d \n", stAlarmTone.AlarmTone[i].stSchedule.nWeekday.val);
				printf("stSchedule.nType.val:%d \n", stAlarmTone.AlarmTone[i].stSchedule.nType.val);
			}
			stAlarmTone.AlarmTone[0].bDisplay.val = !stAlarmTone.AlarmTone[0].bDisplay.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ALARMTONE, &stAlarmTone, sizeof(stAlarmTone));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video alarm tone configuration successfully! \n\n");
			}

			/* 告警提示音试听 */
			EN_IPSDK_AlarmToneType enToneType = stAlarmTone.AlarmTone[0].enToneType.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_ALARMTONE_PLAY, &enToneType, sizeof(enToneType));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Play alarm tone successfully! \n\n");
			}
		}

		/* 告警联动配置 */
		IPSDK_AlarmLinkage stAlarmLinkage;
		memset(&stAlarmLinkage, 0, sizeof(stAlarmLinkage));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_ALARM_LINKAGE, &stAlarmLinkage, sizeof(stAlarmLinkage));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("AlarmLinkage.bToneBroadcast.val:%d \n", stAlarmLinkage.bToneBroadcast.val);
			printf("bLampWhiteFlashes.val:%d \n", stAlarmLinkage.bLampWhiteFlashes.val);
			stAlarmLinkage.bToneBroadcast.val = !stAlarmLinkage.bToneBroadcast.val;
			stAlarmLinkage.bLampWhiteFlashes.val = !stAlarmLinkage.bLampWhiteFlashes.val;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_ALARM_LINKAGE, &stAlarmLinkage, sizeof(stAlarmLinkage));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video alarm linkage configuration successfully! \n\n");
			}
		}

		/* 设备时间配置 */
		IPSDK_SystemTime stSystemTime;
		memset(&stSystemTime, 0, sizeof(stSystemTime));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_TIME, &stSystemTime, sizeof(stSystemTime));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Time.enSyncTime.val:%d \n", stSystemTime.enSyncTime.val);
			if (EN_IPSDK_SYNC_TIME_NTP == stSystemTime.enSyncTime.val)
			{
				printf("NtpTime.bEnabled.val:%d \n", stSystemTime.NtpTime.bEnable.val);
				printf("NtpTime.strDomain.val:%s \n", stSystemTime.NtpTime.strDomain.val);
				printf("NtpTime.nPort.val:%d \n", stSystemTime.NtpTime.nPort.val);
				printf("NtpTime.nSyncCycle.val:%d \n", stSystemTime.NtpTime.nSyncCycle.val);
			}
			else if (EN_IPSDK_SYNC_TIME_MANUAL == stSystemTime.enSyncTime.val)
			{
				printf("ManualTime.u32Utc:%u \n", stSystemTime.ManualTime.u32Utc);
				printf("ManualTime.enTimeZone:%u \n", stSystemTime.ManualTime.enTimeZone);
			}
			stSystemTime.ManualTime.u32Utc = 1652664144;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_TIME, &stSystemTime, sizeof(stSystemTime));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set system time configuration successfully! \n\n");
			}
		}

		/* 定时维护配置 */
		IPSDK_SystemMaintain stSystemMain;
		memset(&stSystemMain, 0, sizeof(stSystemMain));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_MAINTAIN, &stSystemMain, sizeof(stSystemMain));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("SysMain bEnable.val:%d \n", stSystemMain.bEnable.val);
			for (i = 0; i < stSystemMain.enWeekDay._Option.entries; i++)
			{
				printf("enWeekDay.opt[%d]:%u \n", i, stSystemMain.enWeekDay._Option.opt[i]);
			}
			printf("enWeekDay:%u \n", stSystemMain.enWeekDay.val);
			printf("RebootTimes:%u \n", stSystemMain.u32RebootTimes);
			stSystemMain.bEnable.val = !stSystemMain.bEnable.val;
			stSystemMain.u32RebootTimes = 21600;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_MAINTAIN, &stSystemMain, sizeof(stSystemMain));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set system maintain configuration successfully! \n\n");
			}
		}

		/* 灯源配置 */
		IPSDK_LightDevice stLightDevice;
		memset(&stLightDevice, 0, sizeof(stLightDevice));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_LIGHTDEVICE, &stLightDevice, sizeof(stLightDevice));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("LightDev.enDeviceType.val:%d \n", stLightDevice.enDeviceType.val);
			for (i = 0; i < stLightDevice.enDeviceType._Option.entries; i++)
			{
				printf("enDeviceType.opt[%d]:%d \n", i, stLightDevice.enDeviceType._Option.opt[i]);
			}
			printf("enImageMode.val:%d \n", stLightDevice.enImageMode.val);
			for (i = 0; i < stLightDevice.enImageMode._Option.entries; i++)
			{
				printf("enImageMode.opt[%d]:%d \n", i, stLightDevice.enImageMode._Option.opt[i]);
			}
			printf("enLightMode.val:%d \n", stLightDevice.enLightMode.val);
			for (i = 0; i < stLightDevice.enLightMode._Option.entries; i++)
			{
				printf("enLightMode.opt[%d]:%d \n", i, stLightDevice.enLightMode._Option.opt[i]);
			}
			printf("enLightTurnOnSens.val:%d \n", stLightDevice.enLightTurnOnSens.val);
			for (i = 0; i < stLightDevice.enLightTurnOnSens._Option.entries; i++)
			{
				printf("enLightTurnOnSens.opt[%d]:%d \n", i, stLightDevice.enLightTurnOnSens._Option.opt[i]);
			}
			printf("enLightAutoAdjSens.val:%d \n", stLightDevice.enLightAutoAdjSens.val);
			for (i = 0; i < stLightDevice.enLightAutoAdjSens._Option.entries; i++)
			{
				printf("enLightAutoAdjSens.opt[%d]:%d \n", i, stLightDevice.enLightAutoAdjSens._Option.opt[i]);
			}
			printf("stNightRange.bEnable.val:%d \n", stLightDevice.stNightRange.bEnable.val);
			printf("stNightRange.nStartTime.val:%d \n", stLightDevice.stNightRange.nStartTime.val);
			printf("stNightRange.nStopTime.val:%d \n", stLightDevice.stNightRange.nStopTime.val);
			printf("stNightRange.nWeekday.val:%d \n", stLightDevice.stNightRange.nWeekday.val);
			printf("stNightRange.nType.val:%d \n", stLightDevice.stNightRange.nType.val);
			for (i = 0; i < 2; i++)
			{
				printf("AutoControl.enOptType.val:%d \n", stLightDevice.AutoControl[i].enOptType.val);
				for (ii = 0; ii < stLightDevice.AutoControl[i].enOptType._Option.entries; ii++)
				{
					printf("AutoControl.enOptType.opt[%d]:%d \n", ii, stLightDevice.AutoControl[i].enOptType._Option.opt[ii]);
				}
				printf("AutoControl.nDutyRatio.val:%d \n", stLightDevice.AutoControl[i].nDutyRatio.val);
			}
			stLightDevice.enImageMode.val = EN_IPSDK_IMAGE_MODE_DAY;
			stLightDevice.enLightMode.val = EN_IPSDK_LIGHT_SMART_MODE_LAMPWHITE;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_LIGHTDEVICE, &stLightDevice, sizeof(stLightDevice));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set system light device configuration successfully! \n\n");
			}
		}

		/* 账户管理配置 */
		IPSDK_AccountMgr stAccountMgr;
		memset(&stAccountMgr, 0, sizeof(stAccountMgr));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_ACCOUNT_MGR, &stAccountMgr, sizeof(stAccountMgr));
		if (IPSDK_SUCCESS == nRet)
		{
			for (i = 0; i < IPSDK_USR_GROUP_SIZE; i++)
			{
				if (0 == strlen(stAccountMgr.stUsrs[i].Name))
				{
					break;
				}
				printf("stAccountMgr.stUsrs[%d].bEnable:%d \n", i, stAccountMgr.stUsrs[i].bEnable);
				printf("stUsrs[%d].Name:%s \n", i, stAccountMgr.stUsrs[i].Name);
				printf("stUsrs[%d].enClassify:%d \n", i, stAccountMgr.stUsrs[i].enClassify);
			}
			stAccountMgr.nCmd = EN_IPSDK_USR_CMD_ADD;
			snprintf(stAccountMgr.stUsrs[0].Name, sizeof(stAccountMgr.stUsrs[0].Name), "%s", "guest");
			snprintf(stAccountMgr.stUsrs[0].Psk, sizeof(stAccountMgr.stUsrs[0].Psk), "%s", "12345");
			stAccountMgr.stUsrs[0].bEnable = IPSDK_TRUE;
			stAccountMgr.stUsrs[0].enClassify = EN_IPSDK_USR_CLASS_VIEWER;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_ACCOUNT_MGR, &stAccountMgr, sizeof(stAccountMgr));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set account management configuration successfully! \n\n");
			}
		}
#if 0
		/* 系统重启 */
		IPSDK_Int bReboot = IPSDK_TRUE;
		nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_SYSTEM_REBOOT, &bReboot, sizeof(bReboot));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Reboot system successfully! \n\n");
		}

		/* 恢复出厂设置 */
		IPSDK_Int bReset = IPSDK_TRUE;
		nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_SYSTEM_DEFAULTFACTORY, &bReset, sizeof(bReset));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Reset system successfully! \n\n");
		}
#endif
		/* IR-CUT反向配置 */
		IPSDK_PropBoolean IrcutReverse;
		memset(&IrcutReverse, 0, sizeof(IrcutReverse));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_IRCUT_REVERSE, &IrcutReverse, sizeof(IrcutReverse));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("IrcutReverse.def:%d val:%d \n", IrcutReverse.def, IrcutReverse.val);
		}
		IrcutReverse.val = !IrcutReverse.val;
		nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_IRCUT_REVERSE, &IrcutReverse, sizeof(IrcutReverse));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("Set ircut reverse configuration successfully! \n\n");
		}

		/* 移动侦测配置 */
		IPSDK_VideoMd stVideoMd;
		memset(&stVideoMd, 0, sizeof(stVideoMd));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MD, &stVideoMd, sizeof(stVideoMd));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("VideoMd.DayAlarm.bEnable.val:%d \n", stVideoMd.DayAlarm.bEnable.val);
			printf("DayAlarm.nSensitivity.val:%d \n", stVideoMd.DayAlarm.nSensitivity.val);
			printf("DayAlarm.nThreshold.val:%d \n", stVideoMd.DayAlarm.nThreshold.val);
			printf("NightAlarm.bEnable.val:%d \n", stVideoMd.NightAlarm.bEnable.val);
			printf("NightAlarm.nSensitivity.val:%d \n", stVideoMd.NightAlarm.nSensitivity.val);
			printf("NightAlarm.nThreshold.val:%d \n", stVideoMd.NightAlarm.nThreshold.val);
			printf("NightAlarm.stTimeSegment.nStartTime.val:%d \n", stVideoMd.NightAlarm.stTimeSegment.nStartTime.val);
			printf("NightAlarm.stTimeSegment.nStopTime.val:%d \n", stVideoMd.NightAlarm.stTimeSegment.nStopTime.val);
			printf("Mask.nWidth:%d \n", stVideoMd.Mask.nColumns);
			printf("Mask.nHeight:%d \n", stVideoMd.Mask.nRows);
			for (i = 0; i < stVideoMd.Mask.nRows; i++)
			{
				for (ii = 0; ii < stVideoMd.Mask.nColumns; ii++)
				{
					if(stVideoMd.Mask.arrMatrix[i][ii] > 0) printf("%s", "+"); else printf("%s", "-");
				}
				printf("\n");
			}
			for (i = 0; i < IPSDK_MAX_TIMESEGMENT; i++)
			{
				printf("stAlarmSegment.bEnable.val:%d \n", stVideoMd.stAlarmSegment[i].bEnable.val);
				printf("stAlarmSegment.nStartTime.val:%d \n", stVideoMd.stAlarmSegment[i].nStartTime.val);
				printf("stAlarmSegment.nStopTime.val:%d \n", stVideoMd.stAlarmSegment[i].nStopTime.val);
				printf("stAlarmSegment.nWeekday.val:%d \n", stVideoMd.stAlarmSegment[i].nWeekday.val);
				printf("stAlarmSegment.nType.val:%d \n", stVideoMd.stAlarmSegment[i].nType.val);
			}
			stVideoMd.DayAlarm.bEnable.val = !stVideoMd.DayAlarm.bEnable.val;
			stVideoMd.DayAlarm.nSensitivity.val = 85;
			stVideoMd.DayAlarm.nThreshold.val = 75;
			stVideoMd.NightAlarm.bEnable.val = !stVideoMd.NightAlarm.bEnable.val;
			stVideoMd.NightAlarm.nSensitivity.val = 65;
			stVideoMd.NightAlarm.nThreshold.val = 55;
			stVideoMd.NightAlarm.stTimeSegment.nStartTime.val = 18 * 60 * 60;
			stVideoMd.NightAlarm.stTimeSegment.nStopTime.val = 23 * 60 * 60;
			stVideoMd.stAlarmSegment[0].bEnable.val = !stVideoMd.stAlarmSegment[0].bEnable.val;
			stVideoMd.stAlarmSegment[0].nStartTime.val = 6 * 60 * 60;
			stVideoMd.stAlarmSegment[0].nStopTime.val = 20 * 60 * 60;
			stVideoMd.stAlarmSegment[0].nWeekday.val = EN_IPSDK_WEEK_SUN | EN_IPSDK_WEEK_SAT;
			stVideoMd.Mask.nColumns = 22;
			stVideoMd.Mask.nRows = 18;
			for (i = 0; i < stVideoMd.Mask.nRows; i++)
			{
				for (ii = 0; ii < stVideoMd.Mask.nColumns; ii++)
				{
					stVideoMd.Mask.arrMatrix[i][ii] = ((stVideoMd.Mask.arrMatrix[i][ii] + ii) % 2) ? 0 : 1;
					if(stVideoMd.Mask.arrMatrix[i][ii] > 0) printf("%s", "+"); else printf("%s", "-");
				}
				printf("\n");
			}
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MD, &stVideoMd, sizeof(stVideoMd));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video md configuration successfully! \n\n");
			}
		}

		/* 遮挡侦测配置 */
		IPSDK_VideoCd stVideoCd;
		memset(&stVideoCd, 0, sizeof(stVideoCd));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_CD, &stVideoCd, sizeof(stVideoCd));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("VideoCd.bEnable.val:%d \n", stVideoCd.bEnable.val);
			printf("nSensLevel.val:%d \n", stVideoCd.nSensLevel.val);
			printf("nThreshold.val:%d \n", stVideoCd.nThreshold.val);
			printf("fRegionX:%.2f \n", stVideoCd.fRegionX.val);
			printf("fRegionY:%.2f \n", stVideoCd.fRegionY.val);
			printf("fRegionW:%.2f \n", stVideoCd.fRegionW.val);
			printf("fRegionH:%.2f \n", stVideoCd.fRegionH.val);
			for (i = 0; i < IPSDK_MAX_TIMESEGMENT; i++)
			{
				printf("stAlarmSegment.bEnable.val:%d \n", stVideoCd.stAlarmSegment[i].bEnable.val);
				printf("stAlarmSegment.nStartTime.val:%d \n", stVideoCd.stAlarmSegment[i].nStartTime.val);
				printf("stAlarmSegment.nStopTime.val:%d \n", stVideoCd.stAlarmSegment[i].nStopTime.val);
				printf("stAlarmSegment.nWeekday.val:%d \n", stVideoCd.stAlarmSegment[i].nWeekday.val);
				printf("stAlarmSegment.nType.val:%d \n", stVideoCd.stAlarmSegment[i].nType.val);
			}
			stVideoCd.bEnable.val = !stVideoCd.bEnable.val;
			stVideoCd.nSensLevel.val = 4;
			stVideoCd.nThreshold.val = 70;
			stVideoCd.stAlarmSegment[0].bEnable.val = !stVideoCd.stAlarmSegment[0].bEnable.val;
			stVideoCd.stAlarmSegment[0].nStartTime.val = 8 * 60 * 60;
			stVideoCd.stAlarmSegment[0].nStopTime.val = 21 * 60 * 60;
			stVideoCd.stAlarmSegment[0].nWeekday.val = EN_IPSDK_WEEK_SUN;
			stVideoCd.fRegionX.val = 10;
			stVideoCd.fRegionY.val = 15;
			stVideoCd.fRegionW.val = 50;
			stVideoCd.fRegionH.val = 35;
			nRet = NETSDK_SetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_CD, &stVideoCd, sizeof(stVideoCd));
			if (IPSDK_SUCCESS == nRet)
			{
				printf("Set video cd configuration successfully! \n\n");
			}
		}

		/* 获取设备信息配置 */
		IPSDK_DeviceCapabilities stDeviceCaps;
		memset(&stDeviceCaps, 0, sizeof(stDeviceCaps));
		nRet = NETSDK_GetParam(hLogin, &stChannelInfo, EN_IPSDK_DATA_CMD_PROPERTY_DEVICECAPS, &stDeviceCaps, sizeof(stDeviceCaps));
		if (IPSDK_SUCCESS == nRet)
		{
			printf("hwVersion:%s \n", stDeviceCaps.hwVersion);
			printf("swVersion:%s \n", stDeviceCaps.swVersion);
			printf("fwCompileTime:%s \n", stDeviceCaps.fwCompileTime);
			printf("sn:%s \n", stDeviceCaps.sn);
			printf("pid:%s \n", stDeviceCaps.pid);
		}

#define UPLOAD_ALARM_AUDIO_FILE "alarm_audio_file.pcm"
		EN_IPSDK_FileType enFileType = EN_IPSDK_FILE_TYPE_AUDIO_ALARM;
		IPSDK_PChar pstrFileData = IPSDK_NULL;
		IPSDK_Int nFileLen = 0;
		FILE* fp = fopen(UPLOAD_ALARM_AUDIO_FILE, "rb");
		if (fp)
		{
			fseek(fp, 0, SEEK_END);
			nFileLen = ftell(fp);
			fseek(fp, 0, SEEK_SET);

			pstrFileData = (IPSDK_PChar)malloc(nFileLen);
			if (NULL != pstrFileData)
			{
				if (nFileLen != fread(pstrFileData, 1, nFileLen, fp))
				{
					printf("fread(%d bytes) failed\n", nFileLen);
				}
				nRet = NETSDK_UploadFile(hLogin, UPLOAD_ALARM_AUDIO_FILE, pstrFileData, nFileLen, enFileType);
				if (IPSDK_SUCCESS == nRet)
				{
					printf("Upload alarm audio file successfully! \n\n");
				}
				free(pstrFileData);
			}
			fclose(fp);
		}
#endif

	}
#endif

#endif

#if 0
#define UPGRADE_FIRMWARE_FILE "./IFB100-06072_V2.2.1Beta99_Build202202110510.rom"
	NETSDK_UpgradeFirmware("192.168.13.60", UPGRADE_FIRMWARE_FILE, _UpgradeRateCallBack, IPSDK_NULL);
#endif

	IPSDK_Char cmd;
	while (1)
	{
//		system_sleep(2*1000);
		cmd = getchar();
		if ('q' == cmd || 'Q' == cmd)
		{
			break;
		}
	}
	NETSDK_Logout(hLogin);
	NETSDK_Cleanup();

	return 0;
}

