// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_LCD_H
#define XC_LCD_H

//#include <xc.h>
#include "config.h"
//#define _XTAL_FREQ 20000000
unsigned char str[16];

void LCD_PORT_init();
void LCD_init();
void LCD_clear();
void sendbyte(unsigned char c, unsigned char mode);
void sendhalfbyte(unsigned char c);
void LCD_string(char* st);
void LCD_SetPos(unsigned char x, unsigned char y);
char* LCD_StringOnOff(char st,char numb);
const char SHRIFT[] = {
		0x41,	// 0xC0	� 
		0xA0,	// �
		0x42,	// �
		0xA1,	// �
		0xE0,	// �
		0x45,	// �
		0xA3,	// 0��6 �
		0xA4,	// �
		0xA5,	// �
		0xA6,	// �
		0x4B,	// �
		0xA7,	// �
		0x4D,	// �
		0x48,	// �
		0x4F,	// �
		0xA8,	// �
		0x50,	// �			
		0x43,	// �			
		0x54,	// �			
		0xA9,	// �			
		0xAA,	// �	
		0x58,	// �			
		0xE1,	// �
		0xAB,	// �			
		0xAC,	// �								
		0xE2,	// �			
		0xAD,	// �
		0xAE,	// �
		0x62,	// �			
		0xAF,	// �			
		0xB0,	// �			
		0xB1,	// �			
		0x61,	// �	
		0xB2,	// �
		0xB3,	// �
		0xB4,	// �
		0xE3,	// �
		0x65,	// �
		0xB6,	// �
		0xB7,	// �
		0xB8,	// �
		0xB9,	// �
		0xBA,	// �
		0xBB,	// �
		0xBC,	// �
		0xBD,	// �
		0x6F,	// o
		0xBE,	// �
		0x70,	// �
		0x63,	// �
		0xBF,	// �
		0x79,	// �
		0xE4,	// �
		0x78,	// �
		0xE5,	// �
		0xC0,	// �
		0xC1,	// �
		0xE6,	// �
		0xC2,	// �
		0xC3,	// �
		0xC4,	// �
		0xC5,	// �
		0xC6,	// �
		0xC7,	// �
};
unsigned char noConnectionModem[8]={ 
0b00011, 
0b00110, 
0b01100, 
0b10000, 
0b10101, 
0b10010, 
0b10101, 
0b00000
}; 
unsigned char yesConnectionModem[8]={ 
0b00011, 
0b00111, 
0b01111, 
0b11111, 
0b11111, 
0b11111, 
0b11111, 
0b00000
}; 
//
//unsigned char char1[8]={ 
//0b00000011,
//0b00000110,
//0b00001100,
//0b00011000,
//0b00011000,
//0b00001100,
//0b00000110,
//0b00000011}; 

//��������
//unsigned char char2[8]={ 
//	0b01110,
//	0b10001,
//	0b10000,
//	0b01000,
//	0b00100,
//	0b00010,
//	0b00001,
//	0b00000
//};
//unsigned char char3[8] = {
//	0b10001,
//	0b01110,
//	0b01111,
//	0b10111,
//	0b11011,
//	0b11101,
//	0b11110,
//	0b11111
//};
//unsigned char char4[8] = {
//	0b01110,
//	0b10001,
//	0b00001,
//	0b00010,
//	0b00100,
//	0b01000,
//	0b10000,
//	0b00000
//};
//unsigned char char5[8] = {
//	0b10001,
//	0b01110,
//	0b11110,
//	0b11101,
//	0b11011,
//	0b10111,
//	0b01111,
//	0b11111
//};

void define_char(unsigned char pc[],unsigned char char_code);

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