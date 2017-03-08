// Libraries
#include <ESP8266WiFi.h>
#include "DHT.h"

// WiFi credientials
const char* ssid = "UPC2A55751";
const char* password = "sBfj3wfEurnh";

// Status
int status = WL_IDLE_STATUS;

// Pin
#define DHTPIN 5

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE);

// Server
char server[] = "dweet.io"; 

// Client instance
WiFiClient client;

void setup() {
  
  // Initialize serial and wait for port to open:
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
}

void loop() {

  // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Build request
  String request = "GET /dweet/for/myesp8266?temperature=";
  request += String(t);
  request += "&humidity=";
  request += String(h);
  request += " HTTP/1.1";

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    Serial.println(request);
    client.println(request);
    client.println("Host: dweet.io");
    client.println("Connection: close");
    client.println();
  }
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.connected()) {
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }

  // if the server's disconnected, stop the client:
  Serial.println();
  Serial.println("disconnecting from server.");
  client.stop();

  delay(10000);
}


