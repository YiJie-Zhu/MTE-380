#include <roverLib.h>

rover r1 = rover();
  
void setup(){
  Serial.begin(9600); 
  r1.setupSensors();
}

float dist = 0;

void loop() {
  // put your main code here, to run repeatedly:
  
  dist = r1.readDistFront();
  Serial.println(dist);
  dist = r1.readDistLeft();
  Serial.println(dist);

  dist = r1.readGyroZ();
  Serial.println(dist);
  
  Serial.println();
  delay(5000);
}
