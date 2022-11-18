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
    float left_dist_front = r1.readDistLeftFront();
    float front_dist = r1.readDistFront();
    r1.correction(5-left_dist_front);
    delay(100);
    if(front_dist <= 30){
      delay(100);
      if(r1.readDistFront() <= 30){
        r1.stop();
        run = 0;
      }
    }
}
