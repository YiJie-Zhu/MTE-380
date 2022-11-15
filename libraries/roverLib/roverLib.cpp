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

void rover::setupSensors(){
	uLeftFront = Ultrasonic();
	uLeftFront.setup(39,38);
	
	uLeftBack = Ultrasonic();
	uLeftBack.setup(37,36);

	uFront = Ultrasonic();
	uFront.setup(33, 32);
}

void rover::steerForward(){
	s1.write(75);
	s2.write(75);
}

void rover::steer(int x){
	int turn = 75 - x;
	s1.write(turn);
	s2.write(turn);
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

void rover::diffTurnRight(){
	int angle = 35*3.14/180;
	int speed = 225;
	this->steer(35);
	//setDiffSpeed(int fr, int fl, int mr, int ml)
	shield.setDiffSpeed(speed/4, speed, speed*cos(angle)/4, speed*cos(angle));
	//back left
    m1.setSpeed(speed*cos(angle));
	//back right
    m2.setSpeed(speed*cos(angle)/4);
}

void rover::diffTurnLeft(){
	int angle = 35*3.14/180;
	int speed = 200;
	this->steer(-35);
	//setDiffSpeed(int fr, int fl, int mr, int ml)
	shield.setDiffSpeed(speed, speed/4, speed*cos(angle), speed*cos(angle)/4);
	//back left
    m1.setSpeed(speed*cos(angle)/4);
	//back right
    m2.setSpeed(speed*cos(angle));
}

float rover::readDistFront(){
	return uFront.read();
}

float rover::readDistLeftFront(){
	return uLeftFront.read();
}

float rover::readDistLeftBack(){
	return uLeftBack.read();
}

float rover::readGyroZ() {
	return g.angleZ();
}

void rover::turnRight(float tolerance){
	this->diffTurnRight();
	delay(2000); 
	while (this->readDistLeftBack() - this->readDistLeftFront() > tolerance){
		delay(10);
	}

	this->steerForward();
}

void rover::correction(float dist){
	float result = 0;
	if (dist < 0.25 && dist > -0.25){
		result = 0;
	} 
	else{
		result = (1.0/6)*dist*dist*dist+dist;
	}
	Serial.print("Correction Res");
	Serial.println(result);
	this->steer(result);
}