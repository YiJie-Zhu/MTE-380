#include "Motors.h"
#include <Arduino.h>

motor::motor(){
    pin1 = 1;
    pin2 = 2;
    enb = 3;
}

motor::motor(int p1, int p2, int e1){
    pin1 = p1;
    pin2 = p2;
    enb = e1;
}

void motor::setup(){
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(enb, OUTPUT);
}

void motor::forward(){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

void motor::reverse(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

void motor::stop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void motor::setSpeed(int speed){
    analogWrite(enb, speed);
}