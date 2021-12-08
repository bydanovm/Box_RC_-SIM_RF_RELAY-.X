// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_SHIFT_REGISTR_H
#define XC_SHIFT_REGISTR_H
#include "config.h"

#define pinDS PORTBbits.RB0 
#define pinSH PORTBbits.RB2
#define pinST PORTBbits.RB1

//char aDigital[20] = {
//    0b00001000, //0 : 0
//    0b01101011, //1 : 1
//    0b00100100, //2 : 2
//    0b00100001, //3 : 3
//    0b01000011, //4 : 4
//    0b00010001, //5 : 5
//    0b00010000, //6 : 6
//    0b00101011, //7 : 7
//    0b00000000, //8 : 8
//    0b00000001, //9 : 9
//    0b01110111, //- : 10
//    0b01000001, //Y : 11
//    0b00010100, //E : 12
//    0b00010001, //S : 13
//    0b01000010, //H : 14
//    0b01111110, //i : 15
//    0b01011100, //L : 16
//    0b01110000, //o : 17
//    0b01111100, //r : 18
//    0b10000000  //L1 : 19   
//};
//char aNumbers[8] = {
//    0b00100100, //D1 : 0
//    0b00110000, //D2 : 1
//    0b00101000, //D3 : 2
//    0b01100000, //D4 : 3
//    0b10100000, //L2 : 4
//    0b00100010, //R1 : 5
//    0b00100001, //R2 : 6
//    0b00000000  //DP : 7
//};

void fShiftData(unsigned char numberPin);

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