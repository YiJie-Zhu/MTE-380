#include <roverLib.h>
#include "Wire.h"

rover r1 = rover();
int run = 1;

void setup(){
    Serial.begin(9600);
    Wire.begin();
    r1.setupMotors(45, 47, 49, 51, 2, 13);
    r1.setupSensors();
    r1.steerForward();
    r1.setSpeed(150);
    r1.forward();
}

void loop(){
  if(run == 0){
    return;
  }
  delay(2000);
  r1.setSpeed(200);
  float front_dist = r1.readDistFront();
  Serial.println(front_dist);
  if(front_dist <= 60){
    delay(100);
    if(r1.readDistFront() <= 60){
      r1.stop();
      run = 0;
    }
  }
}