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
	unsigned int workday[MAX_WORDDAYTIME_COUNT];//����0-6��ʶ����-����ÿСʱ�����ã�ÿ��Сʱռ��һ��bitλ��0-23BIT��Ч 
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
	unsigned char nEnable;			//���ñ��
	unsigned char bAuto;			//����ʱ���Զ�����
	short nOffsetMin;		//ƫ��ʱ��(����)
	unsigned char nStartMonth;
	unsigned char nStartWeek;		//���µڼ���
	unsigned char nStartWeekday;	//�ܼ�
	unsigned char nStartHour;		//Сʱ
	unsigned char nToMonth;
	unsigned char nToWeek;		//���µڼ���
	unsigned char nToWeekday;	//�ܼ�
	unsigned char nToHour;		//Сʱ
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
	int type;		//AF����: 0: BSD 1: ZUO
	int bSendOnStart;	//�����ͷ�AF����	
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
	int day; //���ڣ� 0-6 = ����һ�������죬 7=ÿ��
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
}AlarmClock;//��������

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
}AlarmOClock;//���㱨ʱ

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
	AlarmClockConfig clockSetting;//��������
}SystemConfig;

// media config

#define TIME_FORMAT_MAX_LEN 32

typedef struct
{
	char format[TIME_FORMAT_MAX_LEN];
}TimeFormat;

typedef struct
{
	int posX;//��posType=POSITION_TYPE_BY_FOUR_CORNERʱ��ֻ����0/1/2������Ϊ����0-100%
	int posY;//��posType=POSITION_TYPE_BY_FOUR_CORNERʱ��ֻ����0/1/2������Ϊ����0-100%
	TimeFormat timeFormat;
	Positiontype posType;
}TimeOverlay;

#define TITLE_MAX_LEN 200
typedef struct
{
	int posX;	//��posType=POSITION_TYPE_BY_FOUR_CORNERʱ��ֻ����0/1/2������Ϊ����0-100%
	int posY;	//��posType=POSITION_TYPE_BY_FOUR_CORNERʱ��ֻ����0/1/2������Ϊ����0-100%
	char title_utf8[TITLE_MAX_LEN];//��titleType=BMPʱ��������BMP·��
	Positiontype posType;
	Titletype titleType; 	
}TitleOverlay;

typedef struct
{
	int enable;
	int transparency; //titleFormatEn��������Ϣ
	TimeOverlay timeOverlay;
	TitleOverlay titleOverlay;
	short style;	//AjOsdOverlayStyle
	short bDsplayWeek;	//0:����ʾ 1:�����ں�ʱ����м���ʾ���ڼ� 2:��ĩβ��ʾ���ڼ�
	short bOverlayFps;	
	short fontsize; // 0 ��׼  1 ������ 2 ��������
	short real_transparency; //͸���ȡ�0-100
	short time24or12;// 0: 24 1: 12
}VideoOverlay;


typedef	struct
{
	int enable;
	
	Positiontype posType;
	int pos_xscale;//�����ȱ���λ��0-100
	int pos_yscale;//����߶ȱ���λ��0-100

	int	color_front;	//ǰ����ɫ
	int color_back;		//������ɫ
	
	short transparency; //͸���ȡ�0-100
	unsigned char fontsize; // 0 ��׼  1 ������ 2 ��������
	unsigned char linegap; // 0-8,0��ʾ�޼�࣬8��ʾ���1���ַ��߶�
	char title_utf8[TITLE_MAX_LEN];//��titleType=BMPʱ��������BMP·��
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
	VIDEO_QUALITY_CUSTOM = 0,//�Զ���
	VIDEO_QUALITY_WORSER = 1, //����
	VIDEO_QUALITY_WORSE = 2,	 //�ϲ�
	VIDEO_QUALITY_NORMAL = 3,    //����
	VIDEO_QUALITY_GOOD = 4,		 //��
	VIDEO_QUALITY_BEST = 5,      //����
}VideoQualityEnum;

typedef struct
{
	int qp_enable;	//�Զ���QP, Ϊ0ʱϵͳ�Զ�����
	int qp_min;	//QP��Сֵ,0-51��QPԽС����Խ��ϸ��ÿ֡�Ĵ�С��Խ���෴��QPԽ����Խ�ֲڣ�ռ�õĴ洢�ռ��ԽС
	int qp_max; //QP���ֵ,0-51��ͬ�ϣ���Ҫ��֤��С��qp_min
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
	QPConfig		qp; //VBRʱ�Զ���QP���ã���Ҫ��������FUNCTION_QP��VBRʱ�������Ч
}VideoEncodeCfg;

typedef struct
{
	int enable; //����/����
	int quality;// 20-100
}JpegEncodeCfg;

typedef struct 
{
	int enable;
	Resolution   resolution;
	int frameRate; 
	int format;//NV12/RGB888�ȵ�
}YuvEncodeCfg;

#define VIDEO_NUMBER_MAX 3 //������Ƶ������

typedef enum
{
	TWO_LENS_WORKMODE_JOINT_AND_CORRECTION = 0,//ƴ�Ӳ�У��
	TWO_LENS_WORKMODE_LEFT_LEN = 1,//��ͷ
	TWO_LENS_WORKMODE_RIGHT_LEN = 2,//�Ҿ�ͷ
	TWO_LENS_WORKMODE_JOINT_NOT_CORRECTION = 3,//ƴ�Ӳ�У��
	TWO_LENS_WORKMODE_TWOSTREAM_Independent  = 4,//˫��ͷ�ֿ�����
}TwoLensWorkMode;

typedef struct
{
	TwoLensWorkMode eTwoLensWorkMode;
	unsigned int nOptimumDistance; //��Ѿ���
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
	short shutter_mode_day;//0-1	//����ģʽ:�Զ�/�ֶ�
	short shutter_mode_night;//0-1	//����ģʽ:�Զ�/�ֶ�
	short shutter_speed_day;//10-10000	//�����ٶ�
	short shutter_speed_night;//10-10000 //�����ٶ�
}VideoShutter;

typedef enum
{
	IRCUT_Mode_Active = 0, //����ģʽ/������Զ�����ģʽ, ISP�Զ��ж�SENSOR���棬����IRCUT�͵ư�
	IRCUT_Mode_DayNight =1, //��ҹģʽ������ʱ���������IRCUT��ͼ���ת��
	IRCUT_Mode_Passive = 2,	//����ģʽ/Ӳ�����ⲿ����ģʽ�����ݵư�Ĺ����������Ӳ���źţ�������IRCUT
	IRCUT_Mode_Manual = 3,	//�ֶ�ģʽ�������ݵư��SENSOR���棬�ɵ��������ֶ��л�
	IRCUT_Mode_ReversePassive =	4, //���򱻶�ģʽ
	IRCUT_Mode_AUTO_BY_HARDWARE = 5, //Ӳ�����Զ�����ģʽ������Ӳ������adc�������л���ҹ
	IRCUT_Mode_LIGHT_ALWAYS_ON = 6, //�ֶ��ƹⳣ��
	IRCUT_Mode_LIGHT_ALWAYS_OFF = 7, //�ֶ��ƹⳣ��
	IRCUT_Mode_MAX
}IRCutMode;

typedef enum
{
	LED_PURE_INFRAED = 0, //������
	LED_PURE_WHITE = 1, //���׹�
	LED_INFRAED_THEN_WHITE = 2, //���ⴥ��ʱ�׹�
	LED_WHITE_THEN_INFRAED = 3, //�׹ⴥ��ʱ����
}LedMode;

typedef enum
{
	LED_IMAGE_NORMAL = 0,// ���� 
	LED_IMAGE_FACE_EXPOSURE_PREVENTION =1,//���������� 
	LED_IMAGE_CHEPAI_MODE=2,//: �ճ���ģʽ 1
	LED_IMAGE_INTELLIGENT_FACE_EXPOSURE_PREVENTION=3, //���ܷ������������澯����ʱ�����÷���������
	LED_IMAGE_CHEPAI_MODE_2=4,//: �ճ���ģʽ 2
	LED_IMAGE_CHEPAI_MODE_3=5,//: �ճ���ģʽ 3
	LED_IMAGE_CHEPAI_MODE_4=6,//: �ճ���ģʽ 4
	LED_IMAGE_CHEPAI_MODE_5=7,//: �ճ���ģʽ 5
	LED_IMAGE_CHEPAI_MODE_6=8,//: �ճ���ģʽ 6
}LedImageMode;//����ͼ��ģʽ

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
	VIDEO_ISP_MODE_NORMAL = 0,// ����ģʽ 
	VIDEO_ISP_MODE_FORCE_FRAMERATE =1,//ǿ��֡��ģʽ 
	VIDEO_ISP_MODE_SUPERSTAR=2,//���ǹ�ģʽ
}VideoEncodeMode;


typedef enum
{
	VIDEO_WDR_MODE_OFF = 0,
	VIDEO_WDR_MODE_WDR = 1,	//��̬ʼ�տ���(325/328Q����רָ���ֿ�̬,���ڷ����Զ�����SENSOR��ȷ������/�����̬)
	VIDEO_WDR_MODE_WDR_BY_TIME = 2, //�����õ�ʱ�������̬
	VIDEO_WDR_MODE_HDR = 3, //HDR(SENSOR�����̬������������һ�������ĺ���Ҫ���������)
}VideoWdrMode;

typedef struct
{
	int brightness;
	int contrast;
	int saturation;
	int sharpness;
	
	unsigned char tvsystem; // 0: NTSC (60HZ) 1: PAL (50HZ)
	unsigned char forct_antiflicker; //ǿ�ƿ�����������"antiflicker"
	short reserved;
	unsigned short cropxpix;	//X��ü�����, ������"video_crop"
	unsigned short cropypix;	//Y��ü�����������"video_crop"

	int hflip;		//ˮƽ��ת 0 1 
	int vflip;		//��ֱ��ת 0 1   
	int rotate;		//����ģʽ 0 1 , ������"rotate_enable"

	int whitebalance;	//enable R G B 4��ֵ��� 
						//enable=(whitebalance>>24)&0xff; R=(whitebalance>>16)&0xff; G=(whitebalance>>8)&0xff; B=(whitebalance)&0xff
	int backlight;		//����(��ⲹ��0-255)
	int HLC;	//ǿ������ //0-255
	int tnf;	//2d���� //0-255
	int snf;	//3D���� //0-255

	////��������////	
	int bManualGain;//0: �Զ����� 1: �ֶ�����, ������"gainsetting"
	int gainValue;//�ֶ�����ֵ, ������"gainsetting"

	////////��̬////////
	int wdr_mode; //VideoWdrMode, ������"wdr_setting"
	DayTimeSpan wdr_worktime; //������"wdr_setting"
	int wdr_value; //������"wdr_setting"

	////////ȥ��////////
	int dfrog_flag;
	int dfrog_value;

	////////���ӿ���////////
	VideoShutter shutterSetting;//������"VideoShutter"

	//ͼ��ISPЧ��ѡ��
	int isp_mode_color;	//ISP��ɫģʽ 0-3
	int isp_mode_night; //ISPҹ��ģʽ 0-3

	//ͼ��ģʽ
	int videoEncodeMode; //VideoEncodeMode, ������"vencodemode_set"

	////////IRCUT�벹�����////////	
	IRCutMode ircut_mode; //������"ircut_setting"
	unsigned char ircut_sensitivity; //0 to 100 //δ�õ�
	unsigned char ircut_openled_delay;//������ʱ //IrcutOpenLedOnIllum, ������"ircut_leddelay"
	unsigned char led_brightness_mode;	//�������ȿ���:0�Զ� 1�ֶ��� ������"ledtype_set"
	unsigned char led_brightness_value;//��������:10%-100%,  ������"ledtype_set"
	unsigned char led_brightness_alarm; //�澯ʱ��������
	DayTimeSpan ircut_nighttime; //������"ircut_setting"
	int ircut_keepcolor; //20120419, ������"ircut_setting"
	LedMode led_mode;// ����ƹ���ģʽ,������"ledtype_set"
	LedImageMode ispadvmode;//0: ���� 1: ���������� 2: �ճ���ģʽ,  ������"ledtype_set"
	////////IRCUT�벹�����////////	
	//�ص�������
	unsigned char light_off_sensitivity; //������"ircut_leddelay"	
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
	int amplify;	//�Ƿ���Ҫ�ڲ�����
	short ra_answer;//������Ƶ�Ƿ���Ҫ��������
	short aec_enable;
	short mute_ptz_turn;//��̨ת��ʱ����
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
	int httpsPort; //HTTPS�˿ڣ���Ҫ������ FUNCTION_HTTPS
	int h5Port;    //H5���Ŷ˿ڣ���Ҫ������ FUNCTION_H5
	char httpsCertificate[MAX_IPC_FILENAME_LEN]; //https֤���ļ�����Ҫ������ FUNCTION_HTTPS
	char httpsKey[MAX_IPC_FILENAME_LEN]; //https��Կ�ļ�����Ҫ������ FUNCTION_HTTPS
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
	TimeSpanCfg  timeSpan;//����ʱ��
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
	unsigned char PlayTone;//������������
	unsigned char InRingTimes;//��������������Զ���ͨ
	unsigned char reserved;///�������壬Ĭ�Ͽ����㲥��Ϣ
	unsigned short keyPressTimeLen;	//�������еİ���ʱ��(����, 100ms-5000ms)��������
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
	PlatRegStatus result;	//0: δע�� 1: ע���� 2: ע��ʧ�� 3: ע��ɹ�
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
	int nstreams;		//��������:0 ������ 1������ 2 ˫����
	int nChannelNum;	//ͨ������
	
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
	int timelapseEnable;	//��ʱ��Ӱ�������
	int timelapseSec;//���������¼��һ֡
	int timelapseFps;//����֡��
	int timelapseFileSize;//��ʱ��Ӱ�ļ���С
}RecordTimelapseConfig;


typedef struct
{
	int		localEnable;
	NetworkStorageType		remoteEnable;
	char    storageSequence[MAX_STORAGE_SEQUENCE_NAME_LEN];
	char    mountParam[MAX_REMOTE_MOUNT_PARAM_LEN];	
	RecordStoragePolicy storePolicy;	
	int recordFileSize;
	int recordFileKeeyDays;//¼�����������

	RecordTimelapseConfig timelapseCfg;//��ʱ��Ӱ����
}RecordCommConfig;

typedef struct
{
	int					stream; // 0:������ 1:������ 2:��������ͬʱ¼��
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
	RECORD_ALARM_BIT_MOTION_DETECT = 0,//�ƶ����
	RECORD_ALARM_BIT_HUMAN = 1,//����
	RECORD_ALARM_BIT_CAR = 2,	//����
	RECORD_ALARM_BIT_MOTO = 3,	//Ħ�г�
	RECORD_ALARM_BIT_ELECTRICBICYCLE = 4,//�絥��
	RECORD_ALARM_BIT_BICYCLE = 5,//���г�
	RECORD_ALARM_BIT_FACE = 6, //����
	RECORD_ALARM_BIT_NONMOTO_VEHICLE = 7,//�ǻ�����
	RECORD_ALARM_BIT_FIRE=8,//����
	RECORD_ALARM_BIT_FALLINGOBJECT=9,//�߿�����
	RECORD_ALARM_BIT_LPR = 10,	//����ʶ��
	RECORD_ALARM_BIT_VIDEO_COVERD = 11,
	RECORD_ALARM_BIT_VIDEO_GATE = 12,//����Χ��
	RECORD_ALARM_BIT_AUDIO_BABYCRY = 13,//Ӥ�����
	RECORD_ALARM_BIT_AUDIO_LSA = 14,//�߷ֱ�����
	RECORD_ALARM_BIT_IO_ALARM = 15,	//IO���뱨��
	RECORD_ALARM_BIT_EMERGENCY_CALL = 16,
	RECORD_ALARM_BIT_TEMP_HUMID_ALARM = 17, //��ʪ�ȸ澯
	RECORD_ALARM_BIT_SENSOR = 18,//������������ʹ��AlarmSensor��Ϊ������
	RECORD_ALARM_BIT_LINKDOWN=19,

	RECORD_ALARM_BIT_MAX,
}AlarmRecordBits;

typedef struct
{
	int					stream; // 0:������ 1:������ 2:��������ͬʱ¼��
	RecordFileFormat	fileFormat;
	RecordMediaType		mediaType;
	int 				precordTime;
	int 				recordTime;
	int					localStore;
	int					remoteStore;
	int					ftpUpload;
	int					emailUpload;
	int 				stopNoAlarm; //if noalarmstop=1, recordTime means the record time after alarm disappear
	unsigned int alarmbits;//��������,ÿһ�ֱ���ռ��1��bit���μ�AlarmRecordBits
}AlarmRecordConfig;

typedef struct
{
	short preTakeTime;
	short sendoutInterval;//FTP/EMAIL����Ƶ��,��.0��ʶ������
	int totalTakeTime;
	int localStore;
	int remoteStore;
	int ftpUpload;
	int emailUpload;
	int 	stopNoAlarm; //if noalarmstop=1, recordTime means the record time after alarm disappear
	int	stream;	//ץͼʹ�õ�����
	unsigned int alarmbits;//��������,ÿһ�ֱ���ռ��1��bit���μ�AlarmRecordBits
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
HIGH:��Ӧ������ƽʱΪ0������ʱд1
LOW:��Ӧ���գ�ƽʱΪ1������ʱд0
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
	int min_interval;//��С���ʱ��
	int playresult;//�����������ͽ��
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
	short enable; //����
	short enable_night;//����
	int times;//���Ŵ��� <=0��ʾһֱ��������0��ʾ����
	int intervalsecnods;	//�����ϴβ��ŵ���С���ʱ����
	char filename[AUDIO_ACTION_LEN_FILENAME];
}AudioPlayAction;


typedef struct
{
	AlarmOutputAction outputAction;
	PTZAction         ptzAction;
	AudioPlayAction	  audioAction;
	unsigned char light_twinkle_enable;//�ƹ���˸
	unsigned char notify_alarmserver_enable;//�ϱ��澯����
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
	unsigned char light_twinkle_enable;//�ƹ���˸
	unsigned char notify_alarmserver_enable;//�ϱ��澯����
	unsigned char reserved2;
	unsigned char reserved3;
}MotionDetectAction;

typedef struct
{
	int enable_babycry;//Ӥ������
	int sensity_babycry;
	int enable_lsd;	//�߷ֱ�����
	int sensity_lsd;	
}AudioAlarm;


#define MD_MAX_GRID_ROW 18
#define MD_MAX_GRID_COL 22
#define MD_CONFIG_STRING_LEN (MD_MAX_GRID_ROW*MD_MAX_GRID_COL+4)
#define MAX_MOTIONDETECT_CONFIG_STRING MD_CONFIG_STRING_LEN//32

//�ƶ�����鶨�壬���ϡ����½�blockλ��
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
	AI_TWINKLE_REGION = 1,//���������˸
	AI_TWINKLE_AROUND = 2,//����������˸
}RectTwinkleEnum;

typedef struct
{
	unsigned char draw_rect_enable;	//�������
	unsigned char draw_human_enable;	//�����ο�
	unsigned char track_human_enable;	//���θ���
	unsigned char rect_twinkle_enable;	//��⵽����ʱ�������˸,�μ�RectTwinkleEnum
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
	unsigned char light_twinkle_enable;//�ƹ���˸
	unsigned char notify_alarmserver_enable;//�ϱ��澯����
	unsigned char alarm_led_enable;//��������
	unsigned char auto_zoom_enable;//�䱶����
}PdAction;

typedef struct
{
	unsigned char draw_rect_enable;	//�������
	unsigned char draw_vehicle_enable;	//�����ο�
	unsigned char rect_twinkle_enable;	//��⵽����ʱ�������˸
	unsigned char reserved;
	AlarmOutputAction outputAction;
	AudioPlayAction	  audioAction;
}VehicleShapeAction;

typedef struct
{
	unsigned char draw_osd_enable;		//���Ƴ���OSD
	unsigned char play_voice_enable;	//��������
	unsigned short reserved;
	AlarmOutputAction outputAction;
}LprAction;


typedef struct
{
	int draw_rect_enable;	//����
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

//����ʶ��--20210611��������ܷ���
typedef enum
{
	AI_TYPE_BIT_CAR = 0,	//����
	AI_TYPE_BIT_MOTO = 1,	//Ħ�г�
	AI_TYPE_BIT_ELECTRICBICYCLE = 2,//�絥��
	AI_TYPE_BIT_BICYCLE = 3,//���г�
	AI_TYPE_BIT_HUMAN = 4,	//����
	AI_TYPE_BIT_FACE = 5, //����
	AT_TYPE_BIT_NONMOTO_VEHICLE = 6,//�ǻ�����
	AT_TYPE_BIT_FIRE=7,//����
	AT_TYPE_BIT_FALLINGOBJECT=8,//�߿�����
	AI_TYPE_BIT_MAX,
}AjAiBits;
	
typedef struct
{
	int enable_day;
	int enable_night;
	unsigned int type;//32bit: bit0: ���� bit1: Ħ�г� bit2:�絥�� bit3:���г� bit4: ����
	PD_AREA_ENTRY area;
	PdAction alarmAction;
	TimeSpanCfg  timeSpan;
	int threshold;
	int sensitivity;	
	Polygon  polygonArea;
}PdAlarm;

//����ʶ��
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
	int  humidity_range_upper;	//ʪ��ȡֵ��Χ���ֵ

	int  voc_enable;			//�ж�����������
	int  voc_threashhold_good;	//�����������ޣ�����Ĭ��300ppb��
	int  voc_threashhold_TracePollution;	//΢����Ⱦ���ޣ�����Ĭ��1500ppb��
	int  voc_threashhold_LightPollution;	//�����Ⱦ���ޣ�����Ĭ��3000ppb��
	int  voc_threashhold_ModeratePollution;	//�ж���Ⱦ���ޣ�����Ĭ��5000ppb��
	int  voc_threashhold_HeavyPollution;	//�ض���Ⱦ���ޣ�����Ĭ��10000ppb��
	
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
	int threadhold_second;		//�ڵ�ʱ����ֵ(��)�������ڵ��೤ʱ�����Ϊ���ڵ�����
	int backgroundUpdateSecond;	//����֡����ʱ�䣨�룩�����ö೤ʱ�����һ�α�������������Mֵ��MĬ��Ϊ120��֡��Ϊ5ʱbackgroundUpdateTime=24
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
	unsigned int type;//32bits,�μ�AT_TYPE_BIT_NONMOTO_VEHICLE���塣���˼��:���������ǻ�����������
	int x0Pos;
	int y0Pos;
	int x1Pos;
	int y1Pos;
	int direction;//0: A<->B 1: A->B 2: A<-B (SIDE A MEANS LEFT OF THE LINE)
}VideoLineStruct;

typedef struct
{
	unsigned char draw_rect_enable;	//�����������
	unsigned char draw_target_enable;	//�����Ŀ��
	unsigned char light_twinkle_enable;//�ƹ���˸
	unsigned char notify_alarmserver_enable;//�ϱ��澯����
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

//����������
typedef enum
{
	AI_RETION_STAY, //������
	AI_RETION_ENTER, //��������
	AI_RETION_LEAVE, //�뿪����
}RegionAiMode;

typedef struct
{
	int enable;
	int sensitivity;
	unsigned int type_filter;//���Ŀ�����ͣ�32bits,�μ�AT_TYPE_BIT_NONMOTO_VEHICLE���塣���˼��:���������ǻ�����������
	RegionAiMode mode;	//���Ŀ��ģʽ
	int stayseconds;//����ʱ��(��)��������������Ч
}RegionAiUnitStruct;

typedef struct
{
	unsigned char draw_rect_enable;	//�������
	unsigned char draw_target_enable;	//�����Ŀ��
	unsigned char light_twinkle_enable;//�ƹ���˸
	unsigned char notify_alarmserver_enable;//�ϱ��澯����
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
	InputAlarm			inputAlarm;				//IO����
	MotionDetectAlarm   motionDetectAlarm;		//�ƶ����
	VideoLostAlarm		videoLostAlarm;  		//��Ƶ��ʧ
	VideoCoverAlarm		videoCoverAlarm;		//��Ƶ�ڵ�
	StorageFullAlarm	storageFullAlarm;		//�洢�ռ�
	AudioAlarm 			audioAlarm;				//�쳣�������(Ӥ����ޡ��߷ֱ�)
	VideoGateAlarm		vgAlarm;				//Խ����
	VideoRegionAiAlarm	regionAiAlarm;			//������:�������֡����������뿪����
	PdAlarm				pdAlarm;				//���ܷ���:���Ρ����͡�Ħ�С��絥�������г�
	LprAlarm			lprAlarm;				//����ʶ��
	FaceDetectAlarm		fdAlarm;				//�������
	OutPutAlarm			outputAlarm;			//IO�������
	TempHumidityAlarm   temphumidityAlarm;		//�¶ȱ���
	SMSAlarm			smsAlarm;				//����Ϣ֪ͨ
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
	char	dhcpOffTime;	//DHCP��ȡIP�󣬶�ñ�ɹ̶�IP:0-48��С��0��ʾDHCPһֱ��Ч�������õ�IP���ɹ̶�IP
	short	onvifAllnetEnable;//�Ƿ�����ONVIFȫ��ͨ
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
	char		snapfile[MAX_SNAP_FILE_PATH_LEN];//ץͼ�ļ�·��
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
	int manual;	//�ֶ�ʱ����������ʱ���Զ�Уʱ��������ʱ
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
	char Manufacturer[G4_STR_LEN_32]; //4Gģ�鳧��
	char Model[G4_STR_LEN_32];		//4Gģ���ͺ�
	char ICCID[G4_STR_LEN_32];
	char IMEI[G4_STR_LEN_32];
	char IMSI[G4_STR_LEN_32];
	char MSISDN[G4_STR_LEN_32];
	char WorkMode[G4_STR_LEN_32]; //��ǰ��������ģʽ, LAN/NO_SRV/WCDMA/LTE
	char Operator[G4_STR_LEN_32]; //��Ӫ��
	G4_srv_status nSvrStatus;
	int	 nDialStatus;	//0:δ���š�1:�Ѳ���
	int	 nSimStatus;	//0--- SIM is not availabl 1--- SIM is available
	int  nSignalLevel;	//�ź�ǿ��,0-100
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


/*λ�����궨��*/
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

