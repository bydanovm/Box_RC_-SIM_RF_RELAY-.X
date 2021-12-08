#include "menu.h"
#include "Bb_device.h"
#include "lcd.h"
#include "gsm.h"
#include "temp_ntc.h"

void fMenuStrip(void){  
        
    if(flMenuStrip == 0x01 && flSwitchButton == FALSE){         //������ ����
        if(_MenuNav == 1) _MenuNav = 2;                         //
        else if(_MenuNav >= 20 && _MenuNav < _MenuArr[0] * 10 + 9) _MenuNav /= 10;
        else if(_MenuNav >= 100 && _MenuNav < _MenuArr[0] * 100 + 99) _MenuNav /= 10;
        else if(_MenuNav >= 1000 && _MenuNav < _MenuArr[0] * 1000 + 999) _MenuNav /= 10;
        else _MenuNav = 1;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    else if(flMenuStrip == 0x02 && flSwitchButton == FALSE){    //������ ����
        if(_MenuNav <= 1) _MenuNav = _MenuArr[0];
        else if(_MenuNav >= 10 && _MenuNav < 100){
            if(_MenuNav <= _tempTwoDigit)
                _MenuNav = _tempTwoDigit + _MenuArr[_cellTwoDigit] - 1;
            else
                _MenuNav--;
        }
        else if(_MenuNav >= 100 && _MenuNav < 1000) {
            if(_MenuNav <= (short int)_tempDigit)
                _MenuNav = (short int)((_tempDigit + _SubMenuArr[_firstCell][_secondCell]) - 1);
            else _MenuNav--;
        }
        else if(_MenuNav >= 1000) _MenuNav = _MenuNav;
        else _MenuNav--;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    else if(flMenuStrip == 0x04 && flSwitchButton == FALSE){    //������ �����    
        if(_MenuNav >= _MenuArr[0] && _MenuNav < 10) _MenuNav = 1;
        else if(_MenuNav >= 10 && _MenuNav < 100){
            if(_MenuNav >= _tempTwoDigit + _MenuArr[_cellTwoDigit] - 1)
                _MenuNav = _tempTwoDigit;
            else
                _MenuNav++;
        }
        else if(_MenuNav >= 100 && _MenuNav < 1000) {
            if(_MenuNav >= (short int)((_tempDigit + _SubMenuArr[_firstCell][_secondCell]) - 1))
                _MenuNav = _tempDigit;
            else _MenuNav++;
        }
        else if(_MenuNav >= 1000) _MenuNav = _MenuNav;
        else _MenuNav++;
        flSwitchButton = TRUE;
        flClearLCD = FALSE;
    }
    else if(flMenuStrip == 0x08 && flSwitchButton == FALSE){    //������ ��
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
    if(_MenuNav == 1){  

//        sprintf(str, "%s%3i %s%3d", "��:", strtoint("-50"), "��:", strtoint("23"));
        sprintf(str, "%s%5d %3d", "��:", rThermistor(Analog.AI1), Analog.AI1);
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        sprintf(str, "%7s%4s%5u", "���.��:", LCD_StringOnOff(_tempPinDO,3),_countSecond);
        LCD_SetPos(0,1);
        LCD_string((char*)str);
        
        LCD_SetPos(15,0);
        if(_statGSM_Init == 1)
            sendbyte(6,1);
        else sendbyte(7,1);
//        if(!_flashSecond){
////            LCD_SetPos(15,0);
////            sendbyte(0x03,1);
//            LCD_SetPos(15,0);
//            sendbyte(46,1);
//        }
//        else if(_flashSecond){   
////            LCD_SetPos(14,0);
////            sendbyte(0x04,1);
//            LCD_SetPos(15,0);
//            sendbyte(32,1);
//        }
        
        flClearLCD = TRUE;
    }
    else if(_MenuNav == 2 || _MenuNav/10 == 2 || _MenuNav/100 == 2 || _MenuNav/1000 == 2){  
//        sprintf(str, "%11s %4u", "�����.����.", _MenuNav);
        sprintf(str, "%16s", "�����.����.");
        LCD_SetPos(0,0);
        LCD_string((char*)str);
//        if(_MenuNav == 20) sprintf(str, "%16s", "�����.��������.");
        if(_MenuNav == 20) sprintf(str, "%16s", "�����");
        else if(_MenuNav == 200) sprintf(str, "%1.2s:%1.2s", *ToD.Time_hour, *ToD.Time_minutes);
        else if(_MenuNav == 2000) sprintf(str, "%16s", "OK");
        if(_MenuNav == 21) sprintf(str, "%16s", "����");
        else if(_MenuNav == 210) sprintf(str, "%1.2s.%1.2s.%1.2s", *ToD.Date_day, *ToD.Date_month, *ToD.Date_year);
        else if(_MenuNav == 2100) sprintf(str, "%16s", "OK");
        if(_MenuNav == 22) sprintf(str, "%16s", "���. �����. GSM");
        else if(_MenuNav == 220) { 
            if(_settingsBit & (1 << 0)) 
                sprintf(str, "%16s", "��*"); 
            else 
                sprintf(str, "%16s", "��"); 
        }
        else if(_MenuNav == 2200){
            bitset(_settingsBit, 0);
            if(GSM_Command("AT+CCLK?\r\n")){
                GSM_Get_String(2);
            }
            _MenuNav = 220;
        }//sprintf(str, "%s", "��-OK"); }
        else if(_MenuNav == 221) { //sprintf(str, "%s", "���");
            if(_settingsBit & (1 << 0)) 
                    sprintf(str, "%16s", "���"); 
                else 
                    sprintf(str, "%16s", "���*"); 
        }
        else if(_MenuNav == 2210) { //sprintf(str, "%s", "���-OK");
            bitclr(_settingsBit, 0);
            _MenuNav = 221;
        }
////        if(_MenuNav == 23) sprintf(str, "%s", "����� GSM");
////        else if(_MenuNav == 230) sprintf(str, "%s", "+79001234567");
////        else if(_MenuNav == 2300) sprintf(str, "%s", "OK");
//        if(_MenuNav == 23) sprintf(str, "%16s", "����� GSM");
//        else if(_MenuNav == 230) sprintf(str, "%16s", aBuff_DateTime);
//        else if(_MenuNav == 2300){ 
//            if(GSM_Command("AT+CCLK?\r\n")) { 
//                GSM_Get_String(2);
////                sprintf(str, "%16s", "����� ���������");
//                _MenuNav = 230;
//            }
//            else 
//                sprintf(str, "%16s", "������!");
//        }
////        
//        
        if(_MenuNav >= 20){
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
    else if(_MenuNav == 3 || _MenuNav/10 == 3 || _MenuNav/100 == 3 || _MenuNav/1000 == 3){
//        sprintf(str, "%16s%u", "�����.�����", _MenuNav);    
        sprintf(str, "%16s", "�����.�����");    
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        
        if(_MenuNav == 30) sprintf(str, "%16s", "��1-���/����.");
        else if(_MenuNav == 300) 
        { 
            if(_settingsBit & (1 << 1)) 
                sprintf(str, "%16s", "�������*"); 
            else 
//                LCD_SetPos(15,1);
//                sendbyte('*', 1);
                sprintf(str, "%16s", "�������"); 
        }
//        sprintf(str, "%s", "�������");
        else if(_MenuNav == 3000) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 0);  //Set IMP to 5 sec
            bitset(_settingsBit, 1);        //Set bit IMP
            _MenuNav = 300;
        }
//        sprintf(str, "%s", "���.-OK");
        else if(_MenuNav == 301) 
        { 
            if(_settingsBit & (1 << 1))  
                sprintf(str, "%16s", "����������"); 
            else 
                sprintf(str, "%16s", "����������*"); 
        }
//        sprintf(str, "%s", "����������");
        else if(_MenuNav == 3010) 
        { 
            bitclr(_settingsBit, 1);
            _MenuNav = 301;
        }
//        sprintf(str, "%s", "����.-OK");
        if(_MenuNav == 31) sprintf(str, "%16s", "��1-����� ���.");
        else if(_MenuNav == 310)
        { 
            if(_settingTimeImpDO1 & (1 << 0))  
                sprintf(str, "%16s", "5 ���.*"); 
            else 
                sprintf(str, "%16s", "5 ���."); 
        }
        //sprintf(str, "%16s", "5 ���.");
        else if(_MenuNav == 3100) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 0);
            _MenuNav = 310;
        }
//        else if(_MenuNav == 311)
//        { 
//            if(_settingTimeImpDO1 & (1 << 1))  
//                sprintf(str, "%16s", "10 ���.*"); 
//            else 
//                sprintf(str, "%16s", "10 ���."); 
//        }
//        //sprintf(str, "%16s", "15 ���.");
//        else if(_MenuNav == 3110) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 1);
//            _MenuNav = 311;
//        }
        else if(_MenuNav == 311)
        { 
            if(_settingTimeImpDO1 & (1 << 2))  
                sprintf(str, "%16s", "20 ���.*"); 
            else 
                sprintf(str, "%16s", "20 ���."); 
        }
        //sprintf(str, "%16s", "30 ���.");
        else if(_MenuNav == 3110) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 2);
            _MenuNav = 311;
        }
        else if(_MenuNav == 312) 
        { 
            if(_settingTimeImpDO1 & (1 << 3))  
                sprintf(str, "%16s", "40 ���.*"); 
            else 
                sprintf(str, "%16s", "40 ���."); 
        }
        //sprintf(str, "%16s", "60 ���.");
        else if(_MenuNav == 3120) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 3);
            _MenuNav = 312;
        }
//        else if(_MenuNav == 314) 
//        { 
//            if(_settingTimeImpDO1 & (1 << 4))  
//                sprintf(str, "%16s", "80 ���.*"); 
//            else 
//                sprintf(str, "%16s", "80 ���."); 
//        }
//        //sprintf(str, "%16s", "90 ���.");
//        else if(_MenuNav == 3140) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 4);
//            _MenuNav = 314;
//        }
//        else if(_MenuNav == 315) 
//        { 
//            if(_settingTimeImpDO1 & (1 << 5))  
//                sprintf(str, "%16s", "160 ���.*"); 
//            else 
//                sprintf(str, "%16s", "160 ���."); 
//        }
//        //sprintf(str, "%16s", "180 ���.");
//        else if(_MenuNav == 3150) 
//        { 
//            _settingTimeImpDO1 = 0;
//            bitset(_settingTimeImpDO1, 5);
//            _MenuNav = 315;
//        }
        else if(_MenuNav == 313) 
        { 
            if(_settingTimeImpDO1 & (1 << 6))  
                sprintf(str, "%16s", "320 ���.*"); 
            else 
                sprintf(str, "%16s", "320 ���."); 
        }
//        sprintf(str, "%16s", "300 ���.");
        else if(_MenuNav == 3130) 
        { 
            _settingTimeImpDO1 = 0;
            bitset(_settingTimeImpDO1, 6);
            _MenuNav = 313;
        }
//        if(_MenuNav == 32) sprintf(str, "%s", "���.����.�� ���.");
//        else if(_MenuNav == 320)// sprintf(str, "%s", "��");
//        { 
//            if(_settingsBit & (1 << 2)) 
//                sprintf(str, "%16s", "��*"); 
//            else 
//                sprintf(str, "%16s", "��"); 
//        }
//        else if(_MenuNav == 3200)// sprintf(str, "%s", "��-OK");
//        { 
//            bitset(_settingsBit, 2);
//            _MenuNav = 320;
//        }
//        else if(_MenuNav == 321)// sprintf(str, "%s", "���");
//        { 
//            if(_settingsBit & (1 << 2)) 
//                sprintf(str, "%16s", "���"); 
//            else 
//                sprintf(str, "%16s", "���*"); 
//        }
//        else if(_MenuNav == 3210)// sprintf(str, "%s", "���-OK");
//        { 
//            bitclr(_settingsBit, 2);
//            _MenuNav = 321;
//        }
//        if(_MenuNav == 33) sprintf(str, "%s", "����� ���.����.");
//        else if(_MenuNav == 330) sprintf(str, "%s", "15:00");
        
        if(_MenuNav >= 30){
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
    else if(_MenuNav == 4 || _MenuNav/10 == 4 || _MenuNav/100 == 4 || _MenuNav/1000 == 4){
//        sprintf(str, "%s%u", "���������", _MenuNav);
        sprintf(str, "%16s", "���������");
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        
        if(_MenuNav == 40) sprintf(str, "%16s", "������. ����");
        else if(_MenuNav == 400) sprintf(str, "%3s%3u  %3s%3u", "��1:", Analog.AI1, "A�2:", Analog.AI2);
//        else if(_MenuNav == 401) sprintf(str, "%s%3u %s%3u", "��3:",cACP, "A�4:", cACP);
        if(_MenuNav == 41) sprintf(str, "%16s", "����. ����");
        else if(_MenuNav == 410) sprintf(str, "%12s%d%d%d%d", "�.�����:",RB3,RB4,RB5,RB6);
        if(_MenuNav == 42) sprintf(str, "%16s", "����. �����");
        else if(_MenuNav == 420) sprintf(str, "%12s%d%d%d%d", "�.������:",_tempPinDO&0x08?1:0,_tempPinDO&0x04?1:0,_tempPinDO&0x02?1:0,_tempPinDO&0x01?1:0);
//        if(_MenuNav == 43) sprintf(str, "%s", "�����. ��");
//        else if(_MenuNav == 430) sprintf(str, "%X %X %X %X", arrCmd[0], arrCmd[1], arrCmd[2], arrCmd[3]);
        
        if(_MenuNav >= 40){
            LCD_SetPos(0,1);
            LCD_string((char*)str);
        }
        flClearLCD = TRUE;
    }
//    else if(_MenuNav == 5 || _MenuNav/10 == 5 || _MenuNav/100 == 5 || _MenuNav/1000 == 5){
////        sprintf(str, "%16s%u", "�����", _MenuNav);
//        sprintf(str, "%16s", "�����");
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        
//        if(_MenuNav == 50) sprintf(str, "%16s", "����� ���.�����.");
//        else if (_MenuNav == 500) {
//            RB3 = FALSE;
//            RB4 = FALSE;
//            RB5 = FALSE;
//            RB6 = FALSE;
//            
//            RA2 = FALSE;
//            RA4 = FALSE;
//            RA5 = FALSE;
//            RB1 = FALSE;
//            
//            for (char i=0; i<sizeof(arrCmd); i++) arrCmd[i] = 0;
//            sprintf(str, "%16s", "����� �.�.-��");
//            _MenuNav = 50;
//        }
////        if(_MenuNav == 51) sprintf(str, "%16s", "����� ��������");
////        if(_MenuNav == 52) sprintf(str, "%16s", "��������� SIM");
////        else if(_MenuNav == 520) sprintf(str, "%16s", aBuff_TextMessage);
////        else if(_MenuNav == 5200){ 
////            if(GSM_Command("AT+CPMS?\r\n")) { 
////                GSM_Get_String(3);
////                _MenuNav = 520;
//////                sprintf(str, "%16s", "����� ���������");
////            }
////            else 
////                sprintf(str, "%16s", "������!");
////        }
////        else if(_MenuNav == 521) sprintf(str, "%16s", "������� SIM");
////        else if(_MenuNav == 5210){ 
////            if(GSM_Command("AT+CMGDA=\"DEL ALL\"\r\n")) { 
//////                GSM_Get_String(3);
//////                sprintf(str, "%16s", "����� ���������");
////                _MenuNav = 521;
////            }
////            else 
////                sprintf(str, "%16s", "������!");
////        }
//        if(_MenuNav >= 50){
//            LCD_SetPos(0,1);
//            LCD_string((char*)str);
//        }
//        flClearLCD = TRUE;
//    }
    else{
        sprintf(str, "%u", _MenuNav);
        LCD_SetPos(0,0);
        LCD_string((char*)str);
        flClearLCD = TRUE;
    }
}
//void fMenuStrip(void){   
//    char iMenu = 0;
//    if(flMenuStrip == 0x01 && flSwitchButton == FALSE){         //������ ����
//        if(flMenuNav[0][2] != 0x00) {
//            flMenuNav[0][2] = 0x00; 
//            flSwitchButton = TRUE;
//            flClearLCD = FALSE;
//            return; 
//        }
//        else if(flMenuNav[0][0] == 0x00) flMenuNav[0][0] |= 0x01;
//        else if(flMenuNav[0][0] >= 0x01 && flMenuNav[0][0] < 0x10) flMenuNav[0][0]<<=1;
//        else if(flMenuNav[0][0] == 0x10) flMenuNav[0][0] = 0x01;
////        LCD_clear();
//        flMenuNav[0][1] = 0x01;
//        flMenuNav[0][2] = 0x00;
//        flSwitchButton = TRUE;
//        flClearLCD = FALSE;
//    }
//    else if(flMenuStrip == 0x02 && flSwitchButton == FALSE){    //������ �����    
////        if(flMenuNav[0][2] != 0x00) iMenu = 2; 
//        iMenu = 1;
//        if(flMenuNav[0][2] == 0x00) flMenuNav[0][iMenu]>>=1;
//        if(flMenuNav[0][iMenu] == 0x00) flMenuNav[0][iMenu] = 0x08;
////        else if(flMenuNav[0][iMenu] > 0x01 && flMenuNav[0][iMenu] <= 0x08) flMenuNav[0][iMenu]>>=1;
////        else if(flMenuNav[0][iMenu] == 0x01) flMenuNav[0][iMenu] = 0x08;
////        flMenuNav[0][2] = 0x00;
//        flSwitchButton = TRUE;
//        flClearLCD = FALSE;
//    }
//    else if(flMenuStrip == 0x04 && flSwitchButton == FALSE){    //������ ������
////        if(flMenuNav[0][2] != 0x00) iMenu = 2; 
//        iMenu = 1;
//        if(flMenuNav[0][2] == 0x00) flMenuNav[0][iMenu]<<=1;
//        if(flMenuNav[0][iMenu] == 0x10) flMenuNav[0][iMenu] = 0x01;
////        else if(flMenuNav[0][iMenu] >= 0x01 && flMenuNav[0][iMenu] < 0x08) flMenuNav[0][iMenu]<<=1;
////        else if(flMenuNav[0][iMenu] == 0x08) flMenuNav[0][iMenu] = 0x01;
////        flMenuNav[0][2] = 0x00;
//        flSwitchButton = TRUE;
//        flClearLCD = FALSE;
//    }
//    else if(flMenuStrip == 0x08 && flSwitchButton == FALSE){    //������ ��
//        if(flMenuNav[0][1] != 0x00) flMenuNav[0][2] = flMenuNav[0][1];
//        flSwitchButton = TRUE;
//        flClearLCD = FALSE;
//    }
//    if(flClearLCD == FALSE) LCD_clear();
//    if(flMenuNav[0][0] == 0x01){  
//        sprintf(str, "%s%3i %s%3i", "��:", -50, "��:", 23);
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        sprintf(str, "%s%s", "����. ��: ", LCD_StringOnOff(PORTA,5));
//        LCD_SetPos(0,1);
//        LCD_string((char*)str);
//        
//        if(heart <= 40){
//            LCD_SetPos(14,0);
//            sendbyte(0x02,1);
//            LCD_SetPos(15,0);
//            sendbyte(0x03,1);
//        }
//        else if(heart > 40 && heart <= 80){   
//            LCD_SetPos(14,0);
//            sendbyte(0x04,1);
//            LCD_SetPos(15,0);
//            sendbyte(0x05,1);
//        }
//        else heart = 0;
//        flClearLCD = TRUE;
//    }
//    else if(flMenuNav[0][0] == 0x02){  
//        sprintf(str, "%s", "��������� ����.");
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        
//        if(flMenuNav[0][1] == 0x01) sprintf(str, "%s", "�����");
//        if(flMenuNav[0][1] == 0x02) sprintf(str, "%s", "����");
//        if(flMenuNav[0][1] == 0x04) sprintf(str, "%s", "����� GSM");
//        if(flMenuNav[0][1] == 0x08 && flMenuNav[0][2] != 0x08) sprintf(str, "%s", "����� GSM");
//        else if(flMenuNav[0][1] == 0x08 && flMenuNav[0][2] == 0x08){
//            if(GSM_Command("AT+CCLK?\r\n")){
//                GSM_Get_String(2);
//                sprintf(str, "%s", aBuff_DateTime);
//            }
//        }
//        
//        LCD_SetPos(0,1);
//        LCD_string((char*)str);
//        flClearLCD = TRUE;
//    }
//    else if(flMenuNav[0][0] == 0x04){
//        sprintf(str, "%s", "��������� ���.");        
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        
//        if(flMenuNav[0][1] == 0x01  && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "��1-���/����.");
//        else if(flMenuNav[0][1] == 0x01 && flMenuNav[0][2] == 0x01) sprintf(str, "%s", "������� 2 ���.");
//        else if(flMenuNav[0][1] == 0x01 && flMenuNav[0][2] == 0x02) sprintf(str, "%s", "����������");
//        if(flMenuNav[0][1] == 0x02  && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "��1-����� ���.");
//        else if(flMenuNav[0][1] == 0x02 && flMenuNav[0][2] == 0x02) sprintf(str, "%s%d%d%d%d", "�.�����:",RB3,RB4,RB5,RB6);
//        if(flMenuNav[0][1] == 0x04  && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "����� 3");
//        else if(flMenuNav[0][1] == 0x04 && flMenuNav[0][2] == 0x04) sprintf(str, "%s%d%d%d%d", "�.������:",RA2,RA4,RA5,RB1);
//        if(flMenuNav[0][1] == 0x08  && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "���.����.�� ���.");
//        else if(flMenuNav[0][1] == 0x08 && flMenuNav[0][2] == 0x08) sprintf(str, "%X %X %X %X", arrLCDData[0], arrLCDData[1], arrLCDData[2], arrLCDData[3]);
//        
//        LCD_SetPos(0,1);
//        LCD_string((char*)str);
//        flClearLCD = TRUE;
//    }
//    else if(flMenuNav[0][0] == 0x08){
//        sprintf(str, "%s", "���������");        
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        
//        if(flMenuNav[0][1] == 0x01 && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "������. ����");
//        else if(flMenuNav[0][1] == 0x01 && flMenuNav[0][2] == 0x01) sprintf(str, "%s%3u %s%3u", "��1:",cACP, "A�2:", cACP);
//        if(flMenuNav[0][1] == 0x02 && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "����. ����");
//        else if(flMenuNav[0][1] == 0x02 && flMenuNav[0][2] == 0x02) sprintf(str, "%s%d%d%d%d", "�.�����:",RB3,RB4,RB5,RB6);
//        if(flMenuNav[0][1] == 0x04 && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "����. �����");
//        else if(flMenuNav[0][1] == 0x04 && flMenuNav[0][2] == 0x04) sprintf(str, "%s%d%d%d%d", "�.������:",RA2,RA4,RA5,RB1);
//        if(flMenuNav[0][1] == 0x08 && flMenuNav[0][2] == 0x00) sprintf(str, "%s", "�����. ��");
//        else if(flMenuNav[0][1] == 0x08 && flMenuNav[0][2] == 0x08) { 
////                                                                        
//                                                                   }
////        else if(flMenuNav[0][1] == 0x08 && flMenuNav[0][1] == 0x08) sprintf(str, "%X %X %X %X", arrLCDData[0], arrLCDData[1], arrLCDData[2], arrLCDData[3]);
//        __delay_ms(100); 
//        LCD_SetPos(0,1);
//        LCD_string((char*)str);
//        flClearLCD = TRUE;
//    }
//    else if(flMenuNav[0][0] == 0x10){
//        sprintf(str, "%s %X %X", "�����", flMenuNav[0][0], flMenuNav[0][1]);        
//        LCD_SetPos(0,0);
//        LCD_string((char*)str);
//        
//        if((flMenuNav[0][1] == 0x01 || flMenuNav[0][1] == 0x04) && flMenuNav[0][2] == 0) sprintf(str, "%s", "����� ���.�����.");
//        else if ((flMenuNav[0][1] == 0x01 || flMenuNav[0][1] == 0x04) && (flMenuNav[0][2] == 0x01 || flMenuNav[0][2] == 0x04)) {
//            RB3 = FALSE;
//            RB4 = FALSE;
//            RB5 = FALSE;
//            RB6 = FALSE;
//            
//            RA2 = FALSE;
//            RA4 = FALSE;
//            RA5 = FALSE;
//            RB1 = FALSE;
//            
//            for (char i=0; i<sizeof(arrLCDData); i++) arrLCDData[i] = 0;
//            
//            flMenuNav[0][2] = 0x00;
//        }
//        if((flMenuNav[0][1] == 0x02 || flMenuNav[0][1] == 0x08) && flMenuNav[0][2] == 0) sprintf(str, "%s", "����� ��������");
//        
//        LCD_SetPos(0,1);
//        LCD_string((char*)str);
//        flClearLCD = TRUE;
//    }
//}
