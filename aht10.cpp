//#include "Arduino.h"
#include "aht10.h"
#include <Wire.h>

aht10th::aht10th()
{
	//int inv = inval;
}

int16_t aht10th::retinval(int16_t inv)
{
	return inv;
}

double aht10th::rhRead()
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

double aht10th::tempRead()
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

void aht10th::reqData()
{
  Wire.requestFrom(I2C_ADDR, 6);
  
  for(int i = 0; i < 6; i++)
  {
  	readByte[i] = Wire.read();
  }
}

void trigMeasure()
{
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(TRIG_MEASURE);
  Wire.endTransmission();
}