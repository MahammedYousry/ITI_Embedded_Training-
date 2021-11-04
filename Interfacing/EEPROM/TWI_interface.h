#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void TWI_VidInitMaster(u8 cpy_u8Address);

void TWI_VidInitSlave(u8 cpy_u8Address);

void TWI_SendStartCondition(void);

void TWI_MasterSendAddress( u8 cpy_u8Address , u8 cpy_u8Operation);

void TWI_MasterSendData( u8 cpy_u8Data );

u8 TWI_MasterReadData(void);

void TWI_SendStopCondition(void);



#endif
