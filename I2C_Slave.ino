#include <Wire.h>


String answer= "Successful";

void setup(){
  Wire.begin(9);
  
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration") ;
}



void receiveEvent(int numBytes) {
  const int bufferSize = 20;
  char data[bufferSize] = {0};
  int bytesRead = 0;

  while (Wire.available() && bytesRead < bufferSize - 1) {
    char c = Wire.read();
    data[bytesRead] = c;
    bytesRead++;
  }

  data[bytesRead] = '\0';
  Serial.println("Receiving data:");
  Serial.println(data);
}


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