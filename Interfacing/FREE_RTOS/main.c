/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "util/delay.h"
#define  F_CPU 8000000
		/*MCAL*/
#include "DIO_interface.h"
		/*HAL*/
#include "F-RTOS/FreeRTOS.h"
#include "F-RTOS/semphr.h"
#include "F-RTOS/task.h"


		/*Prototypes*/

void Task1 (void *p);
void Task2 (void *p);
void Task3 (void *p);
void Task4 (void *p);

xSemaphoreHandle lcd_smph ;


void main (void){


DIO_VidSetPortDirection(Port_D , 0xFF );

//xSemaphoreTake(lcd_smph , 1000) ;


xTaskCreate(   Task1        // Function Address
			 , NULL  		//Function Name
			 , 100  		//Stack Depth
			 , NULL 		//Pointer to void , will be passed to tas
			 , 1     		//task priority
			 , NULL);		//Handle task used with other Functions like Delete task

										/*******/

xTaskCreate(   Task2        // Function Address
			 , NULL  		//Function Name
			 , 100  		//Stack Depth
			 , NULL 		//Pointer to void , will be passed to tas
			 , 1     		//task priority
			 , NULL);		//Handle task used with other Functions like Delete task
										/*******/

xTaskCreate(   Task3        // Function Address
			 , NULL  		//Function Name
			 , 100  		//Stack Depth
			 , NULL 		//Pointer to void , will be passed to tas
			 , 1    		//task priority
			 , NULL);		//Handle task used with other Functions like Delete task

										/*******/

xTaskCreate(  Task4         // Function Address
			 , NULL  	    //Function Name
			 , 100  		//Stack Depth
			 , NULL 		//Pointer to void , will be passed to tas
			 , 1    		//task priority
			 , NULL);	    //Handle task used with other Functions like Delete task

										/*******/
vTaskStartScheduler();

	while(1)
	{

	}
}
										/*******/

void Task1 (void *p)
{
	u8 state = 1 ;

	while(1)
	{
		DIO_VidSetPinValue(Port_D ,pin1  ,state);
		state = !state ;
		vTaskDelay(500);    /* Tics Number */
	}
}
										/*******/
void Task2 (void *p)
{
	u8 state = 1 ;

	while(1)
	{
		DIO_VidSetPinValue(Port_D ,pin2  ,state);
		state = !state ;
		vTaskDelay(1000);
	}
}
										/*******/
void Task3 (void *p)
{
	u8 state = 1 ;

	while(1)
	{
		DIO_VidSetPinValue(Port_D ,pin3  ,state);
		state = !state ;
		vTaskDelay(1500);
	}
}
										/*******/
void Task4 (void *p)
{
	u8 state = 1 ;

	while(1)
	{
		DIO_VidSetPinValue(Port_D ,pin4  ,state);
		state = !state ;
		vTaskDelay(2000);
	}
}
