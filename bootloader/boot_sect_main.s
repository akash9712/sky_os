.code16
.global _start
_start:
	mov $0x8000, %bp
	mov %bp, %sp

	mov $0x9000, %bx       # Loading the kernel at es:bx (can load anywhere below 1MB in real mode)
	mov $2, %dh            # Number of sectors to read

	call disk_load

	mov 0x9000, %dx        # Move into dx the first loaded word, 0xdada
	call print_hex

	call print_nl

	mov $0x9000, %bx
	add $0x200, %bx
	mov (%bx), %dx
	call print_hex         # Print the first word from the second sector, 0xface

	loop:
		jmp loop


.include "real_mode_print/boot_sect_print.s"
.include "real_mode_print/boot_sect_print_hex.s"
.include "boot_sect_disk.s"

.fill 510 - (. - _start), 1, 0
.word 0xaa55

# Fill up sectors 2 and 3 (sector 1 is taken up by bootloader) on the hard disk (of cyl 0)_

.fill 256, 2, 0xdada
.fill 256, 2, 0xface
	
