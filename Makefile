# First rule is executed when no parameters are fed to the Makefile.

all: run

# Add locations where GCC will look for header files here. This list is supplied
# using the -isystem argument, passed to GCC, which tells GCC where to look for
# headers.
std_header_dirs = ./sysroot/usr/include ./sysroot/usr/

kernel/kernel.bin: kernel/kernel_entry.o kernel/kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernel/kernel_entry.o: kernel/kernel_entry.s
	as $< -o $@ --32

kernel/kernel.o: kernel/kernel.c $(std_header_dirs)
	i686-elf-gcc -nostdlib -c $< -o $@ -isystem $(std_header_dirs)

kernel/kernel.dis: kernel/kernel.bin
	objdump -D -m i386 -Maddr32,daa32 $<

bootsect/bootsect.bin: bootsect/bootsect.o
	i686-elf-ld $< -o $@ --oformat=binary --Ttext=0x7c00 -m elf_i386

bootsect/bootsect.o: bootsect/bootsect.s
	as $< -o $@ --32

# Join 512 bytes from the bootloader and the kernel binary to generate
# the OS image, treated as an image on the disk, will be fed to Qemu.
bootsect/os_image.bin: bootsect/bootsect.bin kernel/kernel.bin
	cat $^ > $@

# Run the boot image on Qemu.
run: bootsect/os_image.bin
	qemu-system-i386  $<

clean:
	rm ./*/*.bin ./*/*.o

