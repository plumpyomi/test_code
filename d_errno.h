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

/**
 * @defgroup define marco for error code
 * @{
 */

/** 0x4000xxxx used for system error */
#define D_SYS_DATA_ERROR	(0x40000001)

/** 0x4001xxxx used for memory error */
#define D_MEM_NOMEMORY		(0x40010001)

/** 0x4002xxxx used for message error */
#define D_MSG_QUEUE_UNINIT	(0x40020001)
#define D_MSG_QUEUE_REINIT	(0x40020002)

/** 0x1002xxxx used for common queue message */
#define D_MSG_QUEUE_EMPTY	(0x10020001)

/** @} */

#endif//_D_ERRNO_H_
