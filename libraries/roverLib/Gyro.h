#ifndef Gyro_h
#define Gyro_h

#include <Arduino.h>
#include <MPU6050_light.h>

class gyroSensor{
  public:
    gyroSensor();
    void setup();
    float angleX();
    float angleY();
    float angleZ();
  private:
    MPU6050* mpu;
};

#endif