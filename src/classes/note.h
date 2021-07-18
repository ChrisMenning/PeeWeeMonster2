#pragma once
#include <Arduino.h>
#include "dutyCycle.h"
#include "Partial.h"
class Note{
    public:
    String Name;
    int AnalogValue; // The value received from the CV analog input.
    float Freq; // The frequency of the note in Hz (cycles per second).
    Partial GetPartial(); // A single oscillation of the frequency.

    // Constructor
    Note(String name, int analogVal, float freq){
        Name = name;
        AnalogValue = analogVal;
        Freq = freq;
    }
};