#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>

class Ultrasonic{
  private:
    int trigPin;
    int echoPin;
	
  public:
    Ultrasonic();
    void setup(int trig, int echo);
    float read();
	

};

#endif