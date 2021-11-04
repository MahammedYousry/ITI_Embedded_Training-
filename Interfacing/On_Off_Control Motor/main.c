/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "avr/delay.h"
void main (void){





	DIO_VidSetPinDirection(Port_D, pin1, output);

	DIO_VidSetPinDirection(Port_D, pin0, input);
	u8 x  ;

	while(1){


			DIO_VidGetPinValue(Port_D,pin0,&x);
			if(x == 0){
				DIO_VidSetPinValue(Port_D , high, pin1 );
			}
			else{
				DIO_VidSetPinValue(Port_D ,low, pin1 );
			}
			_delay_ms(30);




	}






}
