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
	DIO_VidSetPinDirection(Port_A ,pin5,output);
	DIO_VidSetPinDirection(Port_A ,pin6,output);

	DIO_VidSetPinDirection(Port_D,pin2 ,input);
	DIO_VidSetPinValue(Port_D , pin2,high);
	DIO_VidSetPinDirection(Port_D,pin3 ,input);
	DIO_VidSetPinValue(Port_D , pin3,high);

	GIE_VidEnable();

	EXTI0_VidInti0();
	EXTI1_VidInti1();
	while(1){


	}
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	DIO_VidSetPinValue(Port_A ,pin5,high);
	_delay_ms(1000);
	DIO_VidSetPinValue(Port_A ,pin5,low);
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	DIO_VidSetPinValue(Port_A ,pin6,high);
	_delay_ms(1000);
	DIO_VidSetPinValue(Port_A ,pin6,low);
}
