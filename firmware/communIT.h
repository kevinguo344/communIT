#include <Arduino.h> //needed for Serial.println
#include <string.h> //needed for memcpy
#include <Servo.h>

#include "Commands.h"
#include "Controls.h"
#include <string>
using namespace std;

#define SERVO_NUM 6
#define LEFT 95
#define STOP 93
#define RIGHT 91

int victor_pins[SERVO_NUM] = {2,3,4,5,6,7};
int potentiometer_pins[SERVO_NUM] = {A0,A1,A2,A3,A4,A5};

int current_states[SERVO_NUM] = {0,0,0,0,0,0};

Servo servos[SERVO_NUM];
