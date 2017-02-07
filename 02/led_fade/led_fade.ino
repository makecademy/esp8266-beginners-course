// Pin
int ledPin = 5;

// Counter
int i = 0;

void setup() {

  // Set pin as output
  pinMode(ledPin, OUTPUT);
  
}

void loop() {

  // Control intensity
  analogWrite(ledPin, i);
  i = i + 1;

  // Check value
  if (i > 255) {
    i = 0;
  }
  
  // Wait
  delay(100);

}
