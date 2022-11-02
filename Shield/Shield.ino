#include "Shield.h"

Shield s1(22, 24, 26, 28, 44, 46);

//150 pwm makes over wall

void setup(){
  Serial.begin(9600);
  s1.setup();
  s1.setSpeed(60);
  delay(2000);
}

void loop(){
  s1.forward();

}