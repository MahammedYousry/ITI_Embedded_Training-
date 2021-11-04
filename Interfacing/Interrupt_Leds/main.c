/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: mahamed youssry
 */
#include "lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include"EXTI_interface.h"
#include"util/delay.h"



void main(){


	DIO_VidSetPinDirection(Port_C ,pin0,output);
	DIO_VidSetPinDirection(Port_C ,pin1,output);
	DIO_VidSetPinDirection(Port_C ,pin2,output);
	DIO_VidSetPinDirection(Port_C ,pin3,output);
	DIO_VidSetPinDirection(Port_C ,pin4,output);
	DIO_VidSetPinDirection(Port_C ,pin5,output);
	DIO_VidSetPinDirection(Port_C ,pin6,output);
	DIO_VidSetPinDirection(Port_C ,pin7,output);

	DIO_VidSetPinDirection(Port_D,pin2 ,input);
	DIO_VidSetPinValue(Port_D , pin2,high);

	GIE_VidEnable();

	EXTI0_VidInti0();

	while(1){
		DIO_VidSetPinValue(Port_C ,pin0,low);
		DIO_VidSetPinValue(Port_C ,pin1,low);
		DIO_VidSetPinValue(Port_C ,pin2,low);
		DIO_VidSetPinValue(Port_C ,pin3,low);
		DIO_VidSetPinValue(Port_C ,pin4,low);
		DIO_VidSetPinValue(Port_C ,pin5,low);
		DIO_VidSetPinValue(Port_C ,pin6,low);
		DIO_VidSetPinValue(Port_C ,pin7,low);
				_delay_ms(500);
		DIO_VidSetPinValue(Port_C ,pin0,high);
		DIO_VidSetPinValue(Port_C ,pin1,high);
		DIO_VidSetPinValue(Port_C ,pin2,high);
		DIO_VidSetPinValue(Port_C ,pin3,high);
		DIO_VidSetPinValue(Port_C ,pin4,high);
		DIO_VidSetPinValue(Port_C ,pin5,high);
		DIO_VidSetPinValue(Port_C ,pin6,high);
		DIO_VidSetPinValue(Port_C ,pin7,high);

		_delay_ms(500);


	}
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){

	u8 pin[]={pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7};

	DIO_VidSetPinValue(Port_C ,pin0,low);
	DIO_VidSetPinValue(Port_C ,pin1,low);
	DIO_VidSetPinValue(Port_C ,pin2,low);
	DIO_VidSetPinValue(Port_C ,pin3,low);
	DIO_VidSetPinValue(Port_C ,pin4,low);
	DIO_VidSetPinValue(Port_C ,pin5,low);
	DIO_VidSetPinValue(Port_C ,pin6,low);
	DIO_VidSetPinValue(Port_C ,pin7,low);

	for(u8 i = 0 ;i<=7;i++){
		DIO_VidSetPinValue(Port_C ,pin[i],high);
		_delay_ms(400);
		DIO_VidSetPinValue(Port_C ,pin[i],low);
	}
}

