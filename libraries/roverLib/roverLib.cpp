#include "roverLib.h"

Rover::rover(){
	/*
	// must provide default constructor
	shield = shieldMotors();
    m1 = motor();
    m2 = motor();
	*/
}

void Rover::init_motors(int p1, int p2, int p3, int p4, int e1, int e2){
	shield = shieldMotors();
    m1 = motor(p1, p2, e1);
    m2 = motor(p3, p4, e2);
}

void Rover::init_sensors(int tr1, int ec1, int tr2, int ec2){
    g = gyroSensor();
    u1 = ultrasonic(tr1, ec1);
    u2 = ultrasonic(tr2, ec2);
}

void Rover::setup(){
    shield.setup();
    m1.stop();
    m2.stop();
    u1.setup();
    u2.setup();
    g.setup();
}

void Rover::forward(){
	shield.forward();
    m1.forward();
    m2.forward();
}

void Rover::reverse(){
	shield.reverse();
    m1.reverse();
    m2.reverse();
}

void Rover::stop(){
	shield.stop();
    m1.stop();
    m2.stop();
}

void Rover::setSpeed(int speed){
	shield.setSpeed(speed);
    m1.setSpeed(speed);
    m2.setSpeed(speed);
}

void Rover::climbSetting(){
    m1.setSpeed(150);
    m2.setSpeed(150);
	shield.setSpeed(100);
}

void Rover::getAngle(){
    return u.angleZ();
}

void Rover::frontDistance(){
    return u1.read();
}

void Rover::sideDistance(){
    return u2.read();
}