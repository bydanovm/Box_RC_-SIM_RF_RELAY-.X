#include "lcd.h"
//#include "shift_registr.h"

#define RS RA2
//#define RW RC1
#define E RA5

//void LCD_PORT_init(){
//    TRISBbits.TRISB0 = 0;
//    TRISBbits.TRISB1 = 0;
//    TRISBbits.TRISB2 = 0;
//    TRISBbits.TRISB3 = 0;
//    TRISCbits.TRISC0 = 0;
//    TRISCbits.TRISC1 = 0;
//    TRISCbits.TRISC2 = 0;
//}

void LCD_init(){
    __delay_ms(50);
//    PORTB &= ~0x0F;
//    PORTC &= ~0x07;
//    __delay_ms(100);
    sendhalfbyte(0b00000011);
    __delay_us(4500);
    sendhalfbyte(0b00000011);
    __delay_us(200);
    sendhalfbyte(0b00000011);
    __delay_ms(1);
    sendhalfbyte(0b00000010);
    __delay_ms(1);
//    sendhalfbyte(0b00000010);
//    __delay_ms(1);
    sendbyte(0b00101000,0); //������� 4 ������� ������ ������, 2 �����, 5�8
    __delay_ms(1);
    sendbyte(0b00001100,0); //�������� �������, ��������� ������ � ������� ���������� ������� 
    LCD_clear();
    sendbyte(0b00000110,0); //��������� ������ �����
    __delay_ms(1);
////    sendbyte(0b00000010,0); //����� �������
////    sendbyte(0b10000000,0); //���������� ������ � ��������� ���������
////    __delay_ms(2);
//    fShiftData(0x00);
}

void sendhalfbyte(unsigned char c){
//    c &= 0b0001111;
//    PORTC &= ~0x3C;
//    PORTC &= ~0x0F;
//    PORTC |= c;
    fShiftData(0x00);
    __delay_us(1);
    if(c & 0x01 || c & 0x02 || c & 0x03)
        c <<= 3;
    else
        c >>= 1;
//    c1 = c;
//    c1 &= ~0x3C;
//    fShiftData(c1);
    c |= 0x04;
    fShiftData(c);
//    E = 1;
    __delay_us(1);
    c &= ~0x04;
    fShiftData(c);
//    E = 0;
    __delay_us(50);
}

void sendbyte(unsigned char c, unsigned char mode){
    unsigned char hb = 0;
    hb = c;
    hb &= ~0x0F;
    c <<= 4;
    //c &= ~0xC0;
    if(mode != 0) //RS = 0; else RS = 1;
//    {
//        c &= ~0x20;
//        hb &= ~0x20;
//    }
//    else
    {
        c |= 0x04;
        hb |= 0x04;
    }
    sendhalfbyte(hb);
    sendhalfbyte(c);
}

void LCD_string(char* st){
    unsigned char symbol;
    unsigned char i = 0;
//    while(i <= sizeof(st)){
    while(st[i] != '\0'){
        if(i == 16 ) LCD_SetPos(0,1);
//        if(i == 0 || i == 32 || i == 64){
//            __delay_ms(2000);
//            LCD_clear();
//            LCD_SetPos(0,0);
//        }
        symbol = st[i++];
        if(symbol > 0xBFu) symbol = SHRIFT[(symbol-0xC0u)];
        sendbyte(symbol,1);
    }
//    __delay_ms(2000);
}

void LCD_SetPos(unsigned char x, unsigned char y){
    switch(y){
        case 0:
            sendbyte((unsigned char)(x|0x80),0);
            break;
        case 1:
            sendbyte((unsigned char)((0x40+x)|0x80),0);
            break;
    }
}

void LCD_clear(){
    sendbyte(0b00000001,0);
    __delay_us(1600);
}

char* LCD_StringOnOff(const unsigned char st, const unsigned char numb){
    if(st & (1u << numb)) return "���";
    else return "����";
}

/*void define_char(unsigned char pc[],unsigned char char_code){ 
    unsigned char i,a; 
    a=(char_code<<3)|0x40; 
    sendbyte(a,0);
    for (i=0; i<8; i++) sendbyte(pc[i],1); 
 } */