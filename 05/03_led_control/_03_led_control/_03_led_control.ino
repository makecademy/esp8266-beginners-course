// Import required libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// LED pin
int ledPin = 5;

// Web server instance
ESP8266WebServer server(80);

// WiFi parameters
const char* ssid = "wifi_name";
const char* password = "wifi_pass";

void ledOn() {

  // Turn LED on
  digitalWrite(ledPin, HIGH);

  // Send answer
  server.send(200, "text/plain", "LED is on");
}

void ledOff() {

  // Turn LED on
  digitalWrite(ledPin, LOW);

  // Send answer
  server.send(200, "text/plain", "LED is off");
}

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Init LED pin
  pinMode(ledPin, OUTPUT);

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

  // Routes
  server.on("/on", ledOn);
  server.on("/off", ledOff);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {

  // Handle connections
  server.handleClient();

}
