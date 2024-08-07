#include "lpc24xx.h"

float light_sensor(void) {
	float voltage;
	int result;
	PINSEL1 &= 0xFFFDFFFF;
	PINSEL1 |= 0x10000;
	PCONP |= 0x1000;
	
	AD0CR &= 0xF8DE0000;							// Clear all bits except reserved and relating to Burst Mode
	AD0CR = AD0CR + 0x200402;				// Select A0.1, CLKDIV = 4, Burst off, Power on, Start = 000
	AD0CR = AD0CR + (1<<24);
	
	// Check when conversion is done before moving forward
	while((AD0DR1 & 0x80000000) == 0x0) {}
	
	result = AD0DR1;								// The result is divided to remove the 6 zero bits so that the proper value is obtained
	result = (result >> 6);
	result = result & 0x3FF;
	voltage = (result / 1023.0 ) * 3.3;
		
	return voltage;
}
