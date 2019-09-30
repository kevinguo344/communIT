#include "communIT.h"

void setup() {
  for(int i = 0; i < SERVO_NUM; i++){
    servos[i].attach(victor_pins[i]);
  }
}

void loop() {
  if(Serial.available()){
    String com = Serial.readString();
    //string *cmd = ;
    //Commands::readCommand(com.c_str());
  }
}

