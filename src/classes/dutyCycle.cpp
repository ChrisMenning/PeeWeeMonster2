#include <Arduino.h>
#include "dutyCycle.h"
#include "pins.h"
#include "math_utils.h"

float DutyCycle::LowPart(){
    return 1 - HighPart;
}

void DutyCycle::SetDutyCycle(int inputPot)
{
    int value = analogRead(inputPot);
    HighPart = mapIntRangetoFloatRange(value, 0, 699, HighFloor, HighCeiling);
}


