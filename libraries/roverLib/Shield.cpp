#include "Shield.h"
#include <Arduino.h>

shieldMotors::shieldMotors(){
    s1 = NULL;
    s2 = NULL;
    s3 = NULL;
    s4 = NULL;
}

void shieldMotors::setup(){
    s1 = new AF_DCMotor(1);
    s2 = new AF_DCMotor(2);
    s3 = new AF_DCMotor(3);
    s4 = new AF_DCMotor(4);
    s1->setSpeed(0);
    s1->run(RELEASE);
    s2->setSpeed(0);
    s2->run(RELEASE);
    s3->setSpeed(0);
    s3->run(RELEASE);
    s4->setSpeed(0);
    s4->run(RELEASE);
}

void shieldMotors::forward(){
    s1->run(FORWARD);
    s2->run(FORWARD);
    s3->run(FORWARD);
    s4->run(FORWARD);
}

void shieldMotors::reverse(){
    s1->run(BACKWARD);
    s2->run(BACKWARD);
    s3->run(BACKWARD);
    s4->run(BACKWARD);
}

void shieldMotors::stop(){
    s1->run(RELEASE);
    s2->run(RELEASE);
    s3->run(RELEASE);
    s4->run(RELEASE);
}

void shieldMotors::setSpeed(int speed){
    s1->setSpeed(speed);
    s2->setSpeed(speed);
    s3->setSpeed(speed);
    s4->setSpeed(speed);
}

void shieldMotors::climb(){
    s1->setSpeed(100);
    s2->setSpeed(100);
    s3->setSpeed(100);
    s4->setSpeed(100);
}