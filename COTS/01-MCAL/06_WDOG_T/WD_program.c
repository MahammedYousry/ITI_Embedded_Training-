/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include"lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#include"DIO_private.h"
#include "DIO_interface.h"
#include"WD_private.h"


void WDT_VidEnable(void){

	SET_BIT(WDTCR , WDTCR_WDE );
}

void WDT_VidDesable(void)
{

/* Write logical one to WDTOE and WDE */
WDTCR |= (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);

/* Turn off WDT */
WDTCR = 0;
}

void WDT_VidSleep(u8 Copy_u8SleepTime){

	WDTCR &= 0b11111000;

	WDTCR |= Copy_u8SleepTime;         // if Copy_u8SleepTime =6  sleep time = 1S


}
