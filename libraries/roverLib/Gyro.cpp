#include "Gyro.h"
#include <Arduino.h>
#include <MPU6050_light.h>
#include "Wire.h"

GyroSensor::gyroSensor(){
    mpu = new MPU6050(Wire);
}

void GyroSensor::setup(){
  byte status = mpu->begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { }
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu->calcOffsets();
  Serial.println("Done!\n");
}

float GyroSensor::angleX(){
    mpu->update();
    return mpu->getAngleX();
}

float GyroSensor::angleY(){
    mpu->update();
    return mpu->getAngleY();
}

float GyroSensor::angleZ(){
    mpu->update();
    return mpu->getAngleZ();
}
