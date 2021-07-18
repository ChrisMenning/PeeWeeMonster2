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

// Global variables
DutyCycle Phase;
AllNotes Notes;
TonePlayer Player;
OperationMode Op;
Timer highTimer;
Timer fullTimer;

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

  Op.PlayWithoutDelay(Notes, Phase, Player, highTimer, fullTimer);
}

