#pragma once
#include <Arduino.h>
#include "pins.h"
#include "AllNotes.h"
#include "TonePlayer.h"

class OperationMode{
    public:
    int state = HIGH;      // the current state of the output pin
    int reading;           // the current reading from the input pin
    int previous = LOW;    // the previous reading from the input pin
    int mode = 1; // The operating mode
    // the follow variables are long's because the time, measured in miliseconds,
    // will quickly become a bigger number than can be stored in an int.
    long time = 0;         // the last time the output pin was toggled
    long debounce = 200;   // the debounce time, increase if the output flickers
    int GetOperationMode();
    void PlayNote(AllNotes, DutyCycle, TonePlayer);
    void PlayWithoutDelay(AllNotes, DutyCycle, TonePlayer, Timer, Timer);
};
