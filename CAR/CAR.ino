#include <Bounce2.h>;

const int LPin = 2;
const int RPin = 3;
const int GoPin = 12;
const int BackPin = 13; 

const int motorPin1 = 11;  
const int motorPin2 = 10;  
//Motor B
const int motorPin3 = 6; 
const int motorPin4 = 5;  


void setup() {
Serial.begin(9600);
}

void loop() {
 int x = digitalRead(LPin);
  delay(50);
 Serial.print(x);

 int y = digitalRead(RPin);
  delay(50);
 Serial.println(y);

}
  void moveStop() {
  analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  } 
  
void moveForward() {


    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);  
  
}

void moveBackward() {
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);   
  
}  

void turnRight() {
 analogWrite(motorPin1, 180);
    analogWrite(motorPin4, 180);
  analogWrite(motorPin3, 0);
    analogWrite(motorPin2, 0);    
delay(100);


} 
 
void turnLeft()
  {
  analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);   
 analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);     
delay(200);
   moveForward();
  }
  


