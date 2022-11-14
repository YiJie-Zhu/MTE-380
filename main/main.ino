#include <roverLib.h>
#include "Wire.h"
#include <PID_v1.h>

rover r1 = rover();
float turn_tol = 1.3;
bool stop = false;
int turns = 0;
int turn_dist[11] = {28, 28, 28, 48, 48, 48, 48, 68, 68, 68, 68};
int left_dist[11] = {6, 6, 6, 6, 26, 26, 26, 26, 46, 46, 46};


float correction(float dist){
  float result = 0;
  if (dist < 0.5 && dist > -0.5) result = 0;
  else result = (1.0/15)*dist*dist*dist+dist;
  return result;
}

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
  if (!stop) {
    if (r1.readDistFront() < turn_dist[turns]){
      r1.turnRight(turn_tol);
      turns += 1;
    }

    if (turns == 1) {
      // while(r1.readDistFront() > turn_dist[turns]) {}
      r1.stop();
      stop = true;
    }

    float front_dist = r1.readDistFront();
    float left_dist_front = r1.readDistLeftFront();
    float left_dist_back = r1.readDistLeftFront();
    float motor_angle = correction(left_dist[turns] - left_dist_front);
    r1.steer(motor_angle);

    // Serial.println(front_dist);
    // Serial.println("Ultrasonic: ");
    // Serial.println(left_dist);
  }
}
