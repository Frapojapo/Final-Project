#include "lpc24xx.h"

int auto_blinds(float sensor_value, int state) {
	if (sensor_value >= 1.4 && state != 3) {
		FIO3PIN &= ~(0x1 << 19);
		FIO3PIN &= ~(0x1 << 20);
		FIO3PIN |= (0x1 << 21);
		state = 0;
	} else if (sensor_value < 1.4 && sensor_value >= 1.3 && state != 2) {
		FIO3PIN &= ~(0x1 << 19);
		FIO3PIN &= ~(0x1 << 21);
		FIO3PIN |= (0x1 << 20);
		state = 0;
	} else if (sensor_value < 1.3 && state != 1) {
		FIO3PIN &= ~(0x1 << 20);
		FIO3PIN &= ~(0x1 << 21);
		FIO3PIN |= (0x1 << 19);
		state = 0;
	}
	return state;
}
	
int manual_blinds(void) {
	int state = 0;
	if (FIO3PIN & (0x1 << 19) != 0x0) {
		FIO3PIN &= ~(0x1 << 19);
		FIO3PIN |= (0x1 << 20);
		state = 1;
	} else if (FIO3PIN & (0x1 << 20) != 0x0) {
		FIO3PIN &= ~(0x1 << 20);
		FIO3PIN |= (0x1 << 21);
		state = 2;
	} else if (FIO3PIN & (0x1 << 21) != 0x0) {
		FIO3PIN &= ~(0x1 << 21);
		FIO3PIN |= (0x1 << 19);
		state = 3;
	}
	return state;
}
