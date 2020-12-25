#include <Wire.h>
#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

uint32_t received_data = 0;
uint8_t readByte[7] = {0, 0, 0, 0, 0, 0};

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  delay(200);

  delay(200);
}

void loop() 
{
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(TRIG_MEASURE);
  Wire.endTransmission();
  delay(200);

  Wire.requestFrom(I2C_ADDR, 6);
 
  for(int i = 0; i < 6; i++)
  {
  	readByte[i] = Wire.read();
  	//Serial.print(readByte[i], BIN);
  	//Serial.print(" | ");
  }

  //sprintgbrs();

  Serial.print(tempRead());
  Serial.println();
  delay(3000);

}

void sprintgbrs()
{
	uint8_t gbrsByte = 2; 
	uint8_t gbrsByte2 = 3;
	uint32_t bigVal = (uint32_t) gbrsByte << 16 | gbrsByte2 << 8 | 7;
	Serial.print(bigVal, BIN);
	//Serial.print(" | ");
	//Serial.print((uint32_t) gbrsByte << 16 | 2, BIN);
	Serial.println();
}

double tempRead()
{
	uint32_t tempData = readByte[3] & 0x0F;
	for(int8_t i = 0; i < 2; i++)
	{
		tempData = tempData << 8 | readByte[4 + i];
	}
	//uint32_t tempData = ((uint32_t) readByte[3] & 0x0F) << 16 | ((uint16_t) readByte[4]) << 8 | readByte[5];
	
	double temp = (double) tempData * 0.00019 - 50;
	return temp;
}