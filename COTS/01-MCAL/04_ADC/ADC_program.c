#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_VoidIntit(){

	/*select Ref*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*select Adjust*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*select 128 Prescaler*/
	SET_BIT(ADCSRA ,ADCSRA_ADPS2);
	SET_BIT(ADCSRA ,ADCSRA_ADPS1);
	SET_BIT(ADCSRA ,ADCSRA_ADPS0);

	/*Enable module*/
	SET_BIT(ADCSRA ,ADCSRA_ADEN);
}
                                           /*********************************************************************************/

u8 ADC_u8ReadChannel (u8 Copy_u8Channel){

	u16 local_timeOut = 0 ;
	/*** Select channel ***/

	/* Clear the 5 bits first */
	ADMUX &= 0b11100000;	                          //clear first bit
	/* Put channel ID in the 5 bits*/
	ADMUX |= Copy_u8Channel;

	/*** Start conversion  ***/	                                              //start conversion
	SET_BIT(ADCSRA , ADCSRA_ADSC);

	/*** Wait conversion  ***/                                                //wait conversion
	while(!GET_BIT(ADCSRA , ADCSRA_ADIF) && (local_timeOut < 20000));
	{
		local_timeOut++;
	}
	/*** Clear complete flag  ***/                                            /*Clear Flag*/
	SET_BIT(ADCSRA , ADCSRA_ADIF);

	/*** Return value   ***/
	return ADCH;


}
                                          /*********************************************************************************/

s32 map (s32 Cpy_InputMini , s32 Cpy_InputMax , s32 Cpy_OutMini , s32 Cpy_OutMax ,  s32 Cpy_val)
{
	s32 local_holder = Cpy_val - Cpy_InputMax ;
	local_holder *= (Cpy_OutMini - Cpy_OutMax);
	local_holder /= (Cpy_InputMini - Cpy_InputMax);
	local_holder += Cpy_OutMax ;
	return local_holder;
}

