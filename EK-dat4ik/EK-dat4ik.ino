#include <IRremote.h>
  IRrecv irrecv(A0);
  decode_results results;
void setup() {
   irrecv.enableIRIn();  // запускаем прием инфракрасного сигнала
   Serial.begin(9600); // подключаем монитор порта
 
}
void loop() {
     if (irrecv.decode(&results)) // если данные пришли выполняем команды
   {
      Serial.println(results.value); // отправляем полученные данные на порт
   irrecv.resume();
   }
}
