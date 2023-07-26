#include <Wire.h>

//This is the string we will transmit
String answer= "Successful";

void setup(){
  Wire.begin(9);
  
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  //initiate serial monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration") ;
}



void receiveEvent(int numBytes) {
  const int bufferSize = 20;
  char data[bufferSize] = {0};
  int bytesRead = 0;
  //receiving data as bytes
  while (Wire.available() && bytesRead < bufferSize - 1) {
    char c = Wire.read();
    data[bytesRead] = c;
    bytesRead++;//calculating bytes read to add null at end
  }

  data[bytesRead] = '\0';//null to identify end of data
  //printing received data
  Serial.println("Receiving data:");
  Serial.println(data);
}

//sending data on request
void requestEvent(){
  byte response[10];
  for(byte i=0;i<10;i++){
    response[i] = (byte)answer.charAt(i);
  }
  Wire.write(response,sizeof(response));
  Serial.println("Sending Data to Master") ;
}

void loop(){
  delay(50);
}