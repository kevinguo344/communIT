#include <Arduino.h>
#include <String.h>
#include <Servo.h>

#include "Controls.h"
#include "Commands.h"

#include <string>
using namespace std;

#define LEFT 95
#define STOP 93
#define RIGHT 91

#define SERVO_NUM 6

static int victor_pins[SERVO_NUM] = {2,3,4,5,6,7};
static int potentiometer_pins[SERVO_NUM] = {A0,A1,A2,A3,A4,A5};
static int current_states[SERVO_NUM] = {0,0,0,0,0,0};
static Servo victors[SERVO_NUM];
