#include <roverLib.h>
#include "Wire.h"

bool inPit = false;
int last_front_dist = 1500;
long int last_front_dist_time = 0;

rover r1 = rover();

void setup(){
    Serial.begin(9600);
    r1.setupSensors();
    r1.setupMotors(45, 47, 49, 51, 2, 13);
    r1.setSpeed(200);
    delay(1000);
    r1.steerForward();
    r1.forward();
}

void loop(){
    if(millis() - last_front_dist_time > 200){
        last_front_dist_time = millis();
        float front_dist = r1.readDistFront();
        if(last_front_dist < 1500 && last_front_dist - front_dist > 30.0){
          inPit = true;
        }
        last_front_dist = front_dist;
        // Serial.print("LFD: ");
        // Serial.println(last_front_dist);
        // Serial.print("FD: ");
        // Serial.println(front_dist);
        Serial.println(inPit);
  }
}