#include <roverLib.h>

rover r1 = rover();

void setup(){
  Serial.begin(9600); 
  r1.setupMotors(45, 47, 49, 51, 2, 13);
  r1.steerForward();
  r1.setSpeed(100);
  r1.forward();
  while(r1.readDistFront() > 20){}
  float dist = r1.readGyroZ();
  r1.diffTurnRight();
  r1.forward();
  //while((r1.readGyroZ() - dist) < 90){}
  delay(3000);
  r1.stop();
}

void loop(){
}
