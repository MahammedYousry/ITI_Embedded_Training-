#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

u8 ADC_u8ReadChannel (u8 Copy_u8Channel);
void ADC_VoidIntit();
s32 map (s32 Cpy_InputMini , s32 Cpy_InputMax , s32 Cpy_OutMini , s32 Cpy_OutMax ,  s32 Cpy_val);

                                  /*********************************************************************************/


#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
                                  /*********************************************************************************/

typedef enum{
	ADC_0 = 0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
}enChannel_t;



#endif
