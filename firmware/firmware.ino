#include <Servo.h>

#define SERVO_NUM 6
#define LEFT 95
#define STOP 93
#define RIGHT 91

int victor_pins[6] = [2,3,4,5,6,7];

Servo servos[SERVO_NUM];

void setup() {
  for(int i = 0; i < SERVO_NUM; i++){
    servos[i].attach(victor_pins[i]);
  }
}

void loop() {

}
