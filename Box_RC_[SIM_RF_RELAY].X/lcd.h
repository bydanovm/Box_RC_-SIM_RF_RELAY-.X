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
		0x41,	// 0xC0	À 
		0xA0,	// Á
		0x42,	// Â
		0xA1,	// Ã
		0xE0,	// Ä
		0x45,	// Å
		0xA3,	// 0õÑ6 Æ
		0xA4,	// Ç
		0xA5,	// È
		0xA6,	// É
		0x4B,	// Ê
		0xA7,	// Ë
		0x4D,	// Ì
		0x48,	// Í
		0x4F,	// Î
		0xA8,	// Ï
		0x50,	// Ð			
		0x43,	// Ñ			
		0x54,	// Ò			
		0xA9,	// Ó			
		0xAA,	// ô	
		0x58,	// Õ			
		0xE1,	// Ö
		0xAB,	// ×			
		0xAC,	// Ø								
		0xE2,	// Ù			
		0xAD,	// Ú
		0xAE,	// Û
		0x62,	// Ü			
		0xAF,	// Ý			
		0xB0,	// Þ			
		0xB1,	// ß			
		0x61,	// à	
		0xB2,	// á
		0xB3,	// â
		0xB4,	// ã
		0xE3,	// ä
		0x65,	// å
		0xB6,	// æ
		0xB7,	// ç
		0xB8,	// è
		0xB9,	// é
		0xBA,	// ê
		0xBB,	// ë
		0xBC,	// ì
		0xBD,	// í
		0x6F,	// o
		0xBE,	// ï
		0x70,	// ð
		0x63,	// ñ
		0xBF,	// ò
		0x79,	// ó
		0xE4,	// Ô
		0x78,	// õ
		0xE5,	// ö
		0xC0,	// ÷
		0xC1,	// ø
		0xE6,	// ù
		0xC2,	// ú
		0xC3,	// û
		0xC4,	// ü
		0xC5,	// ý
		0xC6,	// þ
		0xC7,	// ÿ
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

//ÑÅÐÄÅ×ÊÎ
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