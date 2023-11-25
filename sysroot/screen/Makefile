CURSOR_INLUDED_OBJ :=
CURSOR_INCLUDED_OBJ += $(DRIVER_DIR)/ports.o

VIDEO_MEM_INCLUDED_OBJ :=
VIDEO_MEM_INCLUDED_OBJ += $(CUR_DIR)/cursor.o

cursor.o: $(CURDIR)/cursor.c $(CURDIR)/cursor.h $(CURSOR_INCLUDED_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

video_memory_printing.o: $(CURDIR)/video_memory_printing.c $(CURDIR)/video_memory_printing.h $(VIDEO_MEM_INCLUDED_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm ./*.o


