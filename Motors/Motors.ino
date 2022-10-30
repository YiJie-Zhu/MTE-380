#include "Motors.h"

Motors m1(22, 24, 44);
Motors m2(26, 28, 46);

void setup(){
  Serial.begin(9600);
  Serial.println("Start");
  m1.setup();
  m2.setup();
  delay(100);
}

void loop(){
  Serial.println("loop");

  m1.forward();
  m2.forward();
  delay(1000);
  m1.reverse();
  m2.reverse();
  delay(1000);
  m1.stop();
  m2.stop();
  delay(1000);
}