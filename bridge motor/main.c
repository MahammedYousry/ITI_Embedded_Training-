/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "avr/delay.h"


void main (){



	DIO_VidSetPinDirection(Port_D, pin1, output);

	DIO_VidSetPinDirection(Port_D, pin0, output);


	while(1){


				DIO_VidSetPinValue(Port_D , pin1 , high);

				DIO_VidSetPinValue(Port_D , pin0 ,low);

					_delay_ms(500);
				DIO_VidSetPinValue(Port_D , pin1 , low);

				DIO_VidSetPinValue(Port_D , pin0 ,high);

				_delay_ms(500);
	}



}



