// Pins
int blueLed = 6;
int greenLed = 5;
int redLed = 3;

void setup() {

  // Setup pins
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
}

void loop() {
  
  // Red
  ledControl(120, 0, 0);
  delay(2000); 

  // Green
  ledControl(0, 120, 0);
  delay(2000);

  // Blue
  ledControl(0, 0, 120);
  delay(2000);

  // Cyan
  ledControl(0, 120, 120);
  delay(2000);

  // Magenta
  ledControl(120, 0, 120);
  delay(2000);

  // Yellow
  ledControl(120, 120, 0);
  delay(2000);

  // White
  ledControl(120, 120, 120);
  delay(2000);
  
}

void ledControl(int redIntensity, int greenIntensity, int blueIntensity) {

  analogWrite(blueLed, blueIntensity);
  analogWrite(redLed, redIntensity);
  analogWrite(greenLed, greenIntensity);
 
}



