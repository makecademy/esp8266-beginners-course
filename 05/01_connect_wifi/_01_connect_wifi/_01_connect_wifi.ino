// Import required libraries
#include <ESP8266WiFi.h>

// WiFi parameters
const char* ssid = "wifi_name";
const char* password = "wifi_pass";

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

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

}
