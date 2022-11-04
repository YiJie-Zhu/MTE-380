#include "Motors.h"
#include <Arduino.h>

Motor::motor(){
    pin1 = 1;
    pin2 = 2;
    enb1 = 3;
}

Motor::motor(int p1, int p2, int e1){
    pin1 = p1;
    pin2 = p2;
    enb1 = e1;
}

void Motor::setup(){
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(enb1, OUTPUT);
}

void Motor::forward(){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

void Motor::reverse(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

void Motor::stop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void Motor::setSpeed(int speed){
    analogWrite(enb1, speed);
}