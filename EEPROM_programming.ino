#include <EEPROM.h>
int address;
int data;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  String request = "";
  if (Serial.available()){
    request = Serial.readString();
    if (request.startsWith("read")){
      address = request.substring(request.indexOf(' ') +1).toInt();
      Serial.print("Reading data from address ");
      Serial.print(address);
      Serial.print(": ");
      Serial.print(" ");
      Serial.println(EEPROM.read(address));
      Serial.println();
    } else if (request.startsWith("write")) {
    address = request.substring(6,7).toInt();
    data = request.substring(8).toInt();
    Serial.print("Writing ");
    Serial.print(data);
    Serial.print(" to the following address: ");
    Serial.print(address);
    EEPROM.write(address,data);
    Serial.println();
    }
  }
}
