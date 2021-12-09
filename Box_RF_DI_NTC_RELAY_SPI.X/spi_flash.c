#include "spi_flash.h"

void SPI_init(){
    trisMISO                = TRUE;
    trisMOSI                = FALSE;
    trisSCK                 = FALSE;
    trisCS                  = FALSE;
    
    CS                      = TRUE;
    //������� SSPSTAT
    SSPSTATbits.SMP         = FALSE;  //��� ���������� ��������� ������ 
    SSPSTATbits.CKE         = TRUE; //����� ������ �������� �������
    SSPSTATbits.BF          = FALSE; //���� ���������� ������
    //������� SSPCON
    SSPCONbits.WCOL         = FALSE; //���� ����������� ��������
    SSPCONbits.SSPOV        = FALSE; //���� ������������
    SSPCONbits.SSPEN        = TRUE;  //��������� ������ MSSP
    SSPCONbits.CKP          = FALSE; //��� ���������� ������������
    SSPCONbits.SSPM3        = FALSE; //���� ������ ������ ������ ������ MSSP
    SSPCONbits.SSPM2        = FALSE;
    SSPCONbits.SSPM1        = FALSE;
    SSPCONbits.SSPM0        = TRUE;
}
void SPI_WriteByte(char data){
    SSPBUF = data;
    while(SSPSTATbits.BF == 0);
}
char SPI_ReadByte(char data){
    SPI_WriteByte(data);
    return SSPBUF;
}
void SPI_Write(unsigned int address, unsigned char data){
    while(SPI_notRDY() == 1);
    CS = FALSE;
    SPI_WriteByte(WREN);
    CS = TRUE;
//    __delay_us(100);
    CS = FALSE;
    SPI_WriteByte(address > 255 ? PROGRAM|0x08 : PROGRAM);
//    SPI_WriteByte(address>>16);
//    SPI_WriteByte(address>>8);
    SPI_WriteByte(address);
    SPI_WriteByte(data);
    CS = TRUE;
}
char SPI_Read(unsigned int address){
    while(SPI_notRDY() == 1);
    CS = FALSE;
    SPI_WriteByte(address > 255 ? READ|0x08 : READ);
//    SPI_WriteByte(address>>16);
//    SPI_WriteByte(address>>8);
    SPI_WriteByte(address);
    char data = SPI_ReadByte(0);
    CS = TRUE;
    return data;
}
char SPI_ReadStatus(){
    CS = FALSE;
    SPI_WriteByte(RDSR);
    char status = SPI_ReadByte(0);
    CS = TRUE;
    return status;
}
int SPI_ReadRDID(){
    int rdid;
    CS = FALSE;
    SPI_WriteByte(RDID);
    rdid = SPI_ReadByte(0);
    rdid <<= 8;
    rdid |= SPI_ReadByte(0);
    CS = TRUE;
    return rdid;
}
char SPI_notRDY(){
    char notRDY = SPI_ReadStatus();
    return (notRDY & 0x01);
}
    