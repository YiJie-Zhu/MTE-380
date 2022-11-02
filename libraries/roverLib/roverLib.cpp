#include "roverLib.h"

rover::rover(){
	shield = shieldMotors();
    m1 = motor();
    m2 = motor();
}

void rover::init(int p1, int p2, int p3, int p4, int e1, int e2){
	shield = shieldMotors();
    m1 = motor(p1, p2, e1);
    m2 = motor(p3, p4, e2);
}

void rover::setup(){
    shield.setup();
    m1.stop();
    m2.stop();
}

void rover::forward(){
	shield.forward();
    m1.forward();
    m2.forward();
}

void rover::reverse(){
	shield.reverse();
    m1.reverse();
    m2.reverse();
}

void rover::stop(){
	shield.stop();
    m1.stop();
    m2.stop();
}

void rover::setSpeed(int speed){
	shield.setSpeed(speed);
    m1.setSpeed(speed);
    m2.setSpeed(speed);
}

void rover::climbSetting(){
    m1.setSpeed(150);
    m2.setSpeed(150);
	shield.setSpeed(100);
}