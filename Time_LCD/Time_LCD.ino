
#include <Wire.h> // Добавляем необходимые библиотеки
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h> // Подключаем библиотеку.
iarduino_RTC time(RTC_DS1302,10,13,12); 
LiquidCrystal_I2C lcd(0x27, 16, 2); // Задаем адрес и размерность дисплея
void setup()
{
   lcd.init(); // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  Serial.begin(9600);
  time.begin();
  
}
void loop() {
      Serial.println(time.gettime("s, i, H")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
   
      lcd.print(time.gettime("s"));
      delay(1000);
      lcd.clear();
    
}
