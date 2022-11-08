#include "roverLib.h"

rover::rover(){

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
	s1.write(85);
	s2.write(82);
}

void rover::steerRight(){
	s1.write(45);
	s2.write(45);
}

void rover::steerLeft(){
	s1.write(135);
	s2.write(135);
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

void rover::setupSensors(){
	g = gyroSensor();
	g.setup();
	
	uLeft = Ultrasonic();
	uLeft.setup(37,36);
	
	uFront = Ultrasonic();
	uFront.setup(33, 32);
}

float rover::readDistFront(){
	return uFront.read();
}

float rover::readDistLeft(){
	return uLeft.read();
}

float rover::readGyroZ() {
	return g.angleZ();
}