# First rule is executed when no parameters are fed to the Makefile.

all: run

kernel/kernel.bin: kernel/kernel_entry.o kernel/kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernel/kernel_entry.o: kernel/kernel_entry.s
	as $< -o $@ --32

kernel/kernel.o: kernel/kernel.c
	i686-elf-gcc -nostdlib -c $< -o $@ 

kernel/kernel.dis: kernel/kernel.bin
	objdump -D -m i386 -Maddr32,daa32 $<

bootsect/bootsect.bin: bootsect/bootsect.o
	i686-elf-ld $< -o $@ --oformat=binary --Ttext=0x7c00 -m elf_i386

bootsect/bootsect.o: bootsect/bootsect.s
	as $< -o $@ --32

bootsect/os_image.bin: bootsect/bootsect.bin kernel/kernel.bin
	cat $^ > $@

run: bootsect/os_image.bin
	qemu-system-i386  $<

clean:
	rm ./*/*.bin ./*/*.o

