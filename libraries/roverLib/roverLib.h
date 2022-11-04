#ifndef ROVERLIB_H
#define ROVERLIB_H

#include "Motors.h"
#include "Shield.h"
#include "Gyro.h"
#include "Ultrasonic.h"
#include <Arduino.h>

// Rover OBJ DEFINITIONS ====================================
class Rover {
  private:
	ShieldMotors shield;
	Motor m1;
	Motor m2;
	GyroSensor g;
  Ultrasonic u1;
  Ultrasonic u2;
	
  public:

	rover();
    void init_motors(int p1, int p2, int p3, int p4, int e1, int e2);
    void init_sensors(int tr1, int ec1, int tr2, int ec2);
    void setup();
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
    void climbSetting();
    void frontDistance();
    void sideDistance();
};
#endif