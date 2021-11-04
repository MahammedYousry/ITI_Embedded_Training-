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
	u8 data ;
	DIO_VidSetPortDirection(Port_C ,0xff);

	UART_VoidInit();
	UART_VidSend('H');
	UART_VidSend('i');

	u8 pin[]={pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7};


	while(1)
	{

			data = UART_u8Rec();

			if(data =='0')
			{
			DIO_VidSetPortValue(Port_C ,0x00);

			}

			else if(data =='1')
			{
				DIO_VidSetPortValue(Port_C ,0xff);
			}

			else if(data =='2')
			{
				for(u8 i = 0 ;i<=7;i++)
				{
				DIO_VidSetPinValue(Port_C ,pin[i],high);
				_delay_ms(200);
				DIO_VidSetPinValue(Port_C ,pin[i],low);
				}
			}
			else if(data =='3')
			{
					for(u8 i = 0 ;i<=7;i++)
					{
						DIO_VidSetPinValue(Port_C ,pin[i],high);
						_delay_ms(200);
						DIO_VidSetPinValue(Port_C ,pin[i],low);
					}
			}
			else if(data =='4')
						{
								for(u8 i = 0 ;i<=7;i++)
								{
									DIO_VidSetPinValue(Port_C ,pin[i],high);
									_delay_ms(200);

								}
						}
			else if(data =='5')
						{
								for(u8 i = 0 ;i<=7;i++)
								{

									_delay_ms(200);
									DIO_VidSetPinValue(Port_C ,pin[i],low);
								}
						}
			else if(data =='6')
						{
								for(u8 i = 0 ;i<=7;i++)
								{
									DIO_VidSetPinValue(Port_C ,pin[i],high);
									_delay_ms(200);

								}
						}
			else if(data =='7')
						{
								for(u8 i = 0 ;i<=7;i++)
								{

									_delay_ms(200);
									DIO_VidSetPinValue(Port_C ,pin[i],low);
								}
						}

	}


}
