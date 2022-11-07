#include "roverLib.h"

rover::rover(){
	/*
	// must provide default constructor
	shield = shieldMotors();
    m1 = motor();
    m2 = motor();
	*/
}

void rover::setupMotors(int p1, int p2, int p3, int p4, int e1, int e2){
	s1.attach(10);
	s2.attach(9);
	
	shield = shieldMotors();
    shield.setup();
	
    m1 = motor(p1, p2, e1);
	m1.setup();
    m1.stop();
	
    m2 = motor(p3, p4, e2);
	m2.setup();
    m2.stop();
	
}

void rover::steerForward(){
	s1.write(90);
	s2.write(90);
}

void rover::steerRight(){
	s1.write(0);
	s2.write(0);
}

void rover::steerLeft(){
	s1.write(180);
	s2.write(180);
}

void rover::setupSensors(){
	g = gyroSensor();
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