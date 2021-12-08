/* 
 * File:   extern.h
 * Author: 1
 *
 * Created on 16 окт€бр€ 2020 г., 11:33
 */

#ifndef EXTERN_H
#define	EXTERN_H



#ifdef	__cplusplus
extern "C" {
#endif

//typedef struct {
//    unsigned char AI0;
//    unsigned char AI1;
//    unsigned char AI2;
//    unsigned char AI3;
//} AnalogInput;
    
struct AnalogInput{
    unsigned char AI0;
    unsigned char AI1;
    unsigned char AI2;
    unsigned char AI3;
};

struct AnalogInput Analog;

#ifdef	__cplusplus
}
#endif

#endif	/* EXTERN_H */

