// Pins
int motorPin = 6;

void setup() {

  Serial.begin(115200);

  // Setup pins
  pinMode(motorPin, OUTPUT);
  
}

void loop() {
  
  // Accelerate
  for (int i = 0; i < 255; i++) {
     analogWrite(motorPin, i);
     delay(100);
  }
 
  // Decelerate
  for (int j = 255; j > 0; j--) {
    analogWrite(motorPin, j);
    delay(100);
  }
  
}



