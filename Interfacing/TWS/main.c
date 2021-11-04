/*
 * main.c
 *
 *  Created on: Aug 31, 2021
 *      Author: mahamed youssry
 */
#include"lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#define CPU 8000000
#include "avr/delay.h"
#include "DIO_interface.h"
#include "TWS_interface.h"

void EEP_Write(u8 Address ,u8 val);
void EEP_Read(u8 Address ,u8 *val);

u8 value;
void main()
{

	/*Initial Master*/
	TWI_VoidInitMaster(0);

	DIO_VidSetPinDirection(Port_A ,pin0 ,output);


	while(1)
	{

		EEP_Write(0x19 ,0x11);

		_delay_ms(200);

		EEP_Read(0x18 , &value);

		_delay_ms(200);

		if (value == (0x11)){
			DIO_VidSetPinValue(Port_A ,pin0 ,high);
		}


	}

}

/*void EEP_Write(u8 Address ,u8 val){

	TWI_SendStartCondition();

	TWI_MasterSendAddress(0x51 , TWI_Write);

	TWI_MasterSendData(Address);

	TWI_MasterSendData(val);

	TWI_SendStopCondition();
}

void EEP_Read(u8 Address ,u8 *val){

	TWI_SendStartCondition();

	TWI_MasterSendAddress(0x51 , TWI_Write);

	TWI_MasterSendData(Address);

	TWI_SendStartCondition();

	TWI_MasterSendAddress(0x51 , TWI_Read);

	TWI_MasterReadData(&val);

	TWI_SendStopCondition();

}
*/
