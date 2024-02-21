#ifndef _IPSDK_MEDIA_DEF_TYPE_H_
#define _IPSDK_MEDIA_DEF_TYPE_H_

#include "ipsdk_def_type.h"

typedef enum IPSDK_Media_Data_Type
{
	// video
	EN_IPSDK_MEDIA_DATA_H264 = (0x00000000UL),
	EN_IPSDK_MEDIA_DATA_H265,
	EN_IPSDK_MEDIA_DATA_JPEG,
	// audio
	EN_IPSDK_MEDIA_DATA_PCM = (0x80000000UL),
	EN_IPSDK_MEDIA_DATA_G711A,
	EN_IPSDK_MEDIA_DATA_G711U,
	EN_IPSDK_MEDIA_DATA_AAC,
	//Intelligent Video data
	EN_IPSDK_MEDIA_DATA_MD = (0xC0000000UL),
} EN_IPSDK_Media_Data_Type, EN_DATA_TYPE;

typedef enum IPSDK_Frame_Type
{
	EN_IPSDK_FRAME_TYPE_P = (0),
	EN_IPSDK_FRAME_TYPE_I,
	EN_IPSDK_FRAME_TYPE_B,
	EN_IPSDK_FRAME_TYPE_BTN,
} EN_IPSDK_Frame_Type;

/**********************************************************************************************
*
* 媒体流结构体
*
***********************************************************************************************/
typedef struct tag_ipsdk_media_frame_
{
	EN_DATA_TYPE enMediaType;	/// 媒体数据类型
	IPSDK_UInt64 u64SysTime;	/// 媒体帧系统时间(时分秒)ms
	IPSDK_UInt64 u64Timstmp;	/// 媒体帧时间戳
	IPSDK_UInt32 u32DataLen;	/// 媒体裸数据大小
	IPSDK_UInt32 u32AlarmType;	/// 判断帧是什么报警类型: EN_IPSDK_STORE_TYPE

	union
	{
		struct
		{
			IPSDK_UInt32 u32FrameType;	/// 帧类型: EN_IPSDK_FRAME_TYPE
			IPSDK_UInt32 u32FrameSeq;	/// ref frame counter
			IPSDK_UInt32 u32FrameRate;
			IPSDK_UInt32 u32Width;
			IPSDK_UInt32 u32Height;
		}video, h264, h265;
		struct
		{
			IPSDK_UInt32 u32SampleRate;		/// 采样率: 4000,8000,16000,32000
			IPSDK_UInt32 u32SampleWidth;	/// 采样位: 8位，16位
			IPSDK_UInt32 u32SampleChannel;	/// 采样声道: 1 单声道,2 双声道
			IPSDK_UInt32 u32Ratio; /// if g711a.u == 2.0
			IPSDK_UInt32 res;
		}audio, pcm, g711a, g711u;
	};
	struct
	{
		///H265有vps[32],sps[33],pps[34],idr[19] ==> [按顺序存储]
		///H264有        sps[07],pps[08],idr[05] ==> [按顺序存储]
		IPSDK_Char	vvps_buf[128]; /// 只针对视频信息
		IPSDK_UInt32 vvps_len;
		IPSDK_Char	vpps_buf[128];
		IPSDK_UInt32 vpps_len;
		IPSDK_Char	vsps_buf[128];
		IPSDK_UInt32 vsps_len;
	}media_info;
} IPSDK_MediaFrame;

#endif

