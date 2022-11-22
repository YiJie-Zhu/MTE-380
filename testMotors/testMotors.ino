#include <roverLib.h>
#include "Wire.h"
#include <PID_v1.h>

rover r1 = rover();

float correction(float dist){
  float result = 0;
  if (dist < 0.5 && dist > -0.5) result = 0;
  else result = (1.0/15)*dist*dist*dist+dist;
  Serial.println(result);
  delay(500);
  return result;
}

void setup(){
  Serial.begin(9600);
  Wire.begin();
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.setupSensors();
  r1.steerForward();
  r1.setSpeed(100);
  delay(2000);
  r1.climb();
}

void loop(){
  r1.setSpeedWheel(200, 1); //LF
  r1.setSpeedWheel(200, 2); //RF
  r1.setSpeedWheel(250, 3); //LM
  r1.setSpeedWheel(250, 4); //RM
  r1.setSpeedWheel(200, 5); //LB
  r1.setSpeedWheel(200, 6); //RB
}
