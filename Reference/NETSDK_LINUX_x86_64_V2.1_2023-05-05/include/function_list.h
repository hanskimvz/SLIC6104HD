#ifndef _____FUNCTION_LIST_H____
#define _____FUNCTION_LIST_H____

//for system control config
#define MAX_SYSTEM_CONTROL_STRING_LEN	2048

#define FUNCTION_SUPPORT_STORAGE  		 "storage_support"

#define FUNCTION_WIRELESS_STATION			"wireless_station"
#define FUNCTION_WIFI_AP 					"wifi_ap"
#define FUNCTION_WIFI_AP_STATION_SAMETIME		"ap_station"
#define FUNCTION_MOBILE_NET		        "mobile_net"//�ƶ����磬�Ƿ�֧��4Gģ��
#define FUNCTION_SMS  "mobile_sms"    //֧�ֶ���Ϣ
#define FUNCTION_CHECK_INTERNET  "domains_check"    //֧�����������Ϣ
#define FUNCTION_DHCPIP_FIX		"dhcp_fixtime"	

#define FUNCTION_NETWORK_STORAGE		"network_storage"
#define FUNCTION_FTPEMAIL_STORAGE			"ftpemail_aj"
#define FUNCTION_EMAIL_SSL			"ssl_email"
#define FUNCTION_SCHEDULE_RECORD		"schedule_record"
#define FUNCTION_PICTURE_CAPTURE		"picture_capture"
#define FUNCTION_PTZ_CONTROL			"ptz_control"
#define FUNCTION_GPIO_INPUT				"gpio_input"
#define FUNCTION_GPIO_OUTPUT			"gpio_output"
#define FUNCTION_PTZ_ACTION			"ptz_action"
#define FUNCTION_AUDIOPLAY_ACTION	"audio_action"
#define FUNCTION_AUDIOPLAY_ACTION_DAYNIGHT	"audio_action_daynight" //��Ƶ����������ҹ�ֿ�����
#define FUNCTION_LIGHT_ACTION	"light_action"	//��������ƹ���˸
#define FUNCTION_ALARM_SERVER	"alarm_server"	//�ϱ�����������
#define FUNCTION_ALARM_LED	"alarm_led"	//��������
#define FUNCTION_LEDPANEL_IR	"ir_led_panel"//������ư�
#define FUNCTION_LEDPANEL_WHITE	"white_led_panel"//���׹�ư�
#define FUNCTION_LEDPANEL_DOUBLE "double_led_panel"//����˫��ư�
#define FUNCTION_MANUAL_PTZ_SPEED "manual_set_ptz_speed"//PTZ�ٶȿɿ�
#define FUNCTION_CAT_MANUAL_PTZ_SPEED "cat_manual_set_ptz_speed"//ȥ��PTZ�ٶȿɿ�

#define FUNCTION_PILOT_POWER_LIGHT "pilot_power_light" //Y10ָʾ��_��Դ�ƵĿ��ƿ���

#define FUNCTION_CLOUD_AUTHCODE	"cloud_authcode"	//��ID��Ȩ��
#define FUNCTION_PT_3D	"positioning_3d"	//3d��λ����


#define FUNCTION_RA_ANSWER	"ra_answer"
#define FUNCTION_AEC	"aec_enable"
#define FUNCTION_MUTE_PTZ_TURN	"mute_ptz_turn"
#define FUNCTION_AUDIOCAP_SAMPRATE	"audiocap_samplerate"
#define FUNCTION_RA_PCM	"ra_pcm"	
#define FUNCTION_RA_MP3STREAM	"ra_mp3"	
#define FUNCTION_UPNP	"enable_upnp"	


#define FUNCTION_THREE_VIDEO			"three_video"	//�Ƿ�֧��VIDEO��������
#define FUNCTION_YUV_VIDEO				"yuv_video"		//�Ƿ�֧��YUV VIDEO ����̶�ȡ
#define FUNCTION_YUV_CFG				"yuv_sizecfg"		//�Ƿ�֧��YUV �ߴ�����
#define FUNCTION_ONLY_AUDIO				"only_audio"	//�Ƿ��������Ƶ����
#define FUNCTION_VIDEO_FORBIT			"forbid_video"	//�Ƿ�ɽ�����Ƶ��
#define FUNCTION_VIDEO_ROI				"video_roi"		//�Ƿ��������Ƶ��Ȥ����
#define FUNCTION_LED_TYPE				"ledtype_set" 	//�Ƿ�����ð׹�/�����
#define FUNCTION_VIDEO_ENCODE_MODE		"vencodemode_set" //�Ƿ��������Ƶ����ģʽ(ͼ��ģʽ)
#define FUNCTION_USEROSD		"userosd_set" //�Ƿ�������Զ���OSD
#define FUNCTION_TITLE_BMP		"bmplogo_set" //�Ƿ������BMP LOGOͼƬ
#define FUNCTION_TITLE_COLOR	"titlecolor_set" //�Ƿ������title��ɫͼƬ
#define FUNCTION_TITLE_TRANSPARENT	"alpha_set" //�Ƿ������͸����

#define FUNCTION_FRONT_REPLAY			"front_replay"
#define FUNCTION_REPLAY_BYTIME		"replay_bytime"
#define FUNCTION_MEDIA_CAPABILITY		"media_capabiltiy"
#define FUNCTION_IRCUT_SETTING			"ircut_setting"   //IRCUT ����ģʽ(�Զ��� ��ʱ�� �ⲿ���ƣ� �ֶ�)
#define FUNCTION_IRCUT_BY_ADC_HARDWARE		"ircut_by_adc" //����Ӳ����������adcֵ������IRCUT
#define FUNCTION_HTTPS		"with_https" //�Ƿ�֧��https
#define FUNCTION_H5		"with_h5" //�Ƿ�֧��h5
#define FUNCTION_QP		"with_qpsetting" //�Ƿ�֧��VBR QP�Զ�������

#define FUNCTION_IRCUT_LED_DELAY		"ircut_leddelay" // ������ʱ���ã������������ʽ�� ���Կ�����Ƶ�������
#define FUNCTION_IRCUT_LED_MANUAL_SWITCH	"ircut_ledmanualswitch" //֧���ֶ��ƹⳣ��/����
#define FUNCTION_PROFLE_SETTING		"profile_setting"
#define FUNCTION_WDR_SETTING			"wdr_setting"  //DSP ���ֿ�̬ ����
#define FUNCTION_HDR_SETTING			"hdr_setting"  //SENSOR ��̬����
#define FUNCTION_VIDEO_MASK			"video_mask"    //��Ƶ�ڵ�����
#define FUNCTION_SYSTEM_MAINTAIN		"system_maitain"
#define FUNCTION_LINKDOWN_RECORD		"linkdown_record"
#define FUNCTION_PPTP					"pptp_support"

#define FUNCTION_AUDIO					"audio_support"

#define FUCNTION_3G_EVDO				"evdo_support"
#define FUCNTION_3G_WCDMA				"wcdma_support"
#define FUCNTION_3G_TDSCDMA			"tdscdma_support"


#define FUNCTION_LANGUAGE_ZH_CN		"zh_cn"
#define FUNCTION_LANGUAGE_ZH_TW		"zh_tw"
#define FUNCTION_LANGUAGE_ZH_HK		"zh_hk"
#define FUNCTION_LANGUAGE_EN_US		"en_us"
#define FUNCTION_LANGUAGE_RU_PY		"rs_py"
#define FUNCTION_LANGUAGE_TR_TR		"tr-tr"
#define FUNCTION_LANGUAGE_KO_KO		"ko-ko"
#define FUNCTION_LANGUAGE_CZ_CZEKH	"cz-czekh"


#define FUNCTION_SEARCH_WIFIAP		 	"SEARCH_WIFIAP"
#define FUNCTION_LONG_TITLE		 	"LONG_TITLE"
#define FUNCTION_TIMEZONE_HALFHOUR	"timezone_halfhour"
#define FUNCTION_P2P_CFG				"p2p_cfg_support"

#define FUNCTION_SUPPORT_RECORD_AJV  "ajv_support"
#define FUNCTION_MD_18X22				"md_18x22"
#define FUNCTION_ONLY_18X22			"only_18x22"
#define FUNCTION_AMBAR_ENCMODE		"encmode_setting"
#define FUNCTION_SUPPORT_LBR			"lbr_support"
#define FUNCTION_SUPPORT_28181			"gb28181"
#define FUNCTION_SUPPORT_IPVS			"ipvs"
#define FUNCTION_SUPPORT_RTMP	"rtmp"
#define FUNCTION_SUPPORT_RTMP_TIMESPAN	"rtmp_timespan"
#define FUNCTION_HIK_CONFIG		"hikconfig"	
#define FUNCTION_COMM_ONVIF_ENABLE		"commenable"	
#define FUNCTION_DH_CONFIG		"dhconfig"	


#define FUCNTION_VOIP			"voip"
#define FUNCTION_ROTATE		"rotate_enable"   //��Ƶ��ת
#define FUNCTION_AUDIO_CAPTURE_PARAMETER		"audio_aisetting" //��Ƶ�ɼ�ͨ����������������
#define FUNCTION_AUDIO_AMPLIFY		"audio_amplify"
#define FUNCTION_ALOWIP_SETTING		"ipaddrlimit"
#define FUNCTION_OVERLAYFPS_SETTING		"overlayfps"//����֡��
#define FUNCTION_GAIN_SETTING		"gainsetting"//�ֶ�����/�Զ�����
#define FUNCTION_ALARMCLOCK_SETTING		"alarmclock"
#define FUNCTION_ALARM_VIDEOGATE		"AlarmVG"	//���߼��
#define FUNCTION_ALARM_VIDEOGATE_BY_PD		"AlarmPdVG"	//���μ��ʵ�ְ��߼��
#define FUNCTION_ALARM_REGION_AI		"AlarmRegionAI"	//�������
#define FUNCTION_ISP_MODE		"ispmode"
#define FUNCTION_ALARM_PD		"VideoPD"	//���μ��
#define FUNCTION_ALARM_COVER	"alarm_cover"	//��Ƶ�ڵ�����
#define FUNCTION_FACE_FD		"face_detect"	//�������
#define FUNCTION_FACE_FR		"face_recognize"//����ƥ��
#define FUNCTION_PD_RECT_2		"pd2rectconf"//���ο������ֿ�����
#define FUNCTION_PD_TRACK_HUMAN		"humantrack"//����ƥ��
#define FUNCTION_ALARM_VEHICLE_CAR	"VehicleCar"	//���μ��-����
#define FUNCTION_ALARM_VEHICLE_MOTO	"VehicleMoto"	//���μ��-Ħ��
#define FUNCTION_ALARM_VEHICLE_ELECTRICBICYCLE	"VehicleElectricbicycle"	//���ͼ��-�絥��
#define FUNCTION_ALARM_VEHICLE_BICYCLE	"VehicleBicycle"	//���ͼ��-���г�
#define FUNCTION_ALARM_LPR		"LPRecognition"	//����ʶ��
#define FUNCTION_TIMESPAN_NEW 	"TimeSpanNew"	//�µ�7X24�ֽڱ�ʾ��ʱ��Σ���ȷ��Сʱ
#define FUNCTION_ALARM_FIRE		"Fire"	//������



#define FUCTION_PD_POLYGON     "pd_polygon_area"  //����֧�ֶ���μ������
#define FUCTION_PD_MADP        "pd_madp"  // mstar �������㷨
#define FUNCTION_OSD_ANYPOSITION		"OSD_ANYPOS"	//OSD����λ��
#define FUNCTION_VIDEO_CROP		"video_crop"	//��Ƶ�ü�
#define FUNCTION_VIDEO_FORCT_ANTIFLICKER		"antiflicker"	//ǿ�ƿ���
#define FUCTION_ADVANCE_LIGHT_CONTROL         "advance_light_ctrl"     //Զհ����ĵƹ���ƹ��ܣ� �����澯�������ȣ�ֵ������
#define FUCTION_IO_OUTPUT_SET              "io_output_set"   //IO �������
#define FUNCTION_ALARM_TEMP_HUMIDITY	"temp_humidity"	//��ʪ�ȼ��  temperature  humidity
//#define FUNCTION_ALARM_TEMPERATURE	"temperature_set"
//#define FUNCTION_ALARM_HUMIDITY		"humidity_set"

#define FUNCTION_ALARM_TOXIC_GAS		"toxic_gas"		//�ж�����

#define FUCTION_ONE_OUTPUT                 "one_output"
#define FUCTION_TWO_OUTPUT                 "two_output"
#define FUCTION_THREE_OUTPUT                 "three_output"
#define FUCTION_FOUR_OUTPUT                 "four_output"

#define FUCTION_ONE_INPUT                 "one_input"
#define FUCTION_TWO_INPUT                 "two_input"
#define FUCTION_THREE_INPUT                 "three_input"
#define FUCTION_FOUR_INPUT                 "four_input"


#define FUNCTION_VIDEOMASK_ONESET	"ONEVIDEOMASK"		//��������ʹ��ͬһ����˽�ڵ�������Ҫ�ֿ�����
#define FUNCTION_MULTICAST	"multicast"	
#define FUNCTION_VIDEOSHUTTER	"VideoShutter"	//���ӿ�������

#define FUNCTION_MAC_MODIFY	"ModifyMac"	
#define FUNCTION_AUDIO_ALARM	"AudioAlarm"	


//��˼����֧�ֿ�̬��ȥ���ܣ�������Χ0-255
#define FUNCTION_HISCON_ENCMODE		"hisconenc"	

#define FUNCTION_P2P_CONFIG	"p2p_config"	
#define FUNCTION_P2P_DANALE	"p2p_danale"	
#define FUNCTION_P2P_ANKO		"p2p_anko"	
#define FUNCTION_P2P_GOOLINK	"p2p_goolink"	
#define FUNCTION_P2P_SKYWORTH	"p2p_skyworth"
#define FUNCTION_P2P_AC18PRO	"p2p_ac18pro"
#define FUNCTION_P2P_TENCENTIOT	"p2p_tencent"
#define FUNCTION_P2P_ISMART	"p2p_ismart"	
#define FUNCTION_P2P_QQ		"p2p_qq"
#define FUNCTION_P2P_EYEPLUS		"p2p_eyeplus"

#define FUNCTION_PRE_RECORD   "pre_record"
#define FUNCTION_UPLOAD_SOFTCRYPT   "crypt_upload"
#define FUNCTION_OSD_GB28181  "osd_gb"  //���������С
#define FUNCTION_AF_VERSION		"af_setting"//AF����
#define FUNCTION_AUDIO_8M_Repartition		"audio_Repartition"//AF����

#define FUNCTION_OTA_SUPPORT		"ota_enable"


#define FUNCTION_PTZ_ALL_CTRL   "ptz_all_ctrl"
#define FUNCTION_PTZ_ZOOM   "ptz_zoom"
#define FUNCTION_PTZ_FOCUS   "ptz_focus"
#define FUNCTION_PTZ_IRIS   "ptz_iris"
#define FUNCTION_PTZ_2_DIRECTION   "ptz_2_direction"
#define FUNCTION_PTZ_4_DIRECTION   "ptz_4_direction"
#define FUNCTION_PTZ_8_DIRECTION   "ptz_8_direction"
#define FUNCTION_HIGHCTRL_PTZ      "high_ctrl_ptz"
#define FUNCTION_SMART_265 "smart265"

#define FUNCTION_SCARE_OFF  "scare_off"
#define FUNCTION_BE_SET_MTU	"be_set_mtu" //֧������mtu
#define FUNCTION_ELE_ZOOM  "ele_zoom" //֧�ֵ��ӷŴ����ڶ�Ŀ����ͷ
#define FUNCTION_ZOOM_TRACK "zoom_track"  //�䱶����

#define FUNCTION_POWER_DISPLAY "device_power_display" //������ʾ
#define FUNCTION_LOW_POWER "low_power_support"  //ʡ��ģʽ
#define FUNCTION_PRIVACY_PROTECTION "privacy_protection" //һ���ڵ�
#define FUNCTION_BRIGHTNESS_MODE1     "brightness_mode1" //����ģʽ1�� ���������ӳ��б���ʾ�᲻һ���� ĿǰֻK45֧��

#define FUNCTION_AF_PROTOCOL_4   "af_protocol_4" //֧�ֻ�о��֧�ָ߼���̨����
#define FUNCTION_ACTIVE_CALL  "active_call"    //�������й���
#define FUNCTION_TWOLENS_STICH  "twolens_stitch"    //˫Ŀƴ��
#define FUNCTION_ARMING_DAYNIGHT "arming_daynight" //��������Ϊ��ֹ/ȫ��/����/ҹ���߱���������ʱ�ƶ����/����/Խ��/����֧�ֺ�������/��������������ҹ����

#endif       

