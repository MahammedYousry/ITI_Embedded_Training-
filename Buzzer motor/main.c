/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: mahamed youssry
 */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#define F_CPU 8000000
#include "DIO_interface.h"
#include "util/delay.h"
void main (){







	DIO_VidSetPinDirection(Port_D, pin0, output);








	while(1){
		DIO_VidSetPinValue(Port_D , pin0 ,high);
		_delay_ms(200);
		DIO_VidSetPinValue(Port_D , pin0 ,low);
			_delay_ms(200);


	}






}


