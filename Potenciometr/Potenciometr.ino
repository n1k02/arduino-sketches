int pwm = 0;
int var;
int led_pin = 10;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  
var = analogRead(pwm);
var = map(var, 0, 1023, 0, 255);
constrain(var,0,255);
analogWrite(led_pin, var);
Serial.println(var);
}
