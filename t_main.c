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

#include "d_common.h"
#include "d_message.h"

#include "d_test.h"

int main(int argc, char* argv[])
{
	SYS_DEBUGP("Test for my queue");

	d_message_init();

    d_test_init();

	d_message_loop();

	d_message_deinit();
	
	return 0;
}

/** File end */
