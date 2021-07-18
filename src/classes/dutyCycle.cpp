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

int DutyCycle::SetSweepMode(int inputPot)
{
    int value = analogRead(inputPot);
    if (value > 0 && value <= 233)
        return 0;
    else if (value > 233 && value <= 466)
        return 1;
    else if (value > 466 && value <= 700)
        return 2;
    else return 0;
}

float DutyCycle::SetSweepRate(int inputPot)
  {
    int value = analogRead(inputPot);
    float newValue = (value - 0) * (HighCeiling - HighFloor) / (700 - 0) + HighFloor;
    return newValue;
  }

// When not using potentiometer to control Duty Cycle, sweep them.
  void DutyCycle::DutyCycleSweep(int sweepMode, float rate)
  {
    if (HighPart == 0)
    {
      HighPart = 0.01;  
    }
    if (sweepMode == 0) // Triangle
    {
      // Start ramp up 
      if (HighPart <= HighFloor)
        rising = true;
      if (rising == true)
        HighPart = HighPart + rate;
      if (HighPart >= HighCeiling)
        rising = false;
      if (rising == false)
          HighPart = HighPart - rate; 
    }
  
    else if (sweepMode == 1) // Ramp Up
    {
      // Start ramp up
      if (HighPart < HighCeiling)
        HighPart = HighPart + rate;
      if (HighPart >= HighCeiling)
        HighPart = HighFloor;
    }
  
    else if (sweepMode == 2) // Ramp Down
    {
      // if ramping down, continue ramping down   
      if (HighPart > HighFloor)
        HighPart = HighPart - rate;
      if (HighPart <= HighFloor)
        HighPart = HighCeiling;
    }
    LowPart(); // Set low part of duty cycle.
  }

  