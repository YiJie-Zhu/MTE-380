#include "Motors.h"
#include <Arduino.h>

Motors::Motors(int p1, int p2, int e1, int e2){
    pin1 = p1;
    pin2 = p2;
    enb1 = e1;
    enb2 = e2;
}

void Motors::setup(){
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(enb1, OUTPUT);
    pinMode(enb2, OUTPUT);
}

void Motors::forward(){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
}

void Motors::reverse(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
}

void Motors::stop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void Motors::setSpeed(int speed){
    analogWrite(enb1, speed);
    analogWrite(enb2, speed);
}