#include "lpc24xx.h"
#include "lcd/lcd_grph.h"
#include "lcd/touch.h"
#include <stdio.h>
#include "emergency_button.h"
#include "blinds.h"

void main_page(void){
	lcd_fontColor(YELLOW, NAVY);
	lcd_fillScreen(NAVY);
	
	lcd_drawRect(20,20,140,100,YELLOW);
	lcd_fillcircle(190,60,30,RED);
	lcd_putString(30,30, "Emergency Button");
	
	lcd_drawRect(20,120,140,200,YELLOW);
	lcd_fillcircle(190,160,30,RED);
	lcd_putString(30,130, "Espresso Machine");
	
	lcd_drawRect(20,220,140,300,YELLOW);
	lcd_fillcircle(190,260,30,YELLOW);
	lcd_putString(30,230, "Blinds");
}

void doorbell_display(void){
	lcd_fontColor(YELLOW, NAVY);
	lcd_fillScreen(NAVY);
	
	lcd_putString(80,60, "#############");
	lcd_putString(80,80, "##         ##");
	lcd_putString(80,100, "#  ~~   ~~  #");
	lcd_putString(80,120, "#  ()   ()  #");
	lcd_putString(80,140, "(     ^     )");
	lcd_putString(80,160, " |         | ");
	lcd_putString(80,180, " |  {===}  | ");
	lcd_putString(80,200, "  |       |  ");
	lcd_putString(80,220, " |  -----  | ");
	lcd_putString(70,240, "---  |%| |%|  ---");
	lcd_putString(65,260, "|     |%%%%%|     |");
	lcd_putString(65,280, "      |%| |%|      ");
}

void emergency_button_display(int state){
	if (state == 0) {
		lcd_fillcircle(190,60,30,GREEN);
	} else {
		lcd_fillcircle(190,60,30,RED);
	}
}

void espresso_machine_display(int time_in_s){
	// the screen is filled with a brown background
	lcd_fontColor(WHITE, 0xb365);
	lcd_fillScreen(0xb365);
	unsigned int min = 60/time_in_s;
	unsigned int sec = time_in_s/60;
	char Str[4];
	sprintf(str, "%d:%02d", min, sec);
	lcd_putString(120, 160, Str);
	
}

void blinds_display(int state){
	if (state == 0) {
		lcd_fillcircle(190,260,30,YELLOW);
	} else if (state == 1) {
		lcd_fillcircle(190,260,30,GREEN);
	} else if (state == 2) {
		lcd_fillcircle(190,260,30,BLUE);
	} else if (state == 3) {
		lcd_fillcircle(190,260,30,RED);
	}
}

void lcd_interact(char x, char y, int *emergency_state, int *blinds_state) {
	int x_position = 190;
	int y_emergency = 60;
	int y_espresso = 160;
	int y_blinds = 260;
	int point_x = x*240/255;
	int point_y = y*320/255;
	int radius = 30;
	int d_emergency = ((point_x - x_position)*(point_x - x_position) + 
								 (point_y - y_emergency)*(point_y - y_emergency));
	int d_espresso = ((point_x - x_position)*(point_x - x_position) + 
								 (point_y - y_espresso)*(point_y - y_espresso));
	int d_blinds = ((point_x - x_position)*(point_x - x_position) + 
								 (point_y - y_blinds)*(point_y - y_blinds));
	if (d_emergency < radius) {
		emergency_button_display(*emergency_state);
		*emergency_state = emergency_button(*emergency_state);
	} else if (d_espresso < radius) {
		unsigned int i = 60;
		for (i = 60; i >= 0; i--) {
			//delay for 1 second before incrementing
			udelay(0xF4240);
			espresso_machine_display(i);
		}
	} else if (d_blinds < radius) {
		blinds_display(*blinds_state);
		*blinds_state = manual_blinds();
	}
}
