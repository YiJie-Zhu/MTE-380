#include "Shield.h"

Shield s1(1, 2, 3, 4);

void setup(){
  Serial.begin(9600);
  s1.setup();
}

void loop(){
  s1.forward();
  delay(1000);
  s1.reverse();
  delay(1000);
  s1.stop();
  delay(1000);
}