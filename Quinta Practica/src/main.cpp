#include <Arduino.h>
#include <WebServer.h>

const char *ssid = "JP";
const char *password = "juanpablo";

WebServer server(80);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (true) {
    Serial.println(".");
    if (WiFi.status() == WL_CONNECT_FAILED) {
      Serial.println("Failed to connect");
      break;
    }
    else if (WiFi.status() == WL_NO_SSID_AVAIL) {
      Serial.println("No SSID available");
      break;
    }
    else if (WiFi.status() == WL_IDLE_STATUS) {
      Serial.println("Idle status");
      break;
    }
    else if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Connected");
      Serial.println(WiFi.localIP());
      break;
    delay(250);
    }
  }
  
  server.begin();
  server.on("/", []() {
    server.send(200, "text/plain", "Hello World");
  });
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

// put function definitions here:
void respuesta() {
  stringHTML = "<!DOCTYPE html>";
}