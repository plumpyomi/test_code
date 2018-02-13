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

#define SYS_DEBUG   1

#if SYS_DEBUG
    #define SYS_DEBUGP(...)	do{printf("[%s]<%s>L%04d: ", __FILE__, __func__, __LINE__);\
                           printf(__VA_ARGS__);printf("\n");}while(0)
#else
    #define SYS_DEBUGP(...) 
#endif

#endif//_D_COMMON_H_
