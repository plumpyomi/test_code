/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_queue.c
*   Author: ZhiChao Dong
*   Date: 2018/02/01
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include <stdlib.h>
#include "d_errno.h"
#include "d_queue.h"

int32_t d_init_queue(d_queue_t *p_queue)
{
	if(p_queue == NULL)
		return D_MSG_QUEUE_UNINIT;

	if(p_queue->p_head != NULL)
		return D_MSG_QUEUE_REINIT;

	p_queue->p_head = (d_node_t *)malloc(sizeof(d_node_t));
	if(p_queue->p_head == NULL)
		return D_MEM_NOMEMORY;

	p_queue->p_tail = p_queue->p_head;

	return D_SUCCESS;
}

int32_t d_deinit_queue(d_queue_t *p_queue)
{
	if(p_queue == NULL)
		return D_MSG_QUEUE_UNINIT;

	if(p_queue->p_head != NULL)
		free(p_queue->p_head);

	p_queue->p_head = p_queue->p_tail = NULL;

	return D_SUCCESS;
}

int32_t d_en_queue(d_queue_t *p_queue, d_node_t *p_node)
{
	if(p_queue == NULL)
		return D_MSG_QUEUE_UNINIT;
	if(p_queue->p_head == NULL)
		return D_MSG_QUEUE_UNINIT;

	if(p_node == NULL)
		return D_SYS_DATA_ERROR;

	p_queue->p_tail->p_next = p_node;
	p_queue->p_tail	= p_node;
	p_node->p_next	= NULL;

	return D_SUCCESS;
}

int32_t d_de_queue(d_queue_t *p_queue, d_node_t **pp_node)
{
	if(p_queue == NULL)
		return D_MSG_QUEUE_UNINIT;
	if(p_queue->p_head == NULL)
		return D_MSG_QUEUE_UNINIT;
	
	if(p_queue->p_head == p_queue->p_tail)
		return D_MSG_QUEUE_EMPTY;

	*(pp_node) = p_queue->p_head->p_next;
	p_queue->p_head->p_next = (*pp_node)->p_next;
	if(p_queue->p_head->p_next == NULL)
        p_queue->p_tail = p_queue->p_head;

	return D_SUCCESS;
}

