#include <roverLib.h>

rover r1 = rover();
  
void setup(){
  Serial.begin(9600); 
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.setSpeed(200);
  r1.steerForward();
  r1.stop();
}

void loop(){
}
