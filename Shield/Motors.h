#ifndef Motors_h
#define Motors_h

#include <Arduino.h>

class Motors{
  public:
    Motors(int p1, int p2);
    void setup();
    void forward();
    void reverse();
    void stop();
  private:
    int pin1;
    int pin2;
};

#endif