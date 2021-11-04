
/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "avr/delay.h"
#include"lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"

void main (void){

				/*Initial pins for SPI*/

	DIO_VidSetPinDirection(Port_B , pin0,output); 			//slave 1
	DIO_VidSetPinDirection(Port_B , pin1,output); 			//slave 2

				/*Master Pins*/

	DIO_VidSetPinDirection(Port_B , pin5,output);
	DIO_VidSetPinDirection(Port_B , pin6,input);
	DIO_VidSetPinDirection(Port_B , pin7,output);

	SPI_VoidInitMaster();


	while(1)
	{
		DIO_VidSetPinValue(Port_B , pin0,low);
		SPI_u8Transceive(0x12);
		DIO_VidSetPinValue(Port_B , pin0,high);
		_delay_ms(200);

		DIO_VidSetPinValue(Port_B , pin1,low);
		SPI_u8Transceive(0xc4);
		DIO_VidSetPinValue(Port_B , pin1,high);
		_delay_ms(200);
	}






}
