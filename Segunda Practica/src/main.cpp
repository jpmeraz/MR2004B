/*
Juan Pablo Meraz - A01782191

Piensa en un número de 0 a 4095 y guárdela en una variable entera, 
realiza un programa para que otra persona deba mover el potenciómetro, 
sí el número que el potenciómetro va generando está 100 números por 
arriba o 100 números por abajo al número que se pensó y se presiona 
el botón, el programa debe mostrar por consola “Adivinaste el número” 
de lo contrario “Intenta de nuevo”, muestra por consola serial el valor 
de la lectura del potenciómetro.
*/


//Librerías
#include <Arduino.h>

//Declaración de funciones
void adivinar(int valor);

//Declaración de variables y constantes
#define pin 23
#define LED 2
#define digital 4
#define num 2050

void setup() {
  Serial.begin(115200);
  pinMode(pin, INPUT);
  Serial.println("Piensa en un numero de 0 a 4095");
  delay(6000);
}

void loop() {
  if (digitalRead(pin)) {
    digitalWrite(LED, HIGH);
    adivinar(analogRead(digital));
    delay(10);
  }
  else {
    digitalWrite(LED, LOW);
  }
  delay(100);
}

//Función para comparar la entrada del potenciómetro con el número pensado
void adivinar(int valor) {
  if (valor >= num - 100 && valor <= num + 100) {
    Serial.println("Adivinaste el numero");
  } else {
    Serial.println("Intenta de nuevo");
  }
}
