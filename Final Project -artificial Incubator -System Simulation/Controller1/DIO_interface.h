
#ifndef    DIO_INTERFACE_H_
#define    DIO_INTERFACE_H_
typedef enum{
	input,
	output,
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	Low=0,
	High,
	Low_Port=0x00,
	High_Port=0xff,
	Pin_0=0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7
}enut_DIO;

/*set_Pin*/
void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8Value);
void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection);
void DIO_VidGetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 *Copy_Pu8PinValue);

/*set_Port*/
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8PortDirection);
void DIO_VidGetPortValue(u8 Copy_u8Port,u8 *Copy_Pu8PortValue);

/*other*/
//toggel




#endif
















