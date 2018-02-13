/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_errno.h
*   Author: ZhiChao Dong
*   Date: 2018/02/01
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#ifndef _D_ERRNO_H_
#define _D_ERRNO_H_

#define D_SUCCESS			0
#define D_FAILED			-1

#define D_SYS_DATA_ERROR	(0x40000001)

#define D_MEM_NOMEMORY		(0x40010001)

#define D_MSG_QUEUE_UNINIT	(0x40020001)
#define D_MSG_QUEUE_REINIT	(0x40020002)

#define D_MSG_QUEUE_EMPTY	(0x10020001)

#endif//_D_ERRNO_H_
