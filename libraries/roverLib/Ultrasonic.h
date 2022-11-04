#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>

class Ultrasonic{
  public:
    ultrasonic(int trig, int echo);
    void setup();
    float read();
  private:
    int trigPin;
    int echoPin;
};

#endif