#include "lpc24xx.h"

extern int sensor(void);
extern int check_button(void);

int main(void) {
	while(1){
		int sensor_value = sensor();
		//plays a doorbell sound if button p0.10 is pressed 
		check_button();
	}
}

