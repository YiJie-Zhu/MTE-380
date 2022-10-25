#ifndef Shield_h
#define Shield_h

#include <Arduino.h>
#include "Motors.h"
#include <AFMotor.h>

class Shield{
  public:
    Shield(int p1, int p2, int p3, int p4);
    void setup();
    void forward();
    void reverse();
    void stop();
  private:
    Motors* m1;
    Motors* m2;
    AF_DCMotor* m0;
};

#endif