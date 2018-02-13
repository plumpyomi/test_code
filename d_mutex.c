/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_mutex.c
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include "d_errno.h"
#include "d_mutex.h"

int32_t d_mutex_init(_d_mutex_t *p_mutex)
{
	*p_mutex = 0;

	return D_SUCCESS;
}

int32_t d_mutex_lock(_d_mutex_t *p_mutex, uint32_t wait_op)
{
	do{
		if(D_MUTEX_UNLOCK == *p_mutex){
			*p_mutex = D_MUTEX_LOCK;
			return D_SUCCESS;
		}
	} while (D_MUTEX_LOCK == *p_mutex && wait_op);

	return D_FAILED;
}

int32_t d_mutex_unlock(_d_mutex_t *p_mutex)
{
	*p_mutex = D_MUTEX_UNLOCK;

	return D_SUCCESS;
}

