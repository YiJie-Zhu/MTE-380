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
  r1.forward();
}

void loop(){
  /*
  if (r1.readDistFront() < 23){
    r1.diffTurnRight();
    r1.forward();
    //while((r1.readGyroZ() - dist) < 90){}
    delay(2500);
    r1.stop();
  }
  */
  float front_dist = r1.readDistFront();
  float left_dist = r1.readDistLeft();
  float motor_angle = correction(6-left_dist);
  r1.steer(motor_angle);

  // Serial.println(front_dist);
  // Serial.println("Ultrasonic: ");
  // Serial.println(left_dist);
}
