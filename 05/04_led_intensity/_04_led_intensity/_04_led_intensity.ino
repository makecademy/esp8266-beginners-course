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

void ledControl() {

  // Control LED
  int ledIntensity = (server.arg (0)).toInt();
  analogWrite(ledPin, ledIntensity);

  // Message
  String message = "LED set to ";
  message += String(server.arg ( 0 ));
   
  // Send answer
  server.send(200, "text/plain", message);
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
  server.on("/set", ledControl);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {

  // Handle connections
  server.handleClient();

}
