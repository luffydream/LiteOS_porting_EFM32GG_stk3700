#include "los_bsp_led.h"
#include "bsp.h"
/******************************************************************************
	here include some special hearder file you need
******************************************************************************/



/*****************************************************************************
 Function    : LOS_EvbLedInit
 Description : Init LED device
 Input       : None
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbLedInit(void)
{
	//add you code here.
  BSP_LedsInit();
	return ;
}

/*************************************************************************************************
 *  Function    ��LOS_EvbLedControl
 *  Discription : Led control function
 *  Input       : (1) index Led's index                                                                  *
 *                (2) cmd   Led on or off  
 *  Output      : None
 *  Return      : None                                                                                *
 *                                                                                 *
**************************************************************************************************/
void LOS_EvbLedControl(int index, int cmd)
{
    switch (index)
    {
        case LOS_LED1:
        {
            if (cmd == LED_ON)
            {
							 //add you code here.   
               /*led1 on */
							BSP_LedSet(0);
            }
            else
            {
							//add you code here.
										 /*led1 off */
							BSP_LedClear(0);
            }
            break;
        }
        case LOS_LED2:
        {
            if (cmd == LED_ON)
            {
							//add you code here.
                      /*led2 on */
							BSP_LedSet(1);
            }
            else
            {
							//add you code here.
                     /*led2 off */
							BSP_LedClear(1);
            }
            break;
        }
        case LOS_LED3:
        {
            if (cmd == LED_ON)
            {
						  //add you code here.
                      /*led3 on */
            }
            else
            {
							//add you code here.
                     /*led3 off */
            }
            break;
        }
        default:
        {
            break;
        }
    }
	return ;
}


