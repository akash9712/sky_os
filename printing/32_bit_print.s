.code32

# Printing to screen in 32 bit mode by directly manipulating the VGA memory
# since BIOS interrupts are disabled in 32 bit protected mode

.equ VIDEO_MEMORY, $0xb8000      # VGA buffer is located at 0xb8000
.equ WHITE_ON_BLACK, $0x0f       # Attributes of the text to display

print_string_pm:
	pusha 
	mov VIDEO_MEMORY, %edx

print_string_pm_loop:
	mov (%ebx), %al          # ebx stores the address of the characer
	mov WHITE_ON_BLACK, %ah    
	cmp %al, 0
	je print_string_pm_done

	mov %ax, (%edx)          # store char + attributes at the video memory
	add $1, %ebx             # move to the next character
	add $2, %edx             # move the video memory forward
	
	jmp print_string_pm_loop

print_string_pm_done:
	popa
	ret

