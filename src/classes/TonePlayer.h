#pragma once
#include "dutyCycle.h"
class TonePlayer{
    public:
    bool IsPlaying;
    void PlayToneUsingDelay (float input, int buzzerPin, DutyCycle duty);
};
