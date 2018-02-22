/*===============================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   File Name: d_test.c
*   Author: ZhiChao Dong
*   Date: 2018/02/22
*   Desp.: 
*
*   Update Message: 
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "d_common.h"
#include "d_errno.h"
#include "d_message.h"

#include "d_test.h"

void *t_temperature_thread(void *arg);
void *t_switch_thread(void *arg);
int32_t t_temperature_handler(uint32_t id, base_data_t data);
int32_t t_switch_handler(uint32_t id, base_data_t data);

d_handler_t gh_temperature  = 0;
d_handler_t gh_switch       = 0;

int32_t d_test_init(void)
{
    pthread_t th1, th2;

    srand((unsigned)time(NULL));

    gh_temperature  = d_message_handler_reg(t_temperature_handler);
    gh_switch       = d_message_handler_reg(t_switch_handler);

    pthread_create(&th1, NULL, t_temperature_thread, (void *)0);
    pthread_create(&th2, NULL, t_switch_thread, (void *)0);

	return D_SUCCESS;
}

static int32_t _get_random(int32_t min, int32_t max)
{
    int32_t ret;

    if(min >= max)
        return 0;

    ret = (int32_t)rand()%(max-min);
    ret +=min;

    return ret;
}

int32_t t_temperature_handler(uint32_t id, base_data_t data)
{
    TST_DEBUGP("Temperature message handler:");
    TST_DEBUGP("id: %d", id);
    TST_DEBUGP("Temperature: %d", data.m_ul);

    return D_SUCCESS;
}

void *t_temperature_thread(void *arg)
{
	int i;
 
    i = 0;
	while(1){
        d_msg_data_t t_data;

        d_delay_ms(1000);

	    TST_DEBUGP("Put temperature message %d", i);
        t_data.m_msg_id         = i++;
        t_data.m_handler        = gh_temperature;
        t_data.m_msg_data.m_ul  = _get_random(-30, 40);
        d_put_message(t_data, PRIO_1);

        d_delay_ms(1000);
	}
}

int32_t t_switch_handler(uint32_t id, base_data_t data)
{
    TST_DEBUGP("Switch message handler:");
    TST_DEBUGP("id: %d", id);
    TST_DEBUGP("Switch status:");
    if(data.m_uc[0]){
        TST_DEBUGP("Open");
    }else{
        TST_DEBUGP("Close");
    }
    if(data.m_uc[1]){
        TST_DEBUGP("Open");
    }else{
        TST_DEBUGP("Close");
    }
    if(data.m_uc[2]){
        TST_DEBUGP("Open");
    }else{
        TST_DEBUGP("Close");
    }

    return D_SUCCESS;
}

void *t_switch_thread(void *arg)
{
	int i;
 
    i = 0;
	while(1){
        d_msg_data_t t_data;

        d_delay_ms(1000);

	    TST_DEBUGP("Put switch message %d", i);
        t_data.m_msg_id         = i++;
        t_data.m_handler        = gh_switch;
        t_data.m_msg_data.m_uc[0]  = _get_random(0, 2);
        t_data.m_msg_data.m_uc[1]  = _get_random(0, 2);
        t_data.m_msg_data.m_uc[2]  = _get_random(0, 2);
        d_put_message(t_data, PRIO_0);

        d_delay_ms(1000);
	}
}

/** File End */
