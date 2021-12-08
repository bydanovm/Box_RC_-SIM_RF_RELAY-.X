#include "temp_ntc.h"

short int rThermistor(unsigned char analogAI){
    float A = (255.0 / (float)analogAI) - 1.0;
    return A * RESISTANCER1;
}

signed char rTemperature(unsigned char analogAI){
    if(analogAI == 255) return 0;
    return (1 / ((log(10000.0 / rThermistor(analogAI)) / BCOEFF) + (1.0 / (NORMALTEMP + 273.15)))) - 273.15;
}