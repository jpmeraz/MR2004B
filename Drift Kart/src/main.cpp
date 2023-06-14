#include <Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>


#define rxD2 16
#define txD2 17
SoftwareSerial mygps(rxD2,txD2);

void print_speed();

TinyGPSPlus gps;
int pulso = 2;
void setup() 
{
  Serial.begin(9600);
  mygps.begin(9600);
  pinMode(pulso,OUTPUT);      
  delay(3000);
  Serial.println("Velocimetro");
}

void loop() {
    
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (mygps.available())
    {
      if (gps.encode(mygps.read()))
      {
        newData = true;
      }
    }
  }

  //If newData is true
  if(newData == true)
  {
    newData = false;
    print_speed();
  }
  else
  {
    Serial.print("No hay datos");
    
  }  
  
}

void print_speed()
{
        
  if (gps.location.isValid() == 1)
  {
      
    Serial.print(gps.speed.kmph());
    Serial.println("km/h");
    Serial.print("SAT:");
    Serial.println(gps.satellites.value());
    Serial.print("ALT:");
    Serial.println(gps.altitude.meters(), 0);

    
  }

}