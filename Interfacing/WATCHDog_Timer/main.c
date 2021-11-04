/*
 * main.c
 *
 *  Created on: Aug 28, 2021
 *      Author: mahamed youssry
 */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "WD_interface.h"
#include "avr/delay.h"





void main (){

	DIO_VidSetPinDirection(Port_A ,pin1 ,output);
	DIO_VidSetPinValue(Port_A ,pin1 ,high);
	_delay_ms(200);
	DIO_VidSetPinValue(Port_A ,pin1 ,low);
	_delay_ms(200);
	WDT_VidEnable();
	WDT_VidSleep(6);
	while(1){




}


}
