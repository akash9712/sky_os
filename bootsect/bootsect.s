.code16


.equ KERNEL_LOADING_ADDRESS, 0x1000     # Load kernel at this address while linking.

bootloader:
	mov %dl, BOOT_DRIVE

	mov $0x9000, %bp
	mov %bp, %sp

	lea MSG_REAL_MODE, %bx
	call print
	call print_nl

	call LOAD_KERNEL                 # Read the kernel from disk.
	call switch_to_pm

	jmp . # never executed, infinite loop.


.include "../printing/real_mode_print/boot_sect_print.s"
.include "../printing/real_mode_print/boot_sect_print_hex.s"
.include "./32bit_gdt.s"
.include "../printing/32_bit_print.s"
.include "./32bit_enter.s"
.include "../bootloader/boot_sect_disk.s"

.code16
LOAD_KERNEL:
	lea MSG_LOAD_KERNEL, %bx
	call print
	call print_nl
	mov $KERNEL_LOADING_ADDRESS, %bx   # Since disk read is loaded into ES:BX
        mov $0x01, %dh	 		   # Number of sectors read.
	mov BOOT_DRIVE, %dl
	call disk_load
	ret

# Main differences in 32 bit mode:
#	32-bit registers can now be used.
#	32-bit memory offsets available: e.g. ffffffff
#	Much more complex and sophisticated memory segmentation
.code32
BEGIN_PM:
#	lea MSG_PROT_MODE, %ebx
#	call print_string_pm
	call KERNEL_LOADING_ADDRESS        # Kernel is now at the offset, transfer the control.
	lea MSG_KERNEL_LOADED, %ebx
	call print_string_pm
	jmp .

BOOT_DRIVE: .word 0
MSG_REAL_MODE: .string "Started in 16 bit real mode."
# MSG_PROT_MODE: .string "Loaded 32 bit protected mode."
MSG_LOAD_KERNEL: .string "Loading the kernel."
MSG_KERNEL_LOADED: .string "Kernel loaded, running in 32 bit mode."
.fill 510 - (. - bootloader), 1, 0
.word 0xaa55

