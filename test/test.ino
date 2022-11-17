#include <roverLib.h>
#include "Wire.h"

rover r1 = rover();

long int last_front_dist_time = 0;
float last_front_dist = 0.0;
bool inPit = false;
bool stop = false;
  
void setup(){
  Serial.begin(9600);
  r1.setupSensors();
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.steerForward();
  delay(2000);
  //r1.setSpeed(150);
  r1.climbSetting();
  r1.forward();
}

void loop(){
  if(stop == true){
    return;
  }
  float front_dist = r1.readDistFront();
  if(millis() - last_front_dist_time > 200){
    last_front_dist_time = millis();
    front_dist = r1.readDistFront();
    if(last_front_dist - front_dist > 20.0){
      inPit = true;
    }
    last_front_dist = front_dist;
    Serial.print("LFD: ");
    Serial.println(last_front_dist);
    Serial.print("FD: ");
    Serial.println(front_dist);
    // Serial.println(inPit);
  }
  
  if(front_dist <= 20){
    stop = true;
    r1.stop();
  }
  if(stop == true){
    return;
  }
}
