/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: mahamed youssry
 */

#include"lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"s

#include "DIO_interface.h"
#include "UART_interface.h"


void main ()
{
	u8 data[20] ;


	UART_VoidInit();





	while(1)
	{

		 UART_u8Readstring(data);
		 UART_VidSendString("HELLO ");
		 UART_VidSendString(data);

	}


}
