

#include "Wire.h" // Добавляем необходимые библиотеки
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A0 // к какому пину будет подключен сигнальный выход датчика   PIN(A0)
//выбор используемого датчика
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
byte degree[8] = // кодируем символ градуса
{
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
};
LiquidCrystal_I2C lcd(0x27, 16, 2); // Задаем адрес и размерность дисплея


void setup()
{
  lcd.init(); // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  lcd.createChar(1, degree); // Создаем символ под номером 1
  Serial.begin(9600);
  dht.begin();

}
void loop() {
  
  delay(1000);
  // Добавляем паузы в несколько секунд между измерениями
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  int hi = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  int ti = dht.readTemperature();
  // Read temperature as Fahrenheit

    Serial.println(ti);

/*TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT*/
//4islo xx.0 (x)
  int  t3 = (t - (float)ti) * 10;
  // Serial.println(x);

  //4islo x0.x (x)
  int t2 = (t / 10) - ((float)ti / 100);
  //Serial.println(y);

  //4islo 0x.x (x)
  int t1 = (float)t / 10;
  //Serial.println(z);

/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/
//4islo xx.0 (x)
  int  h3 = (h - (float)hi) * 10;
  // Serial.println(h3);

  //4islo x0.x (x)
  int h2 = (h / 10) - ((float)hi / 100);
  //Serial.println(h2);

  //4islo 0x.x (x)
  int h1 = (float)h / 10;
  //Serial.println(h1);
  
  // Выводим показания влажности и температуры
  
  
  lcd.setCursor(3, 0);
  lcd.print("T");
  lcd.print("H");
  lcd.print("E");
  lcd.print("R");
  lcd.print("M");
  lcd.print("O");
  lcd.print("M");
  lcd.print("E");
  lcd.print("T");
  lcd.print("R");

  lcd.setCursor(0, 1);
  lcd.print("T");
  lcd.print("=");
  lcd.print(t1);
  lcd.print(t2);
  lcd.print(".");
  lcd.print(t3);
  lcd.write(1);

  lcd.setCursor(9, 1);
  lcd.print("H");
  lcd.print("=");
  lcd.print(h1);
  lcd.print(h2);
  lcd.print(".");
  lcd.print(h3);
  lcd.print("%");
  
}
