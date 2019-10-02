#include "communIT.h"

void Controls::moveMotor(int ind, int angle){
  int input = analogRead(potentiometer_pins[ind]);
  int state;
  // checks whether requested angle 
  if(angle <= max_angle[ind] && angle >= min_angle[ind]){
    int position_angle = map(input,0,1023,0,270);
    if (position_angle < angle){ state = RIGHT; }
    else if (position_angle > angle){ state = LEFT; }
    else { state = STOP; }
    
    victors[ind].write(state);
    current_states[ind] = state;
  }
  else { Serial.println("ERROR: REQUESTED ANGLE OUT OF RANGE FOR VICTOR"); }
}
