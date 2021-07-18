#include <Arduino.h>
#include "TonePlayer.h"
#include "dutyCycle.h"

void TonePlayer::PlayToneUsingDelay (float input, int buzzerPin, DutyCycle duty)
{
    if (input > 0 && IsPlaying == false)
    {
        IsPlaying = true;
        digitalWrite(buzzerPin, HIGH);
        delayMicroseconds((input / 2));
        digitalWrite(buzzerPin, LOW);
        delayMicroseconds((input/ 2));
        IsPlaying = false;
    }

}