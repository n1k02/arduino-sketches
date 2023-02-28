int rele_pin = 5;   //Пин на Реле
bool butt = 0;
bool flag = 0;
unsigned long lastPress;
int butt_pin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(butt_pin, INPUT_PULLUP);
  pinMode(rele_pin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  butt = !digitalRead(butt_pin);
  if (butt == 1 && flag == 0) {
    flag = 1;
    Serial.println("Najal");
    digitalWrite(rele_pin, HIGH);
  }

  if (butt == 0 && flag == 1) {
    flag = 0;
    Serial.println("Otjal");
    digitalWrite(rele_pin, LOW);
  }
}
