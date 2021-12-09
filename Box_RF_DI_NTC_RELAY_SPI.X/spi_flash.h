/* 
 * File:   spi_flash.h
 * Author: 1
 *
 * Created on 18 �������� 2020 �., 14:08
 */

#ifndef SPI_FLASH_H
#define	SPI_FLASH_H

#include <xc.h>

#define TRUE        1
#define FALSE       0
#define _XTAL_FREQ  8000000
#define MOSI        PORTCbits.RC5
#define MISO        PORTCbits.RC4
#define SCK         PORTCbits.RC3
#define CS          PORTAbits.RA5
#define trisMOSI    TRISCbits.TRISC5
#define trisMISO    TRISCbits.TRISC4
#define trisSCK     TRISCbits.TRISC3
#define trisCS      TRISAbits.TRISA5

#define WREN        0x06                //���������� ������� �������� ������
#define WRDI        0x04                //�������� ������� �������� ������
#define RDSR        0x05                //��������� ������� �������
#define WRSR        0x01                //�������� � ������� �������
#define READ        0x03                //������� ������ �� ������� ������
#define PROGRAM     0x02                //�������� ������ � ������ ������
#define RDID        0x83                //������� �������� �������������
#define WRID        0x82                //�������� �������� �������������

void SPI_init();
void SPI_WriteByte(char data);
char SPI_ReadByte(char data);
void SPI_Write(unsigned int address, unsigned char data);
char SPI_Read(unsigned int address);
char SPI_ReadStatus();
int SPI_ReadRDID();
char SPI_notRDY();
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SPI_FLASH_H */

