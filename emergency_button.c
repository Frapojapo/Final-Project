#include "lpc24xx.h"
#include "delay.h"

int emergency_button(int state) {
	int i = 0;
	if (state == 0) {
		FIO3PIN &= ~(0x1 << 16);
		while (i < 0x8) {
			FIO3PIN &= ~(0x1 << 17);
			FIO3PIN |= (0x1 << 18);
			DACR = (0x320 << 6);
			mdelay(0x1F4);
			FIO3PIN &= ~(0x1 << 18);
			FIO3PIN |= (0x1 << 17);
			DACR = (0x1F4 << 6);
			i++;
		}
		DACR = (0x0 << 6);
		return 1;
	} else {
		FIO3PIN &= ~(0x1 << 17);
		FIO3PIN &= ~(0x1 << 18);
		FIO3PIN |= (0x1 << 16);
		DACR = (0x0 << 6);
		return 0;
	}
}
