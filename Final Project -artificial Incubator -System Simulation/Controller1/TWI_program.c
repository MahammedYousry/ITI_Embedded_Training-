#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "TWI_private.h"


void TWI_VidInitMaster(u8 cpy_u8Address){

	/*freq = 400 kbps*/
	TWBR = 2 ;
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/*Assign address*/
	if(cpy_u8Address > 0){
		TWAR = (cpy_u8Address<<1);
	}

	/*enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);
}

void TWI_VidInitSlave(u8 cpy_u8Address){

	/*Assign address*/
	if(cpy_u8Address > 0){
		TWAR = (cpy_u8Address << 1);
	}

	/*enable TWI*/
	SET_BIT(TWCR , TWCR_TWEN);
}

void TWI_SendStartCondition(void){
	/*set start condition*/
	SET_BIT(TWCR , TWCR_TWSTA);

	/*start after clearing the flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*wait till job is complete */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*chick if correct*/
}

void TWI_MasterSendAddress( u8 cpy_u8Address , u8 cpy_u8Operation){

	u8 local_u8Address;

	/*set address*/
	local_u8Address = (cpy_u8Address<<1) | cpy_u8Operation ;
	TWDR = local_u8Address;

	/*clear */
	CLR_BIT(TWCR , TWCR_TWSTA);

	/*start after clearing the flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*wait till job is complete */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);
}

void TWI_MasterSendData( u8 cpy_u8Data ){

	/*write data*/
	TWDR = cpy_u8Data ;

	/*start after clearing the flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*wait till job is complete */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);
}

u8 TWI_MasterReadData(void){

	/*start after clearing the flag*/
	SET_BIT(TWCR , TWCR_TWINT);

	/*wait till job is complete */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	/*read data*/
	return TWDR ;
}


void TWI_SendStopCondition(void){

	/*stop indicate*/
	SET_BIT(TWCR , TWCR_TWSTO);

	/*start after clearing the flag*/
	SET_BIT(TWCR , TWCR_TWINT);
}





