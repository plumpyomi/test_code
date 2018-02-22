/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_common.h
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#ifndef _D_COMMON_H_
#define _D_COMMON_H_

#include "d_type.h"

#define LINUX_DEBUG 1

#define SYS_DEBUG   1
#define TST_DEBUG   1
#define MSG_DEBUG   1

#if SYS_DEBUG
    #define SYS_DEBUGP(...)	do{printf("[%s]<%s>L%04d: ", __FILE__, __func__, __LINE__);\
                           printf(__VA_ARGS__);printf("\n");}while(0)
#else
    #define SYS_DEBUGP(...) 
#endif

#if TST_DEBUG
    #define TST_DEBUGP(...)	do{printf("[%s]<%s>L%04d: ", __FILE__, __func__, __LINE__);\
                           printf(__VA_ARGS__);printf("\n");}while(0)
#else
    #define TST_DEBUGP(...) 
#endif

#if MSG_DEBUG
    #define MSG_DEBUGP(...)	do{printf("[%s]<%s>L%04d: ", __FILE__, __func__, __LINE__);\
                           printf(__VA_ARGS__);printf("\n");}while(0)
#else
    #define MSG_DEBUGP(...) 
#endif

void d_delay_ms(uint32_t msec);

#endif//_D_COMMON_H_
