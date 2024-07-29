#include "lpc24xx.h"

// Initialize DAC.
// This should be the same as the previous exercise.
void setup_DAC(void) {
    // Setup Pin Connect for AOUT
        PINSEL1 &= ~(0x3 << 20); //clear bits 20 and 21 1 everything els
  // Set bits 21 and 20 to 0b10 to select DAC function
        PINSEL1 |= (0x2 << 20); //set 20 and 21
}


 
void udelay(unsigned int delay_in_us) {
		
		unsigned int ticks = (Fpclk / 1000000) * delay_in_us;
    
		T0TCR |= 0x02; //  reset using timer control register
    T0TCR |= 0x01; // enable
        

    T0PR = 0x00; // prescale register
    T0TC = 0x00; // timer counter reg
    T0PC = 0x00; // prescale counter
    
    // Start Timer 0
    while (T0TC < ticks) {
            T0TCR = 0x01;// enable
    };

    T0TCR = 0x00; //RESET TIMER

}

// play_tone plays a tone for 'duration' number of microseconds at the pitch
// given by 1/'period'. Played at the volume given by 'vol', which ranges from                                                                   
// 0 (off) to 0x3FF (max volume).                                                                           

void play_tone(unsigned int duration, int period, int vol) {
    int num_cycles = duration / period;
    int half_period = period / 2;
    int j = 0;
        
    while(j < num_cycles){
        DACR = (vol) << 6; //set DAC to volume

        udelay(half_period);

        DACR = 0;

        udelay(half_period);

        j++;
    }
}
