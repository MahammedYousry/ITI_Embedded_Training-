#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"





void UART_VidInit(void){
	u8 UCSRC_temp = 0;
	/*UCSRB*/
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);

	/*UCSRC*/
	SET_BIT(UCSRC_temp , UCSRC_URSEL);
	SET_BIT(UCSRC_temp , UCSRC_UCSZ0);
	SET_BIT(UCSRC_temp , UCSRC_UCSZ1);

	UCSRC = UCSRC_temp;
	/*BR = 9600*/
	UBRRL = 51;
}


void UART_VidSend(u8 cpy_data){
	while(GET_BIT(UCSRA , UCSRA_UDRE) == 0);
		UDR = cpy_data;
}

u8 UART_VidRec(void){
	while(GET_BIT(UCSRA , UCSRA_RXC) == 0);
		return UDR;
}


void UART_VidRec_INT(u8 cpy_u8State){
	if(cpy_u8State == enable){
		SET_BIT(UCSRB , UCSRB_RXCIE);
	}

	else if(cpy_u8State == disable){
		CLR_BIT(UCSRB , UCSRB_RXCIE);
	}
}

u8 *UART_DataPtr = NULL;

static void (*UART_SetCallBackFunc)(void) = NULL ;

void UART_SetCallBack(void(*Copy_pCallBackFunction)(void) , u8 *Cpy_DataPtr){

	if(Copy_pCallBackFunction != NULL){

		UART_SetCallBackFunc = Copy_pCallBackFunction;
		UART_DataPtr = Cpy_DataPtr;
	}
}

void __vector_13(void) __attribute__((signal));

void __vector_13(void){

	if(UART_SetCallBackFunc != NULL){

		*UART_DataPtr = UDR;
		UART_SetCallBackFunc();
	}
}



void UART_VidSendString(const char* Copy_pcString ) {


	for (int i = 0 ; Copy_pcString[i]!='\0' ; i++){

		UART_VidSend(Copy_pcString[i]) ;
	}
}


void UART_VidReceiveString(char* Copy_pcString ) {
	u8 x;
	for (int i = 0 ; Copy_pcString[i]!='\0' ; i++){

		Copy_pcString[i] = 0 ;
	}

	for (int i = 0 ; x != '\r' ; i++){

		Copy_pcString[i] = UART_VidRec();
		x = Copy_pcString[i];
	}

}






