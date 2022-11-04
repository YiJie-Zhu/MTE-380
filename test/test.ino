#include <MPU6050_light.h>

#include <roverLib.h>

// Arduino IDE only allows access to files in same level of folder 

void setup(){
    rover r1 = rover();
    r1.init(22, 24, 26, 28, 44, 46);
    r1.setup();
    r1.setSpeed(20);
    r1.forward();
    delay(2000);
    r1.stop();
}

void loop(){

}
