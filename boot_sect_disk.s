disk_load:
	pusha
	push %dx
	mov $0x02, %ah     # ah=0x02 is 'read sectors from drive' for int 0x13
	mov %dh, %al       # al is number for sectors to read for int 0x13
	mov $0x02, %cl     # cl is the sector to read (sector 1 is bootloader) (0x01...0x11)
	mov $0x00, %ch     # ch is the cylinder to read for int 0x13
	mov $0x00, %dh     # dh is the head number for int 0x13 
	
	int $0x13          # IT'S LOADING TIME!

	jc disk_error      # Unsuccessful load sets the carry bit

	pop %dx
	cmp  %al, %dh      # BIOS sets al to the number of sectors read
	jne disk_error
	popa
	ret

disk_error:
	lea DISK_ERROR, %bx
	call print
	call print_nl
	mov %ah, %dh       # ah is the error code
	call print_hex
	jmp disk_loop

sectors_error:
	lea SECTORS_ERROR, %bx
	call print

disk_loop:
	jmp disk_loop

DISK_ERROR: .string "Disk read error"
SECTORS_ERROR: .string "Incorrect number of sectors read"
