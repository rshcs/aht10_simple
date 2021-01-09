
#include "aht10.h"

void setup() 
{
  Serial.begin(9600);
  aht.begin(); // or Wire.begin()
  delay(200);

}

void loop() 
{
  aht.trigMeasure();
  delay(100); // Data request interval after the trigger must be longer than 75millis
  aht.reqData(); // Requsts all bytes 
  Serial.print(aht.tempRead()); // Print temperature value
  Serial.print(" | ");
  Serial.println(aht.rhRead()); // Print humidity value
  
  delay(10000); // If data request interval smaller than 2S internal temperature of the sensor could go high
}
