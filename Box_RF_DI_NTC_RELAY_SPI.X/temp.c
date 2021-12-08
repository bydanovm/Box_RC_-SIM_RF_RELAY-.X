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
        case 1:
            sprintf(str, "Твн:%3d Тнар:%3d", temperatureAI1, temperatureAI2);
//        sprintf(str, "Твн:%3d", temperatureAI1);
            LCD_SetPos(0,0);
            LCD_string((char*)str);
            sprintf(str, "%7s%4s%5u", "Упр.ДУ:", LCD_StringOnOff(_tempPinDO,3),_countSecond);
            LCD_SetPos(0,1);
            LCD_string((char*)str);

            LCD_SetPos(15,0);
            flClearLCD = TRUE;
            break;
        case 2:
            sprintf(str, "%16s", "Настройки");    
            LCD_SetPos(0,0);
            LCD_string((char*)str);
            fEraseString(str);
            break;
        case 3:
            sprintf(str, "%16s", "Показания");
            LCD_SetPos(0,0);
            LCD_string((char*)str);
            fEraseString(str);
            break;
        case 4:
            sprintf(str, "%16s", "Память");
            LCD_SetPos(0,0);
            LCD_string((char*)str);
            break;
    }
    if(_MenuNav == 1){  
//        sprintf(str, "%d", _firstDigitMenu(326));
//        sprintf(str, "Твн:%3d Тнар:%3d", temperatureAI1, _timerDO2);
        sprintf(str, "Твн:%3d Тнар:%3d", temperatureAI1, temperatureAI2);
//        sprintf(str, "Твн:%3d", temperatureAI1);
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        sprintf(str, "%7s%4s%5u", "Упр.ДУ:", LCD_StringOnOff(_tempPinDO,3),_countSecond);
        LCD_SetPos(0,1);
        LCD_string((char*)str);
        
        LCD_SetPos(15,0);
        flClearLCD = TRUE;
    }
    else if(_firstDigitMenu(_MenuNav) == 2){ 
        sprintf(str, "%16s", "Настройки");    
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        fEraseString(str);
        
//        if(_MenuNav == 20) sprintf(str, "%16s", "Настройка ДО1");
//        ///////Настройка ДО1 по температуре наружней
//        else if(_MenuNav == 200) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2000) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 200;
//        }
//        ///////Настройка ДО1 по температуре внутренней
//        else if(_MenuNav == 201) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2010) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 201;
//        }
//        ///////Настройка ДО1 по пульту ДУ 1
//        else if(_MenuNav == 201) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2010) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 201;
//        }
//        
//        ///////Настройка ДО1 по пульту ДУ 2
//        else if(_MenuNav == 201) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2010) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 201;
//        }
//        
//        ///////Настройка ДО1 по дискретному вводу 1
//        else if(_MenuNav == 201) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2010) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 201;
//        }
//        ///////Настройка ДО1 по дискретному вводу 2
//        else if(_MenuNav == 201) 
//        { 
//            if(_settingsBit & (1 << 1)) 
//                sprintf(str, "%16s", "Темп. нар.*"); 
//            else 
//                sprintf(str, "%16s", "Темп. нар."); 
//        }
//        else if(_MenuNav == 2010) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
//            bitset(_settingsBit, 1);        //Set bit IMP
//            _MenuNav = 201;
//        }
        if(_MenuNav == 20) sprintf(str, "%16s", "ДО1-Имп/пост.");
        else if(_MenuNav == 200) 
        { 
            sprintf(str, "%s", "Импульс");
            if(_settingsBit & (1 << 1))
                fShowStar(15, 1);
        }
        else if(_MenuNav == 2000) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 0);  //Set IMP to 1 sec
            bitset(_settingsBit, 1);        //Set bit IMP
            _MenuNav = 200;
        }
    //        sprintf(str, "%s", "Имп.-OK");
        else if(_MenuNav == 201) 
        { 
            sprintf(str, "%s", "Постоянный");
            if(!(_settingsBit & (1 << 1)))  
                fShowStar(15, 1);
        }
        else if(_MenuNav == 2010) 
        { 
            bitclr(_settingsBit, 1);
            _MenuNav = 201;
        }
        if(_MenuNav == 21) sprintf(str, "%16s", "ДО1-Время имп.");
        else if(_MenuNav == 210)
        { 
            sprintf(str, "%4d сек.", _settingTimeImpDO1);
        }
        else if(_MenuNav == 2100)
        {
            
        }
        if(_MenuNav == 22) sprintf(str, "%16s", "ДО2-Вкл.таймер");
        else if(_MenuNav == 220) 
        { 
            if(_settingsBit & (1 << 3)) 
                sprintf(str, "%16s", "Да*"); 
            else 
    //                LCD_SetPos(15,1);
    //                sendbyte('*', 1);
                sprintf(str, "%16s", "Да"); 
        }
    //        sprintf(str, "%s", "Импульс");
        else if(_MenuNav == 2200) 
        { 
            if(_settingTimerOnDO2 == 0 || _settingTimerOffDO2 == 0)
            {
                _settingTimerOnDO2 = 5;
                _settingTimerOffDO2 = 5;
            }
            bitset(_settingsBit, 3);        //Set bit
            _MenuNav = 220;
        }
    //        sprintf(str, "%s", "Имп.-OK");
        else if(_MenuNav == 221) 
        { 
            if(_settingsBit & (1 << 3))  
                sprintf(str, "%16s", "Нет"); 
            else 
                sprintf(str, "%16s", "Нет*"); 
        }
    //        sprintf(str, "%s", "Постоянный");
        else if(_MenuNav == 2210) 
        { 
            bitclr(_settingsBit, 3);
            _MenuNav = 221;
        }
        if(_MenuNav == 23) sprintf(str, "%16s", "ДО2-Таймер вкл.");
        else if(_MenuNav == 230)
        { 
                sprintf(str, "%4d мин.", _settingTimerOnDO2);
        }
        else if(_MenuNav == 2300)
        {
            _settingTimerOnDO2 = _settingTimerOnDO2;
            _MenuNav == 230;
        }
        if(_MenuNav == 24) sprintf(str, "%16s", "ДО2-Таймер выкл.");
        else if(_MenuNav == 240)
        { 
                sprintf(str, "%4d мин.", _settingTimerOffDO2);
        }
        else if(_MenuNav == 2400)
        {
            _settingTimerOffDO2 = _settingTimerOffDO2;
            _MenuNav == 240;
        }
//        if(_MenuNav == 32) sprintf(str, "%s", "Вкл.нагр.по врм.");
//        else if(_MenuNav == 320)// sprintf(str, "%s", "Да");
//        { 
//            if(_settingsBit & (1 << 2)) 
//                sprintf(str, "%16s", "Да*"); 
//            else 
//                sprintf(str, "%16s", "Да"); 
//        }
//        else if(_MenuNav == 3200)// sprintf(str, "%s", "Да-OK");
//        { 
//            bitset(_settingsBit, 2);
//            _MenuNav = 320;
//        }
//        else if(_MenuNav == 321)// sprintf(str, "%s", "Нет");
//        { 
//            if(_settingsBit & (1 << 2)) 
//                sprintf(str, "%16s", "Нет"); 
//            else 
//                sprintf(str, "%16s", "Нет*"); 
//        }
//        else if(_MenuNav == 3210)// sprintf(str, "%s", "Нет-OK");
//        { 
//            bitclr(_settingsBit, 2);
//            _MenuNav = 321;
//        }
//        if(_MenuNav == 33) sprintf(str, "%s", "Время вкл.нагр.");
//        else if(_MenuNav == 330) sprintf(str, "%s", "15:00");
        
        if(_MenuNav >= 20){
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
    else if(_firstDigitMenu(_MenuNav) == 3){
        sprintf(str, "%16s", "Показания");
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        fEraseString(str);
        
        if(_MenuNav == 30) sprintf(str, "%16s", "Аналог. ввод");
        else if(_MenuNav == 300) sprintf(str, "%3s%3u  %3s%3u", "Ан1:", Analog.AI1, "Aн2:", Analog.AI2);
        if(_MenuNav == 31) sprintf(str, "%16s", "Цифр. ввод");
        else if(_MenuNav == 310) sprintf(str, "%12s%d%d%d%d", "Д.входы:",RB3,RB4,RB5,RB6);
        if(_MenuNav == 32) sprintf(str, "%16s", "Цифр. вывод");
        else if(_MenuNav == 320) sprintf(str, "%12s%d%d%d%d", "Д.выходы:",_tempPinDO&0x08?1:0,_tempPinDO&0x04?1:0,_tempPinDO&0x02?1:0,_tempPinDO&0x01?1:0);
        
        if(_MenuNav >= 30){
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
    else if(_firstDigitMenu(_MenuNav) == 4)
    {
        sprintf(str, "%16s", "Память");
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        if(_MenuNav == 40) sprintf(str, "%16s", "Сохр.тек.настр.");
        else if (_MenuNav == 400) 
        {
            if(flUpdate)
                sprintf(str, "%16s", "Да*");
            else
                sprintf(str, "%16s", "Да");
        }
        else if(_MenuNav == 4000)// sprintf(str, "%s", "Да-OK");
        { 
            flUpdate = TRUE;
            SPI_Write(0,_settingsBit);
            SPI_Write(1,_settingTimeImpDO1>>8);
            SPI_Write(2,_settingTimeImpDO1);
            SPI_Write(3,_settingTimerOnDO2>>8);
            SPI_Write(4,_settingTimerOnDO2);
            SPI_Write(5,_settingTimerOffDO2>>8);
            SPI_Write(6,_settingTimerOffDO2);
            _MenuNav = 400;
        }
//        else if (_MenuNav == 401) 
//        {
//            sprintf(str, "%16s", "Нет");
//        }
//        else if(_MenuNav == 4010)// sprintf(str, "%s", "Да-OK");
//        { 
//            _MenuNav = 401;
//        }
        if(_MenuNav == 41) sprintf(str, "%16s", "Сброс настр. ОЗУ");
        else if (_MenuNav == 410) 
        {
            if(flUpdate)
                sprintf(str, "%16s", "Да*");
            else
                sprintf(str, "%16s", "Да");
        }
        else if(_MenuNav == 4100)
        {
            flUpdate = TRUE;
            _settingsBit = 0;
            _settingTimeImpDO1 = 0;
            _settingTimerOnDO2 = 0;
            _settingTimerOffDO2 = 0;
            _MenuNav = 410;
        }
//        else if (_MenuNav == 411) 
//        {
//            sprintf(str, "%16s", "Нет");
//        }
//        else if(_MenuNav == 4110)
//        {
//            _MenuNav = 411;
//        }
        if(_MenuNav == 42) sprintf(str, "%16s", "Сброс настр. ПЗУ");
        else if (_MenuNav == 420) 
        {
            if(flUpdate)
                sprintf(str, "%16s", "Да*");
            else
                sprintf(str, "%16s", "Да");
        }
        else if(_MenuNav == 4200)
        {
            flUpdate = TRUE;
            
            SPI_Write(0,0);
            SPI_Write(1,0);
            SPI_Write(2,0);
            SPI_Write(3,0);
            SPI_Write(4,0);
            SPI_Write(5,0);
            SPI_Write(6,0);
            
            _MenuNav = 420;
        }
//        else if (_MenuNav == 421) 
//        {
//            sprintf(str, "%16s", "Нет");
//        }
//        else if(_MenuNav == 4210)
//        {
//            _MenuNav = 421;
//        }
        if(_MenuNav >= 40)
        {
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
    else{
        sprintf(str, "%u", _MenuNav);
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        flClearLCD = TRUE;
    }
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
