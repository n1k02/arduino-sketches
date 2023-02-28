#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySwitch.enableReceive(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = mySwitch.getReceivedValue();
  Serial.println(val);

}
