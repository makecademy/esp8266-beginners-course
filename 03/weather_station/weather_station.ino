// Library
#include "DHT.h"

// Pin
#define DHTPIN 5

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE, 15);

void setup() {

  // Start Serial
  Serial.begin(115200);

  // Init DHT
  dht.begin();
}

void loop() {

  // Read light level
  int lightLevelRaw = analogRead(A0);
  float lightLevel = lightLevelRaw/1024. * 100;

  // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Print data
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");

  Serial.print("Light level: ");
  Serial.print(lightLevel);
  Serial.println("%");

  // Wait a few seconds between measurements
  delay(2000);
  
}
