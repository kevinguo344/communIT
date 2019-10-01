#include "communIT.h"

void Controls::moveMotor(int ind, int angle){
  int input = analogRead(potentiometer_pins[ind]);
  int state;
  if(input < 1023 && current_states[ind] == LEFT){
    state = LEFT;
  }
  else if(input > 0 && current_states[ind] == RIGHT){
    state = RIGHT;
  }
  else if(input == 1023){ state = RIGHT; }
  else{ state = LEFT; }
  victors[ind].write(state);
  current_states[ind] = state;
}
