#include <EEPROM.h>
String input="";

void setup() {
  Serial.begin(9600);
}

void loop() {
if (Serial.available()) {
input = Serial.readString();
String request = "";
int readmode = -1;
int address = -1;
int data = -1;
int count = 1;
const char* Input = input.c_str();
for (int i = 0;i<strlen(Input);i++) {
char x = input[i];
if (x == ' ') {
if (count == 1) {
if (request == "write") {
readmode = 0;
}
else if (request == "read") {
readmode = 1;
}
count = 2;
}
else if (count == 2) {
const char* addr = request.c_str();
sscanf(addr,"%d",&address);
count = 3;
}
else if (count == 3) {
break;
}
request = "";
}
else {
request = request + x;
}
}

if (readmode == 0) {
const char* dat = request.c_str();
sscanf(dat,"%d",&data);
if (address>=0 && address<512 && data>=0 && data<256) {
EEPROM.write(address,data);
Serial.print("Writing to address: ");
Serial.println(address);
Serial.print("Value saved: ");
Serial.println(data);
}
else {
Serial.println("Please try again");
}
}
else if (readmode == 1) {
if (count == 2) {
const char* addr = request.c_str();
sscanf(addr,"%d",&address);
}
if (address>=0 && address<512) {
data = EEPROM.read(address);
Serial.print("Reading from address: ");
Serial.println(address);
Serial.print("Value returned: ");
Serial.println(data);
}
else {
Serial.println("Please try again");
}
}
}
}
