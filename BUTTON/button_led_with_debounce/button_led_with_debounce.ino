boolean butt_flag = 0;
boolean butt;

unsigned long last_press;
void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);

}

void loop() {
  butt = digitalRead(3); // считать текущее положение кнопки
  
  if (butt == 1 && butt_flag == 0 && millis() - last_press > 100) {
    butt_flag = 1;
    Serial.println("Button pressed");
  
    last_press = millis();
  }
  if (butt == 0 && butt_flag == 1) {
    butt_flag = 0;
    Serial.println("Button released");
  }
}
