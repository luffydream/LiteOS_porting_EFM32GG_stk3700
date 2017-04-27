#include "los_bsp_key.h"

#ifdef LOS_STM32F412Zx
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#endif

void LOS_EvbKeyInit(void)
{

#ifdef LOS_STM32F412Zx
	GPIO_InitTypeDef   GPIO_InitStructure;

	BSP_LED_Init(LED1);
	
	/* Enable GPIOC clock */
	__HAL_RCC_GPIOC_CLK_ENABLE();

	/* Configure PC.13 pin as input floating */
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Pin = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Enable and set EXTI line 15_10 Interrupt to the lowest priority */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
#endif

	return ;
}

#ifdef LOS_STM32F412Zx
/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_13)
  {
      BSP_LED_Toggle(LED1);
  }
}
#endif

/*****************************************************************************
 Function    : LOS_EvbGetKeyVal
 Description : Get GIOP Key value
 Input       : None
 Output      : None
 Return      : None
 *****************************************************************************/
unsigned int LOS_EvbGetKeyVal(int KeyNum)
{
	unsigned int KeyVal = LOS_GPIO_ERR; 
	
	//add you code here.
	
	return KeyVal;
}

