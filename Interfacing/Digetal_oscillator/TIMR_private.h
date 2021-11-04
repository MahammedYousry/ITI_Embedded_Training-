#ifndef   TIMR_PRIVATE_H_
#define  TIMR_PRIVATE_H_

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

#define TIMSK_OCIE0_PIN        1         //timer counter output compare match interrupt ( enable ) 


#define OCR0  *((volatile u8 *) 0x5C)

#define TIFR  *((volatile u8 *) 0x58)     //Timer Interrupt Flag Register  

#define TIFR_OCF0         1                     //Output Compare Flag 
#define NULL 0


#endif
