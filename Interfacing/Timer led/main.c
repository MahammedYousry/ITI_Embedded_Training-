
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *  Author: mahamed youssry
 */
#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"


void ISR_Blink(void){
	static u16 Loc_u16Counter =0 ;
	static u8 state =0 ;

	if (Loc_u16Counter ==4000){

		state  =! state;
		DIO_VidSetPinValue(Port_A ,pin0 , state) ;
		Loc_u16Counter =0 ;
	}
	else {
		Loc_u16Counter++;
	}

}

void main(){
	TIMR_VidInit();
	TIMR0_SetCallBack(ISR_Blink);
	DIO_VidSetPinDirection(Port_A ,pin0 ,output);
	GIE_VidEnable();

	while(1){


	}


}
