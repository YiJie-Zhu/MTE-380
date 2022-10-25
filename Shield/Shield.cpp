#include "Shield.h"
#include "Motors.h"
#include <Arduino.h>

Shield::Shield(int p1, int p2, int p3, int p4){
    m0 = new AF_DCMotor(4);
    m1 = new Motors(p1, p2);
    m2 = new Motors(p3, p4);
}

void Shield::setup(){
    m0->setSpeed(255);
    m0->run(RELEASE);
    m1->stop();
    m2->stop();
}

void Shield::forward(){
    m0->run(FORWARD);
    m1->forward();
    m2->forward();
}

void Shield::reverse(){
    m0->run(BACKWARD);
    m1->reverse();
    m2->reverse();
}

void Shield::stop(){
    m0->run(RELEASE);
    m1->stop();
    m2->stop();
}