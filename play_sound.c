#include "lpc24xx.h"

struct tone {
	int length;
	int pitch;
	int volume;
};

extern struct tone doorbell[];
extern int doorbell_dur;
extern void udelay(unsigned int delay_in_us);
extern void play_tone(unsigned int duration, int period,  int vol);
extern void setup_DAC(void);

int play_doorbell(void);
int play_sound(struct tone* audio, int duration);

play_sound(struct tone* audio, int duration) {

	// Sets the speed at which the song plays. 
	// This sets the smallest unit of time as a 16th note at
	// approx 72.1Hz
	int rate = 52000; 
	int i = 0;
	

	// Setup the DAC 
	setup_DAC();
	
	// Play the sound
	while(i < duration) {
			play_tone(rate * audio[i].length, audio[i].pitch, audio[i].volume);
			i++;
	}
	return 1;
}
	
//plays the doorbell sound
play_doorbell(void) {
			play_sound(doorbell, doorbell_dur);
			return 1;
}
