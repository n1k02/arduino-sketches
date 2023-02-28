unsigned long time_left;
int button_pin = 3;
int flag;
void setup() {
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);

}
void loop() {
  int button = !digitalRead(button_pin);

  if (millis() - time_left > 80)
  { time_left = millis();

    if (button == 1 && flag == 0)
    {
      flag = 1;
      Serial.println("NAJAL");
    }


    if (button == 0 && flag == 1)
    {
      flag = 0;
      Serial.println("OTJAL");
    }

  }
}
