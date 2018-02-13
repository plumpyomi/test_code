/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_mutex.h
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#ifndef _D_MUTEX_H_
#define _D_MUTEX_H_

#include "d_type.h"

#define D_MUTEX_LOCK			1
#define D_MUTEX_UNLOCK			0

#define D_MUTEX_NO_WAIT			0
#define D_MUTEX_WAIT_FOREVER	1

typedef uint32_t _d_mutex_t;

int32_t d_mutex_init(_d_mutex_t *p_mutex);
int32_t d_mutex_lock(_d_mutex_t *p_mutex, uint32_t wait_op);
int32_t d_mutex_unlock(_d_mutex_t *p_mutex);

#endif//_D_MUTEX_H_
