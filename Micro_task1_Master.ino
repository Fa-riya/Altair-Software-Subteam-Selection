#include <Wire.h>

String master="Hi from Master";
//This is the message we'll be transmitting

void setup(){
  Wire.begin();
  //initiating serial montior
  Serial.begin(9600);
  Serial.println("I2C Communication Master Demonstration") ;
}

void loop() {
  //slight delay to make it possible to read the data in the serial monitor
  delay(1000);
  Serial.println("Sending Data to Slave");
  //slave did not request any data with a particular size
  int dataSize = master.length() + 1;
  byte data[dataSize];
  //converting character string to byte string
  for (int i = 0; i < dataSize - 1; i++) {
    data[i] = master.charAt(i);
  }
  //adding null character to point end of string
  data[dataSize - 1] = '\0'; 

  //transmitting to slave
  Wire.beginTransmission(9);
  Wire.write(data, dataSize);
  Wire.endTransmission();

  //requesting data from slave
  Serial.println("Receiving data");
  Wire.requestFrom(9, 10);

  //converting the data bytes to character string
  String response = "";
  while (Wire.available()) {
    char c = Wire.read();
    response += c;
  }
  //printing the transmitted data on the serial monitor
  Serial.println("Data from Slave is:");
  Serial.println(response);
}
