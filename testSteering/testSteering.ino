#include <roverLib.h>
#include "Wire.h"

rover r1 = rover();
int run = 1;
int turnDist = 28;
float turn_tol = 1.3;

void setup(){
    Serial.begin(9600);
    Wire.begin();
    r1.setupMotors(45, 47, 49, 51, 2, 13);
    r1.setupSensors();
    r1.steerForward();
    r1.setSpeed(100);
    r1.forward();
}

void loop(){
    if(run == 0){
        r1.stop();
        return;
    }
    int front_dist = r1.readDistFront();
    if(front_dist < turnDist){
        r1.turnRight(turn_tol);
        run = 0;
    }
}