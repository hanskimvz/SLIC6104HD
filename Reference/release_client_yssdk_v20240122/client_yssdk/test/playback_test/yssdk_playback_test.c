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

static IPSDK_Int _PlaybackStreamCallBack(
	IPSDK_HANDLE lRealHandle,
	IPSDK_Int nChannel,
	IPSDK_Int nStream,
	IPSDK_Int nDataType,
	IPSDK_PChar pDataBuf,
	IPSDK_Int nDataLen,
	IPSDK_PVoid pUserBuf)
{
	static IPSDK_Int nFrameFirst = 0;
	if (NULL == pDataBuf)
	{
		return IPSDK_FAILURE;
	}
	// 2:直播流 6:回放流
	if (6 == nDataType)
	{
		IPSDK_MediaFrame* pMediaFrame = (IPSDK_MediaFrame*)pDataBuf;
		IPSDK_PChar pMediaBuf = IPSDK_NULL;
		if (EN_IPSDK_MEDIA_DATA_H264 == pMediaFrame->enMediaType)
		{
			if (0 == nFrameFirst && EN_IPSDK_FRAME_TYPE_I == pMediaFrame->h264.u32FrameType)
			{
				nFrameFirst = 1;
			}

			if (1 == nFrameFirst)
			{
				printf("[h264]u32FrameSeq:%d,u32DataLen:%d,media_frame_len:%lu\n",
					pMediaFrame->h265.u32FrameSeq, pMediaFrame->u32DataLen,sizeof(IPSDK_MediaFrame));
				printf("type:%d,u32FrameSeq:%d,u32FrameRate:%d, w:%d,h:%d \n", 
					pMediaFrame->h265.u32FrameType,
					pMediaFrame->h265.u32FrameSeq,
					pMediaFrame->h265.u32FrameRate,
					pMediaFrame->h265.u32Width, pMediaFrame->h265.u32Height);

				pMediaBuf = pDataBuf + sizeof(IPSDK_MediaFrame);
			}
		}
		else if (EN_IPSDK_MEDIA_DATA_H265 == pMediaFrame->enMediaType)
		{
			if (0 == nFrameFirst && EN_IPSDK_FRAME_TYPE_I == pMediaFrame->h265.u32FrameType)
			{
				nFrameFirst = 1;
			}
			if (1 == nFrameFirst)
			{
				printf("[h265]u32FrameSeq:%d,u32DataLen:%d,media_frame_len:%lu\n",
					pMediaFrame->h265.u32FrameSeq, pMediaFrame->u32DataLen, sizeof(IPSDK_MediaFrame));
				printf("type:%d,u32FrameSeq:%d,u32FrameRate:%d, w:%d,h:%d \n",
					pMediaFrame->h265.u32FrameType,
					pMediaFrame->h265.u32FrameSeq,
					pMediaFrame->h265.u32FrameRate,
					pMediaFrame->h265.u32Width, pMediaFrame->h265.u32Height);
				pMediaBuf = pDataBuf + sizeof(IPSDK_MediaFrame);
			}
		}
		else if (EN_IPSDK_MEDIA_DATA_G711U == pMediaFrame->enMediaType ||
			EN_IPSDK_MEDIA_DATA_G711A == pMediaFrame->enMediaType ||
			EN_IPSDK_MEDIA_DATA_AAC == pMediaFrame->enMediaType)
		{
			printf("[audio]media_frame_len:%u", pMediaFrame->u32DataLen);

		}
	}
	return IPSDK_SUCCESS;
}

static IPSDK_Int _Stream_StatusEventCallBack(IPSDK_Int nStateCode, IPSDK_PChar pResponse, IPSDK_PVoid pUserParam)
{
	IPSDK_DEBUG("[_Stream_StatusEventCallBack] nStateCode:%d", nStateCode);
	return IPSDK_SUCCESS; // 如果返回 IPSDK_FAILURE 则意味着停止并关闭回放事件
}

static IPSDK_Int _ProductTestCallBack(IPSDK_Int nTestId, IPSDK_Int nCode, IPSDK_CPChar pResultJson, IPSDK_PVoid pUser)
{
	IPSDK_DEBUG("nTestId:%d,nCode:%d,pResultJson:%s", nTestId, nCode, (IPSDK_NULL == pResultJson) ? "" : pResultJson);
	return IPSDK_SUCCESS;
}

int main(int argc, char* argv[])
{
	IPSDK_Int i = 0;
	IPSDK_Int ii = 0;
	IPSDK_Int nRet = NETSDK_Init();

	// 接受命令行第一个参数为目标IPC的IP地址，便于测试
	char test_ipc[30] = {"192.168.1.123"};
	if (argc > 1){
		strncpy (test_ipc, argv[1], sizeof(test_ipc)/sizeof(char));
	}
	IPSDK_DEBUG("Test IPC IP address: %s", test_ipc);

	IPSDK_Char DataBuf[2*1024] = {0};
	IPSDK_Int nDataLen = sizeof(DataBuf);
	IPSDK_ChannelInfo stChannelInfo;
	stChannelInfo.nChannel = 0;
	stChannelInfo.nStream = 0;
	IPSDK_HLOGIN hLogin = NETSDK_Login(
		test_ipc,
		9980,
		1680,
		"admin",
		"admin",
		IPSDK_NULL);
	CHECK_POINTER_ERR_RET(hLogin, IPSDK_FAILURE);

	//// 回放日期检索，罗列所有存在录像的日期
	nRet = NETSDK_ProductTest(hLogin,
		113,
		_ProductTestCallBack,
		IPSDK_NULL,
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		IPSDK_DEBUG("Product Test successfully!");
	}

	//// 回放时间检索，主要查询某天之中的录像情况
	nRet = NETSDK_ProductTest(hLogin,
		110,
		_ProductTestCallBack,
		"{\"start_time\":1670198400,\"end_time\":1670284799}",
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		IPSDK_DEBUG("Product Test successfully!");
	}

	IPSDK_PlaybackInfo stPlaybackInfo;
	memset(&stPlaybackInfo, 0, sizeof(stPlaybackInfo));
	stPlaybackInfo.nChannel = 0;
	stPlaybackInfo.nStream = 0;
	stPlaybackInfo.u64StartTime = 1670314868; // 回放开始时间
	snprintf(stPlaybackInfo.strSessionId, sizeof(stPlaybackInfo.strSessionId), "%s", "uniqueid");

	IPSDK_HCHANNEL hStream = NETSDK_CreatePlayback(hLogin, &stPlaybackInfo);
	CHECK_POINTER_ERR_RET(hStream, IPSDK_FAILURE);

	nRet = NETSDK_StartPlayback(hStream, _PlaybackStreamCallBack, _Stream_StatusEventCallBack, IPSDK_NULL);
	CHECK_RET_SUCCESS_ERR_RET(nRet, IPSDK_FAILURE);

	//// 回放定点控制，实现一天之中拖动播放的功能
	nRet = NETSDK_ProductTest(hLogin,
		112,
		_ProductTestCallBack,
		"{\"session_id\":\"uniqueid\",\"start_time\":1670202000}",
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		IPSDK_DEBUG("Product Test successfully!");
	}

	//// 回放速率控制，根据需求调整回放速度（正常速度回放，慢进、快进）
	nRet = NETSDK_ProductTest(hLogin,
		111,
		_ProductTestCallBack,
		"{\"session_id\":\"uniqueid\",\"scale\":0.75}",
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		IPSDK_DEBUG("Product Test successfully!");
	}

	//// 回放位置查询，得到当前回放位置时间
	nRet = NETSDK_ProductTest(hLogin,
		114,
		_ProductTestCallBack,
		IPSDK_NULL,
		IPSDK_NULL);
	if (IPSDK_SUCCESS == nRet)
	{
		IPSDK_DEBUG("Product Test successfully!");
	}

	IPSDK_Char cmd;
	while (1)
	{
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

