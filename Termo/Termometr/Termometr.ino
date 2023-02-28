#include <Wire.h>        // Добавляем необходимые библиотеки

#include "DHT.h"
#define DHTPIN A0     // пин для сигнала поступающего с датчика

//выбор используемого датчика
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//инициализация датчика
DHT dht(DHTPIN, DHTTYPE);

 


void setup() {
 
  
   Serial.begin(9600);  
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Выводим показания влажности и температуры
 Serial.print("T =");
 Serial.println(t);
 Serial.print("H =");
 Serial.println(h);
}
