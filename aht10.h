#ifndef aht10_h
#define aht10_h
#include "Arduino.h"
// Add Wire if not added already
#ifndef Wire
	#include <Wire.h>
#endif
//---Sensor I2C Address and Commands
#define I2C_ADDR 0x38
//#define INIT 0xE1
#define TRIG_MEASURE 0xAC

class aht10th
{
private:
	uint8_t readByte[7] = {0, 0, 0, 0, 0, 0}; // received data buffer

public:
	double rhRead(); 
	double tempRead();
	void reqData(); // Requsts and store all six data bytes in a buffer
	void trigMeasure(); // Trigger a measurement
	void begin(); // Wire.begin()
};

#endif

extern aht10th aht;

