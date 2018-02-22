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

#include <pthread.h>

#include "d_common.h"
#include "d_errno.h"
#include "d_message.h"

void *t_thread(void *arg);
int m_test_fun(void);

int main(int argc, char* argv[])
{
	SYS_DEBUGP("Test for my queue");

	d_message_init();

    m_test_fun();

	d_message_loop();

	d_message_deinit();
	
	return 0;
}

int m_test_fun(void)
{
    pthread_t th;

    pthread_create(&th, NULL, t_thread, (void *)0);

    return 0;
}

void *t_thread(void *arg)
{
	int i;
 
	for(i = 0; i < 15; ++i){
        d_msg_data_t t_data;

        d_delay_ms(2000);

	    SYS_DEBUGP("put message %d", i);
        t_data.m_msg_id         = i+1;
        t_data.m_handler        = 0;
        t_data.m_msg_data.m_ul  = i*23+10;
        d_put_message(t_data);
	}
}
