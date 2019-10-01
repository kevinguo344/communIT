#include "communIT.h"

void setup() {
  for(int i = 0; i < SERVO_NUM; i++){
    victors[i].attach(victor_pins[i]);
  }
}

void loop() {
  if(Serial.available()){
    Commands::readCommand(Serial.readString());
  }
}

