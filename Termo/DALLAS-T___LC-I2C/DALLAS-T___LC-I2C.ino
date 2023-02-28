#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Устанавливаем дисплей
// адрес может быть 0x27 или 0x3f

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {

  lcd.init();
  lcd.backlight();  // Включаем подсветку дисплея

  Serial.begin(9600);
  sensors.begin();

}
void loop() {
  sensors.requestTemperatures();  // запрос температуры
  float tempF = sensors.getTempCByIndex(0); // получаем
  int tempI = sensors.getTempCByIndex(0); // получаем

  //4islo xx.0 (x)
  int  t3 = (tempF - (float)tempI) * 10;
  // Serial.println(x);

  //4islo x0.x (x)
  int t2 = (tempF / 10) - ((float)tempI / 100);
  //Serial.println(y);

  //4islo 0x.x (x)
  int t1 = (float)tempF / 10;
  //Serial.println(z);

  
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
  lcd.print(" ");
  lcd.print("=");


  lcd.setCursor(6, 1);
  lcd.print(t1);
  lcd.setCursor(7, 1);
  lcd.print(t2);
  lcd.setCursor(8, 1);
  lcd.print(".");
  lcd.setCursor(9, 1);
  lcd.print(t3);
  
delay(2000);
}
