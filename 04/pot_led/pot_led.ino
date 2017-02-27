// Pins
int inputPin = 0;
int outputPin = 5;

void setup() {

  Serial.begin(115200);
  
  // Setup pins
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  
  // Read pin
  int pinState = analogRead(inputPin);
  int intensity = (int) (pinState/1024. * 255.);

  Serial.println(intensity);
  
  // Control LED accordingly 
  analogWrite(outputPin, intensity);
  delay(1);     
}



