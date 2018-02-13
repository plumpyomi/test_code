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

typedef uint32_t (*p_msg_handler_t)(uint32_t id, base_data_t data);

typedef struct d_msg_data
{
	uint32_t	    m_msg_id;
	base_data_t	    m_msg_data;
	p_msg_handler_t p_func;
} d_msg_data_t;

int32_t d_message_init(void);
int32_t d_message_deinit(void);
int32_t d_put_message(d_msg_data_t data);
int32_t d_get_message(d_msg_data_t *p_data);

#endif//_D_MESSAGE_H_
