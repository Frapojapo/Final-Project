#include "lpc24xx.h"
#include "lcd/lcd_grph.h"
#include "lcd/lcd_hw.h"
#include "lcd/lcd_cfg.h"
#include "lcd/sdram.h"
#include "lcd/touch.h"
#include <stdio.h>

void initialize(void) {
	// LCD
	sdramInit();
	lcdInit(&lcd_config);
	lcdTurnOn();
	touch_init();
	// Ambient Light
	FIO2DIR |= 0x1FE;									// P2.1 to P2.8 is set as output
	FIO0PIN |= 0x400000;							// P0.22 is set as high
	// Blinds
	FIO3DIR |= 0x380000;								// P3.19 to P3.21 is set as output
	// Emergency Button
	FIO3DIR |= 0x70000;								// P3.16 to P3.18 is set as output
	// Audio
	PINSEL1 &= 0xFFCFFFFF;						// Setup P0.26 to be Aout
	PINSEL1 = PINSEL1 + 0x1 << 21;
	FIO0DIR &= 0xFBFFFFFF;						// Set P0.26 (Aout) to be an output
	FIO0DIR = FIO0DIR + 0x1 << 26;
}
