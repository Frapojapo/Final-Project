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
			mov r1, r1, lsl #10
			ldr r2, =FIO0PIN
press_loop
			ldr r0, [r2]
			ands r0, r1
			beq un_pressed 
			bl play_doorbell
un_pressed
			
			bx pc; return to main
			END
