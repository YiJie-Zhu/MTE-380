#include "Wire.h"

float gyroX, gyroY, gyroZ;
float lowerLeft = 10;
float upperLeft = 12;
float turnDistance = 20;
float turns = 9;
float oneBlock = 1; //placeholder for 1 block distance
float driveMotor = 50; //placeholder for driving motor speed

void turn()
{
    // slow down current motor speed
    // set speed of turning motors to move right (80%)
    while (Gyro.angleZ() < 90)
    {
    }
    // reset turning motors
}

// Make sure it is not trying to correct distance instead of turning
void correct_distance(float currSpeed)
{
    //float motor_speed = (leftUltra.read() < lowerLeft ? 5 : (leftUltra.read() > upperLeft ? -5 : 0))
    
    //proportionally adjusting speed rather than constant
    float motor_speed = (lowerLeft - leftUltra.read())*10;    
        float leftMotor = currSpeed+motor_speed;
        float rightMotor = currSpeed - motor_speed;
        // set turning motors to motor_speed
        while (leftUltra.read() < lowerLeft || leftUltra.read > upperLeft);
    {
        // Check if needs to turn instead of correcting
    }
}

bool check_shaking()
{
    if(abs(gyroX) > 5){
        int currX = gyroX;
        delay(100);
        if (abs(gyroX) > 5 && gryoX != currX){
            return true;
        }
    }
    return false;
}
void check_drop() {
    if(abs(gyroY) > 50){
        delay(50);
        //fall detected, and distance to next wall is roughly 1 block
        if (abs(frontUltra.read() - oneBlock) < 3){
            //set motors to max, wait to climb wall
            while(gyroY < 50){}
            while(gyroY > -50){}
        }
    }
}

void loop()
{
    int count = 0 while (count < turns)
    float motorSpeed = driveMotor
    // motor speed fast!
    {
        int thisDistance = turnDistance - (count/3)*oneBlock;
        int shakingDist = thisDistance;
        while (frontUltra.read() > thisDistance)
        {
            check_drop();
            if (frontUltra.read() <= shakingDist) motorSpeed = driveMotor;
            //only check shaking if not currently in a shaking phase
            if (motorSpeed < driveMotor){
                if(check_shaking()){
                    //shaking detected, reduce speed for 1 block
                    shakingDist = frontUltra.read() + oneBlock;
                    motorSpeed = driveMotor/2;
                }
            }
            correct_distance(motorSpeed);
        }
        // Check if ultrasonic is still within range after 100 ms (in case it dipped and ultrasonic looked at the floor)
        // delay(100) if (frontUltra.read() > turnDistance) turn();


        //personally i prefer this method since it reduces delay and actually makes use of gyro
        //but we can switch it back if needed
        if (abs(gyroY) < 5) turn();
        count++;
    }
}

void setup()
{
    // Required setups
    Serial.begin(9600);
    Wire.begin();
    // set up gyro
    // set up ultrasonic
}