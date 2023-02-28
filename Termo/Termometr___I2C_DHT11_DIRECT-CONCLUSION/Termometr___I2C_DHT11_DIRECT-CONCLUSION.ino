

#include <Wire.h> // Добавляем необходимые библиотеки
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
  int h = dht.readHumidity();
  // Read temperature as Celsius
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit
  
  Serial.println(t);

/*TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT*/


/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/

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

  lcd.setCursor(1, 1);
  lcd.print("T");
  lcd.print("=");
  lcd.print(t);
  lcd.write(1);

  lcd.setCursor(10, 1);
  lcd.print("H");
  lcd.print("=");
  lcd.print(h);
  lcd.print("%");
  
}
