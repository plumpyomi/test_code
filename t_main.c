/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: t_main.c
*   Author: ZhiChao Dong
*   Date: 2018/02/01
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "d_errno.h"
#include "d_queue.h"

d_queue_t	g_msg_queue;

int main(int argc, char* argv[])
{
	int i;

	printf("Test for my queue\n");

	d_init_queue(&g_msg_queue);

	for(i = 0; i < 5; ++i){
		d_node_t *p_node;

		p_node = (d_node_t *)malloc(sizeof(d_node_t));
		p_node->m_data = i+1;
		d_en_queue(&g_msg_queue, p_node);
	}

	{
		d_node_t *p_node;
		while(d_de_queue(&g_msg_queue, &p_node) == D_SUCCESS){
			printf("%d ", p_node->m_data);
			free(p_node);
		}
	}

	d_deinit_queue(&g_msg_queue);
	
	return 0;
}

