#include"lib/STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include"avr/delay.h"


void CLCD_VidSendCommand(u8 Copy_u8Command){
	/*Set RS pin as low*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low,CLCD_RS_PIN);

	/*Set RW pin as low to write*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low,CLCD_RW_PIN);
	/*Send command to data pin D0 to D7*/
	DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Set Enable Pin */
	DIO_VidSetPinValue(CLCD_CTRL_PORT,high,CLCD_E_PIN);

	/*Set delay */
	_delay_ms(3);
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low,CLCD_E_PIN);

}
void CLCD_VidSendData(u8 Copy_u8Data){
	/*Set RS pin as low*/
		DIO_VidSetPinValue(CLCD_CTRL_PORT,high,CLCD_RS_PIN);

		/*Set RW pin as low to write*/
		DIO_VidSetPinValue(CLCD_CTRL_PORT,low,CLCD_RW_PIN);

		/*Send command to data pin D0 to D7*/

		DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);

		/*Set Enable Pin */
		DIO_VidSetPinValue(CLCD_CTRL_PORT,high ,CLCD_E_PIN);

		/*Set delay */
		_delay_ms(3);

		DIO_VidSetPinValue(CLCD_CTRL_PORT,low,CLCD_E_PIN);


}
void CLCD_VidInit(void){
	_delay_ms(40);
	/*function Set*/
	CLCD_VidSendCommand(0b00111111);
	/*Display on off*/
	CLCD_VidSendCommand(0b00001100);
	/*Display clear*/
	CLCD_VidSendCommand(1);

}
void CLCD_VidGotoXY(u8 Copy_u8Xpos,u8 Copy_u8YPos){
	u8 Local_u8address =0;
	if(Copy_u8Xpos==0){
		Local_u8address=Copy_u8YPos;

	}
	else if(Copy_u8Xpos==1){

		Local_u8address=0x40 + Copy_u8YPos;



	}
	CLCD_VidSendCommand(0b10000000+Local_u8address);


}
void CLCD_String (u8 *str){
	u8 i =0;
	for (i=0;str[i]!=0;i++){
	CLCD_VidSendData(str[i]);
	}
}

void CLCD_Clear(){
	CLCD_VidSendCommand (0x01);		/* clear display */
	CLCD_VidSendCommand (0x80);		/* cursor at home position */


}





