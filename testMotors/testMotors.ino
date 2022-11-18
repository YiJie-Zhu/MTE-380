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
  r1.forward();
}

void loop(){
  r1.setSpeedWheel(150, 1);
  r1.setSpeedWheel(150, 2);
  r1.setSpeedWheel(150, 3);
  r1.setSpeedWheel(150, 4);
  r1.setSpeedWheel(100, 5);
  r1.setSpeedWheel(100, 6);
}
