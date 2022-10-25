#include "Motors.h"

Motors m1(1, 2);
Motors m2(3, 4);

void setup(){
    m1.setup();
    m2.setup();
}

void loop(){
    m1.forward();
    m2.forward();
    delay(1000);
    m1.reverse();
    m2.reverse();
    delay(1000);
    m1.stop();
    m2.stop();
}