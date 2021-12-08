#include "Bb_device.h"

//void fTxDevice(unsigned char cmd){
//    GPSend1Wire = FALSE;
//    for(i = 0; i < 8; i++){
//        flSendBit = FALSE;
//        flSendDataDown = TRUE;
//        while(flSendBit == FALSE){
//            if(cmd & 0x80){
//                if(flSendDataDown){
//                    TMR1H = vTMR1H_Down;
//                    TMR1L = vTMR1L_Down;
//                } else if(flSendDataRise){
//                    TMR1H = vTMR1H_Raise;
//                    TMR1L = vTMR1L_Raise;
//                }
//            } else {
//                if(flSendDataDown){
//                    TMR1H = vTMR1H_Raise;
//                    TMR1L = vTMR1L_Raise;
//                } else if(flSendDataRise){
//                    TMR1H = vTMR1H_Down;
//                    TMR1L = vTMR1L_Down;
//                }
//            }
//            T1CONbits.TMR1ON = TRUE;
//            while(T1CONbits.TMR1ON);
//        }
//        cmd <<= 1;
//    }
//}
//void fTxStart(){
//    flStartSend = TRUE;
//    TMR1H = 0xFC;//FE
//    TMR1L = 0x18;//70
//    GPSend1Wire = TRUE;
//    T1CONbits.TMR1ON = TRUE;
//    while(T1CONbits.TMR1ON);
//}
//void fTxStop(){
//    flStartSend = FALSE;
//    GPSend1Wire = FALSE;
//    TMR1H = 0xF8;//FE
//    TMR1L = 0x30;//70
//    T1CONbits.TMR1ON = TRUE;
//    while(T1CONbits.TMR1ON);
//    GPSend1Wire = TRUE;
//    TMR1H = 0xF8;//FE
//    TMR1L = 0x30;//70
//    T1CONbits.TMR1ON = TRUE;
//    while(T1CONbits.TMR1ON);
//    GPSend1Wire = FALSE;
//}
//void fInterruptTMR1(){
//    if(flStartSend){
//        if(flStartSendData == FALSE){
//            flStartSendData = TRUE;
//            GPSend1Wire = FALSE; 
//        } else if(flStartSendData == TRUE){
//            if(flSendDataDown){
//                flSendDataDown = FALSE;
//                flSendDataRise = TRUE;
//                GPSend1Wire = TRUE; 
//            } else if(flSendDataRise){
//                flSendDataRise = FALSE;
//                flSendBit = TRUE;
//                GPSend1Wire = FALSE;
//            }
//        }
//    }
//    T1CONbits.TMR1ON = FALSE;
//}
//void fInterruptTMR0(){
//    if(GPRecieve1Wire == TRUE && flStartBitRecieve == FALSE && flModeStep == 0){
//        flStartBitRecieve = TRUE;     
//        flModeStep = 1; 
//        //GPIObits.GP0 = !GPIObits.GP0;
//    }
//    else if(GPRecieve1Wire == FALSE && flStartBitRecieve == TRUE && flModeStep == 2){
//        flModeStep = 3;  
//    }
//    else if(GPRecieve1Wire == TRUE && flStartBitRecieve == TRUE && flModeStep == 3){
//        flStopBitRecieve = TRUE;
//        flModeStep = 4; 
//    }
//    else if(GPRecieve1Wire == FALSE && flStartBitRecieve == TRUE && flStopBitRecieve == TRUE && flModeStep == 4){
////        flStartBitRecieve = FALSE;
////        flStopBitRecieve = FALSE;
//        flRecieveDone = TRUE;
////        flModeStep = 0;
//    } 
//        //GPIObits.GP2 = !GPIObits.GP2;
//    INTCONbits.T0IE = FALSE;
//}
void fInterruptRecieveDevice(){
//    TMR0 = 0;
//    INTCONbits.T0IF = FALSE;
//    INTCONbits.T0IE = TRUE;
    if(GPRecieve1Wire == 1 && flModeStep == 0 && flStartBitRecieve == FALSE){     
        TMR0                    = TMR0_Value;//115;
        INTCONbits.T0IF         = FALSE;
        INTCONbits.T0IE         = TRUE;
        TMR1H = 0x00;
        TMR1L = 0x00;
        flStartBitRecieve = TRUE;
        flModeStep = 1;
        T1CONbits.TMR1ON = TRUE;
//        RB6 = !RB6;
//            INTCONbits.GPIE = FALSE;
    }
    else if(GPRecieve1Wire == 0 && flModeStep == 1 && flStartBitRecieve == TRUE){
        T1CONbits.TMR1ON = FALSE; //останавливаем таймер
//        RB6 = !RB6;
//        flModeStep = 0; 
//        INTCONbits.GPIE = FALSE;
//        if((TMR1H == 0x03 && TMR1L >= 0xE8) || (TMR1H == 0x04 && TMR1L <= 0x4C)){
//        if((TMR1H >= 0x0A && TMR1L >= 0x00) && (TMR1H <= 0x0C && TMR1L <= 0xFF)){
        if(TMR1H >= 0x0A && TMR1H <= 0x0C){
//            GPIO2 = !GPIO2;
//            RB6 = !RB6;
            flModeStep = 2;  //переход на шаг 2 отлавливание битов
//            eeprom_write(0,TMR1H);
//            eeprom_write(1,TMR1L);
            TMR1H = 0x00; //обнуляем таймер
            TMR1L = 0x00;
        }
        else{
            flStartBitRecieve = FALSE;
            flModeStep = 0;
//            GPIO2 = !GPIO2;
        }
        
//        GPIO2 = FALSE;
    }
    else if(GPRecieve1Wire == 1 && flModeStep == 2 && flStartBitRecieve == TRUE){
        T1CONbits.TMR1ON = TRUE;
        flModeStep = 3;
//            GPIO2 = !GPIO2;
    }
    else if(GPRecieve1Wire == 0 && flModeStep == 3 && flStartBitRecieve == TRUE){
//            RB6 = !RB6;
//        GPIO2 = !GPIO2;
        T1CONbits.TMR1ON = FALSE;
        flModeStep = 2;
        if(cQuantity < 32){
            arrCmd[carrCmd] <<= 1;
            if( TMR1H >= 0x02) arrCmd[carrCmd] |= 0b00000001;
            if(cQuantity == 7 || cQuantity == 15 || cQuantity == 23) {carrCmd++;}
        }
        cQuantity++;
        if(cQuantity == 32){
//                            eeprom_write(0,TMR1H);
//                eeprom_write(1,TMR1L);
//            arrCmd[0]=~arrCmd[0];
//            eeprom_write(16,arrCmd[0]);
//            if(arrCmd[0] == 0xF0)
//                GPIO2 = !GPIO2;
//            INTCONbits.GPIE = FALSE;
            flModeStep = 4;
//            flModeStep = 0;
//            flStartBitRecieve = FALSE;
            cQuantity = 0;
            carrCmd = 0;
//            cSucReq++;
        }
        TMR1H = 0x00; //обнуляем таймер
        TMR1L = 0x00;
        
//        
    }
    else if(GPRecieve1Wire == 1 && flModeStep == 4 && flStartBitRecieve == TRUE){
//        GPIO2 = !GPIO2;
        
//            RB6 = !RB6;
        T1CONbits.TMR1ON = TRUE;
        flModeStep = 5;
    }
    else if(GPRecieve1Wire == 0 && flModeStep == 5 && flStartBitRecieve == TRUE){
//        GPIO2 = !GPIO2;
        T1CONbits.TMR1ON = FALSE;
//            eeprom_write(0,TMR1H);
//            eeprom_write(1,TMR1L);
//            INTCONbits.GPIE = FALSE;
        
        if(TMR1H >= 0x02 && TMR1H <= 0x04){//0x34
//            GPIO2 = !GPIO2;
//            flStartBitRecieve = FALSE;
//            TMR1H = 0x00; //обнуляем таймер
//            TMR1L = 0x00;
//            eeprom_write(16,arrCmd[0]);
//            eeprom_write(17,arrCmd[1]);
//            eeprom_write(18,arrCmd[2]);
//            eeprom_write(19,arrCmd[3]);
//            eeprom_write(20,cSucReq);
////            flStartSendRequest = TRUE;
//            RB6 = !RB6;
            flModeStep = 0;
            flStartBitRecieve = FALSE;
            flStopBitRecieve = TRUE;
            
            cTMR0 = 0;
            INTCONbits.T0IF = FALSE;
            INTCONbits.T0IE = FALSE;
            
//            for(char i = 0; i < 4; i++) arrLCDData[i] = arrCmd[i];
//            GPIO2 = !GPIO2;
        }
        __delay_ms(1);
    }
}
//void fTXArrDevice(char address, char function, char data1, char data2){
//    //GPIO = 0; //Обязательно, иначе передача не осуществляется. Баг или особенность защилки, неизвестно.
//    INTCONbits.GPIE = FALSE;
//    fTxStart();
//    fTxDevice(address);
//    fTxDevice(function);
//    fTxDevice(data1);
//    fTxDevice(data2);
//    fTxStop();
////    flStopBit = FALSE;
//    flStartSendData = FALSE;
////    flStartSend = FALSE;
//    INTCONbits.GPIE = TRUE;
//}
//void fTXRespondSlave(){
//    while(flStartSendRequest == FALSE);
//    flStartSendRequest = FALSE;
//    if(arrCmd[0] == 0x66){
//        if(arrCmd[1] == 0x39){
//            GPIO2 = !GPIO2;
//            SLEEP(); //Перевод контроллера в режим экономии энергии (только для подчиненных устройств)
//        }
////        else if(arrCmd[1] == 0x1B){
////            fTXArrDevice(0x01,0x66,GPIObits.GPIO2,fCheckPower());
////        }
//    }
//    else
//        SLEEP();
//}

//unsigned char fCheckPower(){
//        ADCON0bits.ADON = TRUE;
//        __delay_us(100);
//        ADCON0bits.GO_nDONE = TRUE;
//        while(!ADCON0bits.GO_nDONE);
//        __delay_us(100);
//        tChPow = (((ADRESH << 8) + ADRESL)/4);
////        tChPow >= 86 ? GPIO2 = TRUE : GPIO2 = FALSE;
//        ADCON0bits.ADON = FALSE;
//        return tChPow;
//}