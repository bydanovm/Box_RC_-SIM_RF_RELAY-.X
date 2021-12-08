#include "shift_registr.h"

void fShiftData(unsigned char numberPin){    //Function FOR set bit to pin's shift registr 
    for(char i = 0; i < 8; i++)
    {
        if(numberPin & 0x01)
            pinDS = 1;
        else
            pinDS = 0;
        __delay_us(3);
//        __delay_us(20);
        numberPin >>= 1;
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