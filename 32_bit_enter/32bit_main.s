.code16
.global _start

_start:
	mov $0x9000, %bp
	mov %bp, %sp

	lea MSG_REAL_MODE, %bx
	call print
	call print_nl
	call switch_to_pm

	jmp . # never executed, infinite loop.


.include "../printing/real_mode_print/boot_sect_print.s"
.include "./32bit_gdt.s"
.include "../printing/32_bit_print.s"
.include "./32bit_enter.s"

# Main differences in 32 bit mode:
#	32-bit registers can now be used.
#	32-bit memory offsets available: e.g. ffffffff
#	Much more complex and sophisticated memory segmentation
.code32

BEGIN_PM:
	lea MSG_PROT_MODE, %ebx
	call print_string_pm
	jmp .

MSG_REAL_MODE: .string "Started in 16 bit real mode."
MSG_PROT_MODE: .string "Loaded 32 bit protected mode."

.fill 510 - (. - _start), 1, 0
.word 0xaa55

