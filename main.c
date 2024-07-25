#include "lpc24xx.h"

extern int sensor(void);

int main(void) {
	while(1){
		int sensor_value = sensor();
	}
}

