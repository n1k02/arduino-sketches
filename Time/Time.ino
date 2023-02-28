#include <iarduino_RTC.h> // Подключаем библиотеку.
iarduino_RTC time(RTC_DS1302,10,13,12); 
void setup()
{
  Serial.begin(9600);
  time.begin();
  time.settime(0,0,0,0,0,0,0);
}
void loop() {
      Serial.println(time.gettime("s, i, H")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
  
}
