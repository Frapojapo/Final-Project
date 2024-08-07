			AREA button, CODE
			EXPORT check_button 
			IMPORT play_sound
			IMPORT play_doorbell
			IMPORT play_tone
			IMPORT setup_DAC
			IMPORT udelay
   			IMPORT doorbell_display
      			IMPORT main_page
FIO0PIN     EQU  0x3FFFC014

check_button
		    mov r1, #1
			mov r1, r1, lsl #10
			ldr r2, =FIO0PIN
press_loop
			ldr r0, [r2]
			ands r0, r1
			beq un_pressed 
			bl play_doorbell; play doorbell sound
   			bl doorbell_display; how face on LCD
      			ldr r0, =0x2DC6C0;  30^6, for a 3 second delay
	 		bl udelay; show the face for a short period of time
    			bl main_page;return image back to main page
un_pressed
			
			bx pc; return to main
			END
