#include <Arduino.h>
#include "classes/pins.h"
#include "classes/dutyCycle.h"
#include "classes/note.h"
#include "classes/AllNotes.h"
#include "classes/Partial.h"
#include "classes/OperationMode.h"
#include "classes/TonePlayer.h"
#include "classes/math_utils.h"
#include "classes/Timer.h"
#include "classes/Colors.h"

// Global variables
DutyCycle Phase;
AllNotes Notes;
TonePlayer Player;
OperationMode Op;
//Timer highTimer;
//Timer fullTimer;
Timer ModeTimer;
Colors AllColors;

// Function primatives
void PlayNote();

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(buzzerPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(beatLed, OUTPUT);

}

void loop() {
  int mode = Op.GetOperationMode();
  
  if (mode == 1) // VOICE WITH POTENTIOMETER DRIVEN  
  {
    AllColors.Red();
    Phase.SetDutyCycle(potPin2);
    Op.PlayNote(Notes, Phase, Player);
  } else if (mode == 2) // VOICE WITH SWEEPS
  {
    AllColors.Green();
    int sweepMode = Phase.SetSweepMode(potPin2);
    float sweepRate = Phase.SetSweepRate(potPin3);
    Phase.DutyCycleSweep(sweepMode, sweepRate);
    Op.PlayNote(Notes, Phase, Player);
  } else if (mode == 3) // POT-DRIVEN TONE
  {
    AllColors.Blue();
    Phase.SetDutyCycle(potPin2);
    float knobTone = Phase.KnobTone(potPin3);
    Op.PlayTone(knobTone, Phase, Player);
    
  } else if (mode == 4) // POT-DRIVEN TONE WITH SWEEPING DUTY CYCLE
  {
    AllColors.Cyan();
    float knobTone = Phase.KnobTone(potPin3);
    int sweepMode = 0;
    float sweepRate = Phase.SetSweepRate(potPin2);
    Phase.DutyCycleSweep(sweepMode, sweepRate);
    Op.PlayTone(knobTone, Phase, Player);
  } else if (mode == 5)
  {
    AllColors.Purple();
  } else if (mode == 6)
  {
    AllColors.Yellow();
  }
}

