#include "Ultrasonic.h"

int trigPin = 42;
int echoPin = 44;

Ultrasonic ultra(trigPin, echoPin);

void setup() {
  Serial.begin(9600); // Starts the serial communication
  ultra.setup();
}
void loop() {
  int distance = ultra.read();
  Serial.print("Distance: ");
  Serial.println(distance);
}