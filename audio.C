//Off is defined to prevent any issues with dividing by zero
#define OFF		100

#define C4 		3831
#define CS4 	3610
#define D4 		3401
#define DS4 	3215
#define E4 		3030
#define F4 		2857
#define FS4 	2725
#define G4 		2551
#define GS4 	2410
#define A4 		2272
#define AS4 	2146
#define B4 		2024


struct tone {
	int length;
	int pitch;
	int volume;
};

//Doorbell audio, just plays a descendning fourth on the 

int doorbell_dur = 3;

struct tone doorbell[] = {
	{8, G4, 0x3FF},
	{16, C4, 0x3FF},
	{1, OFF, 0}

};
