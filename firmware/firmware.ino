#include "communIT.h"

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < SERVO_NUM; i++){
    victors[i].attach(victor_pins[i]);
  }
}

void loop() {
  // if a serial command comes in, the Command will be read an interpreted
  if(Serial.available()){
    Commands::readCommand(Serial.readString());
  }
}