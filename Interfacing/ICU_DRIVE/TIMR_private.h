#ifndef   TIMR_PRIVATE_H_
#define  TIMR_PRIVATE_H_


                                          /*************************************************************************/
																		/*Define Timer 0*/


#define TCCR0  *((volatile u8 *) 0x53)  // Timer Counter Control register

#define TCCR0_WGM00_PIN    6			//Wave generation mode bit 0
#define TCCR0_WGM01_PIN    3         //Wave generation mode bit 1

#define TCCR0_COM00_PIN     4        //Compare Match output bit 0  ()
#define TCCR0_COM01_PIN     5        //Compare Match output bit 1

#define TCCR0_CS00_PIN     0           //Timer Clock select bit 0  (prescaller)
#define TCCR0_CS01_PIN     1           //Timer Clock select bit 1
#define TCCR0_CS02_PIN     2           //Timer Clock select bit 2 


#define OCR0  *((volatile u8 *) 0x5C)    //output compare register  


#define TIMSK  *((volatile u8 *) 0x59)   //Timer counter interrupt mask   (mask or non maskable)
#define TIMSK_TICIE1_PIN        5
#define TIMSK_OCIE0_PIN        1         //timer counter output compare match interrupt ( enable ) 


#define OCR0  *((volatile u8 *) 0x5C)

#define TIFR  *((volatile u8 *) 0x58)     //Timer Interrupt Flag Register  

#define TIFR_OCF0         1                     //Output Compare Flag 
#define NULL 0

                                          /*************************************************************************/
																		/*Define Timer 1*/


#define TCCR1A  *((volatile u8 *) 0x4F)
#define TCCR0_COM1A1_PIN    7
#define TCCR0_COM1A0_PIN    6
#define TCCR0_COM1B1_PIN    5
#define TCCR0_COM1B0_PIN    4
#define TCCR0_FOC1A_PIN     3
#define TCCR0_FOC1B_PIN     2
#define TCCR0_WGM11_PIN     1
#define TCCR0_WGM10_PIN     0


#define TCCR1B *((volatile u8 *) 0x4E)

#define TCCR0_ICNC1_PIN    7
#define TCCR0_ICES1_PIN    6
#define TCCR0_WGM13_PIN    4
#define TCCR0_WGM12_PIN    3
#define TCCR0_CS12_PIN     2
#define TCCR0_CS11_PIN     1
#define TCCR0_CS10_PIN     0

#define OCR1AL *((volatile u16 *) 0x4A)
#define ICR1L *((volatile u16 *) 0x46)

#define  TCNT1H   (*((volatile u8 *) 0x4D))
#define  TCNT1L   (*((volatile u8 *) 0x4C))
#define  OCR1BL   (*((volatile u16 *) 0x48))
#define  TCNT1    (*((volatile u16 *)0x4c))



#endif
