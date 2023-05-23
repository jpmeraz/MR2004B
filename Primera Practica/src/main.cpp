#include <Arduino.h>

#define LED 2
int input;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    input =  Serial.read();
    if(input=='a'){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
  }
  delay(10);
}
