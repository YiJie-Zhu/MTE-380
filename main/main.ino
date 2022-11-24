#include <roverLib.h>
#include "Wire.h"
#include <PID_v1.h>

rover r1 = rover();
float turn_tol = 1.9;
bool stop = false;
bool inPit = false;
float last_front_dist = 1000;
long int last_front_dist_time = -1000;
long int time_at_wall = 0;
long int time_at_pit = 0;
long int time_in_wheelie = 0;
long int time_at_turn = 0;
float front_dist = 150;
int turns = 0;
float turn_dist[11] = {22.5, 22.5, 24.5, 48, 48, 48, 48, 78, 78, 78, 78};
int left_dist[11] = {5, 5.5, 5, 8, 35.5, 35.5, 35.5, 35.5, 65.5, 65.5, 65.5};
long int turn_delay[11] = {500, 500, 500, 500, 500, 500, 500, 500, 0, 0, 0};
// first left dist is 5 but can be turned down to 4 is nessesary


void setup(){
  Serial.begin(9600);
  Wire.begin();
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.setupSensors();
  delay(4000);
  r1.steerForward();
  r1.setSpeed(250);
  r1.forward();
}

void loop(){
  if(stop == true){
    return;
  }
  if(millis() - last_front_dist_time > 100){
    last_front_dist_time = millis();
    // if(last_front_dist < 1000 && last_front_dist - front_dist > 20.0){
    //   inPit = true;
    //   time_at_pit = millis();
    // }
    // Serial.print("LFD: ");
    // Serial.println(last_front_dist);
    // Serial.print("FD: ");
    // Serial.println(front_dist);
    // Serial.println(inPit);
    front_dist = r1.readDistFront();
  }

  if(inPit){
    // if (last_front_dist - front_dist < 1 && millis() - time_in_wheelie > 1000){
    //   r1.setSpeedWheel(180, 3);
    //   r1.setSpeedWheel(180, 4);
    //   r1.setSpeedWheel(255, 5);
    //   r1.setSpeedWheel(255, 6);
    //   r1.forward();

    //   //r1.steer(15);
    //   delay(1000);
    //   inPit = false;
    //   r1.setSpeed(250);
    // }
    //else if (millis() - time_at_pit > 1000) {
    if(r1.readDistFront() < 75 && millis() - time_at_pit > 2000){
      r1.stop();
      delay(500);
      r1.climbSetting();
      r1.climb();
      //time_in_wheelie = millis();
      delay(1000);
      r1.setSpeedWheel(180, 3);
      r1.setSpeedWheel(180, 4);
      r1.setSpeedWheel(255, 5);
      r1.setSpeedWheel(255, 6);
      r1.forward();
      delay(200);
      inPit = false;
      r1.setSpeed(250);
      r1.forward();
    }
    // else{
    //   r1.pitSetting();
    // }
  }

  float curr_dist = r1.readDistFront();
  // turning function
  if (front_dist < turn_dist[turns] && !inPit && (turn_dist[turns] - front_dist) < 5 && millis() - time_at_turn > turn_delay[turns]){
    // if(millis() - time_at_wall > 2000){
    //   time_at_wall = millis();
    // }
    //else if(millis() - time_at_wall > 600){
    int degree = 35;
    if(turns > 3){
      degree = 40;
    }
    r1.turnRight(turn_tol, degree);
    time_at_turn = millis();
    turns += 1;

    if(turns == 3){
      inPit = true;
      time_at_pit = millis();
    }

    r1.setSpeed(250);
    r1.forward();
    //}
  }

  if (turns >= 11) {
    // while(r1.readDistFront() > turn_dist[turns]) {}
    r1.stop();
    stop = true;
  }
  float left_dist_front = r1.readDistLeftFront();
  r1.correction(left_dist[turns] - left_dist_front);
}
