//#include "Arduino.h"
//#include <Wire.h>
#include "aht10.h"

#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

//aht10th th(1);

uint32_t received_data = 0;
uint8_t readByte[7] = {0, 0, 0, 0, 0, 0};

void setup() 
{
  Serial.begin(9600);
  
  Wire.begin();
  delay(200);

}

void loop() 
{
/*
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(TRIG_MEASURE);
  Wire.endTransmission();
  delay(70);

  Wire.requestFrom(I2C_ADDR, 6);
  
  for(int i = 0; i < 6; i++)
  {
  	readByte[i] = Wire.read();
  }

  Serial.print(tempRead());
  Serial.print(" | ");
  Serial.print(rhRead());
  //Serial.print(" | ");
  */
  //Serial.print(th.retinval(96));
  Serial.println();
  delay(3000);

}


