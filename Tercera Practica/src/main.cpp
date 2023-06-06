/*
Juan Pablo Meraz - A01782191


*/


//Librerías
#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

//Declaración de funciones
int readTemp();
int readHum();

//Declaración de variables y constantes
#define sensore_DHT 15

//Declaración de objetos
DHT sensor1(sensore_DHT, DHT11);


void setup() {
  Serial.begin(115200);
  sensor1.begin();
  pinMode(sensore_DHT, INPUT);
  Serial.println("DHT11 Initialized");
  delay(1000);
}

void loop() {
  Serial.print("Temperatura: ");
  Serial.print(readTemp());
  Serial.println("C");
  Serial.print("Humedad: ");
  Serial.print(readHum());
  Serial.println("%");
  delay(1500);
}

int readTemp()
{
  float temp = sensor1.readTemperature();
  return temp;
}

int readHum()
{
  float hum = sensor1.readHumidity();
  return hum;
}




