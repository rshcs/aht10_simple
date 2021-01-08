#ifndef aht10_h
#define aht10_h
#include "Arduino.h"
// Add Wire if not added already
#ifndef Wire
	#include <Wire.h>
#endif
//---Sensor I2C Address and Commands
#define I2C_ADDR 0x38
#define INIT 0xE1
#define TRIG_MEASURE 0xAC

class aht10th
{
private:
	//int x = 5;
	uint8_t readByte[7] = {0, 0, 0, 0, 0, 0}; // received data buffer
	boolean trigFlag = 0; // If triger(1) measurement or not(1)
	uint32_t reqTmr = 0;// To make a delay between trigger to read data

public:

	aht10th();
	int16_t retinval(int16_t inv);
	double rhRead();
	double tempRead();
	void reqData();
	void trigMeasure();
	void begin();
};

#endif

//extern aht10th aht;
