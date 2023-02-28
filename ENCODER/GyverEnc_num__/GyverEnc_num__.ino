#include <GyverEncoder.h>

Encoder enc(A0, A1, 2, TYPE2);
unsigned long last_time;
int x;
void setup() {

  Serial.begin(9600);
}

void loop() {

  if (last_time - millis() > 10) {
    millis() == last_time;
      enc.tick();
    
    if (enc.isLeft()) {
      x++;
      Serial.println(x);
    }

    if (enc.isRight()) {
      x--;
      Serial.println(x);
    }

    if (enc.isPress()) {
      x = 0;
      Serial.println(x);
    }
    
  }
}
