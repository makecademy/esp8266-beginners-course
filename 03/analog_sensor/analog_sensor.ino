void setup() {

  // Start Serial
  Serial.begin(115200);
}

void loop() {

  // Read light level
  int lightLevel = analogRead(A0);

  Serial.print("Sensor reading: ");
  Serial.println(lightLevel);

  // Wait a few seconds between measurements
  delay(2000);
  
}
