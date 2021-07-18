#pragma once
#include "dutyCycle.h"

class Partial{
    public:
    unsigned long Length;
    unsigned long HighLength(DutyCycle);
    unsigned long LowLength(DutyCycle);
    
    Partial(float freq){
        float high = 1/freq;
        Length = high * 1000000;
    };
};