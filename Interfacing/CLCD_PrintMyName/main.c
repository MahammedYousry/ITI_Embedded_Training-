/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: mahamed youssry
 */
#include "avr/delay.h"
#include"lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
void main (){
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_E_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT , 0b11111111);



	CLCD_VidInit();
u8 arr[]={"mohammed"};
CLCD_String(arr);

	while(1){

	}
}
