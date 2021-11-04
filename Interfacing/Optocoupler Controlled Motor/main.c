/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#define F_CPU 8000000
#include "DIO_interface.h"
#include "avr/delay.h"


void main (){


	DIO_VidSetPinDirection(Port_D, pin0, input);
	DIO_VidSetPinDirection(Port_D, pin1, output);



	u8 x =0;
	while(1){
		_delay_ms(30);
		DIO_VidGetPinValue(Port_D,pin0,&x);
		if(x == 0)
				{
					DIO_VidSetPinValue(Port_D , pin1 , high);

					_delay_ms(30);
					while(x==0)
					{
						DIO_VidGetPinValue(Port_D,pin0,&x);
					}
				}
		if(x ==1)
			{
				DIO_VidSetPinValue(Port_D , pin1 , low);
				_delay_ms(30);
				while(x==1)
					{
				DIO_VidGetPinValue(Port_D,pin0,&x);
					}
			}

		_delay_ms(30);


	}



}



