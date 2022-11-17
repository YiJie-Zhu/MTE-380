#include <roverLib.h>
#include "Wire.h"
#include <PID_v1.h>

rover r1 = rover();
float turn_tol = 1.3;
bool stop = false;
long int last_front_dist_time = 0;
long int time_at_wall = 0;
float front_dist = 150.0;
int turns = 0;
int turn_dist[11] = {25, 25, 25, 55, 55, 55, 55, 85, 85, 85, 85};
int left_dist[11] = {5, 5, 5, 5, 35, 35, 35, 35, 65, 65, 65};


void setup(){
  Serial.begin(9600);
  Wire.begin();
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.setupSensors();
  r1.steerForward();
  r1.setSpeed(250);
  delay(3000);
  r1.forward();
}

void loop(){

  if(stop == true){
    return;
  }
  // experimental pit detection
  bool inPit = false;
  if(millis() - last_front_dist_time > 200){
    last_front_dist_time = millis();
    float last_front_dist = front_dist;
    front_dist = r1.readDistFront();
    if(last_front_dist - front_dist > 5){
      inPit = true;
    }
  }

  if(inPit == true){
    
  }



  if (r1.readDistFront() < turn_dist[turns]){
    if(millis() - time_at_wall > 2000){
      time_at_wall = millis();
    }
    else if(millis() - time_at_wall > 600){
      r1.turnRight(turn_tol);
      turns += 1;
    }
  }

  if (turns >= 6) {
    // while(r1.readDistFront() > turn_dist[turns]) {}
    r1.stop();
    stop = true;
  }

  float front_dist = r1.readDistFront();
  float left_dist_front = r1.readDistLeftFront();
  float left_dist_back = r1.readDistLeftFront();
  r1.correction(left_dist[turns] - left_dist_front);

}
