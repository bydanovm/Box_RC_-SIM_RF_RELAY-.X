#include "menu.h"

void fMenuStrip(void){  
    if(flMenuStrip == 0x01 && flSwitchButton == FALSE){         //Нажата МЕНЮ
        if(_MenuNav == 1) _MenuNav = 2;                         //
        else if(_MenuNav >= 20 && _MenuNav < _MenuArr[0] * 10 + 9) _MenuNav /= 10;
        else if(_MenuNav >= 100 && _MenuNav < _MenuArr[0] * 100 + 99) _MenuNav /= 10;
        else if(_MenuNav >= 1000 && _MenuNav < _MenuArr[0] * 1000 + 999) _MenuNav /= 10;
        else _MenuNav = 1;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
        flUpdate = FALSE;
    }
    else if(flMenuStrip == 0x02 && flSwitchButton == FALSE){    //Нажата Вниз
        if(_MenuNav <= 1) _MenuNav = _MenuArr[0];
        else if(_MenuNav >= 10 && _MenuNav < 100){
            if(_MenuNav <= _tempTwoDigit)
                _MenuNav = _tempTwoDigit + _MenuArr[_cellTwoDigit] - 1;
            else
                _MenuNav--;
        }
        else if(_MenuNav >= 100 && _MenuNav < 1000) {
            if(_MenuNav == 210 && _settingTimeImpDO1 != 0) _settingTimeImpDO1--;
            else if(_MenuNav == 230 && _settingTimerOnDO2 != 0) _settingTimerOnDO2--;
            else if(_MenuNav == 240 && _settingTimerOffDO2 != 0) _settingTimerOffDO2--;
            else if(_MenuNav <= (short int)_tempDigit)
                _MenuNav = (short int)((_tempDigit + _SubMenuArr[_firstCell][_secondCell]) - 1);
            else _MenuNav--;
        }
        else if(_MenuNav >= 1000) _MenuNav = _MenuNav;
        else _MenuNav--;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    else if(flMenuStrip == 0x04 && flSwitchButton == FALSE){    //Нажата Вверх    
        if(_MenuNav >= _MenuArr[0] && _MenuNav < 10) _MenuNav = 1;
        else if(_MenuNav >= 10 && _MenuNav < 100){
            if(_MenuNav >= _tempTwoDigit + _MenuArr[_cellTwoDigit] - 1)
                _MenuNav = _tempTwoDigit;
            else
                _MenuNav++;
        }
        else if(_MenuNav >= 100 && _MenuNav < 1000) {
            if(_MenuNav == 210) _settingTimeImpDO1++;
            else if(_MenuNav == 230) _settingTimerOnDO2++;
            else if(_MenuNav == 240) _settingTimerOffDO2++;
            else if(_MenuNav >= (short int)((_tempDigit + _SubMenuArr[_firstCell][_secondCell]) - 1))
                _MenuNav = _tempDigit;
            else _MenuNav++;
        }
        else if(_MenuNav >= 1000) _MenuNav = _MenuNav;
        else _MenuNav++;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    else if(flMenuStrip == 0x08 && flSwitchButton == FALSE){    //Нажата ОК
        if(_MenuNav > 1 && _MenuNav <= 1000) {
            _MenuNav *= 10;
//            _MenuNav++;
        }
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    if(_MenuNav >= 100){
        _firstCell = (unsigned char)(_MenuNav / 100 - 2);
        _secondCell = (unsigned char)(_MenuNav / 10 % 10);
        _tempDigit = (unsigned short int)(((_firstCell + 2) * 100) + (_secondCell * 10));
    }
    else if(_MenuNav >= 10){
        _cellTwoDigit = (unsigned char)(_MenuNav / 10 - 1);
        _tempTwoDigit = (unsigned char)(_MenuNav / 10 * 10);
    }
    if(flClearLCD == FALSE) LCD_clear();
    
    switch (_MenuNav){
//        case 1:
//            sprintf(str, "Твн:%3d Тнар:%3d", temperatureAI1, temperatureAI2);
////        sprintf(str, "Твн:%3d", temperatureAI1);
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
//            sprintf(str, "%7s%4s%5u", "Упр.ДУ:", LCD_StringOnOff(_tempPinDO,3),_countSecond);
//            LCD_SetPos(0,1);
//            LCD_string((char*)str);
//
//            LCD_SetPos(15,0);
//            flClearLCD = TRUE;
//            break;
        case 2:
            sprintf(str, "%16s", "Настройки");    
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
//            fEraseString(str);
            break;
        case 20:
            sprintf(str, "%16s", "ДО1-Имп/пост");
            break;
        case 200:
            sprintf(str2, "%s", "Импульс");
            if(_settingsBit & (1 << 1))
                strcat(str2, '*');
            break;
        case 2000:
             _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 0);  //Set IMP to 1 sec
            bitset(_settingsBit, 1);        //Set bit IMP
            _MenuNav = 200;
            break;
        case 201:
            sprintf(str2, "%s", "Постоянный");
            if(!(_settingsBit & (1 << 1)))  
                strcat(str2, '*');
            break;
        case 2010:
            bitclr(_settingsBit, 1);
            _MenuNav = 201;
            break;
        case 21: 
            sprintf(str, "%16s", "ДО1-Время имп");
            break;
        case 210:
            sprintf(str2, "%4d сек.", _settingTimeImpDO1);
            break;
        case 2100:
            _settingTimeImpDO1 = _settingTimeImpDO1;
            _MenuNav = 210;
            break;
        case 22:
            sprintf(str, "%16s", "ДО2-Вкл таймер");
            break;
        case 220:
            sprintf(str2, "%s", "Да");  
            if(_settingsBit & (1 << 3)) 
                strcat(str2, '*');
            break;
        case 2200:
            if(_settingTimerOnDO2 == 0 || _settingTimerOffDO2 == 0)
            {
                _settingTimerOnDO2 = 5;
                _settingTimerOffDO2 = 5;
            }
            bitset(_settingsBit, 3);        //Set bit
            _MenuNav = 220;
            break;
        case 221:
            sprintf(str2, "%s", "Нет"); 
            if(!(_settingsBit & (1 << 3)))  
                strcat(str2, '*');
            break;
        case 2210:
            bitclr(_settingsBit, 3);
            _MenuNav = 221;
            break;
        case 23:
            sprintf(str, "%16s", "ДО2-Таймер вкл");
            break;
        case 230:
            sprintf(str2, "%4d мин.", _settingTimerOnDO2);
            break;
        case 2300:
            _settingTimerOnDO2 = _settingTimerOnDO2;
            _MenuNav == 230;
            break;
        case 24:
            sprintf(str, "%16s", "ДО2-Таймер выкл");
            break;
        case 240:
            sprintf(str2, "%4d мин.", _settingTimerOffDO2);
            break;
        case 2400:
            _settingTimerOffDO2 = _settingTimerOffDO2;
            _MenuNav == 240;
            break;
        case 25:
            sprintf(str, "%16s", "ДО2-Вкл по темп");
            break;
        case 250:
            sprintf(str2, "%s", "Да");  
            if(_settingsBit & (1 << 4)) 
                strcat(str2, '*');
            break;
        case 2500:
            bitset(_settingsBit, 4);        //Set bit DO2 On at low temp
            _MenuNav = 250;
            break;
        case 251:
            sprintf(str2, "%s", "Нет");  
            if(!(_settingsBit & (1 << 4))) 
                strcat(str2, '*');
            break;
        case 2510:
            bitclr(_settingsBit, 4);        //Set bit IMP
            _MenuNav = 251;
            break;
        case 3:
            sprintf(str, "%16s", "Показания");
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
//            fEraseString(str);
            break;
        case 30:
            sprintf(str, "%16s", "Аналог. ввод");
            break;
        case 300:
            sprintf(str2, "%3s%3u  %3s%3u", "Ан1:", Analog.AI1, "Aн2:", Analog.AI2);
            break;
        case 3000:
            break;
        case 31:
            sprintf(str, "%16s", "Цифр. ввод");
            break;
        case 310:
            sprintf(str2, "%12s%d%d%d%d", "Д.входы:",RB3,RB4,RB5,RB6);
            break;
        case 3100:
            _MenuNav /= 10;
            break;
        case 32:
            sprintf(str, "%16s", "Цифр. вывод");
            break;
        case 320:
            sprintf(str2, "%12s%d%d%d%d", "Д.выходы:",_tempPinDO&0x08?1:0,_tempPinDO&0x04?1:0,_tempPinDO&0x02?1:0,_tempPinDO&0x01?1:0);
            break;    
        case 3200:
            _MenuNav /= 10;
            break;             
        case 4:
            sprintf(str, "%16s", "Память");
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
            break;
        case 40:
            sprintf(str, "%16s", "Сохр.тек.настр.");
            break;
        case 400:
                sprintf(str2, "%s", "Да");
            if(flUpdate)
                strcat(str2, '*');
            break;
        case 4000:
            flUpdate = TRUE;
            SPI_Write(0,_settingsBit);
            SPI_Write(1,_settingTimeImpDO1>>8);
            SPI_Write(2,_settingTimeImpDO1);
            SPI_Write(3,_settingTimerOnDO2>>8);
            SPI_Write(4,_settingTimerOnDO2);
            SPI_Write(5,_settingTimerOffDO2>>8);
            SPI_Write(6,_settingTimerOffDO2);
            _MenuNav = 400;
            break;
        case 41:
            sprintf(str, "%16s", "Сброс настр. ОЗУ");
            break;
        case 410:
            sprintf(str, "%16s", "Да");
            if(flUpdate)
                strcat(str2, '*');
            break;
        case 4100:
            flUpdate = TRUE;
            _settingsBit = 0;
            _settingTimeImpDO1 = 0;
            _settingTimerOnDO2 = 0;
            _settingTimerOffDO2 = 0;
            _MenuNav = 410;
            break;
        case 42:
            sprintf(str, "%16s", "Сброс настр. ПЗУ");
            break;
        case 420:
            sprintf(str, "%16s", "Да");
            if(flUpdate)
                strcat(str2, '*');
            break;
        case 4200:
            flUpdate = TRUE;
            
            SPI_Write(0,0);
            SPI_Write(1,0);
            SPI_Write(2,0);
            SPI_Write(3,0);
            SPI_Write(4,0);
            SPI_Write(5,0);
            SPI_Write(6,0);
            
            _MenuNav = 420;
            break;
        default:
            sprintf(str, "Твн:%3d Тнар:%3d", temperatureAI1, temperatureAI2);
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
            sprintf(str2, "%3s%4s%5s%4u", "ДУ:", LCD_StringOnOff(_tempPinDO,3),"НАГР:",LCD_StringOnOff(_tempPinDO,4));
//            LCD_SetPos(0,1);
//            LCD_string((char*)str);
//            LCD_SetPos(15,0);
            flClearLCD = TRUE;
            break;
//            sprintf(str, "%u", _MenuNav);
//            LCD_SetPos(0,0);
//            LCD_string((char*)str);
//            flClearLCD = TRUE;
//            break;
    }
    LCD_SetPos(0,0);
    LCD_string((char*)str);
    LCD_SetPos(0,1);
    LCD_string((char*)str2);
//    if(_MenuNav<100)
//        fEraseString(str);
    fEraseString(str2);
            
}

unsigned char _firstDigitMenu(short int _digit){
    unsigned char _tempDigit;
    for(short int i = _digit; i > 0; i/=10)
        _tempDigit = i % 10;
    return _tempDigit;
}
void fShowStar(unsigned char position, unsigned char string){
        LCD_SetPos(position,string);
        sendbyte('*', 1);
}