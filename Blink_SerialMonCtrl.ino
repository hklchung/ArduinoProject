void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    int usr_input = Serial.parseInt();
    if (usr_input == 1){
      digitalWrite(13, HIGH);
    }
    if (usr_input == 0){
      digitalWrite(13, LOW);
    }
  }
}
