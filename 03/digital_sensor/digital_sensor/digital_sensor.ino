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

  // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Print
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.println("");

  // Wait a few seconds between measurements
  delay(2000);
  
}
