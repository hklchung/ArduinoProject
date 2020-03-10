int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 8;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // read the value from the sensor:
  int sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if (sensorValue <= 200) {
  digitalWrite(ledPin, HIGH);
  }
  else{
  // do not turn the ledPin on:
  digitalWrite(ledPin, LOW);
  }
}
