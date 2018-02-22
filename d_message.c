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
#include <stdio.h>
#include <stdlib.h>
#include "d_common.h"
#include "d_errno.h"
#include "d_queue.h"
#include "d_mutex.h"

#include "d_message.h"

#define D_CHECK_HANDLER(handler) ((handler<0)||(handler>=D_MAX_MSG_HANDLE))

_d_queue_t	g_msg_queue;
_d_mutex_t  g_msg_mutex;

p_msg_handler_t g_msg_handler[D_MAX_MSG_HANDLE] = {NULL};

int32_t d_message_handler_def(uint32_t id, base_data_t data)
{
    MSG_DEBUGP("Default message handler:");
    MSG_DEBUGP("id: %d ", id);
    MSG_DEBUGP("data: %d ", data.m_ul);

    return 0;
}

d_handler_t d_message_handler_reg(p_msg_handler_t p_func)
{
    int32_t i;

    for(i = 0; i < D_MAX_MSG_HANDLE; ++i){
        if(g_msg_handler[i] == NULL){
            g_msg_handler[i] = p_func;
            return i;
        }
    }

    return -1;
}

int32_t d_message_init(void)
{
	int32_t     ret;

	ret = d_queue_init(&g_msg_queue);
    if(ret != D_SUCCESS)
        return ret;

    ret = d_mutex_init(&g_msg_mutex);
    if(ret != D_SUCCESS)
        return ret;

    ret = d_message_handler_reg(d_message_handler_def);

    return ret;
}

int32_t d_message_deinit(void)
{
	return d_queue_deinit(&g_msg_queue);
}

int32_t d_put_message(d_msg_data_t data)
{
	int32_t     ret;
	d_node_t    *p_node;

    ret = d_mutex_lock(&g_msg_mutex, D_MUTEX_WAIT_FOREVER);
    if(ret != D_SUCCESS)
        return ret;

	p_node = (d_node_t *)malloc(sizeof(d_node_t));

	p_node->m_data.m_msg_id			= data.m_msg_id;
    p_node->m_data.m_handler        = data.m_handler;
	p_node->m_data.m_msg_data.m_ul	= data.m_msg_data.m_ul;

	ret = d_en_queue(&g_msg_queue, p_node);

    d_mutex_unlock(&g_msg_mutex);

    return ret;
}

int32_t d_get_message(d_msg_data_t *p_data)
{
	int32_t     ret;
	d_node_t    *p_node;

    ret = d_mutex_lock(&g_msg_mutex, D_MUTEX_WAIT_FOREVER);
    if(ret != D_SUCCESS)
        return ret;

	ret = d_de_queue(&g_msg_queue, &p_node);
	if(ret == D_SUCCESS){
		p_data->m_msg_id        = p_node->m_data.m_msg_id;
        p_data->m_handler       = p_node->m_data.m_handler;
		p_data->m_msg_data.m_ul = p_node->m_data.m_msg_data.m_ul;
		free(p_node);
	}

    d_mutex_unlock(&g_msg_mutex);

	return ret;
}

void d_message_loop(void)
{
    d_msg_data_t t_data;

	while(1){
        if(d_get_message(&t_data) == D_SUCCESS){
            if(D_CHECK_HANDLER(t_data.m_handler)){
                MSG_DEBUGP("No handler is registered!");
                continue;
            }
            if(g_msg_handler[t_data.m_handler] != NULL){
                g_msg_handler[t_data.m_handler](t_data.m_msg_id, t_data.m_msg_data);
            }else{
                MSG_DEBUGP("Handler is invalid!");
            }
        }

        d_delay_ms(1000);
	}
}

