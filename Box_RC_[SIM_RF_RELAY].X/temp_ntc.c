#include "temp_ntc.h"

short int rThermistor(unsigned char analogAI){
//    return rR1 * (short int)((short int)((short int)acp_max / (short int)analogAI) - 1);
    float A = ((float)acp_max / (float)analogAI) - 1.0;
//    return ((float)rR1 * (((float)acp_max / (float)analogAI) - 1.0));
    return A * (float)rR1;
}