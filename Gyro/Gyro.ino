#include "Gyro.h"
#include "Wire.h"

Gyro gyro;

void setup() {
  Serial.begin(9600);
  // Wire.begin();
  gyro.setup();
}

void loop() {
  delay(1000);
  Serial.println(gyro.angleZ());
}