#include <roverLib.h>

rover r1 = rover();

void setup(){
  Serial.begin(9600); 
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.diffTurnLeft();
  r1.forward();
  delay(5000);
  r1.stop();
}

void loop(){
}
