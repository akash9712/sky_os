#include <stdint.h>
#include "cursor.h"
#include <drivers/ports.h>

int get_cursor_position() {
	// Get the high byte of the cursor offset
	port_byte_out(REG_SCREEN_CTRL, 14);
	int offset = port_byte_in(REG_SCREEN_DATA) << 8;
	// Get the low byte of the curson offet
	offset += port_byte_in(REG_SCREEN_DATA);
	return offset * 2;
}

void set_cursor_offset(int offset) {
	offset = offset / 2;
	port_byte_out(REG_SCREEN_CTRL, 14);
	port_byte_out(REG_SCREEN_DATA, 15);
	port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}
