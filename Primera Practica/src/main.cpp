#include <Arduino.h>

#define LED 2

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(LED, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
