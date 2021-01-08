
#include "aht10.h"

#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

//aht10th aht;

void setup() 
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  //Wire.begin();
  aht.begin();
  delay(200);

}

void loop() 
{
  aht.trigMeasure();
  delay(200);
  
  aht.reqData();
  Serial.print(aht.tempRead());
  Serial.print(" || ");
  Serial.print(aht.rhRead());
  
  Serial.println();
  
  delay(3000);
}
