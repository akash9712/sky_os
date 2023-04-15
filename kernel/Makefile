INCLUDED_OBJ :=
INCLUDED_OBJ += $(UTIL_DIR)/video_memory_printing.o
INCLUDED_OBJ += $(DRIVER_DIR)/ports.o


$(CURDIR)/kernel.bin: $(CURDIR)/kernel_entry.o $(CURDIR)/kernel.o $(INCLUDED_OBJ)
	$(LD) -o $@ -T $(CURDIR)/linker.ld $^ $ --oformat binary

	
$(CURDIR)/kernel_entry.o: $(CURDIR)/kernel_entry.s
	as $< -o $@ --32

$(CURDIR)/kernel.o: $(CURDIR)/kernel.c $(std_header_dirs)
	$(CC) $(CFLAGS) -c $< -o $@ $(UTIL_INC_SRCH_PATH)

clean:
	rm  ./*.o ./*.bin

