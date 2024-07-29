			AREA button, CODE
			EXPORT check_button 
			IMPORT play_sound
			IMPORT play_doorbell
			IMPORT play_tone
			IMPORT setup_DAC
			IMPORT udelay
FIO0PIN     EQU  0x3FFFC014

check_button
		    	mov r1, #1
			mov r1, r1, lsl #10; create a map for the 10th bit
			ldr r2, =FIO0PIN; get the address for the pin being accessed 
press_loop
			ldr r0, [r2]
			ands r0, r1, r3
			beq pressed 
			; if the dooebell is pressed play doorbell sound
   			bl play_doorbell 
      			; insert the LCD function here 
un_pressed
			
			bx pc; return to main
			END

