#include "config.h"
#include "Bb_device.h"
#include "lcd.h"
#include "menu.h"
#include "shift_registr.h"
#include "temp_ntc.h"
#include "spi_flash.h"


void __interrupt linkup(void){
#testing
    if(INTCONbits.RBIE && INTCONbits.RBIF){
        fInterruptRecieveDevice();
        INTCONbits.RBIF     = FALSE;
    }
    if(INTCONbits.T0IE && INTCONbits.T0IF){
        TMR0 = TMR0_Value;//135;
        if(cTMR0 == 3){
//            for(char i = 0; i < 4; i++) arrCmd[i] = 0;
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
//        if((_countTMR2trigger % 3) == 0)
//            _100ms = TRUE;
        if(_countTMR2trigger >= 28) {
            _countSecond++;
            _countTMR2trigger = 0;
//            _flashSecond = !_flashSecond;
            _second = TRUE;
            if((_countSecond % 60) == 0)
                _minute = TRUE;
            if((_countSecond % 3600) == 0){
                _hour = TRUE;
                _countSecond = 0;
            }
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
}
void fACP(){
    //AI0
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = FALSE;
    ADCON0bits.CHS0         = FALSE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI0 = ADRES;
    //AI1
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = FALSE;
    ADCON0bits.CHS0         = TRUE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI1 = ADRES;
    //AI2
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = TRUE;
    ADCON0bits.CHS0         = TRUE;
    ADCON0bits.ADON         = TRUE;
    __delay_ms(1);
    ADCON0bits.GO_nDONE     = TRUE;
    while(GO_DONE);
    ADCON0bits.ADON         = FALSE;
    Analog.AI2 = ADRES;
}
void main(void) {
    init();
    SPI_init();
    LCD_init();
    fShiftData(0x00);
    LCD_SetPos(0,0);
    LCD_string((char*)"Загрузка....");
    
    if(SPI_Read(100) == 0xFF)
    {
        for(unsigned char SPI_i = 0; SPI_i < 100; SPI_i++)
            SPI_Write(SPI_i,0x00);
        SPI_Write(100,0x01);
    }
    else if(SPI_Read(100) == 0x01)
    {
        _settingsBit = SPI_Read(0);
        
        _settingTimeImpDO1 = SPI_Read(1);
        _settingTimeImpDO1 <<=8;
        _settingTimeImpDO1 |= SPI_Read(2);
        
        _settingTimerOnDO2 = SPI_Read(3);
        _settingTimerOnDO2 <<=8;
        _settingTimerOnDO2 |= SPI_Read(4);
        
        _settingTimerOffDO2 = SPI_Read(5);
        _settingTimerOffDO2 <<=8;
        _settingTimerOffDO2 |= SPI_Read(6);
    }
    __delay_ms(500);
        

    
    _second = FALSE;
    _100ms = FALSE;
    _minute = FALSE;
    _hour = FALSE;
    
    while(1){
        fACP();        
        temperatureAI1 = rTemperature(Analog.AI1);
        temperatureAI2 = rTemperature(Analog.AI2);
        fMenuStrip();
        if(flStopBitRecieve)
        {
            if(arrCmd[0] == 0xF0 && arrCmd[1] == 0x00 && arrCmd[3] == 0x0F)
            {
                if(arrCmd[2] == 0x11 && flDO1 == FALSE)
                {
                    bitset(_tempPinDO,3);
                    flDO1 = TRUE;
                }
                else if(arrCmd[2] == 0x22)
                {
                    bitclr(_tempPinDO,3);
                }
            }
        }    
//      Настройка первого вывода ДО1 работающего от пульта ДУ
        if((_settingsBit & (1 << 1)) && (_tempPinDO & (1 << 3)))
        {
            if(_second) _timerDO1++;
            if(_timerDO1 > (short int)(_settingTimeImpDO1))
            {
                bitclr(_tempPinDO,3);
                _timerDO1 = 0;
            }
        }
        else if(!(_settingsBit & (1 << 1)))
        {
            if(_tempPinDO & (1 << 3))
                bitset(_tempPinDO,3);
            else if (!(_tempPinDO & (1 << 3)))
                bitclr(_tempPinDO,3);   
        }
//      Настройка второго вывода ДО2 работающего по таймеру
        if(_settingsBit & (1 << 3))
        {
            if(_minute) _timerDO2++;
            if((_settingsBit & (1 << 4)) && temperatureAI2 <= 20 && !(_tempPinDO & (1 << 4))){
                bitset(_tempPinDO,4);
                _timerDO2 = 0;
            }
            if(!(_tempPinDO & (1 << 4)))
            {
                if(_timerDO2 >= (short int)(_settingTimerOnDO2))
                {
                    bitset(_tempPinDO,4);
                    _timerDO2 = 0;
                }
            }
            else if(_tempPinDO & (1 << 4))
            {
                if(_timerDO2 >= (short int)(_settingTimerOffDO2))
                {
                    bitclr(_tempPinDO,4);
                    _timerDO2 = 0;
                }
            }
        }
        
//      Настройка третьего вывода ДО3 в режиме И
        if((RB3 && RB4) && (!(_tempPinDO & (1 << 5))))
            bitset(_tempPinDO,5);
        else if (!(RB3 && RB4) && (_tempPinDO & (1 << 5)))
            bitclr(_tempPinDO,5); 

//      Настройка четвертого вывода ДО4 в режиме ИЛИ
        if((RB5 || RB6) && (!(_tempPinDO & (1 << 6))))
            bitset(_tempPinDO,6);
        else if (!(RB5 || RB6) && (_tempPinDO & (1 << 6)))
            bitclr(_tempPinDO,6);

        _second = FALSE;
        _100ms = FALSE;
        _minute = FALSE;
        _hour = FALSE;
    }
}
