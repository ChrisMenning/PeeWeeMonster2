#pragma once
#include "dutyCycle.h"
#include "note.h"
#include "Timer.h"

class TonePlayer{
    public:
    bool IsPlaying;
    void PlayToneUsingDelay(Note, int, DutyCycle);
    void PlayToneWithoutDelay (Note, int, DutyCycle, Timer, Timer);
    void PlayLowFreqUsingDelay(int, int, DutyCycle);
    void Sync();
};
