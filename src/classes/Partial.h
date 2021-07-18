#pragma once
#include "dutyCycle.h"

class Partial{
    public:
    unsigned long Length;
    unsigned long HighLength(DutyCycle);
    unsigned long LowLength(DutyCycle);
    
    Partial(float freq){
        float high = 1 / freq; // Yields a near-zero decimal.
        float highMs = high * 1000; // Convert to ms before assigning to int, to avoid losing percentages.
        Length = highMs * 1000; // Convert to micros.
    };
};