#include "lib/BIT_MATH.h"
#include "lib/STD_TYPES.h"
#include "TIMR_private.h"
#include "TIMR_config.h"
#include "TIMR_interface.h"



                           /*************************************************************************/
                                                   /*Initial for CTC mode*/
/*void TIMR_VidInit(void)
{
	//select mode(CTC)

	CLEAR_BIT(TCCR0 ,TCCR0_WGM00_PIN);
	SET_BIT(TCCR0 ,TCCR0_WGM01_PIN)  ;

	//timer interrupt enable

	SET_BIT(TIMSK , TIMSK_OCIE0_PIN) ;


	//OCR
	OCR0 =250;    //4000 count for 1 second


	//Set timer prescaller

	SET_BIT(TCCR0 , TCCR0_CS00_PIN);
	CLEAR_BIT(TCCR0 , TCCR0_CS01_PIN)  ;
	SET_BIT(TCCR0 , TCCR0_CS02_PIN);
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

//void TIMR_VidInit_FastPWM(){
	/* Select Fast pwm mode  */
	//SET_BIT(TCCR0 ,TCCR0_WGM00_PIN);
//	SET_BIT(TCCR0 ,TCCR0_WGM01_PIN);

//	/* Interrupt Disable */
//	CLEAR_BIT(TIMSK , TIMSK_OCIE0_PIN);

//	/* Select inverted or non_inverted mode */
//	SET_BIT(TCCR0 , TCCR0_COM01_PIN);
//	CLEAR_BIT(TCCR0 , TCCR0_COM00_PIN);				/*Set in Top , Clear in Compare*/

	///*Select the Prescaller*/
//	SET_BIT(TCCR0 , TCCR0_CS00_PIN);
//	SET_BIT(TCCR0 , TCCR0_CS01_PIN);                /*The prescaller is CK/64*/
//	CLEAR_BIT(TCCR0 , TCCR0_CS02_PIN);


//}

//void TIMR_VidSetCompareMatch(u8 Copy_vidDuty){

//	OCR0 = Copy_vidDuty;

//}

                                           /*************************************************************************/
                                                              /*Initial for Phase Correct PMW mode*/
/*
void TIMR_VidInit_PhaseCorrectPWM(){
	/* Select Phase Correct pwm mode  */
	/*SET_BIT(TCCR0 ,TCCR0_WGM00_PIN);
	CLEAR_BIT(TCCR0 ,TCCR0_WGM01_PIN);

	/* Interrupt Disable */
//	CLEAR_BIT(TIMSK , TIMSK_OCIE0_PIN);

	/* Select Compare Output Mode */
//	SET_BIT(TCCR0 , TCCR0_COM01_PIN);
//	CLEAR_BIT(TCCR0 , TCCR0_COM00_PIN);				/*Set in downcounting , Clear in up-counting*/
//
	/*Select the Prescaller*/
	//SET_BIT(TCCR0 , TCCR0_CS00_PIN);
//	SET_BIT(TCCR0 , TCCR0_CS01_PIN);                /*The prescaller is CK/64*/
	//CLEAR_BIT(TCCR0 , TCCR0_CS02_PIN);


//}

//*/
                                            /*************************************************************************/

void TIMR1_VidInit(){

		//set fast pwm non _inverting
	SET_BIT(TCCR1A ,TCCR0_COM1A1_PIN);
	CLEAR_BIT(TCCR1A ,TCCR0_COM1A0_PIN);

	//select wave generation mode
	CLEAR_BIT(TCCR1A ,TCCR0_WGM10_PIN);
	SET_BIT(TCCR1A ,TCCR0_WGM11_PIN);
	SET_BIT(TCCR1B ,TCCR0_WGM12_PIN);
	SET_BIT(TCCR1B ,TCCR0_WGM13_PIN);

	//Select prescaller
	CLEAR_BIT(TCCR1B ,TCCR0_CS10_PIN);
	SET_BIT(TCCR1B ,TCCR0_CS11_PIN);
	CLEAR_BIT(TCCR1B ,TCCR0_CS12_PIN);

}

void TIMR_VidSetICR(u16 Copy_u16TOP){
	ICR1L = Copy_u16TOP;
}

void TIMR_VidSetOCR(u16 Copy_u16OCR){

	OCR1AL = Copy_u16OCR;

}

                                         /*************************************************************************/
															             /*ICU*/
void ICU_INIT(){

	//select wave generation mode  normal
	CLEAR_BIT(TCCR1A ,TCCR0_WGM10_PIN);
	CLEAR_BIT(TCCR1A ,TCCR0_WGM11_PIN);
	CLEAR_BIT(TCCR1B ,TCCR0_WGM12_PIN);
	CLEAR_BIT(TCCR1B ,TCCR0_WGM13_PIN);

	//Input Capture Noise Canceler
	SET_BIT(TCCR1B ,TCCR0_ICNC1_PIN);

	//Input Capture raising Edge
	SET_BIT(TCCR1B ,TCCR0_ICES1_PIN);

	//Select prescaller
	CLEAR_BIT(TCCR1B ,TCCR0_CS10_PIN);
	SET_BIT(TCCR1B ,TCCR0_CS11_PIN);
	CLEAR_BIT(TCCR1B ,TCCR0_CS12_PIN);
	// Input Capture Interrupt Enable
	SET_BIT(TIMSK , TIMSK_TICIE1_PIN );

}
static void (*TIMR1_SetCallbackFunc)(void) =NULL;

void TIMR1_SetCallBack(void(*copy_Pcallback)(void))
{

	if(copy_Pcallback !=NULL)
	{
		TIMR1_SetCallbackFunc=copy_Pcallback;
	}
}



void __vector_9(void)__attribute__((signal));

void __vector_9(void)
{

if(TIMR1_SetCallbackFunc != NULL)
	{
		TIMR1_SetCallbackFunc();
	}

}

