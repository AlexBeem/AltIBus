// Приём IBUS с использованием библиотеки AltSoftSerial.h и передача по протоколу IBUS
// в стандартный серийный порт (USB) (ограничения по числу каналов нет)
// Для Atmega328P

#include "AltSoftSerial.h"
AltSoftSerial mySerial; //(8, 9);   // используются только эти пины, другие назначить нельзя

volatile byte ibyte;

void setup() {
 Serial.begin(115200);
 mySerial.begin(115200);
}

void loop() {
 if(mySerial.available() > 0){
  ibyte = mySerial.read();
  Serial.write(ibyte);
 }
}
