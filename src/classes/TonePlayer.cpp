#include <Arduino.h>
#include "TonePlayer.h"
#include "note.h"
#include "math_utils.h"
#include "Timer.h"
#include "pins.h"

void TonePlayer::PlayLowFreqUsingDelay(int input, int buzzerPin, DutyCycle duty)
{
    IsPlaying = true;
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(beatLed, HIGH); 
    delayMicroseconds(duty.HighPart);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(beatLed, LOW); 
    delayMicroseconds(duty.LowPart());
    IsPlaying = false;

}

void TonePlayer::PlayToneUsingDelay (Note input, int buzzerPin, DutyCycle duty)
{
    if (input.AnalogValue > 0 && IsPlaying == false)
    {
        unsigned long high = input.GetPartial().HighLength(duty);
        unsigned long low = input.GetPartial().LowLength(duty);
        IsPlaying = true;
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(beatLed, HIGH); 
        delayMicroseconds(high);
        digitalWrite(buzzerPin, LOW);
        digitalWrite(beatLed, LOW); 
        delayMicroseconds(low);
        IsPlaying = false;
    }
}

void TonePlayer::PlayToneWithoutDelay (Note input, int buzzerPin, DutyCycle duty, Timer highTimer, Timer fullTimer)
{
    unsigned long high = input.GetPartial().HighLength(duty);
    unsigned long low = input.GetPartial().LowLength(duty);
    bool highDone = highTimer.IsDone(high);
    bool fullDone = highTimer.IsDone(high+low);
    
    if (highDone == false && fullDone == false)
    {
        digitalWrite(buzzerPin, HIGH);
    } else if (highDone == true && fullDone == false){
        digitalWrite(buzzerPin, LOW);
    } else if (fullDone == true)
    {
        digitalWrite(buzzerPin, LOW);
    }
}