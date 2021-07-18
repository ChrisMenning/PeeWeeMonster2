#include "Partial.h"
#include "dutyCycle.h"

unsigned long Partial::HighLength(DutyCycle duty)
{
    return Length * duty.HighPart;
}

unsigned long Partial::LowLength(DutyCycle duty)
{
    return Length - HighLength(duty);
}