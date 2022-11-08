#include <roverLib.h>

rover r1 = rover();
  
void setup(){
  Serial.begin(9600); 
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.setSpeed(150);
}

void loop(){
  
  r1.forward();
  delay(1000);
  
  r1.steerLeft();
  delay(1000);
  r1.steerForward();
  delay(2000);
  r1.steerRight();
  delay(1000);
  
  r1.stop();
  delay(1000);
}
