#include "config.h"
#include "Bb_device.h"
#include "gsm.h"
#include "lcd.h"
#include "menu.h"
#include "shift_registr.h"
#include "temp_ntc.h"

void __interrupt linkup(void){
    if(INTCONbits.RBIE && INTCONbits.RBIF){
        fInterruptRecieveDevice();
        INTCONbits.RBIF     = FALSE;
    }
    if(INTCONbits.T0IE && INTCONbits.T0IF){
        TMR0 = TMR0_Value;//135;
        if(cTMR0 == 2){
            cTMR0 = 0;
            flModeStep          = 0;
            flStartBitRecieve   = FALSE;
            flStopBitRecieve    = FALSE;
            flDO1               = FALSE;
            T1CONbits.TMR1ON    = FALSE;
            INTCONbits.T0IE     = FALSE;
        }
        INTCONbits.T0IF     = FALSE;
        cTMR0++;
    }
    if(PIE1bits.TMR1IE && PIR1bits.TMR1IF){
        T1CONbits.TMR1ON    = FALSE;
        PIR1bits.TMR1IF     = FALSE;
    }
    if(PIE1bits.TMR2IE && PIR1bits.TMR2IF){
        _countTMR2trigger++;
        if((_countTMR2trigger % 3) == 0)
            _100ms = TRUE;
        if(_countTMR2trigger >= 28) {
            _countSecond++;
            _countTMR2trigger = 0;
            _flashSecond = !_flashSecond;
            _second = TRUE;
        }
        if((_countSecond % 60) == 0)
            _minute = TRUE;
        if((_countSecond % 3600) == 0){
            _hour = TRUE;
            _countSecond = 0;
        }
//        if(_countSecond >= 3600) _countSecond = 0;
        PIR1bits.TMR2IF     = FALSE;
    }
    if(PIE1bits.ADIE && PIR1bits.ADIF){
        if(Analog.AI0 >= 35 && Analog.AI0 <= 45) flMenuStrip = 0x01;
        else if(Analog.AI0 >= 85 && Analog.AI0 <= 105) flMenuStrip = 0x02;
        else if(Analog.AI0 >= 130 && Analog.AI0 <= 155) flMenuStrip = 0x04;
        else if(Analog.AI0 >= 190 && Analog.AI0 <= 210) flMenuStrip = 0x08;
        else if (Analog.AI0 >= 230) { flMenuStrip = 0; flSwitchButton = FALSE; }
        PIR1bits.ADIF     = FALSE;
    }
    if(PIE1bits.RCIE && PIR1bits.RCIF){
        if(RCSTAbits.FERR){
            tmp = RCREG;
            return;
        }
        else if(RCSTAbits.OERR){
            RCSTAbits.CREN = 0;
            RCSTAbits.CREN = 1;
            return;
        }
        aBuff_Uart[cBuff] = RCREG;
        cBuff++;
//        if(aBuff_Uart[cBuff-1] == 0x0A){
//            for (char i=0; i<sizeof(aBuff_Uart); i++) {
//                aBuff_Uart2[i] = aBuff_Uart[i];
//                aBuff_Uart[i] = 0;
//            }
//            cBuff = 0;
//        }
//        sprintf(str, "%s %c\r\n", "Hello! ", aBuff_Uart);
//        USART_Transmit_Str((char*)str);
    }
}
void fACP(){
    //AI0
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = TRUE;
    ADCON0bits.CHS0         = TRUE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI0 = ADRES;
    //AI1
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = FALSE;
    ADCON0bits.CHS0         = FALSE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI1 = ADRES;
    //AI2
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = FALSE;
    ADCON0bits.CHS0         = TRUE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI2 = ADRES;
}

    __bit flResp = FALSE;
void main(void) {
    init();
    fShiftData(0x00);
    LCD_init();
    
    define_char(noConnectionModem,6);
    define_char(yesConnectionModem,7);
//    define_char(char1,1);
    //Hearth
//    define_char(char2,2);
//    define_char(char3,4);
//    define_char(char4,3);
//    define_char(char5,5);
        
    LCD_SetPos(0,0);
    LCD_string((char*)"Загрузка....");
    __delay_ms(500);
//    LCD_SetPos(0,1);
//    sprintf(str, "%16s","Инит.модема:....");
//    LCD_string((char*)str);
//    __delay_ms(500);
//    while(_statGSM_Init != 8 && counter != 10){
//        _statGSM_Init = GSM_Init();
//        __delay_ms(200);
//        counter++;
//    };
//    counter = 0;
//    if(_statGSM_Init != 8) sprintf(str, "%14s%02u", "Инит.модема: E",_statGSM_Init);
//    if(_statGSM_Init == 8) sprintf(str, "%16s", "Инит.модема: ОК ");
//    else sprintf(str, "%14s%02u", "Инит.модема: E",_statGSM_Init);
    LCD_SetPos(0,1);
    LCD_string((char*)str);
    __delay_ms(1000);
    LCD_clear();
    short int _timerDO1 = 0;
      
    while(1){
        fShiftData(_tempPinDO);
        if(_minute) flResp = FALSE;
        
//        if(aBuff_Uart[0] != 0 && flResp == FALSE){
//            __delay_ms(100);
//            if(GSM_Get_String(9)){            
//                GSM_Read_Message(aBuff_Number_Message);
//                __delay_ms(100);
//                if(GSM_Get_String(1)){
//                    if(strstr(aBuff_TextMessage, "do1on") || strstr(aBuff_TextMessage, "DO1ON")) bitset(_tempPinDO,3);
//                    else if(strstr(aBuff_TextMessage, "do1off") || strstr(aBuff_TextMessage, "DO1OFF")) bitclr(_tempPinDO,3);
//                    if(aBuff_Number_Message == 9){
//                        GSM_Command("AT+CMGDA=\"DEL ALL\"\r\n");
//                        GSM_ClearBuffer();
//                    }
//                    flResp = TRUE;
//                }
//            }
//        }
        fACP();
        fMenuStrip();
        
        if(flStopBitRecieve){
            if(arrCmd[0] == 0xF0 && arrCmd[1] == 0x00 && arrCmd[3] == 0x0F){
                if(arrCmd[2] == 0x11 && flDO1 == FALSE) {
                    bitset(_tempPinDO,3);
                    flDO1 = TRUE;
                }else if(arrCmd[2] == 0x22) {
                    bitclr(_tempPinDO,3);
                }
            }
        }    
        if((_settingsBit & (1 << 1)) && (_tempPinDO & (1 << 3))){
            if(_second) _timerDO1++;
            if(_timerDO1 > (short int)(_settingTimeImpDO1 * 5)){
                bitclr(_tempPinDO,3);
                _timerDO1 = 0;
            }
        }
        if((_settingsBit & (1 << 0)) && _second){
            for(char i = 0; i < sizeof(aBuff_DateTime); i++){
                if(i < 2) ToD.Date_year[i] = &aBuff_DateTime[i];
                else if(i >= 3 && i < 5) ToD.Date_month[i-3] = &aBuff_DateTime[i];
                else if(i >= 6 && i < 8) ToD.Date_day[i-6] = &aBuff_DateTime[i];
                else if(i >= 9 && i < 11) ToD.Time_hour[i-9] = &aBuff_DateTime[i];
                else if(i >= 12 && i < 14) ToD.Time_minutes[i-12] = &aBuff_DateTime[i];
            }
            if(_minute) {
                GSM_Command("AT+CCLK?\r\n");
                GSM_Get_String(2);
            }
        }
        _second = FALSE;
        _100ms = FALSE;
        _minute = FALSE;
        _hour = FALSE;
    }
}
