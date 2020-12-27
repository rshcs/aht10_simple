#ifndef aht10_h
#define aht10_h
#include "Arduino.h"

class aht10th
private:
	int x = 5;
	
public:
	aht10th(int inval);
	int16_t retinval(int16_t inv);

};

#endif


