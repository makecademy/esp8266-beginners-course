// Import required libraries
#include <ESP8266WiFi.h>
#include "DHT.h"
#include <ESP8266WebServer.h>

// Web server instance
ESP8266WebServer server(80);

// Pin
#define DHTPIN 5

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE, 15);

// WiFi parameters
const char* ssid = "wifi_name";
const char* password = "wifi_pass";

void returnData() {

  // Measure
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Build message
  String message = "The temperature is: ";
  message += String(t);
  message += " degrees Celsius and the humdity is: ";
  message += String(h);
  message += "%.";

  // Send answer
  server.send(200, "text/plain", message);
}

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Init DHT
  dht.begin();

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Route
  server.on("/data", returnData);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {

  // Handle connections
  server.handleClient();

}
