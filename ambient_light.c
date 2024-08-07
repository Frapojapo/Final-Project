#include "lpc24xx.h"

void ambient_light(float voltage) {
	if (voltage >= (1.5 - 0.3 * 7.0/7)) {
		FIO2PIN |= (0x1 << 8);
	} else {
		FIO2PIN &= ~(0x1 << 8);
	}
	if (voltage >= (1.5 - 0.3 * 6.0/7)) {
		FIO2PIN |= (0x1 << 7);
	} else {
		FIO2PIN &= ~(0x1 << 7);
	}
	if (voltage >= (1.5 - 0.3 * 5.0/7)) {
		FIO2PIN |= (0x1 << 6);
	} else {
		FIO2PIN &= ~(0x1 << 6);
	}
	if (voltage >= (1.5 - 0.3 * 4.0/7)) {
		FIO2PIN |= (0x1 << 5);
	} else {
		FIO2PIN &= ~(0x1 << 5);
	}
	if (voltage >= (1.5 - 0.3 * 3.0/7)) {
		FIO2PIN |= (0x1 << 4);
	} else {
		FIO2PIN &= ~(0x1 << 4);
	}
	if (voltage >= (1.5 - 0.3 * 2.0/7)) {
		FIO2PIN |= (0x1 << 3);
	} else {
		FIO2PIN &= ~(0x1 << 3);
	}
	if (voltage >= (1.5 - 0.3 * 1.0/7)) {
		FIO2PIN |= (0x1 << 2);
	} else {
		FIO2PIN &= ~(0x1 << 2);
	}
	if (voltage >= (1.5 - 0.3 * 0.0/7)) {
		FIO2PIN |= (0x1 << 1);
	} else {
		FIO2PIN &= ~(0x1 << 1);
	}
}
