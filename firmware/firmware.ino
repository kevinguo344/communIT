#include <Servo.h>

#define SERVO_NUM 6
#define LEFT 95
#define STOP 93
#define RIGHT 91

int victor_pins[SERVO_NUM] = {2,3,4,5,6,7};
int potentiometer_pins[SERVO_NUM] = {A0,A1,A2,A3,A4,A5};

int current_states[SERVO_NUM] = {0,0,0,0,0,0};

Servo servos[SERVO_NUM];

void setup() {
  for(int i = 0; i < SERVO_NUM; i++){
    servos[i].attach(victor_pins[i]);
  }
}

void loop() {
  
}

void move(int ind){
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
  servos[ind].write(state);
  current_states[ind] = state;
}
