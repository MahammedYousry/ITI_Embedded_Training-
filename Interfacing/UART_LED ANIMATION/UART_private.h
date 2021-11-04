/*
 *  Created on: Aug 16, 2021
 *  Author: mahamed youssry
 */
//file Guard

#ifndef   UART_PRIVATE_H_
#define  UART_PRIVATE_H_


#define UDR *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UBRRL *((volatile u8 *)0x29)
#define OSCCAL *((volatile u8 *)0x51)
#define OCDR *((volatile u8 *)0x51)
#define UBRRH *((volatile u8 *)0x40)
#define UCSRC *((volatile u8 *)0x40)

#define UCSRC_URSEL_PIN      7
#define UCSRC_UMSEL_PIN      6
#define UCSRC_UPM1_PIN       5
#define UCSRC_UPM0_PIN       4
#define UCSRC_USBS_PIN       3
#define UCSRC_UCSZ1_PIN      2
#define UCSRC_UCSZ0_PIN      1
#define UCSRC_UCPOL_PIN      0

#define UBRRH_URSEL_PIN      7

#define UCSRA_RXC_PIN        7
#define UCSRA_TXC_PIN        6
#define UCSRA_UDRE_PIN       5
#define UCSRA_FE_PIN         4
#define UCSRA_DOR_PIN        3
#define UCSRA_PE_PIN         2
#define UCSRA_U2X_PIN        1
#define UCSRA_MPCM_PIN       0

#define UCSRB_RXCIE_PIN      7
#define UCSRB_TXCIE_PIN      6
#define UCSRB_UDRIE_PIN      5
#define UCSRB_RXEN_PIN       4
#define UCSRB_TXEN_PIN       3
#define UCSRB_UCSZ2_PIN      2
#define UCSRB_RXB8_PIN       1
#define UCSRB_TXB8_PIN       0

#endif
