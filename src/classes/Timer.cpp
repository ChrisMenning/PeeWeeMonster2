#include "Timer.h"
#include <Arduino.h>

bool Timer::IsDone(unsigned long interval)
{
  currentMicros = micros();
  if (currentMicros - previousMicros >= interval)
  {
    previousMicros = currentMicros;
    return true;
  }
  return false;
}