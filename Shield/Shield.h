#ifndef Shield_h
#define Shield_h

#include <Arduino.h>
#include "Motors.h"
#include <AFMotor.h>

class Shield{
  public:
    Shield(int p1, int p2, int p3, int p4, int e1, int e2);
    void setup();
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
    void climb();
  private:
    Motors* m1;
    Motors* m2;
    AF_DCMotor* s1;
    AF_DCMotor* s2;
    AF_DCMotor* s3;
    AF_DCMotor* s4;
};

#endif