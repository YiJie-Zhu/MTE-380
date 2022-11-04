#include <MPU6050_light.h>

#include <roverLib.h>

// Arduino IDE only allows access to files in same level of folder 
#define MOTOR1_P1 = ;
#define MOTOR1_P2 = ;
#define MOTOR1_E1 = ;
#define MOTOR2_P1 = ;
#define MOTOR2_P2 = ;
#define MOTOR2_E1 = ;
#define US1_TRIG = ;
#define US1_ECHO = ;
#define US2_TRIG = ;
#define US2_ECHO = ;
#define QUALITY = 0.5;

unsigned long prevTime = millis();
long timeInterval = 500;

void setup(){
    rover r1 = rover();
    r1.init_motors(MOTOR1_P1, MOTOR1_P2, MOTOR1_E1, MOTOR2_P1, MOTOR2_P2, MOTOR2_E1);
    r1.init_sensors(US1_TRIG, US1_ECHO, US2_TRIG, US2_ECHO)
    r1.setup();
    r1.setSpeed(100);
    r1.forward();
}

void loop(){
    left = r1.sideDistance();
    front = r1.frontDistance();
    angle = r1.getAngle();
    turning = false;
    unsigned long startTime;
    unsigned long currentTime = millis();

    // If gyro is pointing left

    if (angle < 0 || (left < 6-quality && !turning)){
      // turning motors to the right
      startTime = millis();
    }
    else if (angle > 0 || (left > 6+quality && !turning)){
      // turning motors to the left
      startTime = millis();
    }
    else if (turning && currentTime - startTime > timeInterval){
      prevTime = currentTime;
      // turning motors off
    }
    else {
      // turning motors off
    }

}
