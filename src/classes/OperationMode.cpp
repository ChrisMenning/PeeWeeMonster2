#include "OperationMode.h"
#include "AllNotes.h"
#include "math_utils.h"
#include "TonePlayer.h"
#include "Timer.h"

int OperationMode::GetOperationMode(){
  int reading = digitalRead(button1Pin);
  reading = digitalRead(button1Pin);

    if (reading == HIGH && previous == LOW && millis() - time > debounce) {
      if (state == HIGH)
        state = LOW;
      else
        state = HIGH;

      // Regardless of high or low, increment mode number.
      mode++;
    time = millis();    
  }

    previous = reading;

    if (mode > 8)
    {
      mode = 1;
    }


  return mode;
}

void OperationMode::PlayTone(float tone, DutyCycle duty, TonePlayer player){
  Note note = {"tone", 1, tone};
  player.PlayToneUsingDelay(note, buzzerPin, duty);
}

void OperationMode::PlayNote(AllNotes notes, DutyCycle duty, TonePlayer player){
  int cvValue = analogRead(cvIn);
  int gateValue = analogRead(gateIn);
  if (gateValue > 1000)
  {
      Note note = notes.GetNoteFromCV(cvValue);
      Note tunedNote("tunedNote", note.AnalogValue, note.Freq * tuning());
      player.PlayToneUsingDelay(tunedNote, buzzerPin, duty);
  } 
}

void OperationMode::PlayWithoutDelay(AllNotes notes, DutyCycle duty, TonePlayer player, Timer highTimer, Timer fullTimer)
{
  int cvValue = analogRead(cvIn);
  int gateValue = analogRead(gateIn);
  if (gateValue > 1000){
    Note note = notes.GetNoteFromCV(cvValue);
    Note tunedNote("tunedNote", note.AnalogValue, note.Freq * tuning());
    player.PlayToneWithoutDelay(tunedNote, buzzerPin, duty, highTimer, fullTimer);
    String msg = "H Current Time: ";
    msg += highTimer.currentMicros;
    msg += " | H Previous Time: ";
    msg += highTimer.previousMicros;
    msg += " | F Current: ";
    msg += fullTimer.currentMicros;
    msg += " | F Previous: ";
    msg += fullTimer.previousMicros;
    Serial.println(msg);
    if (fullTimer.IsDone(tunedNote.Freq * 1000) == true)
    {
      //Serial.println("FULL DONE!");
    }

    if (highTimer.IsDone(duty.HighPart * 1000) == false)
    {
      Serial.println("HIGH NOT DONE YET!");

    }

    if (highTimer.IsDone(duty.HighPart * 1000) == true && fullTimer.IsDone(tunedNote.Freq * 1000) == false)
    {
      //Serial.println("HIGH DONE!");

    }
  }
}