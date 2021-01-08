//#include "Arduino.h"
#include <Wire.h>
#include "aht10.h"
/*
#ifndef Wire
	#include <Wire.h>
#endif
*/
#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

//uint32_t received_data = 0;
uint8_t readByte[7] = {0, 0, 0, 0, 0, 0};

aht10th aht;

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
  //Serial.print(aht.retinval(196));

  aht.trigMeasure();
  delay(200);
  
  aht.reqData();
  Serial.print(aht.tempRead());
  Serial.print(" || ");
  Serial.print(aht.rhRead());
  
  Serial.println();
  
  delay(3000);
}

//===================================
double rhRead()
{
	uint32_t rhData;
	
	for(int8_t i = 0; i < 2; i++)
	{
		rhData |= readByte[1 + i];
		rhData = rhData << 4;
	}
	rhData = (rhData << 4) | (readByte[3] >> 4);
	double rh = (double) rhData * 0.000095;
	return rh;
}

double tempRead()
{
	uint32_t tempData = readByte[3] & 0x0F;
	for(int8_t i = 0; i < 2; i++)
	{
		tempData = tempData << 8 | readByte[4 + i];
	}
	//uint32_t tempData = ((uint32_t) readByte[3] & 0x0F) << 16 | ((uint16_t) readByte[4]) << 8 | readByte[5];
	
	double temp = (double) tempData * 0.000191 - 50;
	return temp;
}
