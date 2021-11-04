/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
typedef enum
{
	input , /*0*/
	output =1 , /*1*/
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	low =0,
	high =1,
	pin0 = 0,
	pin1 ,
	pin2 ,
	pin3 ,
	pin4 ,
	pin5 ,
	pin6,
	pin7

}enut_DIO;

/*set_pin*/

void DIO_VidSetPinValue(u8 copy_u8port , u8 Copy_u8Value , u8 Copy_u8PinNumber);
void DIO_VidSetPinDirection(u8 copy_u8port , u8 Copy_u8PinNumber , u8 Copy_u8PinDeriction);
void DIO_VidGetPinValue(u8 copy_u8port , u8 Copy_u8PinNumber,u8 *Copy_pu8PinValue);


/*Set_Port*/

void DIO_VidSetPortValue(u8 copy_u8port , u8 Copy_u8Value );
void DIO_VidSetPortDirection(u8 copy_u8port , u8 Copy_u8PortDeriction );
void DIO_VidGetPortValue(u8 copy_u8port , u8 *Copy_Pu8PortValue );




#endif
