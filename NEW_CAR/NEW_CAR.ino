#include <IRremote.h> // подключаем библиотеку

int reciverPin = 12; // пин, к котрому подключен ИК-приемник
IRrecv irrecv(reciverPin);
decode_results results;


#include <Wire.h> // Добавляем необходимые библиотеки
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A0 // к какому пину будет подключен сигнальный выход датчика   PIN(A0)
//выбор используемого датчика
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);


#include <Ultrasonic.h>    // подключаем библиотеку Ultrasonic
Ultrasonic ultrasonic(8, 9); // назначаем выходы для Trig и Echo


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


int buzzer = 5; //переменная с номером пина динамика

unsigned long timeLeft;


void setup()
{
  lcd.init(); // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  lcd.createChar(1, degree); // Создаем символ под номером 1
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzer, OUTPUT); //объявляем пин как выход
  Serial.begin(9600);

  irrecv.enableIRIn(); // запуск приемника
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  int dist = ultrasonic.distanceRead();

  // Serial.print(dist);     // выводим расстояние в сантиметрах
  // Serial.println(" cm");


  // постоянно считываем данные с приемника
  if (irrecv.decode(&results)) {
    // выводим в консольку, что получили, число в 16-ричном виде
    Serial.println(results.value);
    
    if (results.value == 16724175)
    {
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

      lcd.setCursor(2, 1);
      lcd.print("T");
      lcd.print("=");
      lcd.print(t, 0);
      lcd.write(1);

      lcd.setCursor(9, 1);
      lcd.print("H");
      lcd.print("=");
      lcd.print(h, 0);
      lcd.print("%");
    }

    if (results.value == 16738455) {
      lcd.setCursor(2, 0);
      lcd.print("Hello World");
    }

     if (results.value == 16732845) {
      lcd.setCursor(2, 0);
      lcd.print("Poshel Nahyi");
    }

     if (results.value == 16743045) {
      lcd.setCursor(5, 0);
      lcd.print("Nik_02");
    }

   
    if (results.value == 16769055) {
      lcd.clear();
    }
    irrecv.resume(); // готовы принимать следующий сигнал
  }





  if (results.value == 16718055) {
    lcd.setCursor(4, 0);
    lcd.print("DISTANCE");
    if (millis() - timeLeft > 100) {
      timeLeft = millis();

      lcd.setCursor(5, 1);
      lcd.println(dist);
      lcd.setCursor(8, 1);
      lcd.print("cm");
    }

    if (dist < 20) {
      analogWrite(buzzer, 100); //включаем звук
      delay(100);
      analogWrite(buzzer, 0); //включаем звук
      delay(200);

      
    }
    else( analogWrite(buzzer, 0)); //выключаем звук

    if (dist < 5) {
      analogWrite(buzzer, 100); //включаем звук
   
      
    }
    else( analogWrite(buzzer, 0)); //выключаем звук
  }



}
