#include <stdint.h>

#ifndef CURSOR_H
#define CURSOR_H

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

// Get the cursor position by sending it to a port and retrieving it.
int get_cursor_position();

// Set the cursor position to a specific offset
void set_cursor_offset(int offset);

#endif
