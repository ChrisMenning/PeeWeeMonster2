#include "math_utils.h"
#include "pins.h"
// Directly map a control voltage to a tone. This is most useful for handling glides.
// OR directly map a potentiometer value to a duty cycle. (int range to float range).
float mapIntRangetoFloatRange(int input, float inMin, float inMax, float outMin, float outMax)
{
    // Map voltage range 200 to 850 to 32 to 260
    float result = (input - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
    return result;
}

float tuning ()
{
  int tuningValue = analogRead(potPin1);
  return mapIntRangetoFloatRange(tuningValue, 0, 695, 0.9, 1.2);
}