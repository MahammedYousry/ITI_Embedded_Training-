#ifndef TIMR_INTERFACE_H_
#define TIMR_INTERFACE_H_

void TIMR_VidInit(void);
void TIMR_VidInit_FastPWM();
void TIMR_VidSetCompareMatch(u8 Copy_vidDuty);
void TIMR_VidInit_PhaseCorrectPWM();

void TIMR1_VidInit();
void TIMR_VidSetICR(u16 Copy_u16TOP);
void TIMR_VidSetOCR(u16 Copy_u16OCR);

#endif
