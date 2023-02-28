int buzzer = 9; //переменная с номером пина динамика
 
void setup() {
  pinMode(buzzer, OUTPUT); //объявляем пин как выход
}
 
void loop() {
  analogWrite(buzzer, 100); //включаем звук
  delay(1000);
  analogWrite(buzzer, 0); //выключаем звук
  delay(1000);
}
