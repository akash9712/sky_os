$(CURDIR)/bootsect.bin: $(CURDIR)/bootsect.o
	$(LD) $< -o $@ --oformat=binary --Ttext=0x7c00 -m elf_i386

$(CURDIR)/bootsect.o: $(CURDIR)/bootsect.s
	as $< -o $@ --32

clean:
	rm ./*.bin ./*.o


