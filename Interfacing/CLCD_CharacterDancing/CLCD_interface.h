#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_VidSendCommand(u8 Copy_u8Command);
void CLCD_VidSendData(u8 Copy_u8Data);
void CLCD_VidInit(void);
void CLCD_VidGotoXY(u8 Copy_u8Xpos,u8 Copy_u8YPos);
void CLCD_VidWriteSpecialCharacter(u8 * copy_pu8pattern,u8 Copy_Patternnumber ,u8 Copy_u8Xpos,u8 Copy_u8YPos);
void CLCD_String (u8 *str);
void CLCD_Clear();

u8 customChar[] = {
		  0x0E,
		  0x0E,
		  0x14,
		  0x0E,
		  0x05,
		  0x0A,
		  0x0A,
		  0x1B
};
u8 customChar2[] = {
  0x0E,
  0x0E,
  0x05,
  0x06,
  0x0C,
  0x1D,
  0x0A,
  0x18
};




#endif
