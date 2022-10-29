#include "Shield.h"
#include "Motors.h"
#include <Arduino.h>

Shield::Shield(int p1, int p2, int p3, int p4, int e1, int e2){
    s1 = new AF_DCMotor(1);
    s2 = new AF_DCMotor(2);
    s3 = new AF_DCMotor(3);
    s4 = new AF_DCMotor(4);
    m1 = new Motors(p1, p2, e1);
    m2 = new Motors(p3, p4, e2);
}

void Shield::setup(){
    s1->setSpeed(0);
    s1->run(RELEASE);
    s2->setSpeed(0);
    s2->run(RELEASE);
    s3->setSpeed(0);
    s3->run(RELEASE);
    s4->setSpeed(0);
    s4->run(RELEASE);
    m1->stop();
    m2->stop();
}

void Shield::forward(){
    s1->run(FORWARD);
    s2->run(FORWARD);
    s3->run(FORWARD);
    s4->run(FORWARD);
    m1->forward();
    m2->forward();
}

void Shield::reverse(){
    s1->run(BACKWARD);
    s2->run(BACKWARD);
    s3->run(BACKWARD);
    s4->run(BACKWARD);
    m1->reverse();
    m2->reverse();
}

void Shield::stop(){
    s1->run(RELEASE);
    s2->run(RELEASE);
    s3->run(RELEASE);
    s4->run(RELEASE);
    m1->stop();
    m2->stop();
}

void Shield::setSpeed(int speed){
    s1->setSpeed(speed);
    s2->setSpeed(speed);
    s3->setSpeed(speed);
    s4->setSpeed(speed);
    m1->setSpeed(speed);
    m2->setSpeed(speed);
}