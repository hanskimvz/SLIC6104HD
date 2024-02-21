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
	POSITION_TYPE_BY_FOUR_CORNER = 0,//�Ľ�
	POSITION_TYPE_BY_SCALE = 1,	//�������(0-100)
	POSITION_TYPE_DISABLE = 2,
}Positiontype;

typedef enum
{
	TYPE_TYPE_BY_TEXT = 0,//�ı�
	TYPE_TYPE_BY_BMP = 1,	//BMPͼƬ
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
	unsigned short xScale;//X����λ��,������������ı���(0-100)
	unsigned short yScale;//Y����λ��,������������ı���(0-100)
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
	char res_name[MAX_NAME_LEN];	//�ֱ��ʡ����ķֱ���ѡ��ʱ������ֵ��Ҫ���ݱ��ṹ��Ӧ����
	char codec_name[MAX_NAME_LEN];	//�����ʽ
	int  stream_type; //0: main, 1: sub, 2: third
	int  def_bitrate; //kbps
	int  min_bitrate; //kbps
	int  max_bitrate; //kbps
	int  def_framerate;	//Ĭ��֡��
	int  min_framerate;	//��С֡��
	int  max_framerate;	//ʵ�����֡��(ʵ����Ч��֡�ʿ�ѡֵֻ������2��֮��)
	int  dual_stream; //if stream_type == 0, dual_stream == 0, means disable sub stream
	int  def_config;  //if def_config = 1, use for default config of video encode
	int  max_display_framerate;	//��ʾ���֡��(֡�ʿ�ѡֵֻ������2��֮��)
}RESOLUTION_ENTRY;

typedef struct tag_audio_mode
{
	char codec_name[MAX_NAME_LEN];		//���뷽ʽ
	int  channels;			//ͨ����
	int  bitspersample;	//������
	int  samplerate;		//������
	int  bitrate;			//������
	int  def_config;		//�Ƿ�Ĭ������
}AUDIO_CODEC_ENTRY;

typedef struct tag_YUV_ENTRY_W
{
	char res_name[MAX_NAME_LEN];	//�ֱ��ʡ�
	int  format; //�̶�Ϊ0��Ŀǰֻ֧��YUV420SP(NV12)��
	int  def_framerate;
	int  min_framerate;
	int  max_framerate; 
	int  def_config;  //if def_config = 1, use for default config of video encode
}YUV_ENTRY;

typedef struct
{
	int lbr_enable;	
	int lbr_style;		//������ģʽ:	0: ����֡��,�Զ�����	1: ��Ƶ��������,�Զ���֡
	int lbr_bitratemode;//���ʿ���:	0: �Զ� 1:�ֶ�
	int lbr_bitrate;		//������Ŀ��ֵ
	int lbr_motionlevel;	//�˶�����:	0: ��ֹ 1:�˶�����С 2:�˶����ȴ�
	int lbr_noicelevel;	//��㼶��:	0: �� 1:�� 2:��
}LbrControl;


typedef enum
{
	AJ_OVERLAY_STYLE_BLACK_WHITE = 0,		//���ְ׵�
	AJ_OVERLAY_STYLE_WHITE_BLACK = 1,		//���ֺڵ�
	AJ_OVERLAY_STYLE_TRANSPARENT_BLACKWHITE = 2,	//͸�����������ְ׿�
	AJ_OVERLAY_STYLE_TRANSPARENT_WHITEBLACK = 3,	//͸�����������ֺڿ�
	AJ_OVERLAY_STYLE_TRANSPARENT_BLACK = 4,	//͸������������
	AJ_OVERLAY_STYLE_TRANSPARENT_WHITE = 5, //͸������������
	AJ_OVERLAY_STYLE_INVERSE_COLOR = 6, //��ɫ
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
	ALARM_CODE_GPIO3_HIGH2LOW = 15,	//�������ڸ澯�����жϡ�IO����ʹ��ALARM_CODE_IO_ALARM��ALARM_CODE_IO_ALARM_FINISH
	ALARM_CODE_GPIO3_LOW2HIGH = 16,	//�������ڸ澯�����жϡ�IO����ʹ��ALARM_CODE_IO_ALARM��ALARM_CODE_IO_ALARM_FINISH
	ALARM_CODE_STORAGE_FREESPACE_LOW = 17, 
	ALARM_CODE_RECORD_START = 18,
	ALARM_CODE_RECORD_FINISHED = 19,	
	ALARM_CODE_RECORD_FAILED = 20,	
	ALARM_CODE_VIDEO_AI = 21,	//���ܷ����������������μ�⡢���ͼ�⡢�綯�������ơ�����ȵȣ�ʹ��AlarmLevel�ֶ���Ϊ�����ͣ�ȡֵ�ο�AjAlarmAI
	ALARM_CODE_VIDEO_AI_FINISH = 22, //���ܷ�������������ʹ��AlarmLevel��Ϊ������
	ALARM_CODE_JPEG_CAPTURED = 23,	
	ALARM_CODE_RS485_DATA = 24,		
	ALARM_CODE_SAME_IP = 25,			
	ALARM_CODE_HW130_PIR = 26,
	ALARM_CODE_LPR = 27,	//����ʶ��
	ALARM_CODE_AUDIO_BABYCRY = 28,//Ӥ�����
	ALARM_CODE_AUDIO_LSA = 29,//�߷ֱ�����

	ALARM_CODE_VIDEO_FORMAT_CHANGED = 30,	//��ʽ/�ֱ��ʸ��ģ�����֪ͨ�ͻ����������ý�����

	ALARM_CODE_VIDEO_GATE = 31,//����Χ��

	ALARM_CODE_RESET_TO_FACTORY = 32,//�ָ�����֪ͨ
	ALARM_CODE_MOTION_DETECT_DISAPPEAR = 33,  //33  //�ƶ����澯����
	
	ALARM_CODE_IO_ALARM = 34,	//IO���뱨��,����һֱ���µ�����£���һֱ�澯
	ALARM_CODE_IO_ALARM_FINISH = 35,	//IO���뱨������
	ALARM_CODE_GPS_INFO = 36,			
	ALARM_CODE_EMERGENCY_CALL = 37,
	ALARM_CODE_VIDEO_GATE_FINISH = 38,

	ALARM_CODE_CONFIG_CHANGED = 39, //����֪ͨdevsdk/���ø���
	ALARM_CODE_BEGIN_REBOOT = 40,	//׼������
	ALARM_CODE_TEMP_HUMID_ALARM = 41, //��ʪ�ȸ澯
	
	ALARM_CODE_EXTERNAL_IO_ALARM = 42,
	ALARM_CODE_EXTERNAL_IO_ALARM_FINISH = 43, 

	ALARM_CODE_KEY_PRESS = 44,
	ALARM_CODE_SENSOR = 45,//������������ʹ��AlarmSensor��Ϊ������
	
	ALARM_CODE_CALL=150, //VOIP ������أ�
	ALARM_CODE_CALL_CALLOUT = 151,//callout ����
	ALARM_CODE_CALL_THROUGH = 152,//through ��ͨ
	ALARM_CODE_CALL_HANGUP = 153,//hangup �Ҷ�
	ALARM_CODE_CALL_TOHANGUP = 154,//timeout_hangup ��ʱ�Ҷ�

	ALARM_CODE_ILLEGAL_MODIFY = 200,  //�Ƿ��޸Ĳ���

	ALARM_CODE_END
}AjAlarmCode;
typedef enum
{
	ALARM_SENSOR_OFF = 0, //�ޱ����򱨾�����
	ALARM_SENSOR_ON  = 1,//���汨��
	ALARM_SENSOR_POW_CUT  = 2,//ͣ�籨��
	ALARM_SENSOR_OUT_OF_SCOPE  = 3,//����������Χ����
	ALARM_SENSOR_FAULT  = 4,//�豸����
	ALARM_SENSOR_MAX
}AjSensorAlarmType;

typedef enum
{
	ALARM_AI_PD = 1, //����
	ALARM_AI_VEHICLE_CAR = 2, //����
	ALARM_AI_VEHICLE_MOTO = 3, //Ħ��
	ALARM_AI_VEHICLE_ELECTRICBICYCLE = 4, //�絥��
	ALARM_AI_VEHICLE_BICYCLE = 5, //���г�
	ALARM_AI_LPR = 6, //����
	ALARM_AI_VIDEO_GATE = 7,//Խ��(����)
	ALARM_AI_FIRE = 8,	//����
	ALARM_AI_FACEDETECT = 9,//FACE DETECT
	ALARM_AI_VIDEO_REGION_DETECT = 10,//������⣬�������������롢�뿪

	ALARM_AI_VIDEO_FALLINGOBJECT = 13,//�߿�����
	ALARM_AI_TEMP_UPPER = 14,//�¶ȹ���
	ALARM_AI_TEMP_LOWER =15,//�¶ȹ���
	ALARM_AI_HUMID_UPPER =16,//ʪ�ȹ���
	ALARM_AI_HUMID_LOWER =17,//ʪ�ȹ���
	ALARM_AI_VOC_THREASHHOLD_GOOD = 18,//������������300
	ALARM_AI_VOC_THREASHHOLD_TRACEPOLLUTION = 19,//΢����Ⱦ����1500
	ALARM_AI_VOC_THREASHHOLD_LIGHTPOLLUTION = 20,//�����Ⱦ����3000
	ALARM_AI_VOC_THREASHHOLD_MODERATEPOLLUTION = 21,//�ж���Ⱦ����5000
	ALARM_AI_VOC_THREASHHOLD_HEAVYPOLLUTION = 22,//�ض���Ⱦ10000
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
	AUDIO_PLAY_READY,	//Ԥ��OK��δ����
	AUDIO_PLAY_RESERVE,//���ڲ��ŷ�����Ƶ
	AUDIO_PLAY_FILE,	//���ڲ����ļ�
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

//������Ƶ����ͷ(�¼�����PCM����)
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

