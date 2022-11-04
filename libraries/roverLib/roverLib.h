#ifndef ROVERLIB_H
#define ROVERLIB_H

#include "Motors.h"
#include "Shield.h"
#include "Gyro.h"
#include <Arduino.h>

// Rover OBJ DEFINITIONS ====================================
class rover {
  private:
	shieldMotors shield;
	motor m1;
	motor m2;
	gyroSensor g;
	
  public:

	rover();
    void init(int p1, int p2, int p3, int p4, int e1, int e2);
    void setup();
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
    void climbSetting();
};
#endif