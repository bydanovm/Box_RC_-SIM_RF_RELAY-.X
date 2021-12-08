#include "config.h"
//#include "extern.h"


void init(void){ 
    //Регистр TRISA
    TRISAbits.TRISA0        = TRUE;
    TRISAbits.TRISA1        = TRUE;
    TRISAbits.TRISA2        = FALSE;
    TRISAbits.TRISA3        = TRUE;
    TRISAbits.TRISA4        = FALSE;
    TRISAbits.TRISA5        = FALSE;
    //Регистр TRISB
    TRISBbits.TRISB0        = FALSE;
    TRISBbits.TRISB1        = FALSE;
    TRISBbits.TRISB2        = FALSE;
    TRISBbits.TRISB3        = TRUE;
    TRISBbits.TRISB4        = TRUE;
    TRISBbits.TRISB5        = TRUE;
    TRISBbits.TRISB6        = TRUE;
    TRISBbits.TRISB7        = TRUE;
    //Регистр TRISC
    TRISCbits.TRISC0        = FALSE;
    TRISCbits.TRISC1        = FALSE;
    TRISCbits.TRISC2        = FALSE;
    TRISCbits.TRISC3        = FALSE;
    TRISCbits.TRISC4        = FALSE;
    TRISCbits.TRISC5        = FALSE;
    TRISCbits.TRISC6        = TRUE;
    TRISCbits.TRISC7        = TRUE;
    //Регистр PORTX
    PORTA = 0x0; 
    PORTB = 0x0;
    PORTC = 0x0;
    //Регистр OPTION_REG
    OPTION_REGbits.nRBPU    = TRUE;
    OPTION_REGbits.INTEDG   = FALSE;
    OPTION_REGbits.T0CS     = FALSE;
    OPTION_REGbits.T0SE     = FALSE;
    OPTION_REGbits.PSA      = FALSE;
    OPTION_REGbits.PS2      = TRUE;
    OPTION_REGbits.PS1      = TRUE;
    OPTION_REGbits.PS0      = TRUE;
    //Регистр INTCON
    INTCONbits.GIE          = TRUE;
    INTCONbits.PEIE         = TRUE;
    INTCONbits.T0IE         = FALSE;
    INTCONbits.INTE         = FALSE;
    INTCONbits.RBIE         = TRUE;
    //Регистр PIE1
    PIE1bits.ADIE           = TRUE;
    PIE1bits.RCIE           = TRUE;
    PIE1bits.TXIE           = FALSE;
    PIE1bits.SSPIE          = FALSE;
    PIE1bits.TMR2IE         = TRUE;
    PIE1bits.TMR1IE         = TRUE;
    //Регистр PIE2
    PIE2bits.CCP2IE         = FALSE;
    //Регистр T1CON
    T1CONbits.T1CKPS1       = FALSE;  // bits 5-4  Prescaler Rate Select bits
    T1CONbits.T1CKPS0       = TRUE;
    T1CONbits.T1OSCEN       = FALSE;  // bit 3 Timer1 Oscillator Enable Control: bit 1=on
    T1CONbits.nT1SYNC       = FALSE;  // bit 2 Timer1 External Clock Input Synchronization Control bit: 1=Do not synchronize external clock input
    T1CONbits.TMR1CS        = FALSE;   // bit 1 Timer1 Clock Source Select bit: 0=Internal clock (FOSC/4) / 1 = External clock from pin T1CKI (on the rising edge)
    T1CONbits.TMR1ON        = FALSE;
    //Регистр T2CON
    T2CONbits.TOUTPS3       = TRUE;
    T2CONbits.TOUTPS2       = TRUE;
    T2CONbits.TOUTPS1       = TRUE;
    T2CONbits.TOUTPS0       = TRUE;
    T2CONbits.TMR2ON        = TRUE;
    T2CONbits.T2CKPS1       = TRUE;
    T2CONbits.T2CKPS0       = FALSE;
    
    TMR2 = 195;
    //Регистр SSPSTAT
    SSPSTATbits.SMP         = FALSE; //бит управления скоростью потока 
    SSPSTATbits.CKE         = FALSE; //Выбор фронта передачи сигнала
    SSPSTATbits.D_nA        = FALSE; //бит данных/адреса
    SSPSTATbits.P           = FALSE; //бит Stop
    SSPSTATbits.S           = FALSE; //бит Start
    SSPSTATbits.R_nW        = FALSE; //чтение/запись
    SSPSTATbits.UA          = FALSE; //флаг обновления адреса устройства
    SSPSTATbits.BF          = FALSE; //флаг заполнения буфера
    //Регистр SSPCON
    SSPCONbits.WCOL         = FALSE; //флаг обнаружения коллизии
    SSPCONbits.SSPOV        = FALSE; //флаг переполнения
    SSPCONbits.SSPEN        = FALSE; //включение модуля MSSP
    SSPCONbits.CKP          = FALSE; //бит управления тактирования
    SSPCONbits.SSPM3        = FALSE; //биты выбора режима работы модуля MSSP
    SSPCONbits.SSPM2        = FALSE;
    SSPCONbits.SSPM1        = FALSE;
    SSPCONbits.SSPM0        = FALSE;
    //Регистр TXSTA
    TXSTAbits.CSRC          = FALSE;
    TXSTAbits.TX9           = FALSE;
    TXSTAbits.TXEN          = TRUE;
    TXSTAbits.SYNC          = FALSE;
    TXSTAbits.BRGH          = TRUE;
    TXSTAbits.TRMT          = FALSE;
    TXSTAbits.TX9D          = FALSE;
    //Регистр RCSTA
    RCSTAbits.SPEN          = TRUE;
    RCSTAbits.RX9           = FALSE;
    RCSTAbits.SREN          = FALSE;
    RCSTAbits.CREN          = TRUE;
    RCSTAbits.FERR          = FALSE;
    RCSTAbits.OERR          = FALSE;
    RCSTAbits.RX9D          = FALSE;
    //Регистр SPBRG
    if(TXSTAbits.BRGH)
        SPBRG               = (char)((_XTAL_FREQ/_Baud_Rate)/16)-1;
    else
        SPBRG               = (char)((_XTAL_FREQ/_Baud_Rate)/64)-1;
    ////ADCON0/////
    ADCON0bits.ADCS1        = FALSE;
    ADCON0bits.ADCS0        = TRUE;
    ADCON0bits.CHS2         = FALSE;
    ADCON0bits.CHS1         = TRUE;
    ADCON0bits.CHS0         = TRUE;
    ADCON0bits.GO_nDONE     = FALSE;
    ADCON0bits.ADON         = FALSE;
    ////ADCON1/////
    ADCON1bits.PCFG2        = TRUE;
    ADCON1bits.PCFG1        = FALSE;
    ADCON1bits.PCFG0        = FALSE;    
    
    TMR0_Value = 127;//60;
    cTMR0 = 0;
    
    __delay_ms(10);
    }

short int strtoint(char *string){
    unsigned char lenghtString = strlen(string);
    unsigned char i = 0;
    unsigned char sign = 0;
    short int tempInt = 0;
    if(string[0] == '-') {i++;sign=TRUE;}
    while(string[i] != '\0'){
        short int powInt = 1;
        for(char x = 1; x <= lenghtString - i - 1; x++){
            powInt *= 10;
        }
        tempInt += ((short int)(string[i++] - '0')) * powInt;
    }
    return sign ? tempInt * -1: tempInt;
}
void fEraseString(char* string){
    string[0] = 0;
}