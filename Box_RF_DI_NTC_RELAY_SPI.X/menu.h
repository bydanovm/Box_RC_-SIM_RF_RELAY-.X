// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MENU_H
#define XC_MENU_H

#include "config.h"
//#include <xc.h>

#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))

#define TRUE 1
#define FALSE 0

char flMenuStrip = 0;    

short int _MenuNav = 1;
unsigned char _MenuArr[10] = {4, 6, 3, 3, 0, 0, 0, 0, 0, 0};//1, 20, 30, 40, 50
unsigned char _SubMenuArr[4][6] = 
{
    {2,1,2,1,1,2},//ур2-1 20 21 22 23 24 25
    {1,1,1,0,0,0},//ур2-2 30 31 32 33 34 35
    {1,1,1,0,0,0},//ур2-3 40 41 42 43 44 45
    {0,0,0,0,0,0} //ур2-4 50 51 52 53 54 55
};
unsigned char _firstCell = 0;
unsigned char _secondCell = 0;
unsigned short int _tempDigit = 0;
unsigned char _cellTwoDigit = 0;
unsigned char _tempTwoDigit = 0;
__bit flUpdate;

extern short int _timerDO1;
extern short int _timerDO2;

extern unsigned short int _countSecond;
extern unsigned char _tempPinDO;    
extern unsigned char _settingsBit;
extern int _settingTimeImpDO1;
extern int _settingTimerOnDO2;
extern int _settingTimerOffDO2;
extern signed char temperatureAI1;
extern signed char temperatureAI2;
extern unsigned char str[16];
extern unsigned char str2[16];
extern void LCD_clear();
extern void LCD_string(char* st);
extern void LCD_SetPos(unsigned char x, unsigned char y);
extern void sendbyte(unsigned char c, unsigned char mode);
extern char* LCD_StringOnOff(char st,char numb);
extern void SPI_Write(long int address, char data);
extern char SPI_Read(long int address);
//extern struct TimeOfDay ToD;
//extern typedef struct {
//    unsigned char AI0;
//    unsigned char AI1;
//    unsigned char AI2;
//    unsigned char AI3;
//} AnalogInput;
//extern struct AnalogInput Analog;
//extern unsigned char _settingsBit;
//extern unsigned short int _countSecond;
//extern unsigned char _tempPinDO;
////char heart = 0;
//int temp_V = 50;
__bit flClearLCD;
__bit flSwitchButton;

    
void fMenuStrip(void);
void fShowStar(unsigned char position, unsigned char string);

unsigned char _firstDigitMenu(short int _digit);

//struct menuItem{
//    unsigned char          *Name;
//	unsigned char          Select;	
//    unsigned char          Id;
//};
//
//struct menuItem Menu[4] = 
//{
//    {"Главное меню    ",    0, 0},//     
//    {"Показания       ",    0, 1},//     
//    {"Показания       ",    0, 2},//     
//    {"Показания       ",    0, 3},//  
//};

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