#pragma once
#include "dutyCycle.h"
#include "note.h"
#include "Timer.h"

class TonePlayer{
    public:
    bool IsPlaying;
    void PlayToneUsingDelay(Note note, int outputPin, DutyCycle phase);
    void PlayToneWithoutDelay (Note tone, int outputPin, DutyCycle phase, Timer high, Timer full);
    void PlayLowFreqUsingDelay(int tone, int outputPin, DutyCycle phase);
    void Sync();
};
