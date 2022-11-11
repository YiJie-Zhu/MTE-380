#ifndef ROVERLIB_H
#define ROVERLIB_H

#include "Motors.h"
#include "Shield.h"
#include "Gyro.h"
#include "Ultrasonic.h"
#include <Servo.h> 
#include <Arduino.h>

// Rover OBJ DEFINITIONS ====================================
class rover {
	
  private:
	shieldMotors shield;
	motor m1;
	motor m2;
	Servo s1, s2;
	gyroSensor g;
	Ultrasonic uFront, uLeft;
	
  public:
	rover();
    void setupMotors(int p1, int p2, int p3, int p4, int e1, int e2);
	void setupSensors();
	
	void steerForward();
	void steerRight(int x);
	void steerLeft(int x);
	
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
    void turnRight();
	void turnLeft();
    void climbSetting();
	void diffTurnRight();
	void diffTurnLeft();
	
	float readDistFront();
	float readDistLeft();
	float readGyroZ();
};
#endif