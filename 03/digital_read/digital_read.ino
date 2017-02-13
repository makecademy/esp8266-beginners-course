// Pin
int digitalPin = 5;

void setup() {
  
  // Init Serial
  Serial.begin(115200);
  
  // Make the pin an input
  pinMode(digitalPin, INPUT);
}

void loop() {
  
  // Read pin
  int pinState = digitalRead(digitalPin);
  
  // Print state of pin
  Serial.println(pinState);
  delay(1);     
}



