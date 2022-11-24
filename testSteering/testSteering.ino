#include <roverLib.h>
#include "Wire.h"

rover r1 = rover();
int run = 1;
int turnDist = 44;
float turn_tol = 1.9;

void setup(){
    Serial.begin(9600);
    Wire.begin();
    r1.setupMotors(45, 47, 49, 51, 2, 13);
    r1.setupSensors();
    delay(1000);
    r1.steerForward();
    r1.setSpeed(250);
    r1.forward();
}

void loop(){
    if(run == 0){
        r1.stop();
        return;
    }
    int front_dist = r1.readDistFront();
    Serial.println(front_dist);
    delay(100);
    if(front_dist <= turnDist && turnDist - front_dist < 8){
        r1.turnRight(turn_tol, 35);
        run = 0;
    }
    if (front_dist < 40){
      run = 0;
    }
}