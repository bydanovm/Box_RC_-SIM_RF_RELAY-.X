/* 
 * File:   temp_ntc.h
 * Author: 1
 *
 * Created on 14 сент€бр€ 2020 г., 12:29
 */

#ifndef TEMP_NTC_H
#define	TEMP_NTC_H

#include <xc.h>
#include <math.h>

#define BCOEFF 3892.48//3950
#define NORMALTEMP 25
#define RESISTANCER1 10000

//#include "config.h"

short int rThermistor(unsigned char analogAI);
signed char rTemperature(unsigned char analogAI);
signed char temperatureAI1, temperatureAI2;

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_NTC_H */

