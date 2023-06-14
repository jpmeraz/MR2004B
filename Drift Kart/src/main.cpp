#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Definicion de pines
#define rxD2 16    // NEO 6M
#define txD2 17    // NEO 6M
#define I2C_SDA 21 // LCD
#define I2C_SCL 22 // LCD
#define DHT_PIN 23 // DHT11

SoftwareSerial mygps(rxD2, txD2);

DHT sensor1(DHT_PIN, DHT11);

// Prototipos de funciones
int Velocidad();

float vel = 0;
float temp = 0;
float hum = 0;
int pulso = 2;

TinyGPSPlus gps; // The TinyGPS++ object

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(115200);
  delay(3000);

  // Se inicializa la pantalla
  lcd.init(I2C_SDA, I2C_SCL);
  lcd.backlight();
  Serial.println("LCD inicializada");

  // Se inicializan los sensores
  mygps.begin(9600);
  sensor1.begin();
  Serial.println("Sensores inicializados");

  pinMode(pulso, OUTPUT);
  delay(3000);
}

void loop()
{
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

  // If newData is true
  if (newData == true)
  {
    newData = false;
    Velocidad();
  }
  else
  {
    Serial.print("No hay datos-");
  }

  float temp = sensor1.readTemperature();
  float hum = sensor1.readHumidity();
  float vel = Velocidad();

  lcd.setCursor(3, 0);
  lcd.print("Tu informacion");
  lcd.setCursor(0, 1);
  lcd.print("Velocidad   " + String(vel) + "km/h");
  lcd.setCursor(0, 2);
  lcd.print("Temperatura " + String(temp) + "C");
  lcd.setCursor(0, 3);
  lcd.print("Humedad     " + String(hum) + "%");
  delay(30);
}

int Velocidad()
{
  if (gps.location.isValid() == 1)
  {
    Serial.print(gps.speed.kmph());
    Serial.println("km/h");
    return gps.speed.kmph();
  }
  else
  {
    Serial.println("No hay datos");
    return 0;
  }
}