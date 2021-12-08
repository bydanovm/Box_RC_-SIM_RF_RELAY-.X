// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_GSM_H
#define XC_GSM_H

#include "config.h"
//#include "lcd.h"

#define TXpin PORTCbits.RC6
#define RXpin PORTCbits.RC7

unsigned char aBuff_Uart[96], cBuff, tmp;
//unsigned char aBuff_Phone[] = "123456789012";
unsigned char aBuff_DateTime[] = "01/12/31,00:00";
unsigned char aBuff_TextMessage[] = "1234567890";
unsigned char aBuff_Number_Message;

int _counter;
short int _countLCD;
    
void GSM_USART_Transmit(unsigned char tx_byte);
void GSM_USART_Transmit_Arr(unsigned char *tx_buff, unsigned int tx_len);
void GSM_USART_Transmit_Str(char *str_buff);

char GSM_Init();
void GSM_Read_Message(unsigned char number_message);
__bit GSM_Get_String(unsigned char type_parsing);
void GSM_ClearBuffer();
void GSM_Display_Message(char countTime);
__bit GSM_Command(char* command);

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif  /* XC_HEADER_TEMPLATE_H */