# First rule is executed when no parameters are fed to the Makefile.

ROOT_DIR = $(CURDIR)
SYSROOT_DIR = $(ROOT_DIR)/sysroot
UTIL_DIR = $(SYSROOT_DIR)/util
STDLIB_DIR = $(SYSROOT_DIR)/usr
KERNEL_DIR = $(ROOT_DIR)/kernel
BOOTSECT_DIR = $(ROOT_DIR)/bootsect


UTIL_INC_SRCH_PATH :=
UTIL_INC_SRCH_PATH += -I$(UTIL_DIR)


# Add locations where GCC will look for header files here. This list is supplied
# using the -isystem argument, passed to GCC, which tells GCC where to look for
# headers.
STD_HEADER_DIR_INCL := $(STDLIB_DIR)/include 
STD_HEADER_DIR := $(STDLIB_DIR)


CC = i686-elf-gcc
LD = i686-elf-ld
CFLAGS = -Wall -nostdlib -isystem $(STD_HEADER_DIR) -isystem $(STD_HEADER_DIR_INCL)

all: 
	cd $(UTIL_DIR) && make
	cd $(BOOTSECT_DIR) && make
	cd $(KERNEL_DIR) && make
	make run


# Export variables defined above to be used by the all the Makefiles in the subdirectories.
export

# Join 512 bytes from the bootloader and the kernel binary to generate
# the OS image, treated as an image on the disk, will be fed to Qemu.
$(ROOT_DIR)/os_image.bin: bootsect/bootsect.bin kernel/kernel.bin
	cat $^ > $@

# Go into the subdirectories and run `make`.


# Run the boot image on Qemu.
run: $(ROOT_DIR)/os_image.bin
	qemu-system-i386  $<

clean:

	cd $(UTIL_DIR) && make clean
	cd $(BOOTSECT_DIR) && make clean
	cd $(KERNEL_DIR) && make clean
	rm ./*.bin


