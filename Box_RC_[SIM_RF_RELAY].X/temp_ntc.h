/* 
 * File:   temp_ntc.h
 * Author: 1
 *
 * Created on 14 сент€бр€ 2020 г., 12:29
 */

#ifndef TEMP_NTC_H
#define	TEMP_NTC_H

#include "config.h"

unsigned char acp_max = 255;
short int rR1 = 10000;
short int rThermistor(unsigned char analogAI);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_NTC_H */

