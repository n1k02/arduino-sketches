
#include <Wire.h> 

#include "DHT.h"
#define DHTPIN 3     // пин для сигнала поступающего с датчика

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//инициализация датчика
DHT dht(DHTPIN, DHTTYPE);

#include <GyverTimer.h>
GTimer myTimer1(MS);
GTimer myTimer2(MS);

#include<AccelStepper.h>
#define HALFSTEP 8

// Определение пинов для управления двигателем
#define motorPin1  8 // IN1 на 1-м драйвере ULN2003
#define motorPin2  9 // IN2 на 1-м драйвере ULN2003
#define motorPin3  10 // IN3 на 1-м драйвере ULN2003
#define motorPin4  11 // IN4 на 1-м драйвере ULN2003
#define degs 99999999
// Инициализируемся с последовательностью выводов IN1-IN3-IN2-IN4
// для использования AccelStepper с 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper3(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper4(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper5(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper6(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

int val;

unsigned long last_time;
void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Задаём максимальную скорость двигателя
  stepper1.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper1.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper1.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper1.moveTo(degs);

  // Задаём максимальную скорость двигателя
  stepper2.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper2.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper2.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper2.moveTo(-degs);

  // Задаём максимальную скорость двигателя
  stepper3.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper3.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper3.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper3.moveTo(degs);

  // Задаём максимальную скорость двигателя
  stepper4.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper4.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper4.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper4.moveTo(-degs);

  // Задаём максимальную скорость двигателя
  stepper5.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper5.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper5.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper5.moveTo(degs);

  // Задаём максимальную скорость двигателя
  stepper6.setMaxSpeed(1200.0);
  // Задаём ускорение двигателя
  stepper6.setAcceleration(10000.0);
  // Установим скорость в шагах за секунду
  stepper6.setSpeed(500);
  // Перемещаем в абсолютно указанное положение
  stepper6.moveTo(-degs);
}

void loop() {
  
  
  
  ///////////  Temperature   //////////////
  if(millis() - last_time > 2000) {
    last_time = millis();
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
    
  Serial.println("Температура");
  Serial.println(t);
  Serial.println("Влажность");
  Serial.println(h);
  }
  //////////////////////////////////////
  
  myTimer1.setTimeout(3460);
  myTimer2.setTimeout(5000);
  
  if (Serial.available()) {
    val = Serial.read();

    ///////////////////////////////////////////////////////////

    if (val == '1') {
      do {
        stepper1.run();
      } while (myTimer1.isReady() == 0);
    }
                                           //// N1/N2 timer1 1-ОБОРОТ
    if (val == '2') {
      do {
        stepper2.run();
      } while (myTimer1.isReady() == 0);
    }

    //////////////////////////////////////////////////////////

    if (val == '3') {
      do {
        stepper3.run();                              //// N3 ПО ЧАСОВОЙ
      } while (myTimer2.isReady() == 0);
    }

    //////////////////////////////////////////////////////////

    if (val == '4') {
      do {
        stepper4.run();                             //// N4 ПРОТИВ ЧАСОВОЙ
      } while (myTimer2.isReady() == 0);
    }

    //////////////////////////////////////////////////////////

    if (val == '5') {
      stepper5.run();                                /// N5 ПО ЧАСОВОЙ БЕЗ ТАЙМЕРА
    }

    ////////////////////////////////////////////////////////////

    if (val == '6') {
      stepper6.run();                               /// N6 ПРОТИВ ЧАСОВОЙ БЕЗ ТАЙМЕРА
    }

    ////////////////////////////////////////////////////////////
  }
}

