/*
 * main.c
 *
 *  Created on: Aug 18, 2021
 *      Author: mahamed youssry
 */

#include"lib/STD_TYPES.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "KPD_config.h"
#include "KPD_interface.h"

void main ()
{
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT , CLCD_E_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT , 0b11111111);
	CLCD_VidInit();

	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8COLUMN0_PIN,output);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8COLUMN1_PIN,output);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8COLUMN2_PIN,output);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8COLUMN3_PIN,output);

	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8ROW0_PIN,input);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8ROW1_PIN,input);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8ROW2_PIN,input);
	DIO_VidSetPinDirection(KPD_u8PORT , KPD_u8ROW3_PIN,input);

	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8COLUMN0_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8COLUMN1_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8COLUMN2_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8COLUMN3_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW0_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW1_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW2_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW3_PIN,high);

	while(1){
		u8 Local_u8KPDResult = KPD_u8GetPressKey();
		if(Local_u8KPDResult != NOT_PRESSED){
			CLCD_VidSendData(Local_u8KPDResult);

		}
	}
}


