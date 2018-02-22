/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_message.h
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#ifndef _D_MESSAGE_H_
#define _D_MESSAGE_H_

#include "d_type.h"

#define D_MAX_MSG_HANDLE    16
#define D_SYS_MESSAGE   0x0000

/**
 * @defgroup custom define
 * @{
 */

/** @} */

typedef union
{
	uint32_t	m_ul;
	uint16_t	m_us;
	int32_t		m_i[2];
	int16_t		m_s[2];
	uint8_t		m_uc[4];
	int8_t		m_c[4];
	float		m_f;
} base_data_t;

typedef int32_t d_handler_t;
typedef int32_t (*p_msg_handler_t)(uint32_t id, base_data_t data);

typedef struct d_msg_data
{
	uint32_t	    m_msg_id;
    d_handler_t     m_handler;
	base_data_t	    m_msg_data;
} d_msg_data_t;

int32_t d_message_init(void);
int32_t d_message_deinit(void);
int32_t d_put_message(d_msg_data_t data);
int32_t d_get_message(d_msg_data_t *p_data);
void d_message_loop(void);

d_handler_t d_message_handler_reg(p_msg_handler_t p_func);

#endif//_D_MESSAGE_H_
