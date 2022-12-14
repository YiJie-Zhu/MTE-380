#include "Ultrasonic.h"
#include <Arduino.h>

Ultrasonic::Ultrasonic(int trig, int echo){
    trigPin = trig;
    echoPin = echo;
}

void Ultrasonic::setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Ultrasonic::read(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}