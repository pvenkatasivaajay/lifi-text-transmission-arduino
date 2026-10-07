#include <Manchester.h>

#define TX_PIN 9

void setup() {
  pinMode(TX_PIN, OUTPUT);
  Serial.begin(9600);
  man.setupTransmit(TX_PIN, MAN_1200);
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    man.transmit(ch);
    delay(100);
  }
}
