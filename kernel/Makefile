$(CURDIR)/kernel.bin: $(CURDIR)/kernel_entry.o $(CURDIR)/kernel.o $(UTIL_DIR)/video_memory_printing.o
#	$(LD) -o $@ -Ttext 0xB000 $^ $ --oformat binary -rpath=$(UTIL_DIR)
	$(LD) -o $@ -T $(CURDIR)/linker2.ld $^ $ --oformat binary -rpath=$(UTIL_DIR)

	
$(CURDIR)/kernel_entry.o: $(CURDIR)/kernel_entry.s
	as $< -o $@ --32

$(CURDIR)/kernel.o: $(CURDIR)/kernel.c $(std_header_dirs)
	$(CC) $(CFLAGS) -c $< -o $@ $(UTIL_INC_SRCH_PATH)

clean:
	rm  ./*.o ./*.bin

