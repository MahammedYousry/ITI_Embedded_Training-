/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "avr/delay.h"
#include"lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "avr/delay.h"

#define mode master

#define master 1
#define slave  2

#if mode == master

void main (void)
{

					/*Initial pins for SPI*/

	DIO_VidSetPinDirection(Port_A , pin7,input); //Button
	DIO_VidSetPinValue(Port_A , pin7,high);

	DIO_VidSetPinDirection(Port_B , pin4,output); // ssi
	DIO_VidSetPinDirection(Port_B , pin5,output); // mosi
	DIO_VidSetPinDirection(Port_B , pin6,input);  //miso
	DIO_VidSetPinDirection(Port_B , pin7,output);//SCK

	SPI_VoidInitMaster();
	u8 val;
	while(1)
	{

		DIO_VidGetPinValue(Port_A , pin7 ,&val);

		if(val == 0){
			SPI_u8Transceive('0');
		}
		else if(val ==1)
		{
			SPI_u8Transceive('1');
		}
		_delay_ms(200);
	}

}


#elif mode == slave
void main (void)
{



					/*Initial pins for SPI*/

	DIO_VidSetPinDirection(Port_D , pin0,output); //LED


	DIO_VidSetPinDirection(Port_B , pin4,input); // SSI
	DIO_VidSetPinDirection(Port_B , pin5,input); // mosi
	DIO_VidSetPinDirection(Port_B , pin6,output);  //miso
	DIO_VidSetPinDirection(Port_B , pin7,input);//SCK

	SPI_VoidInitSlave();

	u8 read;

	while(1)
	{
		read =SPI_u8Transceive(0x55);

		if (read == '1')
		{
			DIO_VidSetPinValue(Port_D,pin0,high);
		}

		else if (read == '0')
		{
			DIO_VidSetPinValue(Port_D,pin0,low);
		}

	}

}
#endif
