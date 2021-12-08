#include "shift_registr.h"

void fShiftData(unsigned char shiftVar){
    short int shiftVariable = 0;
    shiftVariable = _tempPinDO;
    shiftVariable <<= 8;
    shiftVariable |= shiftVar;
    for(char i = 0; i < 16; i++)
    {
        if(shiftVariable & 0x0001)
            pinDS = 1;
        else
            pinDS = 0;
        __delay_us(3);
//        __delay_us(20);
        shiftVariable >>= 1;
        pinSH = 1;
        __delay_us(3);
//        __delay_us(20);
        pinSH = 0;
    }
    pinST = 1;
    __delay_us(3);
//    __delay_us(20);
    pinST = 0;
}

//void doubleShiftData(unsigned char firstVar, unsigned char secondVar){
//    fShiftData(firstVar);
//    fShiftData(secondVar);
//}