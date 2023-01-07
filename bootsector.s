/* For the OS to start working, it first has to be loaded into the memory of the computer.

 The loading itself has to be performed by a program, and this program is called the bootloader.

 Bootloader is the first program that's executed when you power on a computer, and its purpose
 is to simply load the kernel into the memory.

 What loads the bootloader? The BIOS. The BIOS loads the bootloader code into the memory and executes it.

 How does the BIOS know where to find the bootloader? The BIOS always looks into the first 512 bytes of your hard disk, i.e. the bootsector
 and loads them into memory. It is your responsibility to store your bootloader successfully at that
 location and to fit it into the space. BIOS looks at the last two bytes of the first 512 byte sector to check for a signature,
 and if the signature is verified, loads the bootloader into a specific location in the memory (0x7c00) and executes it. 
 The bootloader in turn now loads the kernel into memory, among a few other things. The signature that the BIOS looks for
 is the last two bytes being 0x55aa.

 Also important to note that Real mode can only address 1MB of memory due to only 20 address lines being enabled.

 Why is the bootloader loaded at 0x7c00? That's how the memory BIOS is configured to be. The convention for the memory layout is listed on pg14 on this doc:
 https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf 
*/


.code16 // The bootloader works in real mode. This in turn uses 16 bit registers, operands and registers. This statement sets the default operand and memory addresses to 16 bits.

.global _start
_start:
	lea HELLO, %bx
	call print

	call print_nl

	mov $0xdadc, %dx
	call print_hex
	call print_nl

	lea GOODBYE, %bx
	call print
	call print_nl

loop:
	jmp loop

.include "boot_sect_print.s"
.include "boot_sect_print_hex.s"

HELLO: .string "Hello, World."

GOODBYE: .string "Goodbye."

.fill 510 - (. - _start), 1, 0
.word 0xaa55

