#ifndef _LOS_BSP_KEY_H
#define _LOS_BSP_KEY_H

#define RESET 0

#define USER_KEY 1

#define LOS_GPIO_ERR 0xFF

extern void LOS_EvbKeyInit(void);

unsigned int LOS_EvbGetKeyVal(int KeyNum);

#endif
