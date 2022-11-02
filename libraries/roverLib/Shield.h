#ifndef Shield_h
#define Shield_h

#include <Arduino.h>
#include "Motors.h"
#include <AFMotor.h>

class shieldMotors{
  public:
    shieldMotors();
    void setup();
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
    void climb();
  private:
    AF_DCMotor* s1;
    AF_DCMotor* s2;
    AF_DCMotor* s3;
    AF_DCMotor* s4;
};

#endif