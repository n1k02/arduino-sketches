#include <Ultrasonic.h>    // подключаем библиотеку Ultrasonic
Ultrasonic ultrasonic(8,9); // назначаем выходы для Trig и Echo
 
void setup() {
  Serial.begin(9600);        // подключаем монитор порта
  
}

void loop () {
  int dist = ultrasonic.distanceRead();
  Serial.print(dist);     // выводим расстояние в сантиметрах
  Serial.println(" cm");

  // переключаем цвета светодиода


  delay(100);
}
