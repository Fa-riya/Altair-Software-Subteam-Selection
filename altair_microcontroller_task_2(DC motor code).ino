#include <Encoder.h>

Encoder encoder(2, 3);//initiating encoder

//variables that will count data
long position = 0;
int rotation = 0;
int rpm = 0;

void setup()
{
  Serial.begin(9600);//initializing serial monitor
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  analogWrite(5, 30);
  analogWrite(6, 0);
  
  //reading the position and calculating rotation
  position = encoder.read() / 10;
  rotation = abs(position) / 10;

  //function that returns the time the simulation has been running for
  unsigned long currentTime = millis();
  
  //delaying the calculation to print the rpm once per second
  delay(1000);
  //doing calculations in float then converting to integer 
  //otherwise we'll always get 00 when time is more than 1000millisecs
  rpm = (int)rotation * (1000.0 / currentTime) * 60.0; 
  
  //printing on the serial monitor
  Serial.print("RPM: ");
  Serial.println(rpm);
}
