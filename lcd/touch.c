#include "touch.h"
#include "lpc24xx.h"
#include <stdlib.h>

#define CS_PIN	0x00100000			//P0.20

static unsigned char touch_read(unsigned char command);

void touch_init(void)
{
	//Implement this as you see fit
	//Remember to setup CS_TP as a GPIO output
	PINSEL0 |= 0xC0000000;				// Enabling SCLK
	PINSEL1 |= 0x3C;							// Enabling MOSI, MISO and CS_TP
	PINSEL1 &= 0xFFFFFCFF;
	FIO0DIR = 0x168000;						// Setting SCLK, MOSI, MISO and CS_TP as outputs
	FIO0PIN |= 0x100000;					// Setting CS_TP high
	S0SPCR &= 0xF003;							// Configuring SPI Control Register to specification
	S0SPCR = S0SPCR + 0x93C;
	S0SPCCR = 0x24;								// Configuring SPI Clock Counter Register to specification
}

void touch_read_xy(char *x, char* y)
{
	//Read X co-ordinate from the touch screen controller
	*x = touch_read(0xD8);
	//Read Y co-ordinate from the touch screen controller
	*y = touch_read(0x98);
}

static unsigned char touch_read(unsigned char command)
{
	unsigned short result;

	//Set CS_TP pin low to begin SPI transmission
	FIO0PIN &= 0xFFEFFFFF;
	
	//Transmit command byte on MOSI, ignore MISO (full read write cycle)
	S0SPDR = command;
	while ((S0SPSR & 0x80) == 0x0) {}
	
	//Transmit 0x00 on MOSI, read in requested result on MISO (another full read write cycle)
	S0SPDR = 0x00;
	while ((S0SPSR & 0x80) == 0x0) {}
	result = S0SPDR;
	
	//Transmission complete, set CS_TP pin back to high
	FIO0PIN |= 0x100000;
	
	//Return 8 bit result.
	return (unsigned char) result;
}

