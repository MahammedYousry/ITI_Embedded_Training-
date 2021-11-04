
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mahamed youssry
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#define F_CPU 8000000
#include "util/delay.h"

#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"


void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);


void main(){

	//pins Control as output
	DIO_VidSetPinDirection(Port_D ,pin1 ,output);
	DIO_VidSetPinDirection(Port_D ,pin2 ,output);
	DIO_VidSetPinDirection(Port_D ,pin3 ,output);
	DIO_VidSetPinDirection(Port_D ,pin4 ,output);

	//Create Tasks
	RTOS_u8CreateTask(0 ,0 ,200 ,Task1);
	RTOS_u8CreateTask(1 , 500 ,1000 ,Task2);
	RTOS_u8CreateTask(2 , 1000,2000 ,Task3);
	RTOS_u8CreateTask(3 ,2000  ,3000 ,Task4);

	//RTOS Start
	RTOS_voidStart();

	while(1)
		{
			RTOS_voidDispather();
		}
}

void Task1(void){
	static u8 state = 0 ;
	state = !state;
	DIO_VidSetPinValue(Port_D ,pin1 ,state);
}
void Task2(void){
	static u8 state = 0 ;
	state = !state;
	DIO_VidSetPinValue(Port_D ,pin2 ,state);
}
void Task3(void){
	static u8 state = 0 ;
	state = !state;
	DIO_VidSetPinValue(Port_D ,pin3 ,state);
}
void Task4(void){
	static u8 state = 0 ;
	state = !state;
	DIO_VidSetPinValue(Port_D ,pin4 ,state);
}
