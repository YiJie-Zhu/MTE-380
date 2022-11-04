#ifndef Motors_h
#define Motors_h

#include <Arduino.h>

class Motor{
  public:
	motor();
    motor(int p1, int p2, int e1);
    void setup();
    void forward();
    void reverse();
    void stop();
    void setSpeed(int speed);
  private:
    int pin1;
    int pin2;
    int enb1;
};

#endif