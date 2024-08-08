#include "lpc24xx.h"
#include "light_sensor.h"
#include "ambient_light.h"
#include "blinds.h"
#include "initialize.h"
#include "emergency_button.h"
#include "lcd_display.h"
#include "lcd/touch.h"
#include "lcd_display.h"

int main(void) {
	int blinds_state = 0;
	int emergency_state = 0;
	float sensor_value;
	char x=0, y=0;
	initialize();
	main_page();
	while(1){
		// Light Sensor First
		sensor_value = light_sensor();
		ambient_light(sensor_value);
		blinds_state = auto_blinds(sensor_value, blinds_state);
		// LCD Second
		touch_read_xy(&x, &y);
		lcd_interact(x, y, &emergency_state, &blinds_state);
		// Pushbuttons Third
	}
}
