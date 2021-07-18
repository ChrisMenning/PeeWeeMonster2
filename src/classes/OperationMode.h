#pragma once
#include <Arduino.h>
#include "pins.h"
#include "AllNotes.h"
#include "TonePlayer.h"

class OperationMode{
    public:
    void PlayNote(AllNotes, DutyCycle, TonePlayer);
    void PlayWithoutDelay(AllNotes, DutyCycle, TonePlayer, Timer, Timer);
};
