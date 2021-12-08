// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_BB_DEVICE_H
#define XC_BB_DEVICE_H

#include "config.h" 

//#define TRISSend1Wire TRISBbits.
//#define GPSend1Wire GPIObits.GP0
#define TRISRecieve1Wire TRISBbits.TRISB7
#define GPRecieve1Wire PORTBbits.RB7

//__bit flStartSend;     //стартовый бит
//__bit flStartSendData;     //бит начала передачи данных
//__bit flSendDataRise;     //бит подьема сигнала
//__bit flSendDataDown;     //бит спада сигнала
//__bit flSendBit;     //бит спада сигнала
//__bit flStopBit;     //бит спада сигнала
//__bit flTimerRun; //бит запущенного таймера
//__bit flStartRecieve;     //бит начала передачи
__bit flStartBitRecieve;     //бит начала передачи
__bit flStopBitRecieve;     //бит начала передачи
//__bit flRecieveDone;      //бит успешной передачи
//__bit flStartSendRequest;      //бит успешной передачи
char TMR0_Value = 0;
char cTMR0 = 0;
char cQuantity = 0;     //счётчик принятых ботов
char carrCmd = 0;
char flModeStep = 0;    //числовой флаг шага
//char cSucReq = 0;
//char tGPIO = 0;
//unsigned char tChPow = 0;

//char vTMR1H_Down = 0xFF;
//char vTMR1L_Down = 0x88;
//char vTMR1H_Raise = 0xFE;
//char vTMR1L_Raise = 0x7A;

char arrCmd[4];         //массив принятых данных
//char arrLCDData[4];
//char arrCmdSend[4] = {  //массив данных для передачи
//    0x66,
//    0xA9,
//    0x00,
//    0xFF};

//Далее идет тестовый кусок функций и переменных
//static __bit flMainInit();
//char cMainInit = 0;

//__bit flSearchDevices;
//void fSearchDevices();

//Конец тестового куска

//void fTxDevice(unsigned char cmd); //функция отправки
//void fTxStart();
//void fTxStop();         //функция стопового бита
//void fInterruptTMR0();
//void fInterruptTMR1();
void fInterruptRecieveDevice();     //функция приема, используется в прерывании
//void fTXArrDevice(char address, char function, char data1, char data2); //функция отправки множеста команд - пакета
//unsigned char fCheckPower();

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