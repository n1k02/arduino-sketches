#include <Servo.h>
int servoPin = 3;
Servo Ds1;

void setup() {

  Ds1.attach(servoPin);

}
void loop() {
  Ds1.write(180);
}

