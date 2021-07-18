#include <Arduino.h>
#include "TonePlayer.h"
#include "note.h"
#include "math_utils.h"

void TonePlayer::PlayToneUsingDelay (Note input, int buzzerPin, DutyCycle duty)
{
    if (input.AnalogValue > 0 && IsPlaying == false)
    {
        Note tunedNote("tunedNote", input.AnalogValue, input.Freq * tuning());
        //Serial.println(tuning());
        //Serial.println(tunedNote.Freq);
        unsigned long high = tunedNote.GetPartial().HighLength(duty);
        unsigned long low = tunedNote.GetPartial().LowLength(duty);
        IsPlaying = true;
        digitalWrite(buzzerPin, HIGH);
        delayMicroseconds(high);
        digitalWrite(buzzerPin, LOW);
        delayMicroseconds(low);
        IsPlaying = false;
    }
}

void TonePlayer::PlayToneWithoutDelay (float input, int buzzerPin, DutyCycle duty)
{
    if (input > 0 && IsPlaying == false)
    {
        IsPlaying = true;
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(buzzerPin, LOW);
        delayMicroseconds((input/ duty.LowPart()));
        IsPlaying = false;
    }
}