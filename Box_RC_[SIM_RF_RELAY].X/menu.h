// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MENU_H
#define XC_MENU_H

#include "config.h"

char flMenuStrip = 0;    

short int _MenuNav = 1;
unsigned char _MenuArr[10] = {4, 3, 2, 3, 1, 0, 0, 0, 0, 0};//1, 20, 30, 40, 50
unsigned char _SubMenuArr[4][5] = 
{
    {1,1,2,1,0},//ур2-1 20 21 22 23 24
    {2,4,0,0,0},//ур2-2 30 31 32 33 34
    {1,1,1,0,0},//ур2-3 40 41 42 43 44
    {1,0,0,0,0} //ур2-4 50 51 52 53 54
};
unsigned char _firstCell = 0;
unsigned char _secondCell = 0;
unsigned short int _tempDigit = 0;
unsigned char _cellTwoDigit = 0;
unsigned char _tempTwoDigit = 0;

//char heart = 0;
//int temp_V = 50;
__bit flClearLCD;
__bit flSwitchButton;

    
void fMenuStrip(void);

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