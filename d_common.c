/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_common.c
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include "d_common.h"

#if LINUX_DEBUG
	#include <unistd.h>
#endif

void d_delay_ms(uint32_t msec)
{
#if LINUX_DEBUG
	/** test code for linux platform */
	usleep(msec*1000);
#endif
}

