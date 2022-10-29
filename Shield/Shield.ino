#include "Shield.h"

Shield s1(22, 24, 26, 28);

void setup(){
  Serial.begin(9600);
  s1.setup();
  delay(100);
}

void loop(){
  s1.forward();
}