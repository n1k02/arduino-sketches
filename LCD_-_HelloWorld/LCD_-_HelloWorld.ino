#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(3, 0);
  lcd.print("T");
  lcd.print("H");
  lcd.print("E");
  lcd.print("R");
  lcd.print("M");
  lcd.print("O");
  lcd.print("M");
  lcd.print("E");
  lcd.print("T");
  lcd.print("R");

  lcd.setCursor(1, 1);
  lcd.print("T");
  lcd.print(" ");
  lcd.print("=");
 
 } 
