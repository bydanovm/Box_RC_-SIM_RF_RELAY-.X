// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_CONFIG_H
#define XC_CONFIG_H

#pragma jis
/* for 16F76
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bit (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
*/
// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HSPLL         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//#define _XTAL_FREQ 8000000
#define _XTAL_FREQ 32000000
#define _Baud_Rate 38400

#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))
#define bitsel(var, bitno) ((var) & (1UL<<bitno)) >> (bitno - 1UL))
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char cACP;
//__EEPROM_DATA(0x66,0xA6,0x00,0x00,0x00,0x00,0x00,0x00);      
//__EEPROM_DATA(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);
//__EEPROM_DATA(0x00,0x00,0,0,0,0,0,0);
//__EEPROM_DATA(0x00,0x00,0,0,0,0,0,0);
//__EEPROM_DATA(0x00,0x00,0,0,0,0,0,0);
//__EEPROM_DATA(0x00,0x00,0,0,0,0,0,0);

unsigned char counter;
char TMR0_Value;
char cTMR0;
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

char _statGSM_Init = 0;

struct TimeOfDay{ 
    unsigned char *Date_day[2];
    unsigned char *Date_month[2];
    unsigned char *Date_year[2];
    unsigned char *Time_hour[2];
    unsigned char *Time_minutes[2];
//    unsigned char *Time_second;
};

struct TimeOfDay ToD = {"01","01","01","01","01"};//,0};

unsigned char _settingsBit;
//0 bit - Enable Time GSM
//1 bit - DO1 Imp/Const
//2 bit - On Heat on Time
//3 bit - 
//4 bit - reserv
//5 bit - reserv
//6 bit - reserv
//7 bit - reserv
unsigned char _settingTimeImpDO1;
//0 bit - 5 sec
//1 bit - 15 sec
//2 bit - 30 sec
//3 bit - 60 sec
//4 bit - 90 sec
//5 bit - 180 sec
//6 bit - 300 sec
//7 bit - reserv
unsigned char _tempPinDO;
//0 bit - DO4
//1 bit - DO3
//2 bit - DO2
//3 bit - DO4
//4 bit - reserv
//5 bit - reserv
//6 bit - reserv
//7 bit - reserv
typedef struct {
    unsigned char AI0;
    unsigned char AI1;
    unsigned char AI2;
    unsigned char AI3;
} AnalogInput;

AnalogInput Analog = {0, 127, 254, 90};

void init(void);
short int strtoint(char *string);

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