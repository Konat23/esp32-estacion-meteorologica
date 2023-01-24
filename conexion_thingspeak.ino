#include "ThingSpeak.h"
#include "WiFi.h"

const char* ssid = "";
const char* password = "";

unsigned long channelID = 2007719;              // ID del canal de Thingspeak
const char* WriteAPIKey = "62SBQSM99SCRXMQT";   // Write-APIKey
WiFiClient cliente;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi conectado!");

  ThingSpeak.begin(cliente);
}

void loop() {
  ThingSpeak.setField (1,random(25,29));
  ThingSpeak.setField (2,random(50,60));

  ThingSpeak.writeFields(channelID,WriteAPIKey);
  Serial.println("Datos enviados a ThingSpeak!");
  delay(20000);  // Cada 20s (minimo 15s)
}
