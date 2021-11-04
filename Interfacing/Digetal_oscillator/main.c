
/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mahamed youssry
 */
#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include "TIMR_interface.h"
#include "util/delay.h"

#define Mode FPWM

#define CTC  10
#define FPMW 20
#define phaseCorrectPMW 30




#if Mode == CTC

void ISR_Blink(void);

void main(){

	TIMR_VidInit();
	TIMR0_SetCallBack(ISR_Blink);
	DIO_VidSetPinDirection(Port_A ,pin0 ,output);
	GIE_VidEnable();

	while(1){


	}


}

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

                                           /*************************************************************************/

#elif Mode == FPWM

void ISR_Blink(void);


void main(){


	DIO_VidSetPinDirection(Port_B ,pin3 ,output);
	TIMR_VidInit_FastPWM();
	//TIMR_VidSetCompareMatch(250);


	while(1)
	{
		for( u8 i =0; i <=255 ;i++)
		{
			TIMR_VidSetCompareMatch(i);
			_delay_ms(100);
		}

	}


}

                                           /*************************************************************************/

#elif Mode == phaseCorrectPMW


void main(){


	DIO_VidSetPinDirection(Port_B ,pin3 ,output);
	 TIMR_VidInit_PhaseCorrectPWM();

	//TIMR_VidSetCompareMatch(250);


	while(1)
	{
		for( u8 i =0; i <=255 ;i++)
		{
			TIMR_VidSetCompareMatch(i);
			_delay_ms(100);
		}

	}


}



#endif
