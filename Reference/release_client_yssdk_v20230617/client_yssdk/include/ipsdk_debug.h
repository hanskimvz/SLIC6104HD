#ifndef _IPSDK_DEBUG_H_
#define _IPSDK_DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ipsdk_def_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IPSDK_DEBUG_SWITCH_ON


#if defined(IPSDK_DEBUG_SWITCH_ON)

#if defined(OS_WINDOWS)
#define IPSDK_DEBUG(fmt, ...) \
	do { \
		printf("[%s]-%d: ", __FUNCTION__, __LINE__); \
		printf(fmt, ##__VA_ARGS__); \
		printf("\r\n"); \
	}while(0)
#else
#define IPSDK_DEBUG(fmt, arg...) \
	do { \
		const char* bname = basename(__FILE__); \
		int const syntax_fg = bname[3] % 8; \
		printf("\033[1;%dm[%12s:%4d]\033[0m ", 30 + syntax_fg, bname, __LINE__); \
		printf(fmt, ##arg); \
		printf("\n"); \
	} while (0)
#endif

#else
#define IPSDK_DEBUG(fmt, arg...)
#endif

#define CHECK_POINTER_NO_RET(p) \
	do{ \
		if(IPSDK_NULL == p){ \
			IPSDK_DEBUG("[%s] The pointer is null!", __FUNCTION__); \
			return; \
		} \
	}while(0)

#define CHECK_POINTER_ERR_RET(p, ret) \
	do{ \
		if(IPSDK_NULL == p){ \
			IPSDK_DEBUG("[%s] The pointer is null!", __FUNCTION__); \
			return (ret); \
		} \
	}while(0)

#define CHECK_POINTER_ERR_JUMP(p,__location) \
	do{ \
		if(IPSDK_NULL == p){ \
			IPSDK_DEBUG("[%s] The pointer is null!", __FUNCTION__); \
			goto __location; \
		} \
	}while(0)

#define CHECK_RET_SUCCESS_NO_RET(val) \
	do{ \
		if(IPSDK_SUCCESS != val){ \
			IPSDK_DEBUG("[%s] Return value is not success, %#x!", __FUNCTION__, val); \
			return ; \
		} \
	}while(0)

#define CHECK_RET_SUCCESS_ERR_RET(val, ret) \
	do{ \
		if(IPSDK_SUCCESS != val){ \
			IPSDK_DEBUG("[%s] Return value is not success, %#x!", __FUNCTION__, val); \
			return ret; \
		} \
	}while(0)

#define CHECK_RET_SUCCESS_ERR_JUMP(val,__location) \
	do{ \
		if(IPSDK_SUCCESS != val){ \
			IPSDK_DEBUG("[%s] Return value is not success, %#x!", __FUNCTION__, val); \
			goto __location; \
		} \
	}while(0)

#define CHECK_VALUE_ERR_RET(__condition, __ret) \
	do{ \
		if (__condition){ \
			IPSDK_DEBUG("[%s] Return value is not success, %#x!", __FUNCTION__, __condition); \
			return(__ret); \
		} \
	}while(0)


#define CHECK_VALUE_ERR_JUMP(__condition, __location) \
	do{ \
		if (__condition){ \
			IPSDK_DEBUG("[%s] Return value is not success, %#x!", __FUNCTION__, __condition); \
			goto __location; \
		} \
	}while(0)


#ifdef __cplusplus
}
#endif

#endif

