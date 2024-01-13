#ifndef _IPSDK_DEF_TYPE_H_
#define _IPSDK_DEF_TYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef		char				IPSDK_Int8;
typedef		unsigned char		IPSDK_UInt8;
typedef		short				IPSDK_Int16;
typedef		unsigned short		IPSDK_UInt16;
typedef		int					IPSDK_Int32;
typedef		unsigned int		IPSDK_UInt32;
typedef		unsigned long long	IPSDK_UInt64;
typedef		unsigned long		IPSDK_ULong;
typedef		long				IPSDK_Long;

typedef		char				IPSDK_Char;
typedef		char*				IPSDK_PChar;
typedef		const char*			IPSDK_CPChar;

typedef		unsigned char		IPSDK_Byte;
typedef		unsigned char*		IPSDK_PByte;
typedef		int					IPSDK_Int;
typedef		void				IPSDK_Void;
typedef		void*				IPSDK_PVoid;
typedef		void*				IPSDK_HANDLE;
typedef		int 				IPSDK_Boolean;
typedef		float				IPSDK_Float;

typedef		int					IPSDK_ERR;

typedef		IPSDK_Int32			IPSDK_Size;


#ifndef NULL
#define NULL					0L
#endif

#define IPSDK_NULL				0L
#define IPSDK_SUCCESS			0
#define IPSDK_FAILURE			(-1)

#ifndef IPSDK_TRUE
#define IPSDK_TRUE				1
#endif
#ifndef IPSDK_FALSE
#define IPSDK_FALSE				0
#endif

#define IPSDK_ARRAY_SIZE(ARRAY) (sizeof (ARRAY) / sizeof (ARRAY[0]))

/**
 * 数据小端对齐修正。
 */
#define IPSDK_ALIGN_LITTLE_END(__v, __av) \
	((__av) <= 0 ? 0 : ( \
			((__v > 0) ? \
					((__v) - ((__v) % (__av))) \
					: \
					 ((__v) - ((__v) % (__av)) - ((0 != ((__v) % (__av))) ? (__av) : 0)) \
					)))

/**
 * 数据大端对齐修正。
 */
#define IPSDK_ALIGN_BIG_END(__v, __av) \
	((__av) <= 0 ? 0 : ( \
		((__v > 0) ? \
				((__v) - ((__v) % (__av)) + ((0 != ((__v) % (__av))) ? (__av) : 0)) \
				: \
				 ((__v) - ((__v) % (__av))) \
				)))

/**
 * 16 位大小端转换。
 */
#define IPSDK_SWAP16(__v)  ((((IPSDK_UInt16)(__v) & 0xff00) >> 8) | (((IPSDK_UInt16)(__v) & 0x00ff) << 8))

/**
 * 32 位大小端转换。
 */
#define IPSDK_SWAP32(__v)  ((((IPSDK_UInt32)(__v) & 0xff000000) >> 24) | \
							(((IPSDK_UInt32)(__v) & 0x00ff0000) >> 8) | \
							(((IPSDK_UInt32)(__v) & 0x0000ff00) << 8) | \
							(((IPSDK_UInt32)(__v) & 0x000000ff) << 24))

/**
 * 64 位大小端转换。
 */
#define IPSDK_SWAP64(__v)  ((((IPSDK_UInt64)(__v) & 0xff00000000000000) >> 56) | \
							(((IPSDK_UInt64)(__v) & 0x00ff000000000000) >> 40) | \
							(((IPSDK_UInt64)(__v) & 0x0000ff0000000000) >> 24) | \
							(((IPSDK_UInt64)(__v) & 0x000000ff00000000) >> 8) | \
							(((IPSDK_UInt64)(__v) & 0x00000000ff000000) << 8) | \
							(((IPSDK_UInt64)(__v) & 0x0000000000ff0000) << 24) | \
							(((IPSDK_UInt64)(__v) & 0x000000000000ff00) << 40) | \
							(((IPSDK_UInt64)(__v) & 0x00000000000000ff) << 56))

/**
 * 检测系统是否为小端模式。
 * 小端模式返回 True，大端模式返回 False。
 */
static inline IPSDK_Boolean IPSDK_IS_LITTLE_END()
{
	union
	{
		IPSDK_UInt32 dword;
		IPSDK_UInt8 bytes[4];
	} un;

	un.dword = 0x12345678;
	return (0x78 == un.bytes[0]);
}

/**
 * 8 字节数据实现本地序到网络序的转换。
 */
static inline IPSDK_UInt64 IPSDK_HTON64(IPSDK_UInt64 h)
{
	/// 若本机为大端，与网络字节序同，直接返回
	/// 若本机为小端，转换成大端再返回
	return IPSDK_IS_LITTLE_END() ? IPSDK_SWAP64(h) : h;
}

/**
 * 4 字节数据实现本地序到网络序的转换。
 */
static inline IPSDK_UInt32 IPSDK_HTON32(IPSDK_UInt32 h)
{
	/// 若本机为大端，与网络字节序同，直接返回
	/// 若本机为小端，转换成大端再返回
	return IPSDK_IS_LITTLE_END() ? IPSDK_SWAP32(h) : h;
}

#define IPSDK_SELF_HTON32(__h) do { (__h) = IPSDK_HTON32(__h); } while(0)

/**
 * 3 字节数据实现本地序到网络序的转换。
 */
#define IPSDK_HTON24(__h) (IPSDK_HTON32(__h) >> 8)

/**
 * 2 字节数据实现本地序到网络序的转换。
 */
static inline IPSDK_UInt16 IPSDK_HTON16(IPSDK_UInt16 h)
{
	/// 若本机为大端，与网络字节序同，直接返回
	/// 若本机为小端，转换成大端再返回
	return IPSDK_IS_LITTLE_END() ? IPSDK_SWAP16(h) : h;
}

#define IPSDK_SELF_HTON16(__h) do { (__h) = IPSDK_HTON16(__h); } while(0)

/**
 * 4 字节数据实现网络序到本地序的转换。
 */
#define IPSDK_NTOH32(__n) IPSDK_HTON32(__n)
#define IPSDK_SELF_NTOH32(__n) do { (__n) = IPSDK_NTOH32(__n); } while(0)

/**
 * 3 字节数据实现网络序本地序转换。
 */
#define IPSDK_NTOH24(__n) (IPSDK_NTOH32(__n) >> 8)

/**
 * 2 字节数据实现网络序到本地序的转换。
 */
#define IPSDK_NTOH16(__n) IPSDK_HTON16(__n)
#define IPSDK_SELF_NTOH16(__n) do { (__n) = IPSDK_NTOH16(__n); } while(0)


/**
 * @brief
 *  Timezone GMT Seconds Differance.\n
 */
#define IPSDK_TZ_GMT_OFF(__hour, __min) ((__hour) * 3600 + (__min) * 60)

/**
 * Time Zone Defination.\n
 * The Value is the Seconds Difference to GMT Timezone.\n
 * Such as Eastern GMT+01:00, Value is +3600.\n
 * This Value Add What is UTC1970 is the Seconds of Local Timestamp to 1970/01/01 00:00:00.\n
 */
typedef enum tag_IPSDK_TimeZone_
{
	IPSDK_TZ_GMT_W1200 = -IPSDK_TZ_GMT_OFF(12, 0),//!< IPSDK_TZ_GMT_W1200
	IPSDK_TZ_GMT_W1100 = -IPSDK_TZ_GMT_OFF(11, 0),//!< IPSDK_TZ_GMT_W1100
	IPSDK_TZ_GMT_W1000 = -IPSDK_TZ_GMT_OFF(10, 0),//!< IPSDK_TZ_GMT_W1000
	IPSDK_TZ_GMT_W0900 = -IPSDK_TZ_GMT_OFF(9, 0), //!< IPSDK_TZ_GMT_W0900
	IPSDK_TZ_GMT_W0800 = -IPSDK_TZ_GMT_OFF(8, 0), //!< IPSDK_TZ_GMT_W0800
	IPSDK_TZ_GMT_W0700 = -IPSDK_TZ_GMT_OFF(7, 0), //!< IPSDK_TZ_GMT_W0700
	IPSDK_TZ_GMT_W0600 = -IPSDK_TZ_GMT_OFF(6, 0), //!< IPSDK_TZ_GMT_W0600
	IPSDK_TZ_GMT_W0500 = -IPSDK_TZ_GMT_OFF(5, 0), //!< IPSDK_TZ_GMT_W0500
	IPSDK_TZ_GMT_W0430 = -IPSDK_TZ_GMT_OFF(4, 30),//!< IPSDK_TZ_GMT_W0430
	IPSDK_TZ_GMT_W0400 = -IPSDK_TZ_GMT_OFF(4, 0), //!< IPSDK_TZ_GMT_W0400
	IPSDK_TZ_GMT_W0330 = -IPSDK_TZ_GMT_OFF(3, 30),//!< IPSDK_TZ_GMT_W0330
	IPSDK_TZ_GMT_W0300 = -IPSDK_TZ_GMT_OFF(3, 0), //!< IPSDK_TZ_GMT_W0300
	IPSDK_TZ_GMT_W0200 = -IPSDK_TZ_GMT_OFF(2, 0), //!< IPSDK_TZ_GMT_W0200
	IPSDK_TZ_GMT_W0100 = -IPSDK_TZ_GMT_OFF(1, 0), //!< IPSDK_TZ_GMT_W0100
	IPSDK_TZ_GMT	   = IPSDK_TZ_GMT_OFF(0, 0),  //!< IPSDK_TZ_GMT
	IPSDK_TZ_GMT_E0100 = IPSDK_TZ_GMT_OFF(1, 0),  //!< IPSDK_TZ_GMT_E0100
	IPSDK_TZ_GMT_E0200 = IPSDK_TZ_GMT_OFF(2, 0),  //!< IPSDK_TZ_GMT_E0200
	IPSDK_TZ_GMT_E0300 = IPSDK_TZ_GMT_OFF(3, 0),  //!< IPSDK_TZ_GMT_E0300
	IPSDK_TZ_GMT_E0330 = IPSDK_TZ_GMT_OFF(3, 30), //!< IPSDK_TZ_GMT_E0330
	IPSDK_TZ_GMT_E0400 = IPSDK_TZ_GMT_OFF(4, 0),  //!< IPSDK_TZ_GMT_E0400
	IPSDK_TZ_GMT_E0430 = IPSDK_TZ_GMT_OFF(4, 30), //!< IPSDK_TZ_GMT_E0430
	IPSDK_TZ_GMT_E0500 = IPSDK_TZ_GMT_OFF(5, 0),  //!< IPSDK_TZ_GMT_E0500
	IPSDK_TZ_GMT_E0530 = IPSDK_TZ_GMT_OFF(5, 30), //!< IPSDK_TZ_GMT_E0530
	IPSDK_TZ_GMT_E0545 = IPSDK_TZ_GMT_OFF(5, 45), //!< IPSDK_TZ_GMT_E0545
	IPSDK_TZ_GMT_E0600 = IPSDK_TZ_GMT_OFF(6, 0),  //!< IPSDK_TZ_GMT_E0600
	IPSDK_TZ_GMT_E0630 = IPSDK_TZ_GMT_OFF(6, 30), //!< IPSDK_TZ_GMT_E0630
	IPSDK_TZ_GMT_E0700 = IPSDK_TZ_GMT_OFF(7, 0),  //!< IPSDK_TZ_GMT_E0700
	IPSDK_TZ_GMT_E0800 = IPSDK_TZ_GMT_OFF(8, 0),  //!< IPSDK_TZ_GMT_E0800
	IPSDK_TZ_GMT_E0900 = IPSDK_TZ_GMT_OFF(9, 0),  //!< IPSDK_TZ_GMT_E0900
	IPSDK_TZ_GMT_E0930 = IPSDK_TZ_GMT_OFF(9, 30), //!< IPSDK_TZ_GMT_E0930
	IPSDK_TZ_GMT_E1000 = IPSDK_TZ_GMT_OFF(10, 0), //!< IPSDK_TZ_GMT_E1000
	IPSDK_TZ_GMT_E1100 = IPSDK_TZ_GMT_OFF(11, 0), //!< IPSDK_TZ_GMT_E1100
	IPSDK_TZ_GMT_E1200 = IPSDK_TZ_GMT_OFF(12, 0), //!< IPSDK_TZ_GMT_E1200
	IPSDK_TZ_GMT_E1300 = IPSDK_TZ_GMT_OFF(13, 0), //!< IPSDK_TZ_GMT_E1300

} IPSDK_TimeZone;

/**
 * 图像尺寸。
 */
#define IPSDK_IMG_SZ(__width, __height) ((IPSDK_ALIGN_BIG_END(__width, 2) * 10000) + IPSDK_ALIGN_BIG_END(__height, 2))
#define IPSDK_IMG_SZ_UNDEF      IPSDK_IMG_SZ(0, 0)
#define IPSDK_IMG_SZ_160X90     IPSDK_IMG_SZ(160, 90)
#define IPSDK_IMG_SZ_160X120    IPSDK_IMG_SZ(160, 120)
#define IPSDK_IMG_SZ_172X144    IPSDK_IMG_SZ(172, 144)
#define IPSDK_IMG_SZ_320X180    IPSDK_IMG_SZ(320, 180)
#define IPSDK_IMG_SZ_320X240    IPSDK_IMG_SZ(320, 240)
#define IPSDK_IMG_SZ_352X240    IPSDK_IMG_SZ(352, 240)
#define IPSDK_IMG_SZ_352X288    IPSDK_IMG_SZ(352, 288)
#define IPSDK_IMG_SZ_360X240    IPSDK_IMG_SZ(360, 240)
#define IPSDK_IMG_SZ_360X288    IPSDK_IMG_SZ(360, 288)
#define IPSDK_IMG_SZ_480X270    IPSDK_IMG_SZ(480, 270)
#define IPSDK_IMG_SZ_480X360    IPSDK_IMG_SZ(480, 360)
#define IPSDK_IMG_SZ_480X480    IPSDK_IMG_SZ(480, 480)
#define IPSDK_IMG_SZ_528X384    IPSDK_IMG_SZ(528, 384)
#define IPSDK_IMG_SZ_640X360    IPSDK_IMG_SZ(640, 360)
#define IPSDK_IMG_SZ_640X480    IPSDK_IMG_SZ(640, 480)
#define IPSDK_IMG_SZ_704X240    IPSDK_IMG_SZ(704, 240)
#define IPSDK_IMG_SZ_704X288    IPSDK_IMG_SZ(704, 288)
#define IPSDK_IMG_SZ_704X480    IPSDK_IMG_SZ(704, 480)
#define IPSDK_IMG_SZ_704X576    IPSDK_IMG_SZ(704, 576)
#define IPSDK_IMG_SZ_720X240    IPSDK_IMG_SZ(720, 240)
#define IPSDK_IMG_SZ_720X288    IPSDK_IMG_SZ(720, 288)
#define IPSDK_IMG_SZ_720X480    IPSDK_IMG_SZ(720, 480)
#define IPSDK_IMG_SZ_720X576    IPSDK_IMG_SZ(720, 576)
#define IPSDK_IMG_SZ_720X720    IPSDK_IMG_SZ(720, 720)
#define IPSDK_IMG_SZ_800X600    IPSDK_IMG_SZ(800, 600)
#define IPSDK_IMG_SZ_800X800    IPSDK_IMG_SZ(800, 800)
#define IPSDK_IMG_SZ_960X480    IPSDK_IMG_SZ(960, 480)
#define IPSDK_IMG_SZ_960X576    IPSDK_IMG_SZ(960, 576)
#define IPSDK_IMG_SZ_960X960    IPSDK_IMG_SZ(960, 960)
#define IPSDK_IMG_SZ_1280X720   IPSDK_IMG_SZ(1280, 720)
#define IPSDK_IMG_SZ_1280X960   IPSDK_IMG_SZ(1280, 960)
#define IPSDK_IMG_SZ_1280X1024  IPSDK_IMG_SZ(1280, 1024)
#define IPSDK_IMG_SZ_1056X1056  IPSDK_IMG_SZ(1280, 1024)
#define IPSDK_IMG_SZ_1600X900   IPSDK_IMG_SZ(1600, 900)
#define IPSDK_IMG_SZ_1600X1200  IPSDK_IMG_SZ(1600, 1200)
#define IPSDK_IMG_SZ_1920X1080  IPSDK_IMG_SZ(1920, 1080)
#define IPSDK_IMG_SZ_2048X1512  IPSDK_IMG_SZ(2048, 1512)
#define IPSDK_IMG_SZ_2048X1520  IPSDK_IMG_SZ(2048, 1520)
#define IPSDK_IMG_SZ_2048X1536  IPSDK_IMG_SZ(2048, 1536)
#define IPSDK_IMG_SZ_2304X1296  IPSDK_IMG_SZ(2304, 1296)
#define IPSDK_IMG_SZ_2304X1728  IPSDK_IMG_SZ(2304, 1728)
#define IPSDK_IMG_SZ_2560X1440  IPSDK_IMG_SZ(2560, 1440)
#define IPSDK_IMG_SZ_2592X1520  IPSDK_IMG_SZ(2592, 1520)
#define IPSDK_IMG_SZ_2592X1944  IPSDK_IMG_SZ(2592, 1944)
#define IPSDK_IMG_SZ_2688X1512  IPSDK_IMG_SZ(2688, 1512)
#define IPSDK_IMG_SZ_3072X1728  IPSDK_IMG_SZ(3072, 1728)//500万像素 16:9
#define IPSDK_IMG_SZ_2560X1920  IPSDK_IMG_SZ(2560, 1920)//500万像素 4:3
#define IPSDK_IMG_SZ_4096X2160  IPSDK_IMG_SZ(4096, 2160)//4K高清 885万像素 16:9
#define IPSDK_IMG_SZ_3840X2160  IPSDK_IMG_SZ(3840, 2160)//4K高清 829万像素 16:9


/**
 * 属性选项最大个数。
 */
#define IPSDK_PROP_OPT_MAX_ENT (32)

/**
 * 属性选项字符串最大长度。
 */
#define IPSDK_PROP_STR_MAX_LEN (128)

/**
 * @brief 属性类型定义。
 */
typedef enum tag_IPSDK_PropType_
{
	IPSDK_PROP_TYPE_UNDEF = (-1),

	/**
	 * 布尔属性。
	 */
	IPSDK_PROP_TYPE_BOOL = 0,
	/**
	 * 整型属性。
	 */
	IPSDK_PROP_TYPE_INT,
	/**
	 * 长整型属性。
	 */
	IPSDK_PROP_TYPE_INT64,
	/**
	 * 枚举行属性。
	 */
	IPSDK_PROP_TYPE_ENUM,
	/**
	 * 浮点型属性。
	 */
	IPSDK_PROP_TYPE_FLOAT,
	/**
	 * 文本型属性。
	 */
	IPSDK_PROP_TYPE_STRING,
	/**
	 * 物理地址属性。
	 */
	IPSDK_PROP_TYPE_HWADDR,
	/**
	 * IPv4 地址属性。
	 */
	IPSDK_PROP_TYPE_IPV4,

} IPSDK_PropType;

/**
 * 布尔属性数据结构。
 */
typedef struct tag_IPSDK_PropBoolean_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	IPSDK_Boolean val;
	/**
	 * 默认数值值。\n
	 * 某些场合下，当属性数值发生错误时，默认可能作为调整参考依据。
	 */
	IPSDK_Boolean def;

} IPSDK_PropBoolean;

/**
 * @brief 整型属性数据结构。
 */
typedef struct tag_IPSDK_PropInteger_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	/**
	 * 属性数值。
	 */
	IPSDK_Int32 val;

	/**
	 * 默认数值值。\n
	 * 某些场合下，当属性数值发生错误时，默认可能作为调整参考依据。
	 */
	IPSDK_Int32 def;

	/**
	 * 属性的最大值最小值。\n
	 * 当最大值和最小值均为 0 的时候表示属性数值不受最大最小值约束。\n
	 * 否则数值和默认数值必须处于最大最小值中间，属性才合法。
	 */
	IPSDK_Int min, max;

	/**
	 * 属性选项数据结构。\n
	 * 当 Option 不为 Nil 时，@ref min 和 @ref max 数值无效。\n
	 * 数值的取值范围以选项为参考。
	 */
	struct
	{
		IPSDK_Size entries;
		IPSDK_Int32 opt[IPSDK_PROP_OPT_MAX_ENT];
	} _Option, *Option;

} IPSDK_PropInteger;

/**
 * @brief 浮点型属性数据结构。
 *
 * @author Chec
 * @date 2019/12/13
 */
typedef struct tag_IPSDK_PropFloat_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	/**
	 * 属性数值。
	 */
	IPSDK_Float val;

	/**
	 * 默认数值值。\n
	 * 某些场合下，当属性数值发生错误时，默认可能作为调整参考依据。
	 */
	IPSDK_Float def;

	/**
	 * 属性的最大值最小值。\n
	 * 当最大值和最小值均为 0 的时候表示属性数值不受最大最小值约束。\n
	 * 否则数值和默认数值必须处于最大最小值中间，属性才合法。
	 */
	IPSDK_Float min, max;

	/**
	 * 属性选项数据结构。\n
	 * 当 Option 不为 Nil 时，@ref min 和 @ref max 数值无效。\n
	 * 数值的取值范围以选项为参考。
	 */
	struct
	{
		IPSDK_Size entries;
		IPSDK_Float opt[IPSDK_PROP_OPT_MAX_ENT];
	} _Option, *Option;

} IPSDK_PropFloat;

/**
 * @brief 枚举属性数据结构。
 *
 * 枚举属性类似与整型属性。\n
 * 区别于整型属性，枚举属性没有最大最小的限制，但必须具备选项。\n
 * 每个枚举选项数值后必须有一个文本与之对应。
 */
typedef struct tag_IPSDK_PropEnum_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	/**
	 * 属性数值和默认数值。
	 */
	IPSDK_UInt32 val, def;

	struct
	{
		/**
		 * 有效选项的个数。
		 */
		IPSDK_Size entries;
		/**
		 * 选项数值。
		 */
		IPSDK_UInt32 opt[IPSDK_PROP_OPT_MAX_ENT];
		/**
		 * 选项数值对应的文本。
		 */
		IPSDK_PChar str[IPSDK_PROP_OPT_MAX_ENT];

	} _Option, *Option;

} IPSDK_PropEnum;

/**
 * 文本属性数据结构。
 */
typedef struct tag_IPSDK_PropString_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	IPSDK_Char val[IPSDK_PROP_STR_MAX_LEN + 1], def[IPSDK_PROP_STR_MAX_LEN + 1];

	/**
	 * 文本的最大长度，区别于 @ref IPSDK_PROP_STR_MAX_LEN。
	 * 若文本长度在此长度以内才合法。
	 */
	IPSDK_Size max_len;

	/**
	 * 参考 IPSDK_PropInteger::Option。
	 */
	struct
	{
		IPSDK_Size entries;
		IPSDK_PChar opt[IPSDK_PROP_OPT_MAX_ENT];
	} _Option, *Option;

} IPSDK_PropString;

/**
 * @brief 设备物理地址属性数据结构。
 */
typedef struct tag_IPSDK_PropHwAddr_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	IPSDK_UInt8 val[6];

} IPSDK_PropHwAddr;

/**
 * @brief IPv4 地址属性数据结构。
 */
typedef struct tag_IPSDK_PropIPv4_
{
	/**
	 * 属性只读标识。
	 */
	IPSDK_Boolean read_only;

	/**
	 * 属性类型。
	 */
	IPSDK_PropType type;

	IPSDK_UInt8 val[4];

} IPSDK_PropIPv4;

/**
* 未定义枚举变量。
*/
#define IPSDK_ENUM_UNDEFINED ""

/**
* 定义枚举值映射文本集的接口模板。
* 通过此接口定义函数有效解决重复命名定义问题。
* 宏定义在编译的时候会展开成相关的类型接口。
*/
#define DECLARE_IPSDK_ENUM_MAP(__type)  IPSDK_PChar IPSDK_Enum_Map##__type(IPSDK_##__type enm)

/**
* 定义文本集的接口映射枚举值模板。
*/
#define DECLARE_IPSDK_ENUM_UNMAP(__type)  IPSDK_##__type IPSDK_Enum_Unmap##__type(IPSDK_PChar text)


/**
* 调用对应类型的枚举接口。
*/
#define IPSDK_ENUM_MAP(__type, __enm) IPSDK_Enum_Map##__type(__enm)

/**
* 调用对应类型的枚举接口。
*/
#define IPSDK_ENUM_UNMAP(__type, __text) IPSDK_Enum_Unmap##__type(__text)

/**
 * 属性追加一个选项。
 */
#define IPSDK_PROP_ADD_OPT(__Prop, __val) \
	do{\
		if (!(__Prop)->Option){\
			(__Prop)->Option = &((__Prop)->_Option);\
			(__Prop)->Option->entries = 0;\
			(__Prop)->Option->opt[(__Prop)->Option->entries++] = (__val);\
		}\
		if ((__Prop)->Option->entries >= IPSDK_PROP_OPT_MAX_ENT){\
		/* 选项配额已满。 */\
			break;\
		}\
		IPSDK_Size n;\
		for(n = 0; n < (__Prop)->Option->entries; n++)\
		{\
			/* 选项不存在才添加 */\
			if(__val == (__Prop)->Option->opt[n])\
			{\
				break;\
			}else{\
				if(n == (__Prop)->Option->entries - 1)\
				{\
					(__Prop)->Option->opt[(__Prop)->Option->entries++] = (__val);\
				}\
			}\
		}\
	} while (0)

/**
 * 属性追加一个枚举选项。
 */
#define IPSDK_PROP_ADD_ENUM(__Prop, __type, __opt) \
	do{\
		IPSDK_Size opt_entries = IPSDK_NULL != (__Prop)->Option ? (__Prop)->Option->entries : 0;\
		IPSDK_PROP_ADD_OPT(__Prop, __opt);\
		if (opt_entries + 1 == (__Prop)->Option->entries)\
			(__Prop)->Option->str[(__Prop)->Option->entries - 1] = IPSDK_ENUM_MAP(__type, __opt);\
	} while(0)

/**
 * 源属性复制到目标源属性
 */
#define IPSDK_PROP_COPY_ENUM(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val = (__strProp)->val; \
			(__desProp)->def = (__strProp)->def; \
		IPSDK_Size size;\
		for(size = 0; size < (__strProp)->_Option.entries; size++)\
		{\
			IPSDK_PROP_ADD_OPT(__desProp, (__strProp)->_Option.opt[size]); \
		}\
		}while(0)

#define IPSDK_PROP_COPY_BOOLEAN(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val = (__strProp)->val; \
			(__desProp)->def = (__strProp)->def; \
		}while(0)

#define IPSDK_PROP_COPY_INTEGER(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val = (__strProp)->val; \
			(__desProp)->def = (__strProp)->def; \
			(__desProp)->min = (__strProp)->min; \
			(__desProp)->max = (__strProp)->max; \
			IPSDK_Size size;\
			for(size = 0; size < (__strProp)->_Option.entries; size++)\
			{\
				IPSDK_PROP_ADD_OPT(__desProp, (__strProp)->_Option.opt[size]); \
			}\
		}while(0)

#define IPSDK_PROP_COPY_FLOAT(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val = (__strProp)->val; \
			(__desProp)->def = (__strProp)->def; \
			(__desProp)->min = (__strProp)->min; \
			(__desProp)->max = (__strProp)->max; \
			IPSDK_Size size;\
			for(size = 0; size < (__strProp)->_Option.entries; size++)\
			{\
				IPSDK_PROP_ADD_OPT(__desProp, (__strProp)->_Option.opt[size]); \
			}\
		}while(0)

#define IPSDK_PROP_COPY_STRING(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			snprintf((__desProp)->val,sizeof((__desProp)->val),"%s", (__strProp)->val); \
			snprintf((__desProp)->def,sizeof((__desProp)->def),"%s", (__strProp)->def); \
			(__desProp)->max_len = (__strProp)->max_len; \
		}while(0)

#define IPSDK_PROP_COPY_IPV4(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val[0] = (__strProp)->val[0]; \
			(__desProp)->val[1] = (__strProp)->val[1]; \
			(__desProp)->val[2] = (__strProp)->val[2]; \
			(__desProp)->val[3] = (__strProp)->val[3]; \
		}while(0)

#define IPSDK_PROP_COPY_HWADDR(__strProp, __desProp) \
		do{ \
			(__desProp)->read_only = (__strProp)->read_only; \
			(__desProp)->type = (__strProp)->type; \
			(__desProp)->val[0] = (__strProp)->val[0]; \
			(__desProp)->val[1] = (__strProp)->val[1]; \
			(__desProp)->val[2] = (__strProp)->val[2]; \
			(__desProp)->val[3] = (__strProp)->val[3]; \
			(__desProp)->val[4] = (__strProp)->val[4]; \
			(__desProp)->val[5] = (__strProp)->val[5]; \
		}while(0)
/**
 * 文本转换成 IPv4 属性设置。
 */
#define IPSDK_PROP_IPV4_ATON(__Prop, __ipv4_text) \
	do{\
		IPSDK_Char *ip0, *ip1, *ip2, *ip3;\
		ip0 = __ipv4_text;\
		if (IPSDK_NULL != ip0) {\
			ip1 = strchr(ip0, '.');\
			if (IPSDK_NULL != ip1++) {\
				ip2 = strchr(ip1, '.');\
				if (IPSDK_NULL != ip2++) {\
					ip3 = strchr(ip2, '.');\
					if (IPSDK_NULL != ip3++) {\
						(__Prop)->val[0] = atoi(ip0);\
						(__Prop)->val[1] = atoi(ip1);\
						(__Prop)->val[2] = atoi(ip2);\
						(__Prop)->val[3] = atoi(ip3);\
					}\
				}\
			}\
		}\
	} while(0);

/**
 * IPv4 属性转换成文本。
 */
#define IPSDK_PROP_IPV4_NTOA(__Prop, __text, __size) \
	snprintf(__text, (__size), "%d.%d.%d.%d",\
		(IPSDK_Int)((__Prop)->val[0]),\
		(IPSDK_Int)((__Prop)->val[1]),\
		(IPSDK_Int)((__Prop)->val[2]),\
		(IPSDK_Int)((__Prop)->val[3]))

#define IPSDK_PROP_IPV4_STR IPSDK_PROP_IPV4_NTOA

/**
 * 设置 HW 地址属性的地址。
 */
#define IPSDK_PROP_HWADDR_SET(__Prop, __hw0, __hw1, __hw2, __hw3, __hw4, __hw5) \
	do{\
		(__Prop)->val[0] = (IPSDK_UInt32)(__hw0);\
		(__Prop)->val[1] = (IPSDK_UInt32)(__hw1);\
		(__Prop)->val[2] = (IPSDK_UInt32)(__hw2);\
		(__Prop)->val[3] = (IPSDK_UInt32)(__hw3);\
		(__Prop)->val[4] = (IPSDK_UInt32)(__hw4);\
		(__Prop)->val[5] = (IPSDK_UInt32)(__hw5);\
	} while(0)

/**
 * 文本转换成 HW 地址属性。
 */
#define IPSDK_PROP_HWADDR_ATON(__Prop, __hw_text) \
	do{\
		IPSDK_Size len = strlen(__hw_text);\
		IPSDK_Char *chr, ch;\
		IPSDK_Int i = 0, ii = 0;\
		for (i = 0; i < 6; ++i) {\
			chr = __hw_text + i * 3;\
			if (chr < (__hw_text) + len) {\
				for (ii = 0; ii < 2; ++ii) {\
					if ((chr[ii] >= '0' && chr[ii] <= '9') \
							|| (chr[ii] >= 'a' && chr[ii] <= 'f') \
							|| (chr[ii] >= 'A' && chr[ii] <= 'F')) {\
						if (chr[ii] >= 'a' && chr[ii] <= 'f') ch = chr[ii] - 'a' + 10;\
						else if (chr[ii] >= 'A' && chr[ii] <= 'F') ch = chr[ii] - 'A' + 10;\
						else if (chr[ii] >= '0' && chr[ii] <= '9') ch = chr[ii] - '0';\
						else ch = 0;\
						\
						if (0 == ii) {\
							(__Prop)->val[i] = (ch << 4);\
						} else {\
							(__Prop)->val[i] |= ch;\
						}\
					}\
				}\
			}\
		}\
	} while(0);

/**
 * HW 地址属性转换成文本。
 */
#define IPSDK_PROP_HWADDR_NTOA(__Prop, __text, __size) \
	snprintf(__text, (__size), "%02x:%02x:%02x:%02x:%02x:%02x",\
		(IPSDK_UInt32)((__Prop)->val[0]),\
		(IPSDK_UInt32)((__Prop)->val[1]),\
		(IPSDK_UInt32)((__Prop)->val[2]),\
		(IPSDK_UInt32)((__Prop)->val[3]),\
		(IPSDK_UInt32)((__Prop)->val[4]),\
		(IPSDK_UInt32)((__Prop)->val[5]))

#define IPSDK_PROP_HWADDR_STR IPSDK_PROP_HWADDR_NTOA


#ifdef __cplusplus
}
#endif

#endif

