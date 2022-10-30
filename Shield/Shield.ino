#include "Shield.h"

Shield s1(22, 24, 26, 28, 44, 46);

void setup(){
  Serial.begin(9600);
  s1.setup();
  s1.setSpeed(50);
  delay(100);
}

void loop(){
  s1.forward();
  delay(1000);
  s1.reverse();
  delay(1000);
  s1.stop();
  delay(1000);
}