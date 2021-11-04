#include"lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include"avr/delay.h"
                                        /*********************************************************************************/
																		/*Init Master*/
void SPI_VoidInitMaster(){

	     /*Disable interrupt*/
	CLEAR_BIT(SPCR , SPCR_SPIE_PIN);

		/*MBS first*/
	CLEAR_BIT(SPCR , SPCR_DORD_PIN);

		/*master select*/
	SET_BIT(SPCR ,SPCR_MSTR_PIN);

		/*idle low */
	CLEAR_BIT(SPCR ,SPCR_CPOL_PIN);

		/*Sample at leading edge*/
	CLEAR_BIT(SPCR ,SPCR_CPHA_PIN);

		/*Freq / 16*/
	CLEAR_BIT(SPCR ,SPCR_SPR1_PIN);
	SET_BIT(SPCR ,SPCR_SPR0_PIN);
	CLEAR_BIT(SPSR ,SPSR_SPI2X_PIN);

		/*SPI Enable*/
	SET_BIT(SPCR ,SPCR_SPE_PIN);

}





                                        /*********************************************************************************/
																		/*Initial Slave*/
void SPI_VoidInitSlave(){

    	/*Disable interrupt*/
	CLEAR_BIT(SPCR , SPCR_SPIE_PIN);

		/*MBS first*/
	CLEAR_BIT(SPCR , SPCR_DORD_PIN);

		/*Slave select*/
	CLEAR_BIT(SPCR ,SPCR_MSTR_PIN);

		/*idle low */
	CLEAR_BIT(SPCR ,SPCR_CPOL_PIN);

		/*Sample at leading edge*/
	CLEAR_BIT(SPCR ,SPCR_CPHA_PIN);

		/*SPI Enable*/
	SET_BIT(SPCR ,SPCR_SPE_PIN);

}


                                        /*********************************************************************************/

u8 SPI_u8Transceive(u8 CPY_Data){

	/*Send Data*/
	SPDR = CPY_Data;

	/*Wait till Data is sent*/
	while(GET_BIT(SPSR ,SPSR_SPIF_PIN) == 0);

	/*Return Received Data*/
	return SPDR ;
}
										/*********************************************************************************/







