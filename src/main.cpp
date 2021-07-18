#include <Arduino.h>
#include "classes/pins.h"
#include "classes/dutyCycle.h"
#include "classes/note.h"
#include "classes/AllNotes.h"
#include "classes/Partial.h"
#include "classes/OperationMode.h"
#include "classes/TonePlayer.h"
#include "classes/math_utils.h"

// Global variables
DutyCycle Phase;
AllNotes Notes;
TonePlayer Player;

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
  // put your main code here, to run repeatedly:
  Phase.SetDutyCycle(potPin2);
  PlayNote();
}

void PlayNote(){
  int cvValue = analogRead(cvIn);
  int gateValue = analogRead(gateIn);
  int tuningValue = analogRead(potPin3);
  if (gateValue > 1000)
  {
      Note note = Notes.GetNoteFromCV(cvValue);
      Player.PlayToneUsingDelay(note, buzzerPin, Phase);
  } else
  {
      noTone(buzzerPin);
  }
}