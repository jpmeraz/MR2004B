#include <Arduino.h>

#define pin 23
#define LED 2
#define digital 4

void setup() {
  Serial.begin(115200);
  pinMode(pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(pin)) {
    digitalWrite(LED, HIGH);
    Serial.println(analogRead(digital));
    delay(100);
  } else {
    digitalWrite(LED, LOW);
    Serial.println("LOW");
  }
  delay(10);
}
