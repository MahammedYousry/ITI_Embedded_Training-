#ifndef     ADC_INTERFACE_H_
#define		ADC_INTERFACE_H_



typedef enum channel{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
};

void ADC_int(void);

u8 ADC_Read(u8 channel);







#endif
