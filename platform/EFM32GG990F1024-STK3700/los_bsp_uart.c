#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "los_bsp_uart.h"
#include "los_demo_debug.h"

/******************************************************************************
	here include some special hearder file you need
******************************************************************************/
#include <string.h>
#include "em_usart.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "bsp.h"
/*****************************************************************************
 Function    : LOS_EvbUartInit
 Description : Init uart device
 Input       : None
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbUartInit(void)
{
	//add you code here.
  USART_InitAsync_TypeDef usartInit = USART_INITASYNC_DEFAULT;

  /* Enable High Frequency Peripherals */
  CMU_ClockEnable(cmuClock_HFPER, true);

  /* Enable clocks to GPIO */
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Enable UART clock */
  CMU_ClockEnable( BSP_BCC_CLK, true );
	
	/* Initialize USART */
  USART_InitAsync( BSP_BCC_USART, &usartInit );

  /* Initialize UART pins */
    /* Configure GPIO pin for UART TX */
    /* To avoid false start, configure output as high. */
    GPIO_PinModeSet( gpioPortD, 0, gpioModePushPull, 1 );

    /* Configure GPIO pin for UART RX */
    GPIO_PinModeSet( gpioPortD, 1, gpioModeInput, 1 );

    /* Enable the switch that enables UART communication. */
    GPIO_PinModeSet( BSP_BCC_ENABLE_PORT, BSP_BCC_ENABLE_PIN, gpioModePushPull, 1 );

    BSP_BCC_USART->ROUTE |= USART_ROUTE_RXPEN | USART_ROUTE_TXPEN | BSP_BCC_LOCATION;
	return;
}

/*****************************************************************************
 Function    : LOS_EvbUartWriteByte
 Description : Uart write one byte
 Input       : const char c
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbUartWriteByte(const char c)
{
	//add you code here.
  //while (!(BSP_BCC_USART->STATUS & USART_STATUS_TXBL)) ;
  BSP_BCC_USART->TXDATA = (uint32_t) c;
	return;
}

/*****************************************************************************
 Function    : LOS_EvbUartReadByte
 Description : Uart reaad one byte
 Input       : char* c
 Output      : None
 Return      : None
 *****************************************************************************/
char LOS_EvbUartReadByte(void)
{
	//add you code here.
	char c;
  while (!(BSP_BCC_USART->STATUS & USART_STATUS_RXDATAV)) ;
  c = BSP_BCC_USART->RXDATA;
	return c;
}

static char _buffer[128];
/*****************************************************************************
 Function    : LosUartPrintf
 Description : Los printf function
 Input       : char* fmt, ...
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbUartPrintf(char* fmt, ...)
{
	//add you code here.
    int i;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(_buffer, fmt, ap);
    va_end(ap);

    for (i = 0; _buffer[i] != '\0'; i++)
    {
        LOS_EvbUartWriteByte(_buffer[i]);
    }  
	return;
}

/*****************************************************************************
 Function    : LOS_EvbUartWriteStr
 Description : Uart Write String function
 Input       : const char* str
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbUartWriteStr(const char* str)
{
	//add you code here.
    while (*str)
    {
			LOS_EvbUartWriteByte(*str);
			str++;
    }	
	return;
}

#ifndef LOS_KERNEL_TEST_KEIL_SWSIMU
///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ�����USART */
		LOS_EvbUartWriteByte((char)ch);	
	
		return (ch);
}
#endif
