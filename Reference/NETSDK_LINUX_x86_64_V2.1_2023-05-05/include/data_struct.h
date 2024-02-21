#ifndef _____DATA_STRUCT_H____
#define _____DATA_STRUCT_H____


#ifndef LINUX
#define LINUX
#endif

#ifndef NETSDK
#define NETSDK
#endif

#include <time.h>
#include "media_cfg.h"



#define MAX_WORDDAYTIME_COUNT 7
typedef struct
{
	unsigned int workday[MAX_WORDDAYTIME_COUNT];//数组0-6标识周日-周六每小时的配置，每个小时占用一个bit位，0-23BIT有效 
}TimeSpanCfg;


#define MAX_IPC_FILENAME_LEN 128

#define VIDEO_PRIVATE_HEADER_MAGIC 0x1a2b3c4d
typedef struct
{
	uint32_t flag;			//VIDEO_PRIVATE_HEADER_MAGIC
	uint32_t data;
	uint32_t frame_index;
	uint32_t keyframe_index;
}VIDEO_FRAME_HEADER;

#define MAX_USER_SESSION_COUNT 		20
#define MAX_USER_SESSION			40
#define MAX_SESSION_TIMEOUT_SECOND	2400

#define MAX_IP_NAME_LEN 64


#define GROUP_NAME_MAX_LEN 32
typedef struct 
{
	char groupName[GROUP_NAME_MAX_LEN];
}Group;

#define ACCOUNT_STATUS_MAX_LEN 8
#define ACCOUNT_NAME_MAX_LEN 40
#define ACCOUNT_PASSWORD_MAX_LEN  40

typedef struct
{
	char 	userName[ACCOUNT_NAME_MAX_LEN];
	char 	password[ACCOUNT_PASSWORD_MAX_LEN];
	Group 	group;
	char    status[ACCOUNT_STATUS_MAX_LEN];
}UserAccount;

#define MAX_ACCOUNT_COUNT 10

typedef struct
{
	int count;
	UserAccount accounts[MAX_ACCOUNT_COUNT];
}UserConfig;

typedef struct
{
	char  				serverIP[MAX_IP_NAME_LEN];
	unsigned short  	serverPort;
	unsigned int  		refreshInterval;
}NTPConfig;

#define TIME_MODE_MAX_LEN 32
#define TIME_MODE_NAME_NTP  "NTP"
#define TIME_MODE_NAME_MANUAL "MANUAL"
#define TIME_MODE_NAME_P2P  "P2P"

typedef struct
{
	char modeName[TIME_MODE_MAX_LEN];
}TimeMode;

typedef struct
{
	unsigned char nEnable;			//启用标记
	unsigned char bAuto;			//根据时区自动配置
	short nOffsetMin;		//偏移时间(分钟)
	unsigned char nStartMonth;
	unsigned char nStartWeek;		//该月第几周
	unsigned char nStartWeekday;	//周几
	unsigned char nStartHour;		//小时
	unsigned char nToMonth;
	unsigned char nToWeek;		//该月第几周
	unsigned char nToWeekday;	//周几
	unsigned char nToHour;		//小时
}SummerTimeConfig;

typedef struct
{
	TimeMode  	timeMode;
	int 	  	timeZone;
	NTPConfig 	ntpConfig;
	SummerTimeConfig summerConfig;
}TimeConfig;

#define PTZ_PROTOCOL_NAME_MAX_LEN 32
typedef struct
{
	char protocolName[PTZ_PROTOCOL_NAME_MAX_LEN];
}PTZProtocol;


#define VERIFY_NAME_MAX_LEN 32
typedef struct
{
	char verifyName[VERIFY_NAME_MAX_LEN];
}Verify;


#define FLOW_CONTROL_MAX_LEN 32
typedef struct
{
	char flowControlName[FLOW_CONTROL_MAX_LEN];
}FlowControl;

#define PTZ_FUNCTION_TYPE_MAX_LEN 28

typedef struct
{
	char typeName[PTZ_FUNCTION_TYPE_MAX_LEN];
}PTZFunctionType;

#define PTZ_FUNCTION_NAME_MAX_LEN 32

typedef struct
{
	char functionName[PTZ_FUNCTION_NAME_MAX_LEN];
	int  presetNum;
	PTZFunctionType functionType;
	int reserveValue;
	int  presetNum2;
	PTZFunctionType functionType2;
	int interval_sec;
}PTZFunction;


#define MAX_PTZFUCTION_COUNT 64 
typedef struct
{
	int functionCnt;
	PTZFunction functions[MAX_PTZFUCTION_COUNT];
}PTZAdvanceConfig;


typedef struct
{
	PTZProtocol  		ptzProtocol;
	unsigned  int 		comPort;
	unsigned  int 		baudrate;
	unsigned  int 		dataBits;
	unsigned  int 		stopBits;
	Verify 		 		verify;
	FlowControl  		flowControl;
	unsigned int 		bootAction;
}PTZCommonConfig;

typedef struct
{
	int enable;
	int type;		//AF类型: 0: BSD 1: ZUO
	int bSendOnStart;	//启动就发AF数据	
}AfConfig;

typedef struct
{
	PTZCommonConfig    commonCfg;
	PTZAdvanceConfig    advanceCfg;
	AfConfig			afCfg;
}PTZConfig;

#define FTP_NAME_MAX_LEN 128
#define FTP_PASSWORD_MAX_LEN 128
#define FTP_PATH_MAX_LEN 256


#define SMTP_NAME_MAX_LEN			128
#define SMTP_PASSWORD_MAX_LEN		128
#define SMTP_ACCOUNT_MAX_LEN		256
#define SMTP_SUBJECT_MAX_LEN        256


#define LOG_LEVEL_NAME_MAX_LEN 200
typedef struct
{
	char levelName[LOG_LEVEL_NAME_MAX_LEN];
}LogLevel;

#define STORE_MEDIA_NAME_MAX_LEN 32

typedef struct
{
	char mediaName[STORE_MEDIA_NAME_MAX_LEN];
}StoreMedia;

#define STORE_POLICY_NAME_MAX_LEN 32

typedef struct
{
	char policyName[STORE_POLICY_NAME_MAX_LEN];
}StorePolicy;

#define BACKUP_WAY_NAME_MAX_LEN 32

typedef struct
{
	char wayName[BACKUP_WAY_NAME_MAX_LEN];
}BackupWay;

#define SYSLOG_FILE_NAME_MAX_LEN   32 

typedef struct
{
	LogLevel   			logLevel;
	unsigned int	 	maxDays;
	//unsigned int   		maxEventPerday;
	StoreMedia   		storeMedia;
	StorePolicy   		storePolicy;
	int   				autoBackup; // 1  for auto  0 for manual
	BackupWay   		backupWay;
}SyslogConfig;


#define MAX_LANGUAGE_LEN 32

typedef struct
{
	char language[MAX_LANGUAGE_LEN];
}MiscConfig;

typedef struct
{
	int enable;
	int day; //日期： 0-6 = 星期一到星期天， 7=每天
	DayTime time;
}MaintainConfig;

#define MAX_ALOW_IP_NUM 5
typedef struct
{
	int enable;
	unsigned int nAllowIp[MAX_ALOW_IP_NUM];
}SysAlowIpConfig;


#define MAX_ALARM_CLOCK_NUM 5
typedef struct
{
	unsigned char enable;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;	
}AlarmClock;//闹钟设置

typedef struct
{
	unsigned char enable;	
	unsigned char from_hour;
	unsigned char from_minute;
	unsigned char from_second;	
	unsigned char to_hour;
	unsigned char to_minute;
	unsigned char to_second;	
	unsigned char reserved;
}AlarmOClock;//整点报时

typedef struct
{
	AlarmOClock oclock;
	AlarmClock alarmclock[MAX_ALARM_CLOCK_NUM];
}AlarmClockConfig;

typedef struct
{
	PTZConfig     ptzCfg;
	TimeConfig    timeCfg;
	UserConfig    userCfg;
	SyslogConfig  syslogCfg;
	MiscConfig	  miscCfg;
	MaintainConfig maintainCfg;
	SysAlowIpConfig alowipCfg;
	AlarmClockConfig clockSetting;//闹钟设置
}SystemConfig;

// media config

#define TIME_FORMAT_MAX_LEN 32

typedef struct
{
	char format[TIME_FORMAT_MAX_LEN];
}TimeFormat;

typedef struct
{
	int posX;//当posType=POSITION_TYPE_BY_FOUR_CORNER时，只能是0/1/2。否则为比例0-100%
	int posY;//当posType=POSITION_TYPE_BY_FOUR_CORNER时，只能是0/1/2。否则为比例0-100%
	TimeFormat timeFormat;
	Positiontype posType;
}TimeOverlay;

#define TITLE_MAX_LEN 200
typedef struct
{
	int posX;	//当posType=POSITION_TYPE_BY_FOUR_CORNER时，只能是0/1/2。否则为比例0-100%
	int posY;	//当posType=POSITION_TYPE_BY_FOUR_CORNER时，只能是0/1/2。否则为比例0-100%
	char title_utf8[TITLE_MAX_LEN];//当titleType=BMP时，这里存放BMP路径
	Positiontype posType;
	Titletype titleType; 	
}TitleOverlay;

typedef struct
{
	int enable;
	int transparency; //titleFormatEn。叠加信息
	TimeOverlay timeOverlay;
	TitleOverlay titleOverlay;
	short style;	//AjOsdOverlayStyle
	short bDsplayWeek;	//0:不显示 1:在日期和时间的中间显示星期几 2:在末尾显示星期几
	short bOverlayFps;	
	short fontsize; // 0 标准  1 大字体 2 超大字体
	short real_transparency; //透明度。0-100
	short time24or12;// 0: 24 1: 12
}VideoOverlay;


typedef	struct
{
	int enable;
	
	Positiontype posType;
	int pos_xscale;//画面宽度比例位置0-100
	int pos_yscale;//画面高度比例位置0-100

	int	color_front;	//前景颜色
	int color_back;		//背景颜色
	
	short transparency; //透明度。0-100
	unsigned char fontsize; // 0 标准  1 大字体 2 超大字体
	unsigned char linegap; // 0-8,0表示无间距，8表示间距1个字符高度
	char title_utf8[TITLE_MAX_LEN];//当titleType=BMP时，这里存放BMP路径
	Titletype titleType; 	
}UserOSD;

#define MAX_USER_OSD_NUM 5

typedef	struct
{
	UserOSD data[MAX_USER_OSD_NUM];
}VideoUserOverlay;

#define RESOLUTION_NAME_MAX_LEN 32

typedef struct
{
	char name[RESOLUTION_NAME_MAX_LEN];
}Resolution;

#define VIDEO_ENCODE_FORAMT_MAX_LEN 32
typedef struct
{
	char name[VIDEO_ENCODE_FORAMT_MAX_LEN];
}VideoEncodeFormat;


#define BITRATE_CONTROL_MAX_LEN 32
typedef struct
{
	char name[BITRATE_CONTROL_MAX_LEN];
}BitRateControl;

typedef enum
{
	VIDEO_QUALITY_CUSTOM = 0,//自定义
	VIDEO_QUALITY_WORSER = 1, //更差
	VIDEO_QUALITY_WORSE = 2,	 //较差
	VIDEO_QUALITY_NORMAL = 3,    //正常
	VIDEO_QUALITY_GOOD = 4,		 //好
	VIDEO_QUALITY_BEST = 5,      //更好
}VideoQualityEnum;

typedef struct
{
	int qp_enable;	//自定义QP, 为0时系统自动设置
	int qp_min;	//QP最小值,0-51，QP越小画面越精细，每帧的大小就越大；相反，QP越大画面越粗糙，占用的存储空间就越小
	int qp_max; //QP最大值,0-51，同上，需要保证不小于qp_min
}QPConfig;

typedef struct 
{
	int enable;
	int streamID;
	Resolution   resolution;
	VideoEncodeFormat encodeFormat;
	BitRateControl bitRateControl;
	int initQuant;
	int bitRate;
	int frameRate; 
	int display_frameRate; 
	LbrControl lbrConfig;
	VideoQualityEnum bitRateQuality;
	QPConfig		qp; //VBR时自定义QP设置，需要有能力集FUNCTION_QP。VBR时此项才有效
}VideoEncodeCfg;

typedef struct
{
	int enable; //禁用/启用
	int quality;// 20-100
}JpegEncodeCfg;

typedef struct 
{
	int enable;
	Resolution   resolution;
	int frameRate; 
	int format;//NV12/RGB888等等
}YuvEncodeCfg;

#define VIDEO_NUMBER_MAX 3 //定义视频流数量

typedef enum
{
	TWO_LENS_WORKMODE_JOINT_AND_CORRECTION = 0,//拼接并校正
	TWO_LENS_WORKMODE_LEFT_LEN = 1,//左镜头
	TWO_LENS_WORKMODE_RIGHT_LEN = 2,//右镜头
	TWO_LENS_WORKMODE_JOINT_NOT_CORRECTION = 3,//拼接不校正
	TWO_LENS_WORKMODE_TWOSTREAM_Independent  = 4,//双镜头分开出流
}TwoLensWorkMode;

typedef struct
{
	TwoLensWorkMode eTwoLensWorkMode;
	unsigned int nOptimumDistance; //最佳距离
}TwoLensConfig;

typedef struct
{
	VideoEncodeCfg encodeCfg[VIDEO_NUMBER_MAX];
	//encode profile, 0: default, 1: baseprofile
	int encode_profile;
	int disable_private_data; //0: enalbe, 1: disable
	int encode_mode;//0,4
	int noice_level;//0-10
	TwoLensConfig twoLensCfg;
}VideoEncode;

#define VIDEO_FORMAT_MAX_LEN 32

typedef struct
{
	char name[VIDEO_FORMAT_MAX_LEN];
}VideoFormat;

typedef struct
{
	short shutter_mode_day;//0-1	//快门模式:自动/手动
	short shutter_mode_night;//0-1	//快门模式:自动/手动
	short shutter_speed_day;//10-10000	//快门速度
	short shutter_speed_night;//10-10000 //快门速度
}VideoShutter;

typedef enum
{
	IRCUT_Mode_Active = 0, //主动模式/软光敏自动控制模式, ISP自动判断SENSOR增益，控制IRCUT和灯板
	IRCUT_Mode_DayNight =1, //日夜模式，根据时间段来控制IRCUT和图像彩转灰
	IRCUT_Mode_Passive = 2,	//被动模式/硬光敏外部控制模式，根据灯板的光敏电阻给的硬件信号，来控制IRCUT
	IRCUT_Mode_Manual = 3,	//手动模式，不根据灯板和SENSOR增益，由调用者来手动切换
	IRCUT_Mode_ReversePassive =	4, //反向被动模式
	IRCUT_Mode_AUTO_BY_HARDWARE = 5, //硬光敏自动控制模式，根据硬光敏的adc数据来切换日夜
	IRCUT_Mode_LIGHT_ALWAYS_ON = 6, //手动灯光常开
	IRCUT_Mode_LIGHT_ALWAYS_OFF = 7, //手动灯光常关
	IRCUT_Mode_MAX
}IRCutMode;

typedef enum
{
	LED_PURE_INFRAED = 0, //纯红外
	LED_PURE_WHITE = 1, //纯白光
	LED_INFRAED_THEN_WHITE = 2, //红外触发时白光
	LED_WHITE_THEN_INFRAED = 3, //白光触发时红外
}LedMode;

typedef enum
{
	LED_IMAGE_NORMAL = 0,// 正常 
	LED_IMAGE_FACE_EXPOSURE_PREVENTION =1,//防人脸过曝 
	LED_IMAGE_CHEPAI_MODE=2,//: 照车牌模式 1
	LED_IMAGE_INTELLIGENT_FACE_EXPOSURE_PREVENTION=3, //智能防人脸过爆，告警触发时才启用防人脸过曝
	LED_IMAGE_CHEPAI_MODE_2=4,//: 照车牌模式 2
	LED_IMAGE_CHEPAI_MODE_3=5,//: 照车牌模式 3
	LED_IMAGE_CHEPAI_MODE_4=6,//: 照车牌模式 4
	LED_IMAGE_CHEPAI_MODE_5=7,//: 照车牌模式 5
	LED_IMAGE_CHEPAI_MODE_6=8,//: 照车牌模式 6
}LedImageMode;//补光图像模式

typedef enum
{
	IRCUT_OPENLED_ON_ILLUMINATION_0_01 = 0,// 0.01 
	IRCUT_OPENLED_ON_ILLUMINATION_0_05 = 1,// 0.05
	IRCUT_OPENLED_ON_ILLUMINATION_0_08 = 2,// 0.08 
	IRCUT_OPENLED_ON_ILLUMINATION_0_10 = 3,// 0.10 
	IRCUT_OPENLED_ON_ILLUMINATION_0_20 = 4,// 0.20 
	IRCUT_OPENLED_ON_ILLUMINATION_0_30 = 5,// 0.30 
	IRCUT_OPENLED_ON_ILLUMINATION_0_40 = 6,// 0.40 
	IRCUT_OPENLED_ON_ILLUMINATION_0_50 = 7,// 0.50 
	IRCUT_OPENLED_ON_ILLUMINATION_0_60 = 8,// 0.60 
	IRCUT_OPENLED_ON_ILLUMINATION_0_70 = 9,// 0.70 
	IRCUT_OPENLED_ON_ILLUMINATION_0_80 = 10,// 0.80 
	IRCUT_OPENLED_ON_ILLUMINATION_0_90 = 11,// 0.90
	IRCUT_OPENLED_ON_ILLUMINATION_1_00 = 12,// 1.0
	IRCUT_OPENLED_ON_ILLUMINATION_1_10 = 13,// 1.1
	IRCUT_OPENLED_ON_ILLUMINATION_1_20 = 14,// 1.2
	IRCUT_OPENLED_ON_ILLUMINATION_1_30 = 15,// 1.3
	IRCUT_OPENLED_ON_ILLUMINATION_1_40 = 16,// 1.4
	IRCUT_OPENLED_ON_ILLUMINATION_1_50 = 17,// 1.5
}IrcutOpenLedOnIllum;

typedef enum
{
	VIDEO_ISP_MODE_NORMAL = 0,// 正常模式 
	VIDEO_ISP_MODE_FORCE_FRAMERATE =1,//强制帧率模式 
	VIDEO_ISP_MODE_SUPERSTAR=2,//超星光模式
}VideoEncodeMode;


typedef enum
{
	VIDEO_WDR_MODE_OFF = 0,
	VIDEO_WDR_MODE_WDR = 1,	//宽动态始终开启(325/328Q方案专指数字宽动态,早期方案自动根据SENSOR来确定数字/物理宽动态)
	VIDEO_WDR_MODE_WDR_BY_TIME = 2, //按配置的时间段来宽动态
	VIDEO_WDR_MODE_HDR = 3, //HDR(SENSOR物理宽动态，启动参数不一样，更改后需要重启摄像机)
}VideoWdrMode;

typedef struct
{
	int brightness;
	int contrast;
	int saturation;
	int sharpness;
	
	unsigned char tvsystem; // 0: NTSC (60HZ) 1: PAL (50HZ)
	unsigned char forct_antiflicker; //强制抗闪，能力集"antiflicker"
	short reserved;
	unsigned short cropxpix;	//X轴裁剪像素, 能力集"video_crop"
	unsigned short cropypix;	//Y轴裁剪像素能力集"video_crop"

	int hflip;		//水平翻转 0 1 
	int vflip;		//垂直翻转 0 1   
	int rotate;		//走廊模式 0 1 , 能力集"rotate_enable"

	int whitebalance;	//enable R G B 4个值组合 
						//enable=(whitebalance>>24)&0xff; R=(whitebalance>>16)&0xff; G=(whitebalance>>8)&0xff; B=(whitebalance)&0xff
	int backlight;		//背光(逆光补偿0-255)
	int HLC;	//强光抑制 //0-255
	int tnf;	//2d降噪 //0-255
	int snf;	//3D降噪 //0-255

	////增益配置////	
	int bManualGain;//0: 自动增益 1: 手动增益, 能力集"gainsetting"
	int gainValue;//手动增益值, 能力集"gainsetting"

	////////宽动态////////
	int wdr_mode; //VideoWdrMode, 能力集"wdr_setting"
	DayTimeSpan wdr_worktime; //能力集"wdr_setting"
	int wdr_value; //能力集"wdr_setting"

	////////去雾////////
	int dfrog_flag;
	int dfrog_value;

	////////电子快门////////
	VideoShutter shutterSetting;//能力集"VideoShutter"

	//图像ISP效果选项
	int isp_mode_color;	//ISP彩色模式 0-3
	int isp_mode_night; //ISP夜间模式 0-3

	//图像模式
	int videoEncodeMode; //VideoEncodeMode, 能力集"vencodemode_set"

	////////IRCUT与补光相关////////	
	IRCutMode ircut_mode; //能力集"ircut_setting"
	unsigned char ircut_sensitivity; //0 to 100 //未用到
	unsigned char ircut_openled_delay;//补光延时 //IrcutOpenLedOnIllum, 能力集"ircut_leddelay"
	unsigned char led_brightness_mode;	//补光亮度控制:0自动 1手动， 能力集"ledtype_set"
	unsigned char led_brightness_value;//补光亮度:10%-100%,  能力集"ledtype_set"
	unsigned char led_brightness_alarm; //告警时补光亮度
	DayTimeSpan ircut_nighttime; //能力集"ircut_setting"
	int ircut_keepcolor; //20120419, 能力集"ircut_setting"
	LedMode led_mode;// 补光灯工作模式,能力集"ledtype_set"
	LedImageMode ispadvmode;//0: 正常 1: 防人脸过曝 2: 照车牌模式,  能力集"ledtype_set"
	////////IRCUT与补光相关////////	
	//关灯灵敏度
	unsigned char light_off_sensitivity; //能力集"ircut_leddelay"	
	unsigned char face_exposure_sensitivity; 
}VideoCapture;


#define MAX_VIDEO_MASK_AREA 4
typedef struct
{
	int xPos;
	int yPos;
	int width;
	int height;
}MASK_AREA_ENTRY;

typedef struct
{
	MASK_AREA_ENTRY mainStreamMaskList[MAX_VIDEO_MASK_AREA];
	MASK_AREA_ENTRY subStreamMaskList[MAX_VIDEO_MASK_AREA];
}VideoMaskConfig;


#define MAX_VIDEO_ROI_AREA 4
typedef struct
{
	int xPos;
	int yPos;
	int width;
	int height;
}ROI_AREA_ENTRY;

typedef struct
{
	int enable;
	ROI_AREA_ENTRY roi[MAX_VIDEO_ROI_AREA];
}VideoROI;

typedef struct
{
	VideoCapture   videoCapture;
	VideoEncode    videoEncode;
	JpegEncodeCfg  jpegCfg;
	VideoOverlay   overlay;
	VideoMaskConfig videoMask;
	VideoROI		roiCfg;
	VideoUserOverlay   useroverlay;	
	YuvEncodeCfg	yuvCfg;
}VideoConfig;

typedef struct
{
	int channels;
	int bitspersample;
	int samplerate;
	short volume_capture;
	short volume_play;
	int amplify;	//是否需要内部功放
	short ra_answer;//反向音频是否需要按键接听
	short aec_enable;
	short mute_ptz_turn;//云台转动时静音
	short reserved;
}AudioCapture;
#define AUDIO_ENCODE_TYPE_MAX_LEN 32

typedef struct
{
	char typeName[AUDIO_ENCODE_TYPE_MAX_LEN];
}AudioEncodeType;

typedef struct
{
	int enable;
	int sampleRate;
	AudioEncodeType   audioEncodeType;
	int bitRate;
}AudioEncode;

typedef struct
{
	AudioCapture  audioCapture;
	AudioEncode   audioEncode;
}AudioConfig;

typedef struct
{
	VideoConfig   videoConfig;
	AudioConfig   audioConfig;
}MediaConfig;

typedef struct
{
	int index;
	char  serverIP[MAX_IP_NAME_LEN];
	int serverPort;
	char userName[FTP_NAME_MAX_LEN];
	char password[FTP_PASSWORD_MAX_LEN];
	char filePath[FTP_PATH_MAX_LEN];
	int fileSize;
}FtpServer;

typedef struct
{
	int index;
	char toMail[SMTP_ACCOUNT_MAX_LEN];
	char ccMail[SMTP_ACCOUNT_MAX_LEN];
	char subject[SMTP_SUBJECT_MAX_LEN];
}SmtpServer;

enum
{
	//FTP_INDEX_FOR_RECORD_UPLOAD,
	FTP_INDEX_FOR_ALARM_UPLOAD,
	FTP_INDEX_FOR_LOG_BACKUP,
	FTP_INDEX_FOR_CONFIG_BACKUP,
	FTP_INDEX_FOR_UPDATE,
	FTP_SERVER_COUNT
};

enum
{
	//SMTP_INDEX_FOR_RECORD_UPLOAD,
	SMTP_INDEX_FOR_ALARM_UPLOAD,
	SMTP_INDEX_FOR_LOG_BACKUP,
	SMTP_INDEX_FOR_CONFIG_BACKUP,
	SMTP_SERVER_COUNT
};

//#define FTP_SERVER_COUNT 5

typedef struct
{
	FtpServer ftpServers[FTP_SERVER_COUNT];
}FtpServerList;

//#define SMTP_SERVER_COUNT 4

typedef struct
{
	char  	   		serverIP[MAX_IP_NAME_LEN];
	unsigned  int 	serverPort;
	int             auth;
	char 			userName[SMTP_NAME_MAX_LEN];
	char 			password[SMTP_PASSWORD_MAX_LEN];
	char 			fromMail[SMTP_ACCOUNT_MAX_LEN];
	SmtpServer 		smtpServers[SMTP_SERVER_COUNT];
}SmtpServerList;

typedef struct
{
	FtpServer  ftpServers[FTP_SERVER_COUNT];
	SmtpServerList   smtpServers;
}ServerConfig;

typedef struct
{
	short enable;		
	unsigned short Port;
	unsigned int Ip;
}MulticastStruct;	

typedef struct
{
	int enable_onvif;
	int enable_web;
	//int enable_https;
	int onvif_auth;
	int webPort;
	int httpsPort; //HTTPS端口，需要能力集 FUNCTION_HTTPS
	int h5Port;    //H5播放端口，需要能力集 FUNCTION_H5
	char httpsCertificate[MAX_IPC_FILENAME_LEN]; //https证书文件，需要能力集 FUNCTION_HTTPS
	char httpsKey[MAX_IPC_FILENAME_LEN]; //https密钥文件，需要能力集 FUNCTION_HTTPS
}WebConfig;

typedef struct
{
	int enable;
	unsigned short port;
	short auth;
}HikConfig;


typedef struct
{
	int enable;
	unsigned short port;
	short auth;
}DhConfig;

#define MAX_RTMP_APP_NAME_LEN 64
#define MAX_RTMP_STREAMID_LEN 256

typedef struct
{
	int enable;
	char server[MAX_IP_NAME_LEN];
	unsigned short port;
	short streamno;// 0: main 1: sub 2: third
	char appname[MAX_RTMP_APP_NAME_LEN];
	char streamid[MAX_RTMP_STREAMID_LEN];
	int type;//reserve
	TimeSpanCfg  timeSpan;//推流时间
}RtmpConfig;

typedef struct
{
	int enable_rtsp;
	int rtsp_auth;
	int rtpoverrtsp;
	int videoPort;
}RtspConfig;

typedef struct
{
	int enable;
	int ptzPort;
}CommConfig;

typedef struct
{
	int enable;
}TstConfig;

typedef struct
{
	MulticastStruct StreamMulticast[2];	
}MulticastConfig;

typedef struct
{
	RtspConfig rtspConfig;
	CommConfig commConfig;
	WebConfig webConfig;
	HikConfig hikConfig;
	DhConfig dhConfig;
	TstConfig tstConfig;
	RtmpConfig rtmpConfig;
	MulticastConfig multicastConfig;
}MediaStreamConfig;


typedef struct
{
	int			enable;
	char			server[MAX_IP_NAME_LEN];
	unsigned short  port;
	char username[ACCOUNT_NAME_MAX_LEN];
	char password[ACCOUNT_PASSWORD_MAX_LEN];
}VmPlatformConfig;

typedef struct
{
	unsigned char PlayTone;//启动播放声音
	unsigned char InRingTimes;//来电振铃次数后自动接通
	unsigned char reserved;///韩国门铃，默认开启广播信息
	unsigned short keyPressTimeLen;	//触发呼叫的按键时长(毫秒, 100ms-5000ms)，避免误按
	char filename[MAX_IPC_FILENAME_LEN];
}VoipConfig;

typedef struct
{
	VmPlatformConfig cfg;
	VoipConfig	voipCfg;
}PlatformConfig;

#define PLATFORM_REGISGER_RESULT_FILE "/tmp/flag_plat_reg_result"
typedef enum
{
	PLAT_REG_RESULT_REG_NO = 0,
	PLAT_REG_RESULT_REGGING,
	PLAT_REG_RESULT_REG_FAILED,
	PLAT_REG_RESULT_REG_OK,
}PlatRegStatus;
typedef struct
{
	PlatRegStatus result;	//0: 未注册 1: 注册中 2: 注册失败 3: 注册成功
	char szPlatDevId[32];
	char reservedInfo[128];
}PlatRegResult;

#define GB28181_ID_MAX_LEN 32
#define GB28181_IP_MAX_LEN 32
#define GB28181_NAME_MAX_LEN 64
#define GB28181_PWD_MAX_LEN 32
typedef struct
{
	int enable;
	int nstreams;		//可用码流:0 主码流 1子码流 2 双码流
	int nChannelNum;	//通道数量
	
	char hcId[GB28181_ID_MAX_LEN];
	char hcIp[GB28181_IP_MAX_LEN];
	char hcName[GB28181_NAME_MAX_LEN];
	char hcPwd[GB28181_PWD_MAX_LEN];
	int hcPort;
	
	char lcId[GB28181_ID_MAX_LEN];
	char lcName[GB28181_NAME_MAX_LEN];
	char lcPwd[GB28181_PWD_MAX_LEN];
	int lcPort;
	
	char camId[GB28181_ID_MAX_LEN];
	char alarmId[GB28181_ID_MAX_LEN];
	char device_name[GB28181_NAME_MAX_LEN];
}GB28181Config;


#define RECORD_FILEFORMAT_MAX_LEN 32

typedef struct
{
	char formatName[RECORD_FILEFORMAT_MAX_LEN];
}RecordFileFormat;

#define RECORD_MEDIA_TYPE_MAX_LEN 32
typedef struct
{
	char typeName[RECORD_MEDIA_TYPE_MAX_LEN];
}RecordMediaType;

#define RECORD_STORAGE_POLICY_MAX_LEN 32
typedef struct
{
	char policyName[RECORD_STORAGE_POLICY_MAX_LEN];
}RecordStoragePolicy;


#define MAX_DAYTIMESPAN_COUNT 24

typedef struct
{
	int workday;
	int timeSpancnt;
	DayTimeSpan timeSpans[MAX_DAYTIMESPAN_COUNT];
}WorkDayTime;


typedef struct
{
	int workdayCnt;
	WorkDayTime workdayTimes[MAX_WORDDAYTIME_COUNT];
}TimeSpanList;



#define MAX_STORAGE_SEQUENCE_NAME_LEN 256
#define MAX_REMOTE_MOUNT_PARAM_LEN 256

typedef enum
{
	NETWORK_STORAGE_DISABLE=0,
	NETWORK_STORAGE_TYPE_NFS=1,	
}NetworkStorageType;

typedef struct
{
	int timelapseEnable;	//缩时摄影启用与否
	int timelapseSec;//间隔多少秒录制一帧
	int timelapseFps;//播放帧率
	int timelapseFileSize;//缩时摄影文件大小
}RecordTimelapseConfig;


typedef struct
{
	int		localEnable;
	NetworkStorageType		remoteEnable;
	char    storageSequence[MAX_STORAGE_SEQUENCE_NAME_LEN];
	char    mountParam[MAX_REMOTE_MOUNT_PARAM_LEN];	
	RecordStoragePolicy storePolicy;	
	int recordFileSize;
	int recordFileKeeyDays;//录像保留最大天数

	RecordTimelapseConfig timelapseCfg;//缩时摄影配置
}RecordCommConfig;

typedef struct
{
	int					stream; // 0:主码流 1:子码流 2:主子码流同时录像
	RecordFileFormat	fileFormat;
	RecordMediaType		mediaType;
	int					localStore;
	int					remoteStore;
	TimeSpanCfg		timeSpan;
	
	int 				jpgInterval;
	int					ftpUpload;
	int					emailUpload;
}ScheduleRecordConfig;

typedef enum
{
	RECORD_ALARM_BIT_MOTION_DETECT = 0,//移动侦测
	RECORD_ALARM_BIT_HUMAN = 1,//人形
	RECORD_ALARM_BIT_CAR = 2,	//汽车
	RECORD_ALARM_BIT_MOTO = 3,	//摩托车
	RECORD_ALARM_BIT_ELECTRICBICYCLE = 4,//电单车
	RECORD_ALARM_BIT_BICYCLE = 5,//自行车
	RECORD_ALARM_BIT_FACE = 6, //人脸
	RECORD_ALARM_BIT_NONMOTO_VEHICLE = 7,//非机动车
	RECORD_ALARM_BIT_FIRE=8,//火焰
	RECORD_ALARM_BIT_FALLINGOBJECT=9,//高空抛物
	RECORD_ALARM_BIT_LPR = 10,	//车牌识别
	RECORD_ALARM_BIT_VIDEO_COVERD = 11,
	RECORD_ALARM_BIT_VIDEO_GATE = 12,//电子围栏
	RECORD_ALARM_BIT_AUDIO_BABYCRY = 13,//婴儿啼哭
	RECORD_ALARM_BIT_AUDIO_LSA = 14,//高分贝声音
	RECORD_ALARM_BIT_IO_ALARM = 15,	//IO输入报警
	RECORD_ALARM_BIT_EMERGENCY_CALL = 16,
	RECORD_ALARM_BIT_TEMP_HUMID_ALARM = 17, //温湿度告警
	RECORD_ALARM_BIT_SENSOR = 18,//传感器报警，使用AlarmSensor作为子类型
	RECORD_ALARM_BIT_LINKDOWN=19,

	RECORD_ALARM_BIT_MAX,
}AlarmRecordBits;

typedef struct
{
	int					stream; // 0:主码流 1:子码流 2:主子码流同时录像
	RecordFileFormat	fileFormat;
	RecordMediaType		mediaType;
	int 				precordTime;
	int 				recordTime;
	int					localStore;
	int					remoteStore;
	int					ftpUpload;
	int					emailUpload;
	int 				stopNoAlarm; //if noalarmstop=1, recordTime means the record time after alarm disappear
	unsigned int alarmbits;//报警类型,每一种报警占用1个bit，参见AlarmRecordBits
}AlarmRecordConfig;

typedef struct
{
	short preTakeTime;
	short sendoutInterval;//FTP/EMAIL发送频率,秒.0标识不控制
	int totalTakeTime;
	int localStore;
	int remoteStore;
	int ftpUpload;
	int emailUpload;
	int 	stopNoAlarm; //if noalarmstop=1, recordTime means the record time after alarm disappear
	int	stream;	//抓图使用的码流
	unsigned int alarmbits;//报警类型,每一种报警占用1个bit，参见AlarmRecordBits
}AlarmCaptureConfig;

typedef struct
{
	RecordCommConfig		commonCfg;
	ScheduleRecordConfig	scheduleRecordCfg;
	AlarmRecordConfig   motionRecordCfg;
	AlarmCaptureConfig  motionCaptureCfg;
	AlarmRecordConfig   inputAlarmRecordCfg;
	AlarmCaptureConfig  inputAlarmCaptureCfg;
}RecordConfig;

#define MAX_PTZPOSITION_COUNT 20

typedef struct
{
	int positionIndex;
}PTZPosition;

typedef struct
{
	PTZPosition  postion;
}PositionPreset;

typedef struct
{
	int interval;
	int duration;
	int positionCount;
	PTZPosition ptzPositions[MAX_PTZPOSITION_COUNT];
}PositionLoop;

typedef struct
{
	int interval;
	int walkCount;
	int positionCount;
	PTZPosition ptzPositions[MAX_PTZPOSITION_COUNT];
}PositionWalk;

#define PTZ_ACTION_TYPE_MAX_LEN 32
typedef  struct
{
	char actionName[PTZ_ACTION_TYPE_MAX_LEN];
}PTZActionType;

typedef struct
{
	int enable;
	PTZActionType actionType;	
	union Action
	{
		PositionPreset preset;
		PositionLoop  loop;
		PositionWalk  walk;
	}action;
}PTZAction;

/*
HIGH:对应常开，平时为0，触发时写1
LOW:对应常闭，平时为1，触发时写0
*/
#define TRIGGER_TYPE_NAME_MAX_LEN 32
typedef struct
{
	char name[TRIGGER_TYPE_NAME_MAX_LEN];
}TriggerType;

#define CHANNEL_TYPE_NAME_MAX_LEN 32
typedef struct
{
	char name[CHANNEL_TYPE_NAME_MAX_LEN];
}ChannelType;


typedef struct _OutputChannel
{
	int portIndex;
	int dayEnable;
	int nightEnable;
	int duration;
	ChannelType channelType;	
	TriggerType triggerType;	
}OutputChannel;

#define MAX_OUTPUT_CHANENL_COUNT 4

typedef struct 
{
	int channelCnt;
	OutputChannel outputChannels[MAX_OUTPUT_CHANENL_COUNT];
}OutPutAlarm;


#define MAX_SMS_DESTNUM_LEN 64
#define MAX_SMS_FIX_CONTENT_LEN 128
typedef struct 
{
	int enable;
	int min_interval;//最小间隔时间
	int playresult;//语音播报发送结果
	char szSmsDstNum[MAX_SMS_DESTNUM_LEN];
	char szSmsFixContent[MAX_SMS_FIX_CONTENT_LEN];
}SMSAlarm;

typedef struct _OutputChannelAction
{
	int enable;
	int portIndex;
}OutputChannelAction;


typedef struct _OldOutputChannelAction
{
	int magicNum; //old cfg magic Num is 0xAABBCCDD
	int enable;
	int portIndex;
	int triggerType;
	int duration;
}OldOutputChannelAction;


typedef struct
{
	int channelCnt;	
	union 
	{
		OutputChannelAction outputChnlActions[MAX_OUTPUT_CHANENL_COUNT];
		OldOutputChannelAction   oldOutputChnlAction;
	};
}AlarmOutputAction;

#define AUDIO_ACTION_LEN_FILENAME 128
typedef struct
{
	short enable; //白天
	short enable_night;//晚上
	int times;//播放次数 <=0表示一直播。大于0表示次数
	int intervalsecnods;	//距离上次播放的最小间隔时间秒
	char filename[AUDIO_ACTION_LEN_FILENAME];
}AudioPlayAction;


typedef struct
{
	AlarmOutputAction outputAction;
	PTZAction         ptzAction;
	AudioPlayAction	  audioAction;
	unsigned char light_twinkle_enable;//灯光闪烁
	unsigned char notify_alarmserver_enable;//上报告警中心
	unsigned char notify_sms;
	unsigned char reserved3;
}InputAction;

typedef struct
{
	int enable;
	int portIndex;
	ChannelType		channelType;	
	TriggerType		triggerType;
	TimeSpanCfg		timeSpan;
	InputAction		alarmAction;
}AlarmChannel;

#define MAX_ALARMCHANNEL_COUNT 4

typedef struct
{
	int channelCnt;
	AlarmChannel alarmChannels[MAX_ALARMCHANNEL_COUNT];
}InputAlarm;

typedef struct
{
	AlarmOutputAction outputAction;
	PTZAction         ptzAction;
	AudioPlayAction	  audioAction;
	unsigned char light_twinkle_enable;//灯光闪烁
	unsigned char notify_alarmserver_enable;//上报告警中心
	unsigned char reserved2;
	unsigned char reserved3;
}MotionDetectAction;

typedef struct
{
	int enable_babycry;//婴儿哭声
	int sensity_babycry;
	int enable_lsd;	//高分贝声音
	int sensity_lsd;	
}AudioAlarm;


#define MD_MAX_GRID_ROW 18
#define MD_MAX_GRID_COL 22
#define MD_CONFIG_STRING_LEN (MD_MAX_GRID_ROW*MD_MAX_GRID_COL+4)
#define MAX_MOTIONDETECT_CONFIG_STRING MD_CONFIG_STRING_LEN//32

//移动侦测组定义，左上、右下角block位置
typedef struct
{
	int left;
	int top;
	int right;
	int bottom;
}MdGroupConfig;

typedef struct
{
	int enable;
	TimeSpanCfg  timeSpan;
	int blockCount; // low 16 bits for row , high 16 bits for column; //block_row=blockCount&0xffff;block_col=blockCount>>16;
	char blockCfg[MAX_MOTIONDETECT_CONFIG_STRING]; // ''\0' terminate
	int sensitivity;
	int alarmThreshold;
	int dayNightSwitch;
	int nightSensitivity;
	int nightAlarmThreshold;
	DayTimeSpan nightTime;
	MotionDetectAction alarmAction;
}MotionDetectAlarm;

typedef enum
{
	AI_TWINKLE_DISABLE = 0,
	AI_TWINKLE_REGION = 1,//设防区域闪烁
	AI_TWINKLE_AROUND = 2,//画面四周闪烁
}RectTwinkleEnum;

typedef struct
{
	unsigned char draw_rect_enable;	//画区域框
	unsigned char draw_human_enable;	//画人形框
	unsigned char track_human_enable;	//人形跟踪
	unsigned char rect_twinkle_enable;	//检测到人形时区域框闪烁,参见RectTwinkleEnum
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
	unsigned char light_twinkle_enable;//灯光闪烁
	unsigned char notify_alarmserver_enable;//上报告警中心
	unsigned char alarm_led_enable;//红蓝警灯
	unsigned char auto_zoom_enable;//变倍跟踪
}PdAction;

typedef struct
{
	unsigned char draw_rect_enable;	//画区域框
	unsigned char draw_vehicle_enable;	//画车形框
	unsigned char rect_twinkle_enable;	//检测到车形时区域框闪烁
	unsigned char reserved;
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}VehicleShapeAction;

typedef struct
{
	unsigned char draw_osd_enable;		//绘制车牌OSD
	unsigned char play_voice_enable;	//语音播报
	unsigned short reserved;
	AlarmOutputAction outputAction;
}LprAction;


typedef struct
{
	int draw_rect_enable;	//画框
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}FdAction;

typedef struct
{
	int xPos;
	int yPos;
	int width;
	int height;
}PD_AREA_ENTRY;


typedef struct _AJ_POINT_S
{
	int x;
	int y;
}AJ_POINT_S;


#define MAX_POLYGON_POINT_CNT 10
typedef struct _Polygon
{
	AJ_POINT_S points[MAX_POLYGON_POINT_CNT];
	int count;
}Polygon;

//人形识别--20210611扩充成智能分析
typedef enum
{
	AI_TYPE_BIT_CAR = 0,	//汽车
	AI_TYPE_BIT_MOTO = 1,	//摩托车
	AI_TYPE_BIT_ELECTRICBICYCLE = 2,//电单车
	AI_TYPE_BIT_BICYCLE = 3,//自行车
	AI_TYPE_BIT_HUMAN = 4,	//人形
	AI_TYPE_BIT_FACE = 5, //人脸
	AT_TYPE_BIT_NONMOTO_VEHICLE = 6,//非机动车
	AT_TYPE_BIT_FIRE=7,//火焰
	AT_TYPE_BIT_FALLINGOBJECT=8,//高空抛物
	AI_TYPE_BIT_MAX,
}AjAiBits;
	
typedef struct
{
	int enable_day;
	int enable_night;
	unsigned int type;//32bit: bit0: 汽车 bit1: 摩托车 bit2:电单车 bit3:自行车 bit4: 人形
	PD_AREA_ENTRY area;
	PdAction alarmAction;
	TimeSpanCfg  timeSpan;
	int threshold;
	int sensitivity;	
	Polygon  polygonArea;
}PdAlarm;

//车牌识别
typedef struct
{
	int enable;
	LprAction alarmAction;
	TimeSpanCfg  timeSpan;
	int sensitivity;	
	Polygon  polygonArea;
}LprAlarm;


//-------------------------//
typedef struct
{
	AlarmOutputAction outputAction;
}TempHumidityAction;

//-------------------------//

#define TEMP_ALARM_DESCRIBE "Temperature alarm"
#define HUMIDITY_ALARM_DESCRIBE "Humidity alarm"

typedef struct 
{
	int  temp_enable;
	int  temp_upper_limit;
	int  temp_lower_limit;
	int  temp_range_lower;	
	int  temp_range_upper;

	int  humidity_enable;
	int  humidity_upper_limit;	
	int  humidity_lower_limit;
	int  humidity_range_lower;	
	int  humidity_range_upper;	//湿度取值范围最大值

	int  voc_enable;			//有毒气体检测启用
	int  voc_threashhold_good;	//空气优良门限（出厂默认300ppb）
	int  voc_threashhold_TracePollution;	//微量污染门限（出厂默认1500ppb）
	int  voc_threashhold_LightPollution;	//轻度污染门限（出厂默认3000ppb）
	int  voc_threashhold_ModeratePollution;	//中度污染门限（出厂默认5000ppb）
	int  voc_threashhold_HeavyPollution;	//重度污染门限（出厂默认10000ppb）
	
//	int  enable;
	TempHumidityAction alarmAction;
}TempHumidityAlarm;
//-------------------------//
typedef struct
{
	int enable_day;
	int enable_night;
	PD_AREA_ENTRY area;
	FdAction alarmAction;
	TimeSpanCfg  timeSpan;
	int threshold;
	int sensitivity;	
}FaceDetectAlarm;


typedef struct
{
	AlarmOutputAction outputAction;
}VideoLostAction;

typedef struct
{
	int enable;
	TimeSpanCfg  timeSpan;
	VideoLostAction alarmAction;
}VideoLostAlarm;

typedef struct
{
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}VideoCoverAction;

typedef struct
{
	int enable;
	int sensitivity;
	int threadhold_second;		//遮挡时间阈值(秒)：持续遮挡多长时间才认为是遮挡报警
	int backgroundUpdateSecond;	//背景帧更新时间（秒）：配置多长时间更新一次背景。用于设置M值，M默认为120，帧率为5时backgroundUpdateTime=24
	TimeSpanCfg		timeSpan;
	VideoCoverAction	alarmAction;
}VideoCoverAlarm;

typedef struct
{
	AlarmOutputAction outputAction;
}StorageFullAction;

typedef struct
{
	int enable;
	int threshold;
	StorageFullAction alarmAction;
}StorageFullAlarm;


typedef struct
{
	int enable_day;
	int enable_night;
	int sensitivity;
	unsigned int type;//32bits,参见AT_TYPE_BIT_NONMOTO_VEHICLE定义。过滤检测:机动车、非机动车、行人
	int x0Pos;
	int y0Pos;
	int x1Pos;
	int y1Pos;
	int direction;//0: A<->B 1: A->B 2: A<-B (SIDE A MEANS LEFT OF THE LINE)
}VideoLineStruct;

typedef struct
{
	unsigned char draw_rect_enable;	//画检测配置线
	unsigned char draw_target_enable;	//画检测目标
	unsigned char light_twinkle_enable;//灯光闪烁
	unsigned char notify_alarmserver_enable;//上报告警中心
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}VideoGateAction;

#define MAX_VIDEO_VG_LINE	4
typedef struct
{
	VideoLineStruct data[MAX_VIDEO_VG_LINE];
	VideoGateAction alarmAction;
	TimeSpanCfg  timeSpan;
}VideoGateAlarm;

//区域检测类型
typedef enum
{
	AI_RETION_STAY, //区域逗留
	AI_RETION_ENTER, //进入区域
	AI_RETION_LEAVE, //离开区域
}RegionAiMode;

typedef struct
{
	int enable;
	int sensitivity;
	unsigned int type_filter;//检测目标类型，32bits,参见AT_TYPE_BIT_NONMOTO_VEHICLE定义。过滤检测:机动车、非机动车、行人
	RegionAiMode mode;	//检测目标模式
	int stayseconds;//逗留时间(秒)，仅对区域逗留有效
}RegionAiUnitStruct;

typedef struct
{
	unsigned char draw_rect_enable;	//画区域框
	unsigned char draw_target_enable;	//画检测目标
	unsigned char light_twinkle_enable;//灯光闪烁
	unsigned char notify_alarmserver_enable;//上报告警中心
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}RegionAiAction;


#define MAX_VIDEO_REGION_AI_NUM 3
typedef struct
{
	Polygon  polygonArea;
	RegionAiUnitStruct data[MAX_VIDEO_REGION_AI_NUM];
	RegionAiAction alarmAction;
	TimeSpanCfg  timeSpan;
}VideoRegionAiAlarm;


typedef struct
{
	InputAlarm			inputAlarm;				//IO输入
	MotionDetectAlarm   motionDetectAlarm;		//移动侦测
	VideoLostAlarm		videoLostAlarm;  		//视频丢失
	VideoCoverAlarm		videoCoverAlarm;		//视频遮挡
	StorageFullAlarm	storageFullAlarm;		//存储空间
	AudioAlarm 			audioAlarm;				//异常声音检测(婴儿啼哭、高分贝)
	VideoGateAlarm		vgAlarm;				//越界检测
	VideoRegionAiAlarm	regionAiAlarm;			//区域检测:区域入侵、进入区域、离开区域
	PdAlarm				pdAlarm;				//智能分析:人形、车型、摩托、电单车、自行车
	LprAlarm			lprAlarm;				//车牌识别
	FaceDetectAlarm		fdAlarm;				//人脸检测
	OutPutAlarm			outputAlarm;			//IO输出配置
	TempHumidityAlarm   temphumidityAlarm;		//温度报警
	SMSAlarm			smsAlarm;				//短消息通知
}AlarmConfig;

/*
typedef struct
{
	char  IPAddress[MAX_IP_NAME_LEN];
	char  netMask[MAX_IP_NAME_LEN];
	char  gateWay[MAX_IP_NAME_LEN];
	char  DNS1[MAX_IP_NAME_LEN];
	char  DNS2[MAX_IP_NAME_LEN];
}StaticIPConfig;

typedef struct
{
	char reserved[16];
}DHCPConfig;

typedef struct
{
	int enable;
	int interval;
}ADSLAutoConnect;

typedef struct
{
	char IPAddress[MAX_IP_NAME_LEN];
	char netMask[MAX_IP_NAME_LEN];
	char gateWay[MAX_IP_NAME_LEN];
}ADSLLanConfig;

#define ADSL_NAME_MAX_LEN 32
#define ADSL_PASSWORD_MAX_LEN 32

typedef struct
{
	char userName[ADSL_NAME_MAX_LEN];
	char password[ADSL_PASSWORD_MAX_LEN];
	ADSLAutoConnect autoConnect;
	ADSLLanConfig   adslLanCfg;
}ADSLConfig;

*/

#define MAX_WEPENCRYPT_AUTHMODE_NAME_LEN 64
#define MAX_WEPENCRYPT_ENCRYPTTYPE_NAME_LEN 64
#define MAX_WEPENCRYPT_KEYMODE_NAME_LEN 64
#define MAX_WEPENCRYPT_KEYVALUE_LEN 64

#define WEPENCRYPT_AUTHMODE_NAME_OPENSYSTEM "open system"
#define WEPENCRYPT_AUTHMODE_NAME_SHAREDKEY "shared key"

#define WEPENCRYPT_AUTHMODE_VALUE_OPENSYSTEM 0
#define WEPENCRYPT_AUTHMODE_VALUE_SHAREDKEY 1
#define WEPENCRYPT_AUTHMODE_VALUE_UNKNOWN -1

typedef struct
{
   char authMode[MAX_WEPENCRYPT_AUTHMODE_NAME_LEN];
   char encryptType[MAX_WEPENCRYPT_ENCRYPTTYPE_NAME_LEN];
   char keyMode[MAX_WEPENCRYPT_KEYMODE_NAME_LEN];
   char keyValue[MAX_WEPENCRYPT_KEYVALUE_LEN];
   int  keyIndex;
}WepEncrypt;


#define MAX_WPAENCRYPT_ENCRYPTTYPE_NAME_LEN 64
#define MAX_WPAENCRYPT_AUTHMODE_NAME_LEN 64
#define MAX_WPAENCRYPT_KEYVALUE_LEN 64

#define WPAENCRYPT_ENCRYPTTYPE_NAME_TKIP  "tkip"
#define WPAENCRYPT_ENCRYPTTYPE_NAME_AES   "aes"

typedef struct
{
	char encryptType[MAX_WPAENCRYPT_ENCRYPTTYPE_NAME_LEN];
    char authMode[MAX_WPAENCRYPT_AUTHMODE_NAME_LEN];
	char keyValue[MAX_WPAENCRYPT_KEYVALUE_LEN];
}WpaEncrypt;

#define MAX_WIRELESSENCRYPT_ENCRYPTTYPE_NAME_LEN 64
#define WIRELESSENCRYPT_ENCRYPTTYPE_NAME_WEP  "wep"
#define WIRELESSENCRYPT_ENCRYPTTYPE_NAME_WPA  "wpa"


typedef struct
{
	int enable;
	char encryptType[MAX_WIRELESSENCRYPT_ENCRYPTTYPE_NAME_LEN];
	WepEncrypt  wepEncrypt;
	WpaEncrypt  wpaEncrypt;
}WirelessEncrypt;


#define MAC_ADDRESS_LEN   18    //00:11:11:11:11:11
#define MAX_WIRELESS_OPERATIONMODE_NAME_LEN 32
#define MAX_WIRELESS_MACMODE_NAME_LEN 64
#define MAX_WIRELESS_ESSID_NAME_LEN 64
#define MAX_WIRELESS_REGION_NAME_LEN 64
#define MAX_WIRELESS_BITRATE_NAME_LEN 10
#define MAX_WIFI_VERSION_LEN 10

#define WIRELESS_OPERATIONMODE_MASTER_NAME "master"
#define WIRELESS_OPERATIONMODE_MANAGED_NAME "managed"

#define WIRELESS_MACMODE_NAME_A "A"
#define WIRELESS_MACMODE_NAME_B "B"
#define WIRELESS_MACMODE_NAME_G "G"
#define WIRELESS_MACMODE_NAME_MIXED "MIXED"

#define WIRELESS_MACMODE_VALUE_A  4
#define WIRELESS_MACMODE_VALUE_B  3
#define WIRELESS_MACMODE_VALUE_G  2	
#define WIRELESS_MACMODE_VALUE_MIXED  1
#define WIRELESS_MACMODE_VALUE_UNKNOWN   -1


#define WIRELESS_REGION_NAME_TAIWAN "TAIWAN"
#define WIRELESS_REGION_NAME_USA "USA"
#define WIRELESS_REGION_NAME_FRANCE "FRANCE"
#define WIRELESS_REGION_NAME_ISRAEL "ISRAEL"

#define WIRELESS_REGION_VALUE_TAIWAN 2 
#define WIRELESS_REGION_VALUE_USA  1
#define WIRELESS_REGION_VALUE_FRANCE  3	
#define WIRELESS_REGION_VALUE_ISRAEL  5

#define WIRELESS_REGION_VALUE_UNKNOWN  -1

/*
typedef struct
{
	int enable;
	char operationMode[MAX_WIRELESS_OPERATIONMODE_NAME_LEN];
	char macMode[MAX_WIRELESS_MACMODE_NAME_LEN];
	char bitRate[MAX_WIRELESS_BITRATE_NAME_LEN];
	char essid[MAX_WIRELESS_ESSID_NAME_LEN];
	char region[MAX_WIRELESS_REGION_NAME_LEN];
	int channelNum;
	char MACAddress[MAC_ADDRESS_LEN];
	WirelessEncrypt wirelessEncrypt;
}WirelessConfig;

typedef struct
{
	unsigned char MACAddress[MAC_ADDRESS_LEN];
}WireConfig;
*/

#define MAX_DDNS_SERVER_NAME_LEN 256
#define MAX_DDNS_DOMAIN_NAME_LEN 256
#define MAX_DDNS_USERNAME_LEN 256
#define MAX_DDNS_PASSWORD_LEN 256
typedef struct
{
	int enable;
	char server[MAX_DDNS_SERVER_NAME_LEN];
	char domain[MAX_DDNS_DOMAIN_NAME_LEN];
	char userName[MAX_DDNS_USERNAME_LEN];
	char password[MAX_DDNS_PASSWORD_LEN];
	int freshInterval;
}DDNSConfig;

typedef struct
{
	int enable;
}UPNPConfig;

typedef enum
{
	P2P_TYPE_NOTDEFINED = 0,
	P2P_TYPE_DANALE = 1,
	P2P_TYPE_ANKO = 2,
	P2P_TYPE_GOOLINK = 3,
	P2P_TYPE_YUECAM = 4,
	P2P_TYPE_QQCONNECT = 5,
    P2P_TYPE_TUTK = 6,
    P2P_TYPE_EYEPLUS = 7,
	P2P_TYPE_SKYWORTH = 8,
	P2P_TYPE_TUYA = 9,
	P2P_TYPE_AC18PRO = 10,
	P2P_TYPE_TENCENT = 11,
	P2P_TYPE_HAIER = 12
}P2pType;

#define P2P_AUTH_CODE_LEN 16
typedef struct
{
	int enable;
	int p2ptype;	//
	char authcode[P2P_AUTH_CODE_LEN];
}P2PConfig;


#define ADSL_NAME_MAX_LEN 32
#define ADSL_PASSWORD_MAX_LEN 32

typedef struct
{
	int  enable;
	char userName[ADSL_NAME_MAX_LEN];
	char password[ADSL_PASSWORD_MAX_LEN];
}ADSLConfigNew;

typedef struct
{
	unsigned char   MACAddress[MAC_ADDRESS_LEN];	
	char	dhcpEnable;
	char	dhcpOffTime;	//DHCP获取IP后，多久变成固定IP:0-48。小于0表示DHCP一直生效，不会拿到IP后变成固定IP
	short	onvifAllnetEnable;//是否启用ONVIF全网通
	char  IPAddress[MAX_IP_NAME_LEN];
	char  netMask[MAX_IP_NAME_LEN];
	char  gateWay[MAX_IP_NAME_LEN];
	char  DNS1[MAX_IP_NAME_LEN];
	char  DNS2[MAX_IP_NAME_LEN];
	char  hostname[MAX_IP_NAME_LEN];//hostname
	unsigned int mtu;
}LANConfig;

typedef struct
{
	int enable;
	char address[MAX_IP_NAME_LEN];
	int interval;
	int maxFail;
}WIFIPingWatchConfig;

typedef struct
{
	int enable;
	char version[MAX_WIFI_VERSION_LEN];
	int	dhcpEnable;
	char IPAddress[MAX_IP_NAME_LEN];
	char netMask[MAX_IP_NAME_LEN];
	char gateWay[MAX_IP_NAME_LEN];	
	char operationMode[MAX_WIRELESS_OPERATIONMODE_NAME_LEN];
	char macMode[MAX_WIRELESS_MACMODE_NAME_LEN];
	char bitRate[MAX_WIRELESS_BITRATE_NAME_LEN];
	char essid[MAX_WIRELESS_ESSID_NAME_LEN];
	char region[MAX_WIRELESS_REGION_NAME_LEN];
	int channelNum;
	char MACAddress[MAC_ADDRESS_LEN];
	WirelessEncrypt wirelessEncrypt;
	WIFIPingWatchConfig pingWatchCfg;	
}WIFIConfig;

typedef struct
{
	int enable;
	char version[MAX_WIFI_VERSION_LEN];
	char IPAddress[MAX_IP_NAME_LEN];
	char netMask[MAX_IP_NAME_LEN];
	char macMode[MAX_WIRELESS_MACMODE_NAME_LEN];
	char bitRate[MAX_WIRELESS_BITRATE_NAME_LEN];
	char essid[MAX_WIRELESS_ESSID_NAME_LEN];
	char region[MAX_WIRELESS_REGION_NAME_LEN];
	int channelNum;
	char MACAddress[MAC_ADDRESS_LEN];
	WirelessEncrypt wirelessEncrypt;
}WIFIApConfig;


#define MAX_DIALNUMBER_LEN  32
#define MAX_APN_STRING		256
#define MAX_CENTER_NUMBER   256 

#if 0

#define DIAL_OPTION_MANUAL		0
#define DIAL_OPTION_CALL		1
#define DIAL_OPTION_AUTO		2

#else  //not same as PVT

#define DIAL_OPTION_AUTO		0
#define DIAL_OPTION_CALL		1

#endif

typedef struct
{
	int enable;
	int type;
	char dialNumber[MAX_DIALNUMBER_LEN];
	char apnString[MAX_APN_STRING];
	char userName[ADSL_NAME_MAX_LEN];
	char password[ADSL_PASSWORD_MAX_LEN];
	int  dialOption; //0: manual dial; 1: call dial; 2: auto
	char centerNumber[MAX_CENTER_NUMBER];
	char SMSC[MAX_CENTER_NUMBER];
}G3Config;

#define MAX_VPN_SERVER_NAME_LEN 256
#define MAX_VPN_USERNAME_LEN 256
#define MAX_VPN_PASSWORD_LEN 256
typedef struct
{
	int enable;
	char vpnServerIp[MAX_VPN_SERVER_NAME_LEN];
	char userName[MAX_VPN_USERNAME_LEN];
	char password[MAX_VPN_PASSWORD_LEN];
	int mtu;
}PPTPConfig;

#define MAX_URL_LEN 128
typedef struct
{
	char url[MAX_URL_LEN];
	char userName[ACCOUNT_NAME_MAX_LEN];
	char password[ACCOUNT_PASSWORD_MAX_LEN];
	int	 withattachment;
}AlarmServerConfig;

typedef struct
{
	LANConfig		lanCfg;
	WIFIConfig		wifiCfg;
	ADSLConfigNew	adslCfg;
	DDNSConfig		ddnsCfg;
	UPNPConfig		upnpCfg;
	G3Config		g3Cfg;
	PPTPConfig      pptpCfg; 
	P2PConfig		p2pCfg;
	WIFIApConfig	wifiApCfg;
	AlarmServerConfig alarmServerCfg;
}NetworkConfigNew;

typedef struct
{
	char szVersion[64];
}ConfigVersion;


typedef struct
{
	SystemConfig		systemCfg;
	ServerConfig  		serverCfg;
	MediaStreamConfig 	mediaStreamCfg;
	PlatformConfig		platformCfg;
	RecordConfig  		recordCfg;
	NetworkConfigNew	networkCfgNew;
	GB28181Config		gb28181Cfg;
	ConfigVersion		versionCfg;
	MediaConfig 		mediaCfg;
	AlarmConfig  		alarmCfg;
}GlobalConfig;

typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}SYSTEM_TIME;

#define MAX_ALARM_DATA 220//128 //32->128 modified by 20090403
#define MAX_SNAP_FILE_PATH_LEN 96
typedef struct 
{
	SYSTEM_TIME	alarmtime;
	AjAlarmCode 		alarmcode;
	int 		alarmflag;
	int			alarmlevel;
	char 		alarmdata[MAX_ALARM_DATA];
	char		snapfile[MAX_SNAP_FILE_PATH_LEN];//抓图文件路径
} ALARM_MSG_DATA;


typedef struct
{
	//Configuration
	char device_name[64];
	char gb_publisher[64];
	char time_xy[8];
	char title_xy[8];
	char lan[16];
	char ie_lan[16];
	char password[64];
	char title[200];
	//Conctrol
	int audio_out;
	int audio_in;
	int sen_o_li;
	int sen_c_li;
	int li_pw;
	int led;
	int brightness;
	int saturation;
	int sharpness;
	int contrast;
	char resolution_value_0[64];
	char resolution_value_1[64];
	char resolution_value_2[64];
	char resolution_value_0_fake[64];
	char resolution_value_1_fake[64];
	char resolution_value_2_fake[64];
	int encoder_0;
	int encoder_1;
	int encoder_2;
	int privacy_ptz_direction_value;
	int tvsystem;
	int kc_mode;
	int ptz_speed;
	int low_li_pw;
	int optimumdistance;
	//Capability
	int ptz_yuntai ;
	int ptz_zoom ;
	int ptz_af ;
	int ptz_track ;
	int ptz_cruise ;
	int cover ;
	int call ;
	int low_pw ;
	int led_type;
}
SECOND_DEFAULTCONFIG_DATA;

#define MAX_TRANS_DATA_LEN 128	
typedef struct
{
	char data[MAX_TRANS_DATA_LEN];
	int  len;
}TRANS_MSG_DATA;

typedef struct
{
	char username[ACCOUNT_NAME_MAX_LEN];
	char password[ACCOUNT_PASSWORD_MAX_LEN];
}LOGIN_MSG_DATA;

typedef struct
{
	char username[ACCOUNT_NAME_MAX_LEN];
	char password[ACCOUNT_PASSWORD_MAX_LEN];
	char vendorid[ACCOUNT_PASSWORD_MAX_LEN];
	int	 authmethod;
}LOGIN_MSG_DATA_EX;

typedef struct
{
	char filePath[256];
}CONFIG_UPDATE_MSG_DATA;

typedef struct
{
	char filePath[256];
	unsigned int nPhyAddr;
	unsigned int nFileLen;
}APPBIN_UPDATE_MSG_DATA;

typedef struct
{
	char path[256];
	char fileName[256];
}FIRMWARE_FTP_UPDATE_MSG_DATA;

typedef struct
{
	char fileName[256];
}RECORD_REMOVE_MSG_DATA;

typedef struct
{
	int mounted;
	int total;
	int used;
	int free;
	int percent;
}SDCARD_INFO_DATA;

typedef struct
{
	int mounted;
	int total;
	int used;
	int free;
	int percent;
}USB_INFO_DATA;

typedef struct
{
	int mounted;
	int total;
	int used;
	int free;
	int percent;
}NETWORK_INFO_DATA;

typedef struct
{
	SDCARD_INFO_DATA  sd1;
	SDCARD_INFO_DATA  sd2;
	USB_INFO_DATA     usb;
	NETWORK_INFO_DATA     network;
}STORAGE_INFO_DATA;

typedef struct 
{
	char kernelVersion[256];
	char fsVersion[256];
}SYSTEM_VERSION_DATA;

typedef struct
{
	struct tm time;
	int tz;
	int manual;	//手动时不考虑夏令时。自动校时考虑夏令时
}TIMESET_MSG_DATA;

typedef struct
{
	int index;
	int open;
	int brightness;
}LIGHT_CTRL_MSG_DATA;


typedef struct
{
	int playsound;
	int ledon;
	int playtime;
}SCARE_OFF_MSG_DATA;



typedef struct
{
	int level_direction;
	int vert_direction;
}PTZ_DIRECTION_CTRL_MSG_DATA;


typedef struct
{
	int level_step;
	int level_speed;
	int vert_step;
	int vert_speed;
}PTZ_SPEED_CTRL_MSG_DATA;

typedef struct _MotorCtrUserConfig_s
{
	int levelDire;
	int vertDire;
	int levelStep; 
	int vertStep;
	int levelSpeed; 
	int vertSpeed;
	int defaultLevelStep;
	int defaultVertStep;
	int defaultLevelSpeed;
	int defaultVertSpeed;
}MotorCtrUserConfig;



typedef struct
{
	int doBridge;

	char wireMac[256];	

	char ipType[256];
	char ip[256];
	char gateway[256];
	char netmask[256];
	char dns1[256];
	int  dns1Exsit;
	char dns2[256];
	int dns2Exsit;

	int isWirelessUp;
	//20130626
	char wirelessIp[256];
	char wirelessGateway[256];
	char wirelessNetmask[256];
	//20130626 end
	char wirelessMac[256];
	char essid[256];	
	char operationMode[256];
	char bitRate[256];
	char freq[256];
	char accessPoint[256];
	char encryptType[256];

	unsigned char linkquality;
	//unsigned char signallevel;
	//unsigned char noise;
	int signallevel;
	int noise;

	int cloudLogined;
	char cloudId[128];
	int cloudEnable;
	int cloudType;	
	//add end
}NETWORK_STATUS_DATA;

#define MAX_WIFI_AP_CNT  50 

#define WIFI_AUTH_OPEN   		0
#define WIFI_AUTH_SHARED   		1
#define WIFI_AUTH_WPAPSK   		2
#define WIFI_AUTH_WPA2PSK   	3
#define WIFI_AUTH_UNSPPORT   	4

#define WIFI_ENCRYP_NONE  		0
#define WIFI_ENCRYP_WEP   		1
#define WIFI_ENCRYP_TKIP  		2
#define WIFI_ENCRYP_AES   		3
#define WIFI_ENCRYP_UNSPPORT 	4

typedef struct
{
	char ssid[128];
	char wirelessMode[64];
	int authMode;
	int encryType; 
	int quality;
	int signalLevel;
	int noiseLevel;
	int channelnum;
}WIFI_AP_INFO;

typedef struct
{
	int apCnt;
	WIFI_AP_INFO  apInfos[MAX_WIFI_AP_CNT];	
}WIFI_AP_SCAN;


typedef enum
{
	SHOWDATA_PRINTF,
	SHOWDATA_DEBUG,
	SHOWDATA_NONE,
}ShowDataType;

#define UPLOAD_MP3_TO_CFG_MTD_MAX_FILE_SIZE (40*1024)
#define UPLOAD_MP3_TO_CFG_MTD_MIN_LEFT_SIZE (70*1024)
#define UPLOAD_MP3_FILE_NAME "upload.mp3"
#define UPLOAD_CERTIFICATION_FILE_NAME "https.crt"
#define UPLOAD_KEY_FILE_NAME "https.key"


typedef enum
{
	G4_SERVICE_NO = 0,		//0--- No service
	G4_SERVICE_LIMITED=1,		//1--- Limited service
	G4_SERVICE_AVAILABLE=2,	//2--- Service available
	G4_SERVICE_LIMITED_REGIONAL=3,//3--- Limited regional service
	G4_SERVICE_POWER_SAVE=4,//4--- Power save or deep sleep
}G4_srv_status;

#define G4_STR_LEN_64 64
#define G4_STR_LEN_32 32
#define G4_STR_LEN_256 256
typedef struct
{
	char Manufacturer[G4_STR_LEN_32]; //4G模块厂商
	char Model[G4_STR_LEN_32];		//4G模块型号
	char ICCID[G4_STR_LEN_32];
	char IMEI[G4_STR_LEN_32];
	char IMSI[G4_STR_LEN_32];
	char MSISDN[G4_STR_LEN_32];
	char WorkMode[G4_STR_LEN_32]; //当前工作网络模式, LAN/NO_SRV/WCDMA/LTE
	char Operator[G4_STR_LEN_32]; //运营商
	G4_srv_status nSvrStatus;
	int	 nDialStatus;	//0:未拨号　1:已拨号
	int	 nSimStatus;	//0--- SIM is not availabl 1--- SIM is available
	int  nSignalLevel;	//信号强度,0-100
}G4InfoStruct;


typedef struct
{
	int LedMode;
	int IrCutMode;
}FactoryDefaultCfg;

typedef struct
{
	int xPos;		//0-100
	int yPos;		//0-100
	int width;		//0-100
	int height;		//0-100
}AreaStruct;


typedef struct
{
    short    posx;
    short    posy;
    short    posw;
    short    posh;
} RectPos_t;

typedef struct
{
	char *pYUVData;
	unsigned int nBufferLen;
	unsigned int nDataLen;
	int	bDataValid;
	int bHanding;
	unsigned short width;
	unsigned short height;	
}YUV_DataStruct;


/*位操作宏定义*/
#define BIT_GET_64(res,index)  		(((unsigned long long)(res)) & (((unsigned long long)0x1) << (index)))
#define BIT_SET_64(res,index)  		(res = (((unsigned long long)(res)) | (((unsigned long long)0x1) << (index))))
#define BIT_UNSET_64(res,index)		(res = ((unsigned long long)(res) & (~(((unsigned long long)0x1) << (index)))))

#define BIT_GET_32(res,index)  		(((unsigned int)(res)) & (((unsigned int)0x1) << (index)))
#define BIT_SET_32(res,index)		(res = (((unsigned int )(res)) | (((unsigned int)0x1) << (index))))
#define BIT_UNSET_32(res,index)		(res = ((unsigned int)(res) & (~(((unsigned int)0x1) << (index)))))

#define BIT_GET_16(res,index)  		(((unsigned short)(res)) & (((unsigned short)0x1) << (index)))
#define BIT_SET_16(res,index)  		(res = (((unsigned short )(res)) | (((unsigned short)0x1) << (index))))
#define BIT_UNSET_16(res,index)		(res = ((unsigned short)(res) & (~(((unsigned short)0x1) << (index)))))

#define BIT_GET_8(res,index)		 (((unsigned char)(res)) & (((unsigned char)0x1) << (index)))
#define BIT_SET_8(res,index)  		(res = (((unsigned char )(res)) | (((unsigned char)0x1) << (index))))
#define BIT_UNSET_82(res,index)		(res = ((unsigned char)(res) & (~(((unsigned char)0x1) << (index)))))

#endif

