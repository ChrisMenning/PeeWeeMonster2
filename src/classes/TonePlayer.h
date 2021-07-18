#pragma once
#include "dutyCycle.h"
#include "note.h"

class TonePlayer{
    public:
    bool IsPlaying;
    void PlayToneUsingDelay(Note, int, DutyCycle);
    void PlayToneWithoutDelay (float, int, DutyCycle);
};
