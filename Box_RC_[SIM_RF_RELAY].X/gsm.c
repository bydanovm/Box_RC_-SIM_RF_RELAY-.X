#include "gsm.h"
#include "lcd.h"

void GSM_USART_Transmit(unsigned char tx_byte){
    while(!TRMT);
    TXREG = tx_byte;
}

void GSM_USART_Transmit_Arr(unsigned char *tx_buff, unsigned int tx_len){
    unsigned int cnt = 0;
    while(cnt<tx_len){
        GSM_USART_Transmit(tx_buff[cnt]);
        cnt++;
    }
}

void GSM_USART_Transmit_Str(char *str_buff){
    unsigned char i = 0;
    while(str_buff[i] != 0){
        GSM_USART_Transmit(str_buff[i++]);
    }
}


char GSM_Init(){
    char _init = 1;
    
/////////////////////////Блок для отладки сообщений/////////////////////////////
//    GSM_USART_Transmit_Str("AT+CSCB?\r\n");
//    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
//    __delay_ms(5);
//    return 1;
////////////////////////////////////////////////////////////////////////////////
    
    GSM_USART_Transmit_Str("AT\r\n"); //Начало опроса модема
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//1
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//2
    
    GSM_USART_Transmit_Str("ATE0\r\n"); //Отключить ЭХО
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//2
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//3
    
    GSM_USART_Transmit_Str("AT+CMGF=1\r\n"); //Включить текстовый режим 
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//3
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//4
    
    GSM_USART_Transmit_Str("AT+CSCS=\"GSM\"\r\n"); //Кодировка GSM
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//4
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//5
    
    GSM_USART_Transmit_Str("AT+GSMBUSY=0\r\n"); //Запрет входящих звонков
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//5
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//6
    
    GSM_USART_Transmit_Str("AT+CLTS=1\r\n"); //Считывать время от оператора
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//6
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//7
    
    GSM_USART_Transmit_Str("AT&W\r\n"); //Сохранить настройки
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) return _init;//7
    _counter = 0;
    __delay_ms(5);
    GSM_ClearBuffer();
    _init++;//8
    
//    GSM_USART_Transmit_Str("AT+CMGR=1\r\n"); //Прочитать СМС под номером 1
//    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
//    __delay_ms(5);
//    GSM_USART_Transmit_Str("AT+CPMS?\r\n"); //Узнать сколько места свободно на сим-карте
//    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
//    __delay_ms(5);
    
//    GSM_USART_Transmit_Str("AT+CREG?\r\n");
//    while(!(strstr(aBuff_Uart, "+CREG:"))&&(_counter <= 500)){_counter++;};
//    _init = 2;
//    GSM_ClearBuffer();





//    GSM_USART_Transmit_Str("AT+CSQ\r\n");
//    while(!(strstr(aBuff_Uart, "+CSQ:"))&&(_counter <= 500)){_counter++;};
//    GSM_ClearBuffer();
//    _init = 4;


//    GSM_USART_Transmit_Str("AT+CPAS\r\n");
//    while(!(strstr(aBuff_Uart, "+CPAS:"))&&(_counter <= 500)){_counter++;};
//    __delay_ms(5);
//    GSM_ClearBuffer();
//    _init = 5;


//    GSM_USART_Transmit_Str("AT+CBC\r\n");
//    while(!(strstr(aBuff_Uart, "+CSQ:"))&&(_counter <= 500)){_counter++;};
//    __delay_ms(5);
//    GSM_ClearBuffer();
//    _init = 6;

    

        
    return _init;
}

void GSM_Read_Message(unsigned char number_message){
    char string[12];
    sprintf(string,"AT+CMGR=%u%s",number_message,"\r\n");
    GSM_USART_Transmit_Str(string); //Прочитать СМС под номером 'number_message'
    while(!(strstr(aBuff_Uart, "+CMGR"))&&(_counter <= 2500)){_counter++;};
    __delay_ms(50);
//    if(_counter>=500) {
//        GSM_ClearBuffer();
//        GSM_USART_Transmit_Str("AT+CMGR=1\r\n");
//        while(!(strstr(aBuff_Uart, "+CMGR"))&&(_counter <= 1000)){_counter++;};
//    }
//    __delay_ms(15);  
//    return string;
}

__bit GSM_Get_String(unsigned char type_parsing){
    
//    for (char i = 0; i <= sizeof(aBuff_Phone[i]); i++) {
//        if(i == sizeof(aBuff_Phone)) aBuff_Phone[i] = '\0';
//        else aBuff_Phone[i] = ' ';
//    }
    for (char i = 0; i <= sizeof(aBuff_DateTime); i++) {
        if(i == (sizeof(aBuff_DateTime))) aBuff_DateTime[i] = '\0';
        else aBuff_DateTime[i] = ' ';
    }
    for (char i = 0; i <= sizeof(aBuff_TextMessage); i++) {
        if(i == sizeof(aBuff_TextMessage)) aBuff_TextMessage[i] = '\0';
        else aBuff_TextMessage[i] = ' ';
    }
    __delay_ms(100);
    switch(type_parsing){
        case 1:
            for(unsigned char i = 0; i < sizeof(aBuff_Uart); i++){
//                if(aBuff_Uart[i] == 0x2B && aBuff_Uart[i+1] == 0x37 && aBuff_Uart[i+2] == 0x39){ // +79
//                    sprintf(aBuff_Phone, "%11.12s", &aBuff_Uart[i]);
////                    for(unsigned char y = 0; y <= sizeof(aBuff_Phone); y++){
////                        if(y == sizeof(aBuff_Phone)) aBuff_Phone[y] = '\0';
////                        else aBuff_Phone[y] = aBuff_Uart[i+y];
////                    }
//                }
                if(aBuff_Uart[i] == 0x22 && aBuff_Uart[i+1] == 0x0D){ // "\r
//                    sprintf(aBuff_DateTime, "%13.14s", &aBuff_Uart[i-20]);
                    sprintf(aBuff_TextMessage, "%1.10s", &aBuff_Uart[i+3]);
//                    for(unsigned char y = 0; aBuff_DateTime[y] != 0; y++){
//                        aBuff_DateTime[y] = aBuff_Uart[i-(unsigned char)20+y];
//                    }
//                    for(unsigned char y = 0; aBuff_TextMessage[y] != 0; y++){
//                        if(aBuff_Uart[i+(unsigned char)4+y] == 0x0A || aBuff_Uart[i+(unsigned char)4+y] == 0x0D) aBuff_TextMessage[y+(unsigned char)1] = 0;
//                        aBuff_TextMessage[y] = aBuff_Uart[i+(unsigned char)3+y];
//                    }
                    GSM_ClearBuffer();
//                    break;
                    return TRUE;
                }
            }
            return FALSE;
//            break;
        case 2:
            for(unsigned char i = 0; i < sizeof(aBuff_Uart); i++){
                if(aBuff_Uart[i] == 'C' && aBuff_Uart[i+(unsigned char)1] == 'C' && aBuff_Uart[i+(unsigned char)2] == 'L'  && aBuff_Uart[i+(unsigned char)3] == 'K'){ // "\r
                    sprintf(aBuff_DateTime, "%13.14s", &aBuff_Uart[i+7]);
//                    for(unsigned char y = 0; y <= sizeof(aBuff_DateTime); y++){
//                        if(y == sizeof(aBuff_DateTime)) aBuff_DateTime[y] = '\0';
//                        else aBuff_DateTime[y] = aBuff_Uart[i+(unsigned char)7+y];
                        
                        
//                    }
                    GSM_ClearBuffer();
//                    break;
                    return TRUE;
                }
            }
            return FALSE;
//            break;
//        case 3:
//            for(unsigned char i = 0; i < sizeof(aBuff_Uart); i++){
//                if(aBuff_Uart[i] == 'C' && aBuff_Uart[i+(unsigned char)1] == 'P' && aBuff_Uart[i+(unsigned char)2] == 'M'  && aBuff_Uart[i+(unsigned char)3] == 'S'){ // "\r
//                    for(unsigned char y = 0; y <= sizeof(aBuff_TextMessage) - 4; y++){
//                        if(y == sizeof(aBuff_TextMessage) - 4) aBuff_TextMessage[y] = '\0';
//                        else  aBuff_TextMessage[y] = aBuff_Uart[i+(unsigned char)7+y];
//                    }
//                    GSM_ClearBuffer();
//                    break;
//                }
//            }
//            break;
        case 9:
//            if(strlen(aBuff_Uart) > 0){
                for(unsigned char i = 0; i < sizeof(aBuff_Uart); i++){
                    if(aBuff_Uart[i] == 'C' && aBuff_Uart[i+(unsigned char)1] == 'M' && aBuff_Uart[i+(unsigned char)2] == 'T'  && aBuff_Uart[i+(unsigned char)3] == 'I'){ // "\r
//                        for(unsigned char y = 0; y <= 6; y++){
//                            if(y == 6) aBuff_TextMessage[y] = '\0';
//                            else aBuff_TextMessage[y] = aBuff_Uart[i+(unsigned char)y + 6];
                        aBuff_Number_Message = (unsigned char)aBuff_Uart[i+11] - '0';
//                        aBuff_TextMessage[0] = aBuff_Uart[i+11];
//                        aBuff_TextMessage[1] = '\0';
//                        }
                        GSM_ClearBuffer();
//                        break;
                        return TRUE;
                    }
                }
//            }
            return FALSE;
        
        default:
//            break;
            return FALSE;
    }
}
void GSM_ClearBuffer(){
    for (char i=0; i<sizeof(aBuff_Uart); i++) aBuff_Uart[i] = NULL;
    cBuff = 0;
}
void GSM_Display_Message(char countTime){
    LCD_clear();
    LCD_SetPos(0,0);
//    LCD_string(aBuff_Phone);
    LCD_SetPos(0,1);
    if(_countLCD <= countTime) LCD_string(aBuff_DateTime);
    else if(_countLCD <= countTime * 2) LCD_string(aBuff_TextMessage);
    else if(_countLCD > countTime * 2) _countLCD = 0;
    _countLCD++;
}
__bit GSM_Command(char* command){
    GSM_USART_Transmit_Str(command);
    while(!(strstr(aBuff_Uart, "OK"))&&(_counter <= 500)){_counter++;};
    if(_counter>=500) {
        _counter = 0;
        return 0;
    }
    __delay_ms(10);
//    GSM_ClearBuffer();
    return 1;
}