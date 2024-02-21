#ifndef _____AJ_MEDIA_CFG_H____
#define _____AJ_MEDIA_CFG_H____

#include <time.h>
#include <stdint.h>

#if defined (__cplusplus)
extern "C" {
#endif

#ifndef StreamTimeStamp
typedef double      StreamTimeStamp;
#endif

//move there by XXX 20111220
typedef struct
{
	int hour;
	int minute;
	int sec;
}DayTime;

typedef struct
{
	DayTime startTime;
	DayTime endTime;
}DayTimeSpan;


typedef	enum
{
	CONFIG_LANGUAGE_CN = 0,
	CONFIG_LANGUAGE_HK,
	CONFIG_LANGUAGE_TW,
	CONFIG_LANGUAGE_EN,
	CONFIG_LANGUAGE_RUSSION
}CONFIG_LANGUAGE;


typedef enum
{
	TITLE_ADD_NOTHING = 0,
	TITLE_ADD_RESOLUTION,
	TITLE_ADD_BITRATE,
	TITLE_ADD_RESOLUTION_AND_BITRATE
}titleFormatEn;

typedef enum
{
	POSITION_TYPE_BY_FOUR_CORNER = 0,//四角
	POSITION_TYPE_BY_SCALE = 1,	//画面比例(0-100)
	POSITION_TYPE_DISABLE = 2,
}Positiontype;

typedef enum
{
	TYPE_TYPE_BY_TEXT = 0,//文本
	TYPE_TYPE_BY_BMP = 1,	//BMP图片
}Titletype;


typedef	enum
{
	OSD_POINT_LEFT_TOP = 0,
	OSD_POINT_LEFT_BOTTOM,
	OSD_POINT_RIGHT_TOP,
	OSD_POINT_RIGHT_BOTTOM,
	OSD_POINT_HIDE, 
}PositionByCornerEnum;

typedef struct
{
	unsigned short xScale;//X方向位置,基于整个画面的比例(0-100)
	unsigned short yScale;//Y方向位置,基于整个画面的比例(0-100)
}PositionByScaleStruct;

typedef struct
{
	Positiontype type;
	union
	{
		PositionByCornerEnum value1;	
		PositionByScaleStruct value2;
	};
}osdPointEn;

#define MAX_NAME_LEN 32
typedef struct tag_encode_resolution
{
	char res_name[MAX_NAME_LEN];	//分辨率。更改分辨率选择时，其他值需要根据本结构相应更改
	char codec_name[MAX_NAME_LEN];	//编码格式
	int  stream_type; //0: main, 1: sub, 2: third
	int  def_bitrate; //kbps
	int  min_bitrate; //kbps
	int  max_bitrate; //kbps
	int  def_framerate;	//默认帧率
	int  min_framerate;	//最小帧率
	int  max_framerate;	//实际最大帧率(实际生效的帧率可选值只能是这2者之间)
	int  dual_stream; //if stream_type == 0, dual_stream == 0, means disable sub stream
	int  def_config;  //if def_config = 1, use for default config of video encode
	int  max_display_framerate;	//显示最大帧率(帧率可选值只能是这2者之间)
}RESOLUTION_ENTRY;

typedef struct tag_audio_mode
{
	char codec_name[MAX_NAME_LEN];		//编码方式
	int  channels;			//通道数
	int  bitspersample;	//比特率
	int  samplerate;		//采样率
	int  bitrate;			//比特率
	int  def_config;		//是否默认配置
}AUDIO_CODEC_ENTRY;

typedef struct tag_YUV_ENTRY_W
{
	char res_name[MAX_NAME_LEN];	//分辨率。
	int  format; //固定为0，目前只支持YUV420SP(NV12)。
	int  def_framerate;
	int  min_framerate;
	int  max_framerate; 
	int  def_config;  //if def_config = 1, use for default config of video encode
}YUV_ENTRY;

typedef struct
{
	int lbr_enable;	
	int lbr_style;		//低码率模式:	0: 保持帧率,自动码率	1: 视频质量优先,自动丢帧
	int lbr_bitratemode;//码率控制:	0: 自动 1:手动
	int lbr_bitrate;		//低码率目标值
	int lbr_motionlevel;	//运动级别:	0: 静止 1:运动幅度小 2:运动幅度大
	int lbr_noicelevel;	//噪点级别:	0: 无 1:低 2:高
}LbrControl;


typedef enum
{
	AJ_OVERLAY_STYLE_BLACK_WHITE = 0,		//黑字白底
	AJ_OVERLAY_STYLE_WHITE_BLACK = 1,		//白字黑底
	AJ_OVERLAY_STYLE_TRANSPARENT_BLACKWHITE = 2,	//透明背景，黑字白框
	AJ_OVERLAY_STYLE_TRANSPARENT_WHITEBLACK = 3,	//透明背景，白字黑框
	AJ_OVERLAY_STYLE_TRANSPARENT_BLACK = 4,	//透明背景，黑字
	AJ_OVERLAY_STYLE_TRANSPARENT_WHITE = 5, //透明背景，白字
	AJ_OVERLAY_STYLE_INVERSE_COLOR = 6, //反色
}AjOsdOverlayStyle;

typedef enum {
	ALARM_CODE_BEGIN=0,
	ALARM_CODE_LINKDOWN=1,
	ALARM_CODE_LINKUP = 2,
	ALARM_CODE_USB_PLUG = 3,
	ALARM_CODE_USB_UNPLUG = 4,
	ALARM_CODE_SD0_PLUG = 5,
	ALARM_CODE_SD0_UNPLUG = 6,
	ALARM_CODE_SD1_PLUG = 7,
	ALARM_CODE_SD1_UNPLUG = 8,
	ALARM_CODE_USB_FREESPACE_LOW = 9,
	ALARM_CODE_SD0_FREESPACE_LOW = 10,
	ALARM_CODE_SD1_FREESPACE_LOW = 11,
	ALARM_CODE_VIDEO_LOST = 12,
	ALARM_CODE_VIDEO_COVERD = 13,
	ALARM_CODE_MOTION_DETECT = 14,
	ALARM_CODE_GPIO3_HIGH2LOW = 15,	//仅仅用于告警触发判断。IO报警使用ALARM_CODE_IO_ALARM和ALARM_CODE_IO_ALARM_FINISH
	ALARM_CODE_GPIO3_LOW2HIGH = 16,	//仅仅用于告警触发判断。IO报警使用ALARM_CODE_IO_ALARM和ALARM_CODE_IO_ALARM_FINISH
	ALARM_CODE_STORAGE_FREESPACE_LOW = 17, 
	ALARM_CODE_RECORD_START = 18,
	ALARM_CODE_RECORD_FINISHED = 19,	
	ALARM_CODE_RECORD_FAILED = 20,	
	ALARM_CODE_VIDEO_AI = 21,	//智能分析报警，包含人形检测、车型检测、电动车、车牌、火焰等等，使用AlarmLevel字段作为子类型，取值参考AjAlarmAI
	ALARM_CODE_VIDEO_AI_FINISH = 22, //智能分析报警消除，使用AlarmLevel作为子类型
	ALARM_CODE_JPEG_CAPTURED = 23,	
	ALARM_CODE_RS485_DATA = 24,		
	ALARM_CODE_SAME_IP = 25,			
	ALARM_CODE_HW130_PIR = 26,
	ALARM_CODE_LPR = 27,	//车牌识别
	ALARM_CODE_AUDIO_BABYCRY = 28,//婴儿啼哭
	ALARM_CODE_AUDIO_LSA = 29,//高分贝声音

	ALARM_CODE_VIDEO_FORMAT_CHANGED = 30,	//格式/分辨率更改，用于通知客户端重新配置解码器

	ALARM_CODE_VIDEO_GATE = 31,//电子围栏

	ALARM_CODE_RESET_TO_FACTORY = 32,//恢复出厂通知
	ALARM_CODE_MOTION_DETECT_DISAPPEAR = 33,  //33  //移动侦测告警消除
	
	ALARM_CODE_IO_ALARM = 34,	//IO输入报警,用于一直按下的情况下，就一直告警
	ALARM_CODE_IO_ALARM_FINISH = 35,	//IO输入报警结束
	ALARM_CODE_GPS_INFO = 36,			
	ALARM_CODE_EMERGENCY_CALL = 37,
	ALARM_CODE_VIDEO_GATE_FINISH = 38,

	ALARM_CODE_CONFIG_CHANGED = 39, //用于通知devsdk/配置更改
	ALARM_CODE_BEGIN_REBOOT = 40,	//准备重启
	ALARM_CODE_TEMP_HUMID_ALARM = 41, //温湿度告警
	
	ALARM_CODE_EXTERNAL_IO_ALARM = 42,
	ALARM_CODE_EXTERNAL_IO_ALARM_FINISH = 43, 

	ALARM_CODE_KEY_PRESS = 44,
	ALARM_CODE_SENSOR = 45,//传感器报警，使用AlarmSensor作为子类型
	
	ALARM_CODE_CALL=150, //VOIP 呼叫相关，
	ALARM_CODE_CALL_CALLOUT = 151,//callout 呼叫
	ALARM_CODE_CALL_THROUGH = 152,//through 接通
	ALARM_CODE_CALL_HANGUP = 153,//hangup 挂断
	ALARM_CODE_CALL_TOHANGUP = 154,//timeout_hangup 超时挂断

	ALARM_CODE_ILLEGAL_MODIFY = 200,  //非法修改操作

	ALARM_CODE_END
}AjAlarmCode;
typedef enum
{
	ALARM_SENSOR_OFF = 0, //无报警或报警消除
	ALARM_SENSOR_ON  = 1,//常规报警
	ALARM_SENSOR_POW_CUT  = 2,//停电报警
	ALARM_SENSOR_OUT_OF_SCOPE  = 3,//传感器超范围报警
	ALARM_SENSOR_FAULT  = 4,//设备故障
	ALARM_SENSOR_MAX
}AjSensorAlarmType;

typedef enum
{
	ALARM_AI_PD = 1, //人形
	ALARM_AI_VEHICLE_CAR = 2, //车形
	ALARM_AI_VEHICLE_MOTO = 3, //摩托
	ALARM_AI_VEHICLE_ELECTRICBICYCLE = 4, //电单车
	ALARM_AI_VEHICLE_BICYCLE = 5, //自行车
	ALARM_AI_LPR = 6, //车牌
	ALARM_AI_VIDEO_GATE = 7,//越界(拌线)
	ALARM_AI_FIRE = 8,	//火焰
	ALARM_AI_FACEDETECT = 9,//FACE DETECT
	ALARM_AI_VIDEO_REGION_DETECT = 10,//区域侦测，包括逗留、进入、离开

	ALARM_AI_VIDEO_FALLINGOBJECT = 13,//高空抛物
	ALARM_AI_TEMP_UPPER = 14,//温度过高
	ALARM_AI_TEMP_LOWER =15,//温度过低
	ALARM_AI_HUMID_UPPER =16,//湿度过高
	ALARM_AI_HUMID_LOWER =17,//湿度过低
	ALARM_AI_VOC_THREASHHOLD_GOOD = 18,//空气优良门限300
	ALARM_AI_VOC_THREASHHOLD_TRACEPOLLUTION = 19,//微量污染门限1500
	ALARM_AI_VOC_THREASHHOLD_LIGHTPOLLUTION = 20,//轻度污染门限3000
	ALARM_AI_VOC_THREASHHOLD_MODERATEPOLLUTION = 21,//中度污染门限5000
	ALARM_AI_VOC_THREASHHOLD_HEAVYPOLLUTION = 22,//重度污染10000
	ALARM_AI_MAX
}AjAiAlarmType;

#define ALARM_CODE_VIDEO_PD ALARM_CODE_VIDEO_AI
#define ALARM_CODE_VIDEO_PD_FINISH ALARM_CODE_VIDEO_AI_FINISH

typedef struct
{
	int year;
	int month;
	int day;
	int wday;
	int hour;
	int minute;
	int second;
}ALARM_TIME;

#define MAX_ALARM_DATA_LEN 128

typedef struct 
{
	ALARM_TIME	time;
	AjAlarmCode code;
	int 		flag;
	int			level;
	char 		data[MAX_ALARM_DATA_LEN];
} ALARM_ENTRY;

typedef enum
{
	AUDIO_PLAY_READY,	//预备OK，未播放
	AUDIO_PLAY_RESERVE,//正在播放反向音频
	AUDIO_PLAY_FILE,	//正在播放文件
}AudioPlayStatus;


typedef enum _AudioChannel_e{
	AudioChannel_Mono	= 1,
	AudioChannel_Stereo = 2
}AudioChannel_e;

typedef enum _AudioType_e{
	AudioType_PCMU,
	AudioType_AAC_LC,
	AudioType_PCMA,
	AudioType_PCM,
	AudioType_OPUS,
	AudioType_MP3,
}AudioType_e;

typedef enum _AU_SampleRate_e{
	AU_SampleRate_8000HZ	= 8000,
	AU_SampleRate_16000HZ	= 16000,
	AU_SampleRate_32000HZ	= 32000,
	AU_SampleRate_44100HZ	= 44100,
	AU_SampleRate_48000HZ	= 48000
}AU_SampleRate_e;

typedef struct
{
	int bBlocked;	
	int bRun;
}PcmPlayParam;

//反向音频数据头(新加用于PCM播放)
#define AJ_RA_MAGIC 0xEEbbAAdd
typedef struct
{
	unsigned int magic; //AJ_RA_MAGIC
	unsigned short audiotype;
	unsigned short samplerate;
	unsigned short channels;
	unsigned short reserve;
}RaDataHeader;


#if defined (__cplusplus)
}
#endif

#endif

