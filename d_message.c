/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_message.c
*   Author: ZhiChao Dong
*   Date: 2018/02/13
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include <stdlib.h>

#include "d_errno.h"
#include "d_message.h"
#include "d_queue.h"

d_queue_t	g_msg_queue;

int32_t d_message_init(void)
{
	return d_init_queue(&g_msg_queue);
}

int32_t d_message_deinit(void)
{
	return d_deinit_queue(&g_msg_queue);
}

int32_t d_put_message(d_msg_data_t data)
{
	d_node_t *p_node;

	p_node = (d_node_t *)malloc(sizeof(d_node_t));

	p_node->m_data.m_msg_id			= data.m_msg_id;
	p_node->m_data.m_msg_data.m_ul	= data.m_msg_data.m_ul;

	return d_en_queue(&g_msg_queue, p_node);
}

int32_t d_get_message(d_msg_data_t *p_data)
{
	int32_t ret;

	d_node_t *p_node;

	ret = d_de_queue(&g_msg_queue, &p_node);
	if(ret == D_SUCCESS){
		p_data->m_msg_id        = p_node->m_data.m_msg_id;
		p_data->m_msg_data.m_ul = p_node->m_data.m_msg_data.m_ul;
		free(p_node);
	}

	return ret;
}
