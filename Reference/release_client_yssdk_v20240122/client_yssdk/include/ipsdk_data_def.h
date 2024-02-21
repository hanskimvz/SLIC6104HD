#ifndef _IPSDK_DATA_DEF_TYPE_H_
#define _IPSDK_DATA_DEF_TYPE_H_

#include "ipsdk_def_type.h"

#define IPSDK_DEFULT_LEN	(64)

/**
 * 感兴趣区域最大个数。
 */
#define IPSDK_ROI_MAX_ENT (4)

/**
 * 感兴趣区域多边形最大边数。
 */
#define IPSDK_ROI_DOT_MAX_ENT (8)

/**
 * 告警提示音时间布防最大个数。
 */
#define IPSDK_ALARM_TONE_MAX_ENT (4)

/**
 * 广告语时间布防最大个数。
 */
#define IPSDK_ADVERT_TONE_MAX_ENT (4)

/**
 * 最大时间段个数。
 */
#define IPSDK_MAX_TIMESEGMENT (4)

/**
 * @macro
 *  定义最大通道数。
 */
#define IPSDK_DEV_MAX_MEDIA_CH (64)

 /**
 * @macro
 *  定义最大码流数。
 */
#define IPSDK_DEV_MAX_MEDIA_CH_STREAM     (4)

/**
 * @macro
 *  支持最多扩展标题数。
 */
#define IPSDK_MAX_EXPAND_TITLE (4)

/**
 * @macro
 *  定义最大码流点播数。
 */
#define IPSDK_DEV_MAX_MEDIA_STREAM_ONCMD (16)

/**
 * @macro
 *  用户最大名称长度定义。
 */
#define IPSDK_USER_MAX_NAME_SZ    (32)

/**
 * @macro
 *  用户最大密码长度定义。
 */
#define IPSDK_USER_MAX_PASS_SZ    (IPSDK_USER_MAX_NAME_SZ)

/**
 * @macro
 *  支持设置的最大账户个数。
 */
#define IPSDK_USR_GROUP_SIZE (10)

/**
 * @macro
 *  会话ID最大长度定义。
 */
#define IPSDK_SESSION_ID_MAX_SZ (64)

/**
 * 编码码率控制模式。
 */
typedef enum IPSDK_BitRateCtrlMode
{
	EN_IPSDK_BR_CTRL_MODE_UNDEF = (-1),
	/**
	 * 恒定码率控制。
	 */
	EN_IPSDK_BR_CTRL_MODE_CBR,

	/**
	 * 可变码率控制。
	 */
	EN_IPSDK_BR_CTRL_MODE_VBR,

} EN_IPSDK_BitRateCtrlMode;

/**
 * 音频输入模式。
 */
typedef enum IPSDK_AudioInputMode
{
	EN_IPSDK_AUDIO_INPUT_MODE_UNDEF = (-1),
	/**
	 * 音频输入方式。
	 */
	EN_IPSDK_AUDIO_INPUT_MODE_AUTO,

	EN_IPSDK_AUDIO_INPUT_MODE_LINE,// 有源

	EN_IPSDK_AUDIO_INPUT_MODE_MIC   // 无源

} EN_IPSDK_AudioInputMode;

/**
 * 视频编码器类型。
 */
typedef enum IPSDK_VideoEncCodec
{
	EN_IPSDK_VENC_CODEC_UNDEF = (-1),
	EN_IPSDK_VENC_CODEC_MPEG,
	EN_IPSDK_VENC_CODEC_H264,
	EN_IPSDK_VENC_CODEC_HEVC,
	EN_IPSDK_VENC_CODEC_H264_PLUS,
	EN_IPSDK_VENC_CODEC_HEVC_PLUS,

} EN_IPSDK_VideoEncCodec;

/**
 * 音频编码器类型。
 */
typedef enum IPSDK_AudioEncCodec
{
	EN_IPSDK_AUDIO_CODEC_UNDEF = (-1),
	EN_IPSDK_AUDIO_CODEC_G711A,
	EN_IPSDK_AUDIO_CODEC_G711U,
	EN_IPSDK_AUDIO_CODEC_AAC,

} EN_IPSDK_AudioEncCodec;

/**
 * 编码复杂度
 */
typedef enum IPSDK_ProfileMode
{
	EN_IPSDK_H264_PROFILE_UNDEF = (-1),
	EN_IPSDK_H264_PROFILE_BASELINE,
	EN_IPSDK_H264_PROFILE_MAIN,
	EN_IPSDK_H264_PROFILE_HIGH,

} EN_IPSDK_ProfileMode;

/**
 * OSD 日期格式
 */
typedef enum IPSDK_DateFormat
{
	EN_IPSDK_DATEFMT_UNDEF = (-1),
	EN_IPSDK_DATEFMT_DASH_YYYYMMDD,
	EN_IPSDK_DATEFMT_DASH_MMDDYYYY,
	EN_IPSDK_DATEFMT_DASH_DDMMYYYY,
	EN_IPSDK_DATEFMT_SLASH_YYYYMMDD,
	EN_IPSDK_DATEFMT_SLASH_MMDDYYYY,
	EN_IPSDK_DATEFMT_SLASH_DDMMYYYY,

} EN_IPSDK_DateFormat;

/**
 * OSD 时间格式
 */
typedef enum IPSDK_TimeFormat
{
	EN_IPSDK_TIMEFMT_UNDEF = (-1),
	EN_IPSDK_TIMEFMT_DASH_HHMMSS,
	EN_IPSDK_TIMEFMT_SLASH_HHMMSS,
	EN_IPSDK_TIMEFMT_COLON_HHMMSS,

} EN_IPSDK_TimeFormat;

/**
 * 图像场景模式
 */
typedef enum IPSDK_ImageSceneMode
{
	EN_IPSDK_IMG_SCENE_MODE_AUTO = (0),
	EN_IPSDK_IMG_SCENE_MODE_INDOOR,
	EN_IPSDK_IMG_SCENE_MODE_OUTDOOR,
} EN_IPSDK_ImageSceneMode;

/**
 * 图像曝光模式
 */
typedef enum IPSDK_ImageExposureMode
{
	/// 自动曝光模式。
	EN_IPSDK_IMG_EXPO_MODE_AUTO = (0),
	/// 强光曝光模式。
	EN_IPSDK_IMG_EXPO_MODE_BRIGHT,
	/// 低照曝光模式。
	EN_IPSDK_IMG_EXPO_MODE_DARK,
} EN_IPSDK_ImageExposureMode;

/**
 * 图像自动白平衡模式
 */
typedef enum IPSDK_ImageAutoWBMode
{
	EN_IPSDK_IMG_AWB_MODE_AUTO = (0),
	EN_IPSDK_IMG_AWB_MODE_INDOOR,
	EN_IPSDK_IMG_AWB_MODE_OUTDOOR,
} EN_IPSDK_ImageAutoWBMode;

/**
 * 图像背光补偿模式
 */
typedef enum IPSDK_ImageBacklightCompensation
{
	EN_IPSDK_IMG_BL_COMP_AUTO = (0),
	EN_IPSDK_IMG_BL_COMP_ALWAIPSDK_ON,
	EN_IPSDK_IMG_BL_COMP_ALWAIPSDK_OFF,
} EN_IPSDK_ImageBacklightCompensation;

/**
 * 图像低照度模式
 */
typedef enum IPSDK_LowlightMode
{
	EN_IPSDK_IMG_LL_MODE_OFF = (0),
	EN_IPSDK_IMG_LL_MODE_ONLY_NIGHT,
	EN_IPSDK_IMG_LL_MODE_DAY_AND_NIGHT,
	EN_IPSDK_IMG_LL_MODE_AUTO,
} EN_IPSDK_LowlightMode;

/**
 * 视频制式
 */
typedef enum IPSDK_PowerFrequence
{
	EN_IPSDK_PWR_FREQ_UNDEF = (-1),
	EN_IPSDK_PWR_FREQ_PAL = (50),
	EN_IPSDK_PWR_FREQ_NTSC = (60),
} EN_IPSDK_PowerFrequence;

/**
 * 同步时间方式
 */
typedef enum IPSDK_SyncTime
{
	EN_IPSDK_SYNC_TIME_UNDEF = (-1),
	EN_IPSDK_SYNC_TIME_NTP,
	EN_IPSDK_SYNC_TIME_MANUAL,
} EN_IPSDK_SyncTime;

/**
 * @brief 定时维护
 */
typedef enum IPSDK_Week
{
	EN_IPSDK_WEEK_SUN = (1 << 0),	// 星期日
	EN_IPSDK_WEEK_MON = (1 << 1),	// 星期一
	EN_IPSDK_WEEK_TUE = (1 << 2),	// 星期二
	EN_IPSDK_WEEK_WED = (1 << 3),	// 星期三
	EN_IPSDK_WEEK_THU = (1 << 4),	// 星期四
	EN_IPSDK_WEEK_FRI = (1 << 5),	// 星期五
	EN_IPSDK_WEEK_SAT = (1 << 6),	// 星期六
	EN_IPSDK_WEEK_EVE = (1 << 7),	// 每天
} EN_IPSDK_Week;

/**
 * Wi-Fi 工作模式。
 */
typedef enum IPSDK_EthWiFiMode
{
	/**
	 * 不支持 Wi-Fi。
	 */
	EN_IPSDK_ETH_WIFI_MODE_NA = (-1),

	/**
	 * 站点模式。
	 */
	EN_IPSDK_ETH_WIFI_MODE_STA = (0),

	/**
	 * 热点模式。
	 */
	EN_IPSDK_ETH_WIFI_MODE_AP,

	/**
	 * 中继模式。
	 */
	EN_IPSDK_ETH_WIFI_MODE_REP,

} EN_IPSDK_EthWiFiMode;

/**
 * Wi-Fi 连通信道。
 */
typedef enum IPSDK_EthWiFiAccessChannel
{
	EN_IPSDK_ETH_WIFI_ACCESS_CH_AUTO = (0),
	EN_IPSDK_ETH_WIFI_ACCESS_CH_1,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_2,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_3,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_4,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_5,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_6,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_7,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_8,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_9,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_10,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_11,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_12,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_13,
	EN_IPSDK_ETH_WIFI_ACCESS_CH_14,

} EN_IPSDK_EthWiFiAccessChannel;

typedef enum IPSDK_AlarmToneType
{
	EN_IPSDK_ALARM_TONE_TYPE_UNDEF = (-1),	/// 无定义
	EN_IPSDK_ALARM_TONE_TYPE_01 = (0),		/// 垃圾分类
	EN_IPSDK_ALARM_TONE_TYPE_02 = (1),		/// 疫情期间
	EN_IPSDK_ALARM_TONE_TYPE_03 = (2),		/// 购物愉快
	EN_IPSDK_ALARM_TONE_TYPE_04 = (3),		/// 用餐愉快
	EN_IPSDK_ALARM_TONE_TYPE_05 = (4), 		/// 开心愉快
	EN_IPSDK_ALARM_TONE_TYPE_06 = (5), 		/// 警戒区域
	EN_IPSDK_ALARM_TONE_TYPE_07 = (6), 		/// 鱼塘警戒
	EN_IPSDK_ALARM_TONE_TYPE_08 = (7), 		/// 监控区域
	EN_IPSDK_ALARM_TONE_TYPE_09 = (8), 		/// 私人领域
	EN_IPSDK_ALARM_TONE_TYPE_10 = (9), 		/// 上班提示
	EN_IPSDK_ALARM_TONE_TYPE_11 = (10), 	/// 下班提示
	EN_IPSDK_ALARM_TONE_TYPE_12 = (11), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_13 = (12), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_14 = (13), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_15 = (14), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_16 = (15), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_17 = (16), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_18 = (17), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_19 = (18), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_20 = (19), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_21 = (20), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_22 = (21), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_23 = (22), 	/// 预留
	EN_IPSDK_ALARM_TONE_TYPE_24 = (23),		/// 预留
} EN_IPSDK_AlarmToneType;

typedef enum IPSDK_AdvertToneType
{
	EN_IPSDK_ADVERT_TONE_TYPE_UNDEF = (-1),		// 无定义
	EN_IPSDK_ADVERT_TONE_TYPE_01 = (0),		// 保留扩展
	EN_IPSDK_ADVERT_TONE_TYPE_02 = (1),		// 保留扩展
	EN_IPSDK_ADVERT_TONE_TYPE_03 = (2),		// 保留扩展
	EN_IPSDK_ADVERT_TONE_TYPE_04 = (3),		// 保留扩展
} EN_IPSDK_AdvertToneType;

/**
 * 光敏类型
 */
typedef enum IPSDK_LdrType
{
	EN_IPSDK_LDR_TYPE_UNDEF = (-1),		// 无定义
	EN_IPSDK_LDR_TYPE_HARDLDR = (0),	// 软光敏
	EN_IPSDK_LDR_TYPE_SOFTLDR			// 硬光敏
}EN_IPSDK_LdrType;

/**
 * 图像模式
 */
typedef enum IPSDK_ImageMode
{
	EN_IPSDK_IMAGE_MODE_UNDEF = (-1),		// 无定义
	EN_IPSDK_IMAGE_MODE_AUTO = (1<<1),		// 自动模式
	EN_IPSDK_IMAGE_MODE_DAY = (1<<2),		// 白天模式
	EN_IPSDK_IMAGE_MODE_NIGHT = (1<<3),	// 夜晚模式
	EN_IPSDK_IMAGE_MODE_TIME = (1<<4)		// 定时模式
}EN_IPSDK_ImageMode;

/**
 * 灯光模式
 */
typedef enum IPSDK_LightMode
{
	EN_IPSDK_LIGHT_MODE_UNDEF = (-1),					// 无定义
	EN_IPSDK_LIGHT_MODE_LAMPRED = (0x00),				// 红外普通模式
	EN_IPSDK_LIGHT_MODE_LAMPWHITE,						// 白光（暖光）普通模式
	EN_IPSDK_LIGHT_MODE_LAMPDOUBLE,						// 双光源（红外、白光/暖光）普通模式
	EN_IPSDK_LIGHT_SMART_MODE_LAMPRED	= (0x10),		// 红外智能调光模式
	EN_IPSDK_LIGHT_SMART_MODE_LAMPWHITE,				// 白光/暖光智能调光模式
	EN_IPSDK_LIGHT_SMART_MODE_LAMPDOUBLE				// 双光源（红外、白光/暖光）智能调光模式
}EN_IPSDK_LightMode;

/**
 * 光源启动灵敏度
 */
typedef enum IPSDK_LightTurnOnSens
{
	EN_IPSDK_LIGHT_TURN_ON_UNDEF = (-1),		// 无定义
	EN_IPSDK_LIGHT_TURN_ON_EARLY = (1<<1),		// 早
	EN_IPSDK_LIGHT_TURN_ON_MIDDLE = (1<<2),		// 中
	EN_IPSDK_LIGHT_TURN_ON_LATE = (1<<3)		// 晚
}EN_IPSDK_LightTurnOnSens;

/**
 * 光源自动调节灵敏度
 */
typedef enum IPSDK_LightAutoAdjSens
{
	EN_IPSDK_LIGHT_AUTO_ADJ_UNDEF = (-1),		// 无定义
	EN_IPSDK_LIGHT_AUTO_ADJ_FAST = (1<<1),		// 快
	EN_IPSDK_LIGHT_AUTO_ADJ_MIDDLE = (1<<2),	// 中
	EN_IPSDK_LIGHT_AUTO_ADJ_SLOW = (1<<3)		// 慢
}EN_IPSDK_LightAutoAdjSens;

typedef enum IPSDK_PWMMode
{
	EN_IPSDK_PWM_MODE_UNDEF = (-1),	// 无定义
	EN_IPSDK_PWM_MODE_AUTO = (0),		// 自动模式
	EN_IPSDK_PWM_MODE_MANUAL = (1)	// 手动模式
} EN_IPSDK_PWMMode;

/**
 * @brief 语言列表
 */
typedef enum IPSDK_LanguageGroup
{
	EN_IPSDK_LANGUAGE_CHN = 0,		//!< 简体中文
	EN_IPSDK_LANGUAGE_ENG,			//!< 英文
} EN_IPSDK_LanguageGroup;

/**
 * @brief
 *  用户等级定义。
 */
typedef enum IPSDK_UserClassify
{
	EN_IPSDK_USR_CLASS_ADMIN = (0),		//!< 管理者
	EN_IPSDK_USR_CLASS_OPERATOR,		//!< 操作者
	EN_IPSDK_USR_CLASS_VIEWER,			//!< 查看者

} EN_IPSDK_UserClassify;


/**
 * @brief 操作类型定义
 */
typedef enum IPSDK_UserMgrCmd
{
	EN_IPSDK_USR_CMD_ADD = (0),		// !< 添加用户信息
	EN_IPSDK_USR_CMD_MOD,			// !< 修改用户信息
	EN_IPSDK_USR_CMD_DEL,			// !< 删除用户信息
}EN_IPSDK_UserMgrCmd;

/**
 * @brief 上传文件类型定义
 */
typedef enum IPSDK_FileType
{
	EN_IPSDK_FILE_TYPE_ISPCFG_DAY = (0x201),		// !< ISP (白天)配置文件类型
	EN_IPSDK_FILE_TYPE_ISPCFG_NIGHT,				// !< ISP (夜晚)配置文件类型
	EN_IPSDK_FILE_TYPE_AUDIO_ALARM = (0x301),		// !< 告警音频文件类型
	EN_IPSDK_FILE_TYPE_AUDIO_LOGO,					// !< 公司 LOGO 音频文件类型
	EN_IPSDK_FILE_TYPE_AUDIO_AD,					// !< 广告语音频文件类型
	EN_IPSDK_FILE_TYPE_SYSCFG_OEM = (0x401)			// !< 系统 OEM 配置文件类型
} EN_IPSDK_FileType;

/**
 * @brief 全网通操作定义
 */
typedef enum IPSDK_AllNetConnect
{
	EN_IPSDK_ALL_NET_CONNECT_UNDEF = (0),		// !< 操作未定义
	EN_IPSDK_ALL_NET_CONNECT_ON,				// !< 全网通开启
	EN_IPSDK_ALL_NET_CONNECT_OFF,				// !< 全网通关闭
} EN_IPSDK_AllNetConnect;

/**
 * @brief 设备（灯光）类型定义
 */
typedef enum IPSDK_DeviceMode
{
	EN_IPSDK_DEVICE_MODE_LAMPRED = (0),			// !< 红外
	EN_IPSDK_DEVICE_MODE_LAMPWHITE,				// !< 暖光
	EN_IPSDK_DEVICE_MODE_LAMPDOUBLE,			// !< 双光
	EN_IPSDK_DEVICE_MODE_LAMPNONE,				// !< 无灯
} EN_IPSDK_DeviceMode;

/**
 * @brief 授权掩码类型定义
 */
#if (_MSC_VER)
#define EN_IPSDK_LICENSE_MASK_SN  (1ULL << 63)
#define	EN_IPSDK_LICENSE_MASK_MAC  (1ULL << 62)
#define	EN_IPSDK_LICENSE_MASK_UUID  (1ULL << 61)
#else
	typedef enum IPSDK_LicenseMask
	{
		EN_IPSDK_LICENSE_MASK_SN = (1ULL << 63),		// !< SerialId
		EN_IPSDK_LICENSE_MASK_MAC = (1ULL << 62),		// !< MAC
		EN_IPSDK_LICENSE_MASK_UUID = (1ULL << 61),		// !< CloudId
} EN_IPSDK_LicenseMask;
#endif

/**
 * @brief OSD 刷新类型定义
 */
typedef enum IPSDK_OsdRefreshType
{
	EN_IPSDK_OSDREFRESH_TYPE_TEXT = (0),				// !< 文本
	EN_IPSDK_OSDREFRESH_TYPE_POSITION,					// !< 位置
} EN_IPSDK_OsdRefreshType;

/**
 * @brief 通知类型定义
 */
typedef enum IPSDK_NotificationType
{
	EN_IPSDK_NOTIFICATION_TYPE_NA = (0),				// !< 无效通知
	EN_IPSDK_NOTIFICATION_TYPE_MD = (0x200),			// !< 运动侦测通知
	EN_IPSDK_NOTIFICATION_TYPE_HD = (0x202),			// !< 人形侦测通知
	EN_IPSDK_NOTIFICATION_TYPE_CD = (0x402),			// !< 视频遮挡通知
} EN_IPSDK_NotificationType;

/**
 * @brief 传输类型定义
 */
typedef enum IPSDK_TransmissionType
{
	EN_IPSDK_TRANSMISSION_TYPE_NA = (0),				// !< 无效传输
	EN_IPSDK_TRANSMISSION_TYPE_TP = (1),				// !< 透明传输
} EN_IPSDK_TransmissionType;

/**
 * @brief 产测命令类型定义
 */
typedef enum IPSDK_ProductCommand
{
	EN_IPSDK_PRODUCT_CMD_SYSTEM_REBOOT		= 0x201,		//// 重启系统,禁用掉
	EN_IPSDK_PRODUCT_CMD_LIGHT_REDLAMP_OPEN	= 0x301,		//// 红外灯操作
	EN_IPSDK_PRODUCT_CMD_LIGHT_REDLAMP_CLOSE,
	EN_IPSDK_PRODUCT_CMD_LIGHT_WHITELAMP_OPEN,				//// 白光灯操作
	EN_IPSDK_PRODUCT_CMD_LIGHT_WHITELEMP_CLOSE,
	EN_IPSDK_PRODUCT_CMD_LIGHT_IRCUT_DAYMODE,				//// IRCUT操作
	EN_IPSDK_PRODUCT_CMD_LIGHT_IRCUT_NIGHTMODE,
	EN_IPSDK_PRODUCT_CMD_LIGHT_ALARMLED_OPEN,				//// 警示灯操作
	EN_IPSDK_PRODUCT_CMD_LIGHT_ALARMLED_CLOSE,

	EN_IPSDK_PRODUCT_CMD_ISP_EFFECT_DAYMODE,				//// ISP白天模式生效
	EN_IPSDK_PRODUCT_CMD_ISP_EFFECT_NIGHTMODE,				//// ISP夜晚模式生效
	EN_IPSDK_PRODUCT_CMD_ISP_EFFECT_AUTOMODE,				//// ISP自动模式生效
	EN_IPSDK_PRODUCT_CMD_ISP_OPEN_DEBUGMODE,				//// 启动ISP的调试模式
	EN_IPSDK_PRODUCT_CMD_ISP_CLOSE_DEBUGMODE,				//// 关闭ISP的调试模式

	EN_IPSDK_PRODUCT_CMD_FILE_FACTORY_ISPCFG	= 0x401,	//// ISP配置恢复出厂文件
	EN_IPSDK_PRODUCT_CMD_FILE_FACTORY_AIOCFG,				//// 音频播放文件恢复出厂
	EN_IPSDK_PRODUCT_CMD_FILE_FACTORY_SYSCFG,				//// 系统配置文件恢复出厂

	EN_IPSDK_PRODUCT_CMD_TEST_ALARM_FILE		= 0x501,	//// 测试报警音频操作生效

	EN_IPSDK_PRODUCT_CMD_ADVTEST_AUDIOAO_START	= 0x601,	//// 高级测试语音输出（喇叭）开始
	EN_IPSDK_PRODUCT_CMD_ADVTEST_AUDIOAO_STOP,					//// 高级测试语音输出（喇叭）结束
	EN_IPSDK_PRODUCT_CMD_ADVTEST_LIGHT_START,					//// 高级测试光源（红外/暖光）开始
	EN_IPSDK_PRODUCT_CMD_ADVTEST_LIGHT_STOP,					//// 高级测试光源（红外/暖光）结束
	EN_IPSDK_PRODUCT_CMD_ADVTEST_IRCUT_START,					//// 高级测试切换器开始
	EN_IPSDK_PRODUCT_CMD_ADVTEST_IRCUT_STOP,					//// 高级测试切换器结束

	EN_IPSDK_PRODUCT_CMD_TEST_FINISH		= 0x701,	//// 产测完成操作
	EN_IPSDK_PRODUCT_CMD_TEST_UNFINISH		= 0x702,	//// 产测未完成操作
	EN_IPSDK_PRODUCT_CMD_DELETE_LICENSE		= 0x801,	//// 删除授权信息

	EN_IPSDK_PRODUCT_CMD_UNKOWN,
} EN_IPSDK_ProductCommand;

/**
 * @brief JSON透明协议命令类型定义
 */
typedef enum IPSDK_JSON_PROTOCOL_COMMAND
{
	EN_JSON_PROTOCOL_CMD_DEVICE_SearchOnvif		= (416),	/// 远程控制设备启动ONVIF搜索
	EN_JSON_PROTOCOL_CMD_DEVICE_SearchSdk		= (417),	/// 远程控制设备启动私有协议搜索

	EN_JSON_PROTOCOL_CMD_DEVICE_ListChannel		= (510),	/// 获取所有通道设备列表
	EN_JSON_PROTOCOL_CMD_DEVICE_GetChannel		= (520),	/// 获取指定通道设备参数
	EN_JSON_PROTOCOL_CMD_DEVICE_AddChannel		= (521),	/// 添加指定通道设备参数
	EN_JSON_PROTOCOL_CMD_DEVICE_DelChannel		= (522),	/// 删除指定通道设备参数
	EN_JSON_PROTOCOL_CMD_DEVICE_ModifyChannel	= (523),	/// 修改指定通道设备参数


	EN_JSON_PROTOCOL_CMD_UNKOWN,
} EN_IPSDK_JSON_PROTOCOL;
/**
 * PTZ云台控制
 */
typedef enum IPSDK_PTZCommand
{
	EN_IPSDK_PTZ_CMD_UNDEF = (-1),
	EN_IPSDK_PTZ_CMD_STOP = (0),
	EN_IPSDK_PTZ_CMD_CAMERA_PWRON = (1),
	EN_IPSDK_PTZ_CMD_LIGHT_PWRON = (2),
	EN_IPSDK_PTZ_CMD_WIPER_PWRON = (3),
	EN_IPSDK_PTZ_CMD_FAN_PWRON = (4),
	EN_IPSDK_PTZ_CMD_HEATER_PWRON = (5),
	EN_IPSDK_PTZ_CMD_AUX_PWROYS = (6),
	EN_IPSDK_PTZ_CMD_AUX_PWRON2 = (7),
	EN_IPSDK_PTZ_CMD_TILT_UP = (100),
	EN_IPSDK_PTZ_CMD_TILT_DOWN,
	EN_IPSDK_PTZ_CMD_PAN_LEFT = (200),
	EN_IPSDK_PTZ_CMD_PAN_RIGHT,
	EN_IPSDK_PTZ_CMD_PAN_AUTO,
	EN_IPSDK_PTZ_CMD_PAN_STOP_ALL,
	EN_IPSDK_PTZ_CMD_ZOOM_IN = (300),
	EN_IPSDK_PTZ_CMD_ZOOM_OUT,
	EN_IPSDK_PTZ_CMD_FOCUS_IN = (400),
	EN_IPSDK_PTZ_CMD_FOCUS_OUT,
	EN_IPSDK_PTZ_CMD_IRIS_OPEN = (500),
	EN_IPSDK_PTZ_CMD_IRIS_CLOSE,
	EN_IPSDK_PTZ_CMD_IRIS_ENLARGE,
	EN_IPSDK_PTZ_CMD_IRIS_SHRINK,
	EN_IPSDK_PTZ_CMD_SET_PRESET = (1000),
	EN_IPSDK_PTZ_CMD_GOTO_PRESET,
	EN_IPSDK_PTZ_CMD_CLEAR_PRESET,
	EN_IPSDK_PTZ_CMD_FILL_PRE_SEQ,		// 将预置点加入巡航序列
	EN_IPSDK_PTZ_CMD_SET_SEQ_DWELL,// 设置巡航点停顿时间
	EN_IPSDK_PTZ_CMD_RUN_SEQ,			// 开始巡航
	EN_IPSDK_PTZ_CMD_STOP_SEQ,			// 停止巡航
	EN_IPSDK_PTZ_CMD_CLE_PRE_SEQ,		// 将预置点从巡航速度中删除
} EN_IPSDK_PTZCommand;

typedef enum IPSDK_DATA_CMD_PARAM
{
	EN_IPSDK_DATA_CMD_SYSTEM_DEVICEINFO = (0),	///<! "/NetSDK/System/DeviceInfo"
	EN_IPSDK_DATA_CMD_SYSTEM_USERINFO,			///<! "/NetSDK/System/UserInfo"
	EN_IPSDK_DATA_CMD_SYSTEM_DEFAULTFACTORY,	///<! "/NetSDK/System/DefaultFactory"
	EN_IPSDK_DATA_CMD_SYSTEM_REBOOT,			///<! "/NetSDK/System/Reboot"
	EN_IPSDK_DATA_CMD_SYSTEM_TIME,				///<! "/NetSDK/System/Time"
	EN_IPSDK_DATA_CMD_SYSTEM_WIRED,				///<! "/NetSDK/NetWork/Interface/Wired"
	EN_IPSDK_DATA_CMD_AUDIO_ENCODE,				///<! "/NetSDK/Media/Audio/Encode"
	EN_IPSDK_DATA_CMD_VIDEO_ENCODE,				///<! "/NetSDK/Media/Video/Encode"
	EN_IPSDK_DATA_CMD_VIDEO_REQESTKEYFRAME,		///<! "/NetSDK/Media/Video/RequestKeyFrame"
	EN_IPSDK_DATA_CMD_VIDEO_OSD,				///<! "/NetSDK/Media/Video/OSD"
	EN_IPSDK_DATA_CMD_VIDEO_PRIVACYMASK,		///<! "/NetSDK/Media/Video/PrivacyMask"
	EN_IPSDK_DATA_CMD_VIDEO_MOTIONDETECTION,	///<! "/NetSDK/Media/Video/MotionDetection"
	EN_IPSDK_DATA_CMD_VIDEO_ISP,				///<! "/NetSDK/Media/Video/ISP"
	EN_IPSDK_DATA_CMD_VIDEO_SNAPSHOT,			///<! "/NetSDK/Media/Video/Snapshot"
	EN_IPSDK_DATA_CMD_SYSTEM_LIGHT,				///<! "/NetSDK/System/Light"
	EN_IPSDK_DATA_CMD_ALARMTONE_PLAY,			///<! 告警提示音试听
	EN_IPSDK_DATA_CMD_UPLOAD_ISP_FILE,			///<! 客户端上传 ISP 配置文件
	EN_IPSDK_DATA_CMD_UPLOAD_OEM_FILE,			///<! 客户端上传 OEM 定制文件
	EN_IPSDK_DATA_CMD_PRODUCT_TEST,				///<! 整机测试
	EN_IPSDK_DATA_CMD_DEVICE_PROPERTY,

	EN_IPSDK_DATA_CMD_PROPERTY_DEVICECAPS,			///<! 获取设备能力集	IPSDK_DeviceCapabilities
	EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_TIME,			///<! 设备时间参数		IPSDK_SystemTime
	EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_MAINTAIN,		///<! 系统维护			IPSDK_SystemMaintain
	EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_ADVERTTONE,	///<! 广告语			IPSDK_SystemAdvertTone
	EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_BROADTONE,	///<! 语音播报			IPSDK_SystemBroadTone
	EN_IPSDK_DATA_CMD_PROPERTY_SYSTEM_LIGHTDEVICE,	///<! 灯源参数	IPSDK_LightDevice
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_HUMAN,			///<! 人形检测参数		IPSDK_VideoHuman
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ROICONFIG,	///<! ROI参数				IPSDK_RoiConfig
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ALARMTONE,	///<! 告警提示音		IPSDK_AlarmTone
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MD,			///<! 移动侦测			IPSDK_MotionDetection
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_MASK,			///<! 视频掩盖			IPSDK_VideoMask
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_OSD,			///<! 视频OSD			IPSDK_VideoOsd
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ENCODER,		///<! 视频编码参数		IPSDK_VideoEncoder
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_ISPCONFIG,		///<! 视频采集参数	IPSDK_VideoIspConfig
	EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_AIAO,			///<! 音频输入输出		IPSDK_AudioAiao
	EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_ENCODER,		///<! 音频编码器		IPSDK_AudioEncoder
	EN_IPSDK_DATA_CMD_PROPERTY_AUDIO_DECODER,		///<! 音频解码器		IPSDK_AudioDecoder
	EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_CONFIG,		///<! 网络配置			IPSDK_NetConfig
	EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_DNS,			///<! dns配置			IPSDK_NetDns
	EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_GB28181,		///<! GB28181配置		IPSDK_NetGB28181
	EN_IPSDK_DATA_CMD_PROPERTY_NETWORK_IPADAPT,		///<! IP自适应		IPSDK_NetIpAdaption
	EN_IPSDK_DATA_CMD_PROPERTY_ALARM_LINKAGE,		///<! 报警联动			IPSDK_AlarmLinkage
	EN_IPSDK_DATA_CMD_PROPERTY_ACCOUNT_MGR,		///<! 账户管理				IPSDK_AccountMgr
	EN_IPSDK_DATA_CMD_PROPERTY_IRCUT_REVERSE,	///<! IR-CUT反向			IPSDK_PropBoolean
	EN_IPSDK_DATA_CMD_PROPERTY_VIDEO_CD,			///<! 遮挡侦测			IPSDK_CoverDetection

	EN_IPSDK_DATA_CMD_PROTOCOL_JSON = (0x1001),				///<! 整机测试

	EN_IPSDK_DATA_CMD_BTN,
} EN_IPSDK_DATA_PARAM;

#pragma pack (push, 4)
/**
*
* 共用结构体定义
*/
typedef struct tag_ipsdk_time_segment_
{
	IPSDK_PropBoolean		bEnable;	//// 是否开启
	IPSDK_PropInteger		nStartTime;	//// 开始时间
	IPSDK_PropInteger		nStopTime;	//// 停止时间
	IPSDK_PropInteger		nWeekday;	//// 星期几位取值
	IPSDK_PropInteger		nType;		//// 为兼用不同版本需要的时间布防类型标识
} IPSDK_TimeSegment;

/**
 * @brief
 *  ipsdk 设备能力集。
 */
typedef struct tag_ipsdk_DeviceCapabilities
{
	/// 设备硬件码，用于在固件升级时作为设备的唯一性，\n
	/// 缺省为 0。
	IPSDK_UInt32 hwCode;

	/// 硬件版本号，\n
	/// 缺省为 "1.0.0"。
	IPSDK_Char hwVersion[32];

	/// 扩展版本标识，\n
	/// 缺省为 ""。
	IPSDK_Char extVersion[16];

	/// 设备版本号，建议使用三段式格式 x.x.x，\n
	/// 缺省为 SDK 版本号。
	IPSDK_Char swVersion[32];

	/// 应用程序编译时间，建议使用ISO8601格式，\n
	IPSDK_Char fwCompileTime[32];

	/// 设备序列号，发现设备时作为UID+MAC返回，\n
	/// 缺省为 ""。
	IPSDK_Char sn[64];

	/// 设备pid号，发现设备时作为产品名称返回，\n
	/// 缺省为 ""。
	IPSDK_Char pid[64];

	/// 设备支持有线网络 RJ45 接口，\n
	/// 缺省为 True。
	IPSDK_Boolean supportRJ45;

	/// 设备支持无线站点模式，对于支持 WiFi 站点模式的无线设备，置位此标识，\n
	/// 缺省为 False。
	IPSDK_Boolean supportWiFiStation;

	/// 设备支持无线热点模式，对于支持 WiFi 热点模式的无线设备，置位此标识。\n
	/// 缺省为 False。
	IPSDK_Boolean supportWiFiAP;

	/// 设备支持无线站点与热点模式同时工作，置位此标识。\n
	/// 当此标致置位后，自动忽略 @ref supportWiFiStation 和 @ref supportWiFiAP，\n
	/// 缺省为 False。
	IPSDK_Boolean supportWiFiRepeater;

	/// 最大通道号，最大 128 路，\n
	/// 缺省为 1。
	IPSDK_Size maxMediaChannel;

	/// 通道能力描述。

	struct
	{
		/// 每个通道最大码流，\n
		/// 缺省为 2。
		IPSDK_Size maxStream;

		struct
		{
			/// 每个码流的最大访问数，\n
			/// 缺省为 4。
			IPSDK_Size maxOnCommand;

		} Stream[IPSDK_DEV_MAX_MEDIA_CH_STREAM];

	} MediaChannel[IPSDK_DEV_MAX_MEDIA_CH];

	/// 最大 TF 卡支持，\n
	/// 缺省为 1。
	IPSDK_Size maxTFCard;

	/// 最大硬盘支持，\n
	/// 缺省为 0。
	IPSDK_Size maxHardDiskDriver;

} IPSDK_DeviceCapabilities;

typedef struct tag_ipsdk_channel_info_
{
	IPSDK_Int nChannel;		/// 设备通道
	IPSDK_Int nStream;		/// 主码流[0],从码流[1]
} IPSDK_ChannelInfo;

typedef struct tag_ipsdk_device_info_
{
	IPSDK_Char strDevModel[32];			/// 设备型号定义。
	IPSDK_Char strDevMagic[64];			/// 设备平台唯一号
	IPSDK_Char strDevName[32];			/// 设备名称
	IPSDK_Char strDevBuildDate[32];		/// 设备发布版本日期
	IPSDK_Char strDevHardVer[32];		/// 硬件版本号
	IPSDK_Char strDevSoftVer[32];		/// 软件版本号
	IPSDK_Char strDevSerialId[32];		/// 出厂序列号[32位]
	IPSDK_Char strDevCloudId[32];		/// 设备的云 ID 号。
	IPSDK_Char strDevOemName[32];		/// 设备OEM厂家名字
	IPSDK_Char strDevOemId[32];			/// 设备OEM的ID
	IPSDK_Char strDevOemSN[64];			/// 设备平台唯一号
	IPSDK_Char res[64];					/// 扩展结构
} IPSDK_DeviceInfo;

typedef struct tag_ipsdk_lan_info_
{
	IPSDK_Int nSessionPort;				/// 会话端口
	IPSDK_Int nStreamPort;				/// 直播端口
	IPSDK_Char strDns1[64];				/// dns域名
	IPSDK_Char strDns2[64];				/// dns域名
	struct
	{
		IPSDK_Char strNetType[16];		/// 网络类型: 有线[Wired]/无线[Wireless]
		IPSDK_Char strIpAddr[16];
		IPSDK_Char strMask[16];
		IPSDK_Char strGateway[16];
		IPSDK_Char strMacAddr[24];
		IPSDK_Int bEnableDhcp;
		EN_IPSDK_AllNetConnect enAllNetConnect;	/// 全网通
	} Lan[2];
	IPSDK_Char res[64];					/// 扩展结构
} IPSDK_LanInfo;

typedef struct tag_IPSDK_UserInfo
{
	IPSDK_Char strUserName[IPSDK_USER_MAX_NAME_SZ];		/// 用户名
	IPSDK_Char strPassword[IPSDK_USER_MAX_PASS_SZ];		/// 密码
	IPSDK_Char res[64];					/// 扩展结构
} IPSDK_UserInfo;

typedef struct tag_IPSDK_SearchDevice
{
	IPSDK_Char strDeviceId[64];		/// 自动获取填充设备对像ID,用来标识设备端设备
	EN_IPSDK_DeviceMode nDeviceMode;	/// 设备（灯光）类型
	IPSDK_DeviceInfo stDeviceInfo;	/// 设备信息
	IPSDK_LanInfo stLanInfo;
	IPSDK_UserInfo stUserInfo;
	IPSDK_UInt64 enLicenseMask;		/// 授权掩码，是EN_IPSDK_LicenseMask的组合
	EN_IPSDK_ProductCommand enProductCmd;	/// 产测命令
} IPSDK_SearchDevice;

/**
 * @brief
 *  IPSDK 视频编码器数据结构定义。
 */
typedef struct tag_IPSDK_VideoEncoder
{
	/// 编码器名称，根据此值区分具体数据结构。@ref EN_IPSDK_VideoEncCodec
	IPSDK_PropEnum enCodec;

	union
	{
		struct
		{
			/// 编码器配置。@ref EN_IPSDK_ProfileMode
			IPSDK_PropEnum enEncodeProfile;

			/// 编码分辨率。@ref #define IPSDK_IMG_SZ
			IPSDK_PropEnum enResolution;

			/// 码率控制模式。@ref EN_IPSDK_BitRateCtrlMode
			IPSDK_PropEnum enBitRateCtrlMode;

			/// 编码码率（单位：kbps，千位每秒）。
			IPSDK_PropInteger nBitRate;

			/// 编码帧率（单位：fps，帧每秒）。
			IPSDK_PropInteger nFrameRate;

			/// 关键帧间隔（单位：frames，帧）。
			IPSDK_PropInteger nKeyFrameInterval;
		} H264, H265, HEVC;
	};

} IPSDK_VideoEncoder;

/**
* 音频输入输出设置
*/
typedef struct tag_IPSDK_AudioAiao
{
	IPSDK_PropInteger nSampleRate;		/// 音频采样率[8000,16000,32000]
	IPSDK_PropInteger nSampleBitWidth;	/// 音频采样位宽[8,16]
	IPSDK_PropInteger nInputVolume;		/// 音频输入音量
	IPSDK_PropInteger nOutputVolume;	/// 音频输出音量
	IPSDK_PropEnum enInputMode;			/// 音频输入模式。@ref EN_IPSDK_AudioInputMode
} IPSDK_AudioAiao;

/**
* 音频编码解码器
*/
typedef struct tag_ipsdk_audio_encoder_decoder_
{
	IPSDK_PropBoolean bEnabled;		/// 音频开启关闭使能
	IPSDK_PropEnum enPayload;		/// 音频编码解码类型。@ref EN_IPSDK_AudioEncCodec
} IPSDK_AudioEncoder, IPSDK_AudioDecoder;


/**
 * @brief 告警联动配置相关数据结构。
 */
typedef struct tag_ipsdk_alarm_Linkage
{
	IPSDK_PropBoolean	bAlarmLights;		///!< 警示灯闪烁使能
	IPSDK_PropBoolean	bToneBroadcast;		///!< 语音播报使能
	IPSDK_PropBoolean	bTfCardRecord;		///!< TF卡录像使能
	IPSDK_PropBoolean	bLampWhiteFlashes;	///!< 白光灯闪烁使能
} IPSDK_AlarmLinkage;

/**
 * @brief 移动侦测配置相关数据结构。
 */
typedef struct tag_ipsdk_video_motion_detection_
{
	struct
	{
		IPSDK_PropBoolean	bEnable; 		///!< 白天告警使能
		IPSDK_PropInteger	nSensitivity;	///!< 白天灵敏度[0-100]
		IPSDK_PropInteger	nThreshold;		///!< 白天告警阈值[0-100]
	} DayAlarm;

	struct
	{
		IPSDK_PropBoolean	bEnable; 		///!< 夜晚告警使能
		IPSDK_PropInteger	nSensitivity;	///!< 夜晚灵敏度[0-100]
		IPSDK_PropInteger	nThreshold;		///!< 夜晚告警阈值[0-100]
		IPSDK_TimeSegment	stTimeSegment;	///!< 夜晚时间段
	} NightAlarm;

	/**
	 * 检测区域掩码。
	 * 配置视频运动侦测除了配置灵敏度以外还须要配置检测掩码，
	 * 当掩码活动区域全部为 True 的时候表示整个视频运动检测，
	 * 否则则为掩码区域活动的区域检测，检测掩码最大颗粒为 32x24，如果设备运动这测区域实现的颗粒大于此值则须要进行适配。
	 *
	 */
	struct
	{
		/**
		 * 小于等于 32x24。
		 */
		IPSDK_Size nColumns, nRows;
		IPSDK_Byte arrMatrix[24][32];
	} Mask;

	/**
	 * @brief 布防时间段设置
	 */
	IPSDK_TimeSegment stAlarmSegment[IPSDK_MAX_TIMESEGMENT];	// 布防时间段

	/**
	 * @brief 告警联动设置
	 */
	IPSDK_AlarmLinkage stAlarmLinkage;	// 告警联动
} IPSDK_VideoMd, IPSDK_MotionDetection;

/**
 * @brief 遮挡侦测配置相关数据结构。
 */
typedef struct tag_ipsdk_video_cover_detection_
{
	IPSDK_PropBoolean	bEnable;		///!< 告警使能
	IPSDK_PropInteger	nSensLevel;		///!< 灵敏度级别[1-5]
	IPSDK_PropInteger	nThreshold; 	///!< 告警阈值[0-100]

	/**
	 * @brief 布防区域设置
	 */
	IPSDK_PropFloat		fRegionX;		// 布防区域左上角X坐标(百分比)
	IPSDK_PropFloat		fRegionY;		// 布防区域左上角Y坐标(百分比)
	IPSDK_PropFloat		fRegionW;		// 布防区域宽度(百分比)
	IPSDK_PropFloat		fRegionH;		// 布防区域高度(百分比)

	/**
	 * @brief 布防时间段设置
	 */
	IPSDK_TimeSegment stAlarmSegment[IPSDK_MAX_TIMESEGMENT];	// 布防时间段

	/**
	 * @brief 告警联动设置
	 */
	IPSDK_AlarmLinkage stAlarmLinkage;	// 告警联动
} IPSDK_VideoCd, IPSDK_CoverDetection;

/**
* 视频隐私区域配置相关数据结构。
*/
typedef struct tag_ipsdk_video_mask_
{
	struct
	{
		IPSDK_PropBoolean bEnabled;
		IPSDK_PropInteger nColor;
		IPSDK_PropFloat x, y, width, height;
	} Mask[4];
} IPSDK_VideoMask;

/**
* 视频OSD显示域配置相关数据结构。
*/
typedef struct tag_ipsdk_video_osd_
{
	/**
	 * 显示模式(保留)。
	 */
	IPSDK_PropEnum enMethod;

	struct {

		/**
		 * 显示标识。
		 */
		IPSDK_PropBoolean bEnabled;

		/**
		 * 显示位置。
		 */
		IPSDK_PropFloat x, y;

		/**
		 * 字体/背景颜色。
		 */
		IPSDK_PropInteger nFontColor, nBackColor;

		/**
		 * 文本编码标识，
		 * 为 True 时则 @ref Text 编码为 UTF-8，否则为 GB2312。
		 */
		IPSDK_PropBoolean bTextUTF8;

		/**
		 * 传入文本。
		 */
		IPSDK_PropString strText;

	} Title[IPSDK_MAX_EXPAND_TITLE];

	struct {

		/**
		 * 显示标识。
		 */
		IPSDK_PropBoolean bEnabled;

		/**
		 * 显示位置。
		 */
		IPSDK_PropFloat x, y;

		/**
		 * 字体/背景颜色。
		 */
		IPSDK_PropInteger nFontColor, nBackColor;

		/**
		 * 显示星期标识。
		 */
		IPSDK_PropBoolean bDisplayWeekday;

		/**
		 * 显示中文。
		 */
		IPSDK_PropBoolean bDisplayChinese;

		/**
		 * 显示时间 12 小时制标识。
		 */
		IPSDK_PropBoolean bTimeFormt12HRs;

		/**
		 * 日期显示格式。@ref EN_IPSDK_DateFormat
		 */
		IPSDK_PropEnum enDateFormat;

		/**
		 * 时间显示格式。@ref EN_IPSDK_TimeFormat
		 */
		IPSDK_PropEnum enTimeFormat;

	} Time;

} IPSDK_VideoOsd;


/**
 * @brief 告警提示音配置相关数据结构。
 */
typedef struct tag_ipadk_AlarmTone
{
	struct
	{
		IPSDK_PropBoolean bDisplay; 	/// 告警提示音列表显示使能
		IPSDK_PropInteger nRepeatTimes; /// 重复播报告警提示音次数，默认为一次
		IPSDK_PropInteger nRoiIndex;	/// 告警提示音对应的ROI序号(范围为 0 ~ IPSDK_ROI_MAX_ENT - 1)
		IPSDK_PropEnum enToneType;		/// 告警提示音类型，用以区分播报不同的音频文件@ref EN_IPSDK_AlarmToneType
		IPSDK_TimeSegment stSchedule;	/// 告警提示音时间布防，只有在布防时间内触发报警才播报提示音
	} AlarmTone[IPSDK_ALARM_TONE_MAX_ENT];
} IPSDK_AlarmTone;


typedef struct tagIPSDK_Coordinate
{
	IPSDK_PropFloat x;								/// 横坐标 百分比
	IPSDK_PropFloat y;								/// 纵坐标 百分比
} IPSDK_Coordinate;

/**
 * @brief ROI（感兴趣区域）配置相关数据结构。
 */
typedef struct tag_ipsdk_RoiConfig
{
	struct
	{
		IPSDK_PropBoolean bEnable;						/// 区域使能开关
		IPSDK_PropInteger nDefaultColor;				/// 默认非报警时线框显示的颜色
		IPSDK_PropInteger nAlarmColor;					/// 报警时线框显示的颜色
		IPSDK_PropInteger nDotTotal;					/// 多边形总边数
		IPSDK_Coordinate stDot[IPSDK_ROI_DOT_MAX_ENT];	/// 多边形各顶点坐标
	} RoiCfg[IPSDK_ROI_MAX_ENT];
} IPSDK_RoiConfig;


/**
 * @brief 人形配置相关数据结构。
 */
typedef struct tag_ipsdk_VideoHuman
{
	/// 使能开关
	IPSDK_PropBoolean bEnable;

	/// 灵敏度
	IPSDK_PropInteger nSensitivity;

} IPSDK_VideoHuman;


/**
* @brief ISP 设置模块 是 @ref IPSDK_VideoIspConfig 的子集
*/
typedef struct tag_ipsdk_video_image_
{
	IPSDK_PropInteger nBrightness;		///<! 亮度值
	IPSDK_PropInteger nSaturation;		///<! 饱和度
	IPSDK_PropInteger nSharpness;		///<! 锐度值
	IPSDK_PropInteger nContrast;		///<! 对比度
	IPSDK_PropInteger nHue;				///<! 色度
	IPSDK_PropInteger nBacklight;		///<! 背光
	IPSDK_PropEnum enVideoStandard;		///<! 视频制式@ref EN_IPSDK_PowerFrequence
	IPSDK_PropBoolean bHFlip;
	IPSDK_PropBoolean bVFlip;			///<! 水平和垂直翻转使能开关
	IPSDK_PropBoolean bPreventExposure;	///<! 防过曝开关
} IPSDK_VideoImage;

/**
* @brief 高级参数属性值描述
*  包含3种属性元： 使能、模式(自动/手动)、增益
*/
typedef struct tag_ipsdk_isp_attr_
{
	IPSDK_PropBoolean bEnable;
	IPSDK_PropBoolean bAutoMode;
	IPSDK_PropInteger nValue;
} IPSDK_AdvacedAttr;

/**
* @brief ISP 高级配置
*  是 @ref IPSDK_VideoIspConfig 的子集
*/
typedef struct tag_ipsdk_isp_Advaced_config_
{
	IPSDK_PropEnum		enExposureMode;	///!< 曝光模式@ref EN_IPSDK_ImageExposureMode
	struct
	{
		IPSDK_PropInteger	nStep;		///!< AE灵敏度
		IPSDK_PropInteger	nTolerance;	///!< AE容忍度
	}ae;
	struct
	{
		IPSDK_PropBoolean bEnable;		/// 模块使能
		IPSDK_PropBoolean bAutoMode;	/// manual[0] auto[1]
		IPSDK_PropInteger nManualRgain;	/// [0-255]白平衡R增益
		IPSDK_PropInteger nManualBgain;	/// [0-255]白平衡B增益
	}awb;								///!< 白平衡
	IPSDK_PropEnum		enColorStyle;	///!< 风格(保留)
	IPSDK_PropBoolean	bLensDistortion;///!< 镜头畸变 lens distortion
	IPSDK_PropBoolean	bSuperStarLight;///!< 超星光模式
	IPSDK_PropEnum		enSceneMode;	///!< 场景模式@ref EN_IPSDK_ImageSceneMode
	IPSDK_AdvacedAttr	stImageWdr;		///!< 宽动态
	IPSDK_AdvacedAttr	stDenoise2D;	///!< 2D降噪
	IPSDK_AdvacedAttr	stDenoise3D;	///!< 3D降噪
	IPSDK_AdvacedAttr	stThroughFog;	///!< 透雾模式
} IPSDK_AdvacedIsp;

/**
* @brief 图像效果参数(isp config)
*/
typedef struct tag_ipsdk_video_isp_config_
{
	IPSDK_VideoImage	stImageConfig;	///!< ISP图像参数
	IPSDK_AdvacedIsp	stAdvacedIsp;	///!< ISP高级参数
} IPSDK_VideoIspConfig;

/**
 * @brief 串口配置相关数据结构。
 */
typedef struct tag_IPSDK_Serial
{
	IPSDK_PropInteger nPort;		/// 设备端口号
	IPSDK_PropInteger nBaudRate;	/// 波特率
	IPSDK_PropInteger nFlowCtrl;	/// 流控
	IPSDK_PropInteger nDataBits;	/// 数据位
	IPSDK_PropInteger nParity;		/// 校验
	IPSDK_PropInteger nStopBits;	/// 停止位
} IPSDK_SystemSerial;


/**
* @brief 设备时间配置相关数据结构。
*/
typedef struct tag_ipsdk_system_time_
{
	IPSDK_PropEnum	enSyncTime;	///!< 生效的同步方式 @ref EN_IPSDK_SyncTime

	union
	{
		struct
		{
			IPSDK_PropBoolean	bEnable;		///!< 使能开关(保留)
			IPSDK_PropString	strDomain;		///!< 域名，需要提供当前值和默认值即可
			IPSDK_PropInteger	nPort;			///!< ntp端口号
			IPSDK_PropInteger	nSyncCycle; 	///!< 同步时间周期
		} NtpTime; ///!< ntp同步时间
		struct
		{
			IPSDK_UInt32	u32Utc; 			/// UTC 时间（格林尼治相对公元1970年1月1日00时00分00秒时间戳）
			IPSDK_TimeZone	enTimeZone; 		/// 时间所在时区
		} ManualTime; ///<! 手动同步时间
	};
} IPSDK_SystemTime;

typedef struct tag_ipsdk_system_maintain_
{
	IPSDK_PropBoolean	bEnable;			//!< 使能开关，是否开启定时维护功能
	IPSDK_PropEnum		enWeekDay;			//!< 重启的工作日 @ref EN_IPSDK_Week
	IPSDK_UInt32		u32RebootTimes;		//!< 重启的时间点(如02:00重启就是2*3600秒)
} IPSDK_SystemMaintain;


/**
 * @brief
 *  网卡配置信息。
 */
typedef struct tag_ipsdk_net_config_
{
	/**
	 *
	 * +-------------+------------+------------+------------+------------+------------+
	 * |             | ESSID      | PSK        | EnableDHCP | HwAddr     | { IPv4 }   |
	 * +-------------+------------+------------+------------+------------+------------+
	 * | NetWired    | n          | n          | y          | y          | y          |
	 * +-------------+------------+------------+------------+------------+------------+
	 * | NetWiFi     | y          | y          | y          | y          | y          |
	 * +-------------+------------+------------+------------+------------+------------+
	 *
	 */

	/**
	 * 连接无线热点 / NVR 所对应的 ESSID。
	 */
	IPSDK_PropString strESSID;

	/**
	 * 当 classify 为 IPSDK__LAN_SETUP_WIFIAP 时，\n
	 * 表示热点的接入密码；\n
	 * 当 classify 为 IPSDK__LAN_SETUP_WIFISTA 或者 IPSDK__LAN_SETUP_WIFINVR 时，\n
	 * 表示连接无线热点 / NVR 所对应的 ESSID 的接入密码。
	 */
	IPSDK_PropString strPSK;

	/**
	 * 当 classify 为 IPSDK__LAN_SETUP_WIFIAP 时，\n
	 * 表示本地是否开启 DHCP 服务；\n
	 * 当 classify 为 IPSDK__LAN_SETUP_WIFISTA 时，\n
	 * 表示是否使用无线热点的 DHCP 服务获取地址；\n
	 * 当 classify 为 IPSDK__LAN_SETUP_WIFINVR 时，\n
	 * 此值一直为 False。
	 */
	IPSDK_PropBoolean bEnableDHCP;

	/**
	 * 物理网卡地址。
	 */
	IPSDK_PropHwAddr HwAddr;

	/**
	 * IP 地址配置。
	 */
	IPSDK_PropIPv4 IPAddress, Netmask, Gateway, DomainNameServer;

	/**
	 * Wi-Fi 工作模式，对应 @ref EN_IPSDK_EthWiFiMode 类型。
	 */
	IPSDK_PropEnum enWiFiMode;

	/**
	 * Wi-Fi 连接相关参数。\n
	 * 每个对象包含一个数据（如 @ref _Station）和数据指针（如 @ref Station），当数据指针指向数据时表示有效，\n
	 * 数据结构中分表描述 Wi-Fi 连接所需要的 essid 和密码，分辨对应 @ref essid 和 @ref passphrase 参数，\n
	 * 在中继使用时，客户端会设置两个站点配置，分别为 @ref Station 和 @ref StationAlternative，具体使用哪个连接似乎设备自身策略，\n
	 * 对于站点模式来说，@ref Station::essid 和 @ref Station::passphrase 分别代表连接到的热点名称和校验密码，\n
	 * 对于热点模式，@ref AccessPoint::essid 和 @ref AccessPoint::passphrase 分别代表热点本身被广播名称和校验密码。\n
	 */
	struct
	{
		/**
		 * 连接网络热点的名称。
		 */
		IPSDK_Char strEssid[32];

		/**
		 * 链接网络 @ref essid 对应密码。
		 */
		IPSDK_Char strPassphrase[32];

		/**
		 * 隐藏 SSID 标志，仅在热点模式和中继模式有效。
		 */
		IPSDK_Boolean bHidden;

		/**
		 * 热点开放信道，对应 @ref EN_IPSDK_EthWiFiAccessChannel \n
		 * 仅在热点模式和中继模式有效。
		 */
		IPSDK_PropEnum enAccessChannel;

	} _Station, _StationAlternative, _AccessPoint, *Station, *StationAlternative, *AccessPoint;

	/**
	 * 只读，仅在中继模式有效。
	 */
	IPSDK_Int nConnection;
	/**
	 * 站点或中继模式下的速率
	 */
	IPSDK_Int nStationsignal;
	/**
	 * 连接信息。
	 */
	struct
	{
		/**
		 * 连接设备的物理地址。
		 */
		IPSDK_PropHwAddr hwBssID;

		/**
		 * 连接速率。
		 */
		IPSDK_PropInteger nRate;

	} Connection[8];

	/// 临时修改标识，保留。
	IPSDK_Boolean bTemporary;

} IPSDK_NetConfig;

/**
 * DNS 地址配置。
 */
typedef struct tag_ipsdk_net_dns_
{
	/**
	 * 首选的 DNS 地址。
	 */
	 IPSDK_PropIPv4 Preferred;

	/**
	 * 备用的 DNS 地址。
	 */
	 IPSDK_PropIPv4 Alternative;

} IPSDK_NetDns;

/**
 * ip 自适应 配置。
 */
typedef struct tag_ipsdk_net_ipadaption_
{
	/**
	 * IP 自适应使能标识。
	 * 记录到配置文件。
	 */
	IPSDK_PropBoolean bAutoAdaption;

	/**
	 * 临时配置变量，不用保存到配置，
	 * 此标识和 @ref IPAutoAdaption 没有绝对关系，表示当前状态模块内期望临时开启、关闭自适应功能。
	 * 在上层实现中，仅当 @ref IPAutoAdaption 和 @ref ipAutoAdaptionActived 同时使能时 IP 自适应个功能有效。
	 *
	 */
	IPSDK_Boolean bAutoAdaptionActived;

} IPSDK_NetIpAdaption;

/**
 * @brief 广告语配置相关数据结构。
 */
typedef struct tag_ipsdk_system_AdvertTone_
{
	struct
	{
		IPSDK_PropBoolean	bEnable;		/// 广告语列表显示使能
		IPSDK_PropInteger	nRepeatTimes;	/// 重复播报广告语次数，默认为一次
		IPSDK_PropInteger	nCycleInterval;	/// 循环播放广告语间隔时间，以秒为单位
		IPSDK_PropEnum		enToneType;		/// 广告语类型，用以区分播报不同的音频文件@ref EN_IPSDK_AdvertToneType
		IPSDK_TimeSegment	stSchedule;		/// 广告语时间布防，只有在布防时间内才播报广告语
	} AdvertTone[IPSDK_ADVERT_TONE_MAX_ENT];
} IPSDK_SystemAdvertTone;

/**
 * @brief 语音播报配置相关数据结构。
 */
typedef struct tag_ipsdk_system_BradcastTone_
{
	IPSDK_PropBoolean bSelfCheckBroadcast;	//// 开机自检语音使能
	IPSDK_PropBoolean bHourlyBroadcast;		//// 整点报时语音使能
	IPSDK_PropBoolean bSystemBroadcast;		//// 系统配置语音使能
} IPSDK_SystemBroadTone;

/**
 * @brief 光源配置相关数据结构。
 */
typedef struct tag_ipsdk_system_light_device_
{
	IPSDK_PropEnum		enDeviceType;		/// 光敏类型@ref EN_IPSDK_LdrType,软光敏/硬光敏
	IPSDK_PropEnum		enImageMode;		/// 图像模式@ref EN_IPSDK_ImageMode
	IPSDK_PropEnum		enLightMode;		/// 光源模式@ref EN_IPSDK_LightMode
	IPSDK_PropEnum		enLightTurnOnSens;	/// 光源启动灵敏度@ref EN_IPSDK_LightTurnOnSens
	IPSDK_PropEnum		enLightAutoAdjSens;	/// 光源自动调节灵敏度@ref EN_IPSDK_LightAutoAdjSens
	IPSDK_PropBoolean	bLightDebug;		/// 光源调试模式@ref IPSDK_False:关闭光源调试模式 IPSDK_True:开启光源调试模式
	struct
	{
		IPSDK_PropInteger	nNormal2IrIsoThr; /* RW, Range: [0, 0xFFFFFFFF]. ISO threshold of switching from normal to IR mode. */
		IPSDK_PropInteger	nIr2NormalIsoThr; /* RW, Range: [0, 0xFFFFFFFF]. ISO threshold of switching from IR to normal mode. */
		IPSDK_PropInteger	nRGMax;			/* RW, Range: [0x0, 0xFFF]. Maximum value of R/G in IR scene, 4.8-bit fix-point. */
		IPSDK_PropInteger	nRGMin;			/* RW, Range: [0x0, u32RGMax]. Minimum value of R/G in IR scene, 4.8-bit fix-point. */
		IPSDK_PropInteger	nBGMax;			/* RW, Range: [0x0, 0xFFF]. Maximum value of B/G in IR scene, 4.8-bit fix-point. */
		IPSDK_PropInteger	nBGMin;			/* RW, Range: [0x0, u32BGMax]. Minimum value of B/G in IR scene, 4.8-bit fix-point. */
	} SoftProteus;							/// 软光敏功能（只有在光源调试模式开启时才允许设置）
	struct
	{
		IPSDK_PropEnum		enOptType;		/// 定义自动模式/手动模式@ref EN_IPSDK_PWMMode
		IPSDK_PropInteger	nDutyRatio;		/// 定义占空比[0-100] 灯源亮度强度
		IPSDK_PropInteger	nLumThd;		/// 定义lum阀值:分界黑转彩 总体亮度阈值
		IPSDK_PropInteger	nIsoThd;		/// 定义iso阀值:分界黑转彩 环境亮度阈值
	} AutoControl[2];						/// PWM功能[0]红外，[1]白光/暖光
	IPSDK_TimeSegment		stNightRange;	/// 夜晚时间段（图像模式为定时模式下生效，除此之外的时间均为白天时间段）
} IPSDK_LightDevice;

/**
 * @brief GB28181 配置相关数据结构。
 */
typedef struct tag_ipsdk_network_gb28181_
{
	IPSDK_PropBoolean bEnable;			// 使能开关，是否开启GB28181功能
	IPSDK_Char strServerHost[32];		// 服务器地址
	IPSDK_UInt32 nServerPort;			// 服务器端口
	IPSDK_Char strServerID[32];			// 服务器ID
	IPSDK_Char strServerName[32];		// 服务器域
	IPSDK_UInt32 nExpires;				// 注册有效期
	IPSDK_UInt32 nKeepAlive;			// 心跳周期
	IPSDK_UInt32 nKeepAliveNum;			// 最大心跳超时次数
	IPSDK_Char strDevName[32];			// 用户名
	IPSDK_Char strDevID[32];			// 用户认证ID
	IPSDK_Char strPasswd[32];			// 用户认证密码
	IPSDK_UInt32 nDevPort;				// 本地端口
	IPSDK_UInt32 nStreamIdx;			// 流索引号 0:主码流; 1:子码流。
	IPSDK_Char strVideoID[32][32];		// 视频通道编码ID
	IPSDK_Char strAudioID[32][32];		// 语音输出通道编码ID
	IPSDK_Char strAlarmID[32][32];		// 报警通道编码ID
} IPSDK_NetGB28181;

/*****************************************************************/
/**
 * @brief 设备语言
 */
typedef struct tag_ipsdk_system_Languagelist
{
	IPSDK_PropEnum	enLanguage;		//!< 支持的语言列表@ref EN_IPSDK_LanguageGroup
} IPSDK_SystemLangList;


/**
 * @brief 用户信息
 */
typedef struct IPSDK_UsrInfo{
	IPSDK_Char				Name[IPSDK_USER_MAX_NAME_SZ];	// !< 用户名
	/**
	 * @brief 密码
	 *	出于保密需要都是客户端提交给服务器端才需要此动作,服务器端不需要回复数据给客户端
	 */
	IPSDK_Char				Psk[IPSDK_USER_MAX_PASS_SZ];	// !< 密码
	IPSDK_Boolean			bEnable;	// !< 是否启用
	EN_IPSDK_UserClassify	enClassify;	// !< 用户权限等级
}IPSDK_UsrInfo;

/**
 * @brief 账户管理
 */
typedef struct IPSDK_AccountMgr
{
	EN_IPSDK_UserMgrCmd	nCmd;		// !< 账户管理命令
	IPSDK_UsrInfo		stUsrs[IPSDK_USR_GROUP_SIZE];	// !< 用户信息
} IPSDK_AccountMgr;


/**
 * @brief 远程回放
 */
typedef struct tag_ipsdk_playback_info_
{
	IPSDK_Int nChannel;		// !< 设备通道,目前暂时不用
	IPSDK_Int nStream;		// !< 主码流[0],从码流[1],目前暂时不用
	IPSDK_UInt64 u64StartTime;		// !< 回放开始时间(UTC)
	IPSDK_Char strSessionId[IPSDK_SESSION_ID_MAX_SZ];	// !< 回放会话ID
} IPSDK_PlaybackInfo;


typedef struct tag_ipsdk_position_
{
	IPSDK_Float x;		/// 横坐标 百分比
	IPSDK_Float y;		/// 纵坐标 百分比
} IPSDK_Position;

/**
 * @brief OSD 刷新
 */
typedef struct tag_ipsdk_osdrefresh_
{
	IPSDK_Int nChannel;		// !< 设备通道,目前暂时不用
	IPSDK_Int nStream;		// !< 主码流[0],从码流[1],目前暂时不用
	IPSDK_Int nIndex;		// !< OSD 刷新索引号，0:对应右上角OSD,1:对应左下角OSD,2:对应右下角OSD
	EN_IPSDK_OsdRefreshType enType;// !< OSD 刷新类型，通过此值判断 stPosition 或者 strText 哪个值生效
	IPSDK_Position stPosition; // !< OSD 刷新坐标，左上角对应(0, 0),右下角对应(100, 100)
	IPSDK_Char strText[IPSDK_DEFULT_LEN];	// !< OSD 显示的文本信息(UTF-8编码)
} IPSDK_OsdRefresh;

/**
 * @brief 通知
 */
typedef struct tag_ipsdk_notification_
{
	EN_IPSDK_NotificationType enType;	// !< 通知类型
	IPSDK_UInt64 u64UTC;				// !< 通知 UTC 时间
	IPSDK_UInt32 u32Reserved;			// !< 保留
} IPSDK_Notification;
#pragma pack (pop)

#endif

