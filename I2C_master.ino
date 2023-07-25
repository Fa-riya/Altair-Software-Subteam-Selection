#include <Wire.h>

String master="Hi from Master";

void setup(){
  Wire.begin();
  
  Serial.begin(9600);
  Serial.println("I2C Communication Master Demonstration") ;
}

void loop() {
  delay(1000);
  Serial.println("Sending Data to Slave");
  
  int dataSize = master.length() + 1;
  byte data[dataSize];

  for (int i = 0; i < dataSize - 1; i++) {
    data[i] = master.charAt(i);
  }
  data[dataSize - 1] = '\0'; 

  Wire.beginTransmission(9);
  Wire.write(data, dataSize);
  Wire.endTransmission();

  Serial.println("Receiving data");
  Wire.requestFrom(9, 10);

  String response = "";
  while (Wire.available()) {
    char c = Wire.read();
    response += c;
  }
  Serial.println("Data from Slave is:");
  Serial.println(response);
}
