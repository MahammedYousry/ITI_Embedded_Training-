#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include "TIMR_private.h"
#include "TIMR_config.h"
#include "TIMR_interface.h"



                           /*************************************************************************/
                                                   /*Initial for CTC mode*/
void TIMR_VidInit(void)
{
	//select mode(CTC)

	CLEAR_BIT(TCCR0 ,TCCR0_WGM00_PIN);
	SET_BIT(TCCR0 ,TCCR0_WGM01_PIN)  ;

	//timer interrupt enable

	SET_BIT(TIMSK , TIMSK_OCIE0_PIN) ;


	//OCR
	OCR0 =250;    //4000 count for 1 second


	//Set timer prescaller

	CLEAR_BIT(TCCR0 , TCCR0_CS00_PIN);
	SET_BIT(TCCR0 , TCCR0_CS01_PIN)  ;
	CLEAR_BIT(TCCR0 , TCCR0_CS02_PIN);
}


static void (*TIMR0_SetCallbackFunc)(void) =NULL;

void TIMR0_SetCallBack(void(*copy_Pcallback)(void))
{

	if(copy_Pcallback !=NULL)
	{
		TIMR0_SetCallbackFunc=copy_Pcallback;
	}
}



void __vector_10(void)__attribute__((signal));

void __vector_10(void)
{

if(TIMR0_SetCallbackFunc != NULL)
	{
		TIMR0_SetCallbackFunc();
	}

}


                              /*************************************************************************/
                                                   /*Initial for Fast PMW mode*/

void TIMR_VidInit_FastPWM(){
	/* Select Fast pwm mode  */
	SET_BIT(TCCR0 ,TCCR0_WGM00_PIN);
	SET_BIT(TCCR0 ,TCCR0_WGM01_PIN);

	/* Interrupt Disable */
	CLEAR_BIT(TIMSK , TIMSK_OCIE0_PIN);

	/* Select inverted or non_inverted mode */
	SET_BIT(TCCR0 , TCCR0_COM01_PIN);
	CLEAR_BIT(TCCR0 , TCCR0_COM00_PIN);				/*Set in Top , Clear in Compare*/

	/*Select the Prescaller*/
	SET_BIT(TCCR0 , TCCR0_CS00_PIN);
	SET_BIT(TCCR0 , TCCR0_CS01_PIN);                /*The prescaller is CK/64*/
	CLEAR_BIT(TCCR0 , TCCR0_CS02_PIN);


}

void TIMR_VidSetCompareMatch(u8 Copy_vidDuty){

	OCR0 = Copy_vidDuty;

}

                                           /*************************************************************************/
                                                              /*Initial for Phase Correct PMW mode*/

void TIMR_VidInit_PhaseCorrectPWM(){
	/* Select Phase Correct pwm mode  */
	SET_BIT(TCCR0 ,TCCR0_WGM00_PIN);
	CLEAR_BIT(TCCR0 ,TCCR0_WGM01_PIN);

	/* Interrupt Disable */
	CLEAR_BIT(TIMSK , TIMSK_OCIE0_PIN);

	/* Select Compare Output Mode */
	SET_BIT(TCCR0 , TCCR0_COM01_PIN);
	CLEAR_BIT(TCCR0 , TCCR0_COM00_PIN);				/*Set in downcounting , Clear in up-counting*/

	/*Select the Prescaller*/
	SET_BIT(TCCR0 , TCCR0_CS00_PIN);
	SET_BIT(TCCR0 , TCCR0_CS01_PIN);                /*The prescaller is CK/64*/
	CLEAR_BIT(TCCR0 , TCCR0_CS02_PIN);


}


                                            /*************************************************************************/




