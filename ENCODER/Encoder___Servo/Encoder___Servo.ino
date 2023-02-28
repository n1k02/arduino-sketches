#include <GyverEncoder.h>
#include "Servo.h"
Encoder enc(A0, A1, 2, TYPE2);
Servo S1;
int servoPin = 5;
unsigned long last_time;
int x = 90;

void setup() {

  Serial.begin(9600);
  S1.attach(servoPin);
}

void loop() {
  if (last_time - millis() > 5) {
    millis() == last_time;
      enc.tick();
    
    if (enc.isLeft()) {
      x += 5;
      Serial.println(x);
      S1.write(x);
    }

    if (enc.isRight()) {
      x -= 5;
      Serial.println(x);
      S1.write(x);
    }

    if (enc.isPress()) {
      x = 90;
      Serial.println(x);
      S1.write(x);
    }
    
  }
}
