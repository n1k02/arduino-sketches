//Бибилиотеки

unsigned long last_time1;
unsigned long last_time2;
unsigned long last_time3;
unsigned long last_time4;

#define led_pin 3   //пин диода
#define SPin A0
int flag = 0;
void setup() {
  Serial.begin(9600);

  pinMode(led_pin, OUTPUT);

}

void loop() {
  int x = analogRead(SPin);

  if (x > 70 && millis() - last_time1 > 180 && flag == 0) {
    last_time1 = millis();
    Serial.println("najal");
    flag = 1;
  }
  delay(150);
    x = analogRead(SPin);
  delay(150);
  
  if (x > 70 && flag == 1 && millis() - last_time4 > 180) {
    last_time4 = millis();
    Serial.println("otjal");
    flag = 0;

  }
  digitalWrite(led_pin, flag);
}







