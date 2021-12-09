// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_CONFIG_H
#define XC_CONFIG_H

#pragma jis
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bit (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)

#define _XTAL_FREQ 8000000
#define _Baud_Rate 38400

#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))
#define bitsel(var, bitno) ((var) & (1UL<<bitno)) >> (bitno - 1UL))
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

char cACP;

unsigned char counter;
extern char TMR0_Value;
extern char cTMR0;
extern void SPI_Write(unsigned int address, unsigned char  data);
extern char SPI_Read(unsigned int address);
char _countTMR2trigger; //подсчёт количества срабатываний TMR2
unsigned short int _countSecond;
//unsigned short int _countMinute;
//unsigned short int _countHour;

__bit _100ms;
__bit _250ms;
__bit _500ms;
__bit _second;
__bit _flashSecond;
__bit _minute;
__bit _hour;
__bit flDO1;

//char _statGSM_Init = 0;

//struct TimeOfDay{ 
//    unsigned char *Date_day[2];
//    unsigned char *Date_month[2];
//    unsigned char *Date_year[2];
//    unsigned char *Time_hour[2];
//    unsigned char *Time_minutes[2];
////    unsigned char *Time_second;
//};
//
//struct TimeOfDay ToD = {"01","01","01","01","01"};//,0};
struct AnalogInput{
    unsigned char AI0;
    unsigned char AI1;
    unsigned char AI2;
    unsigned char AI3;
};
struct AnalogInput Analog;

unsigned char _settingsBit;//0 cell in spi flash
//0 bit - Enable Time GSM
//1 bit - DO1 Imp/Const
//2 bit - On Heat on Time
//3 bit - DO2 Timer On
//4 bit - DO2 On at low temp
//5 bit - reserv
//6 bit - reserv
//7 bit - reserv
unsigned int _settingTimeImpDO1;//1 cell in spi flash
unsigned int _settingTimerOnDO2;
unsigned int _settingTimerOffDO2;    
short int _timerDO1 = 0;
short int _timerDO2 = 0;
unsigned char _tempPinDO;
//0 bit - DO1
//1 bit - DO3
//2 bit - DO2
//3 bit - DO4
//4 bit - reserv
//5 bit - reserv
//6 bit - reserv
//7 bit - reserv

//AnalogInput Analog;// = {0, 127, 254, 90};

void init(void);
//short int strtoint(char *string);
void fEraseString(char* string);

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