			AREA light_sensor, CODE
			EXPORT sensor
			
; Pin Setup
PINSEL1			EQU 0xE002C004
FIO0DIR			EQU 0x3FFFC000
FIO2DIR			EQU 0x3FFFC040
FIO0PIN			EQU 0x3FFFC014
FIO2PIN			EQU 0x3FFFC054

; Coding
; Gotta know how to extract current value form ADC
sensor
			mov		r4, #0x1
			ldr		r0, =PINSEL1
			ldr		r1, [r0]
			and		r1, r1, #0xFFF3FFFF
			add		r1, r1, r4, lsl #18
			str		r0, [r1]
			nop
			mov		r4, #0x1
			ldr		r0, =FIO0DIR
			ldr		r1, [r0]
			and		r1, r1, #0xFDFFFFFF
			add		r1, r1, r4, lsl #25
			str		r0, [r1]
			nop
			mov		r4, #0xFF
			ldr		r0, =FIO2DIR
			ldr		r1, [r0]
			bic		r1, r1, #0x1E
			bic		r1, r1, #0x1E0
			add		r1, r1, r4, lsl #1
			str		r0, [r1]
			nop
			ldr		r0, =FIO0PIN
			ldr		r1, [r0]
			ldr		r2, =FIO2PIN
			ldr		r3, [r2]
			
			
			
			
			
			
			END
			
