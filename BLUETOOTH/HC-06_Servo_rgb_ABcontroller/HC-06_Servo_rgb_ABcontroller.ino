//Бибилиотеки
#include "Servo.h"
Servo S1;   // Название серво-движка
int servoPin = 5;   //Серво-пин
unsigned long last_time;
int val = 0;   //Значение кнопки
int val2 = 90;   //значение угла для ползунка
int x = 90;   //значение угла для кнопки
#define led_pin 3   //пин диода
int flag = 0;   //значение флажка
void setup() {
  Serial.begin(9600);
  S1.attach(servoPin);  //запуск серво
  pinMode(led_pin, OUTPUT);
  Serial.setTimeout(8);   //тайм-аут для parseInt (чтобы parseInt считывал без задержки)
}

void loop() {
  if (Serial.available()) {  //если в буфере (serial) есть данные
    if (flag == 0) {
      val = Serial.read() - '0';   //считывание чисел в норм виде, по порядку (123 = 1,2,3)
    }
    if (flag == 1) {
      val2 = Serial.parseInt();   //нормальное считывание чисел (123 = 123)

    }
    if (flag == 1) {
      Serial.println(val2);
    }

    if (flag == 0) {
      Serial.println(val);
    }

    if (val == 3 && flag == 0) {   //если отправить 3, серво-привод сдвинется на +1 градус
      S1.write(x++);
    }
    if (val == 4 && flag == 0) {   //если 4, на -1 градус
      S1.write(x--);
    }
    if (val == 1 && flag == 0) {   //кнопка 1, горит светодиод
      digitalWrite(led_pin, HIGH);
    }
    if (val == 2 && flag == 0) {   //кнопка 2, гасит
      digitalWrite(led_pin, LOW);
    }
    if (val == 5 && flag == 0) {
      flag = 1;
      val2 = Serial.parseInt();
    }
    if (val2 == 200 && flag == 1) {
      flag = 0;
    }
    if (flag == 1) {
      S1.write(val2);
    }

  }
}

