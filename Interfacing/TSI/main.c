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


void main()
{

	/*Initial Master*/
	TWI_VoidInitMaster(0);

	while(1)
	{

		/*Start Condition*/
		TWI_SendStartCondition();

		/*Send Address*/
		TWI_MasterSendAddress(0x11 , TWI_Write);

		/*Send Data*/
		TWI_MasterSendData(0x33);

		/*Stop Condition*/
		TWI_SendStopCondition();

		_delay_ms(200);

	}

}
