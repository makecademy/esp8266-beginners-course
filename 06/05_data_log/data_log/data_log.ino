// Import required libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <aREST.h>
#include "DHT.h"

// DHT11 sensor pins
#define DHTPIN 5
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE, 15);

// Clients
WiFiClient espClient;
PubSubClient client(espClient);

// Create aREST instance
aREST rest = aREST(client);

// Unique ID to identify the device for cloud.arest.io
char* device_id = "5cg8cg";

// WiFi parameters
const char* ssid = "UPC2A55751";
const char* password = "sBfj3wfEurnh";

// Functions
void callback(char* topic, byte* payload, unsigned int length);

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Set callback
  client.setCallback(callback);

  // Init DHT
  dht.begin();

  // Give name & ID to the device (ID should be 6 characters long)
  rest.set_id(device_id);
  rest.set_name("data_logger_1");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop() {

  // Connect to the cloud
  rest.handle(client);

  // Publish data
  int temperature = dht.readTemperature();
  Serial.print("Sending data to aREST.io ...");
  rest.publish(client, "temperature", temperature);
  Serial.println(" done");
  delay(10000);

}

// Handles message arrived on subscribed topic(s)
void callback(char* topic, byte* payload, unsigned int length) {

  rest.handle_callback(client, topic, payload, length);

}
