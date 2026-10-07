#include <Manchester.h>

#define RX_PIN A0

int threshold = 300;

void setup() {
  Serial.begin(9600);
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
}

void loop() {
  if (man.receiveComplete()) {
    char receivedChar = man.getMessage();
    Serial.print(receivedChar);
    man.beginReceive();
  }
}
