
#include <Servo.h>
int servoPin = 3;
Servo Ds1;

unsigned long last_time;

int PHOTO_SENSOR_PIN = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Ds1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - last_time > 30) {
    last_time = millis();
    int i = analogRead(PHOTO_SENSOR_PIN);
    Serial.println(i);
    if(i >= 85){
      delay(280);
      Ds1.write(20);
      delay(400);
    } Ds1.write(40);
  }

}
