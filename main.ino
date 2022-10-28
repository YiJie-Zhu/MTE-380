#include "Wire.h"

float gyroX, gyroY, gyroZ;
float lowerLeft = 10;
float upperLeft = 12;
float turnDistance = 20;
float turns = 9;

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
void correct_distance()
{
    float motor_speed = (leftUltra.read() < lowerLeft ? 10 : (leftUltra.read() > upperLeft ? -10 : 0))
        // set turning motors to motor_speed
        while (leftUltra.read() < lowerLeft || leftUltra.read > upperLeft);
    {
        // Check if needs to turn instead of correcting
    }
}

void loop()
{
    int count = 0 while (count < turns)
    // motor speed fast!
    {
        while (frontUltra.read() > turnDistance)
        {
            correct_distance();
        }
        // Check if ultrasonic is still within range after 100 ms (in case it dipped and ultrasonic looked at the floor)
        delay(100) if (frontUltra.read() > turnDistance) turn();
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