#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_
#define NOT_PRESSED 101
#define    KPD_u8ARR               {                 \
                                   {'7','8','9','/'},\
                                   {'4','5','6','*'},\
                                   {'1','2','3','-'},\
                                   {'C','0','=','+'} \
                                   } ;


#define KPD_u8PORT                Port_D
/*The columns pins*/
#define KPD_u8COLUMN0_PIN         pin0
#define KPD_u8COLUMN1_PIN         pin1
#define KPD_u8COLUMN2_PIN         pin2
#define KPD_u8COLUMN3_PIN         pin3
/*The rows pins*/
#define KPD_u8ROW0_PIN         pin4
#define KPD_u8ROW1_PIN         pin5
#define KPD_u8ROW2_PIN         pin6
#define KPD_u8ROW3_PIN         pin7

#endif
