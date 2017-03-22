/**
  ******************************************************************************
  * @file    main.c
  * @author  Supowang  any question please send mail to 512965803@qq.com
  * @version V1.0
  * @date    2016-12-07
  * @brief   Huawei LiteOS  ARM Cortex M0 DEMO 
  ******************************************************************************
  * @attention
	* Platform :  Atmel SAM D21 Xplained Pro
  *	Huawei LiteOS Source Code:http://developer.huawei.com/ict/cn/site-iot/product/liteos
	* GitHub:https://github.com/LiteOS
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
// Huawei LiteOS Headfiles
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "los_base.h"
#include "los_config.h"
#include "los_typedef.h"
#include "los_hwi.h"
#include "los_task.ph"
#include "los_sem.h"
#include "los_event.h"
#include "los_memory.h"
#include "los_queue.ph"

#include "bsp.h"
#include "Board_LED.h"
UINT32 g_TestTskHandle;

void delay(unsigned int n)
{
	int i,j;
	for(j=0;j<200;j++)
		for(i=0;i<n;i++);
}

void hardware_init(void)
{
		LED_Initialize();
		//USART_Init();
}

VOID task1(void)
{
	UINT32 uwRet = LOS_OK;
	while(1)
	{
		LED_On(0);
		delay(1000);
		LED_Off(0);
		delay(1000);
		uwRet = LOS_TaskDelay(1000);
		if(uwRet !=LOS_OK)
			return;
	}
}
UINT32 creat_task1(void)
{
	UINT32 uwRet = LOS_OK;
	TSK_INIT_PARAM_S task_init_param;
	task_init_param.usTaskPrio = 0;
	task_init_param.pcName = "task1";
	task_init_param.pfnTaskEntry = (TSK_ENTRY_FUNC)task1;
	task_init_param.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
	task_init_param.uwResved = LOS_TASK_STATUS_DETACHED;
	uwRet = LOS_TaskCreate(&g_TestTskHandle,&task_init_param);
	if(uwRet !=LOS_OK)
	{
		return uwRet;
	}
	return uwRet;
}

VOID task2(void)
{
	UINT32 uwRet = LOS_OK;
	//int count=0;
	//char c='1';
	while(1)
	{
		//count++;
		//USART_putc(c);
		//printf("Hello HuaweiLiteOS,count is %d\r\n",count);
		uwRet = LOS_TaskDelay(1000);
		if(uwRet !=LOS_OK)
			return;
	}
}

UINT32 creat_task2(void)
{
	UINT32 uwRet = LOS_OK;
	TSK_INIT_PARAM_S task_init_param;
	task_init_param.usTaskPrio = 1;
	task_init_param.pcName = "task2";
	task_init_param.pfnTaskEntry = (TSK_ENTRY_FUNC)task2;
	task_init_param.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
	task_init_param.uwResved = LOS_TASK_STATUS_DETACHED;
	uwRet = LOS_TaskCreate(&g_TestTskHandle,&task_init_param);
	if(uwRet !=LOS_OK)
	{
		return uwRet;
	}
	return uwRet;
}



UINT32 osAppInit(void)
{
	UINT32 uwRet = 0;
	hardware_init();
	uwRet = creat_task1();
	if(uwRet !=LOS_OK)
	{
		return uwRet;
	}
	uwRet = creat_task2();
	if(uwRet !=LOS_OK)
	{
		return uwRet;
	}
	return LOS_OK;
}
/*********************************************END OF FILE**********************/
