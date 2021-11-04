/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#include"lib/STD_TYPES.h"
#include"lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"



void UART_VoidInit(){


	u8 UCSRC_temp = 0 ;

	// UCSRB

	SET_BIT(UCSRB ,UCSRB_RXEN_PIN );
	SET_BIT(UCSRB ,UCSRB_TXEN_PIN );

	//UCSRC

	SET_BIT(UCSRC_temp,UCSRC_URSEL_PIN);
	SET_BIT(UCSRC_temp,UCSRC_UCSZ1_PIN);
	SET_BIT(UCSRC_temp,UCSRC_UCSZ0_PIN);

	UCSRC =UCSRC_temp;

	//BR= 9600

	UBRRL =51 ;

}


void UART_VidSend(u8 Cpy_data){

	while (GET_BIT(UCSRA , UCSRA_UDRE_PIN) == 0 ){

	}

	UDR =Cpy_data;


}

u8 UART_u8Read(){
while (GET_BIT(UCSRA , UCSRA_RXC_PIN) == 0){

}
return UDR;
}

void UART_VidSendString (u8 *str){


	for (u8 i=0 ; str[i] !='\0'; i++){

		UART_VidSend(str[i]);

	}
}

u8 UART_u8Readstring(u8 *CPY_D){

	u8 x;

	for(u32 i = 0 ;x != '\r'; i++)
	{
		*(CPY_D+i) = UART_u8Read();


		x=*(CPY_D+i);
	}

}
