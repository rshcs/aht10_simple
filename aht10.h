#ifndef aht10_h
#define aht10_h
#include "Arduino.h"
//---Sensor I2C Address and Commands
#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

class aht10th
{
private:
	int x = 5;
	uint8_t readByte[7] = {0, 0, 0, 0, 0, 0};

public:
	aht10th();
	int16_t retinval(int16_t inv);
	double rhRead();
	double tempRead();
	void reqData();
};

#endif

extern aht10th th;