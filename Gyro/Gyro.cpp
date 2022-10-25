#include "Gyro.h"
#include <Arduino.h>
#include <MPU6050_light.h>
#include "Wire.h"

Gyro::Gyro(){
    mpu = new MPU6050(Wire);
}

void Gyro::setup(){
  byte status = mpu->begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { }
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu->calcOffsets();
  Serial.println("Done!\n");
}

float Gyro::angleX(){
    mpu->update();
    return mpu->getAngleX();
}

float Gyro::angleY(){
    mpu->update();
    return mpu->getAngleY();
}

float Gyro::angleZ(){
    mpu->update();
    return mpu->getAngleZ();
}
