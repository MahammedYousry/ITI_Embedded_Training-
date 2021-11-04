#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"




/*initialization*/

void ADC_int(void){
	/*Voltage Reference Selections for ADC*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*The ADC Data Register*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*ADC Prescaler Selections*/
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


/*ADC read*/

u8 ADC_Read(u8 channel){

	/*set channel value in  ADMUX*/
	ADMUX &= 0b11100000 ;
	ADMUX |= (channel<<ADMUX_MUX0);

	/*ADC Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*wait for Conversion flag*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

	/*clear flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*return result*/
	return ADCH;
}

























