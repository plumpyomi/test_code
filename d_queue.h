/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_queue.h
*   Author: ZhiChao Dong
*   Date: 2018/02/01
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#ifndef _D_QUEUE_H_
#define _D_QUEUE_H_

#include "d_type.h"

typedef uint32_t	d_data_type_t;

typedef struct d_node
{
	d_data_type_t	m_data;
	struct d_node	*p_next;
} d_node_t;

typedef struct d_queue
{
	d_node_t *p_head;
	d_node_t *p_tail;
} d_queue_t;

int32_t d_init_queue(d_queue_t *p_queue);
int32_t d_deinit_queue(d_queue_t *p_queue);
int32_t d_en_queue(d_queue_t *p_queue, d_node_t *p_node);
int32_t d_de_queue(d_queue_t *p_queue, d_node_t **pp_node);

#endif//_D_QUEUE_H_
