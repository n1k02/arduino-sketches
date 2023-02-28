#include <DHT.h>

#include <Wire.h> 

#define DHTPIN 3     // пин для сигнала поступающего с датчика

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//инициализация датчика
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);   
  dht.begin();
}

void loop() {
   float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
//  float f = dht.readTemperature(true);
  if(isnan(t) || isnan(h)) {
    Serial.print("Humidity: ");
   Serial.print(h);
   Serial.print("%\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.print(" *C");
   delay(1000); 
  }
  
}
