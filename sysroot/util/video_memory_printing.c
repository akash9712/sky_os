#include <stdint.h>
#include "video_memory_printing.h"
const uint32_t VIDEO_MEMORY_LOCATION = 0xb8000;
uint16_t* const VIDEO_MEMORY_BUFFER = (uint16_t*) VIDEO_MEMORY_LOCATION;

const uint16_t TERMINAL_WIDTH = 80;
const uint16_t TERMINAL_HEIGHT = 25;

uint16_t terminal_row;
uint16_t terminal_col;


uint32_t strlen(char* str) {
	uint32_t len = 0;
	while(str[len])
		len++;
	return len;
}


void print_char(unsigned char c, uint8_t x, uint8_t y,  vga_color font_col, vga_color back_col) {	
	if(c == '\n') {
		terminal_col = TERMINAL_WIDTH - 1;
		return;
	}
	uint16_t offset = (y * TERMINAL_WIDTH + x);
	VIDEO_MEMORY_BUFFER[offset] = vga_entry(c, font_col, back_col);
}

void clear_terminal() {
	terminal_row = 0;
	terminal_col = 0;
	vga_color default_bg = VGA_COLOR_BLACK;
	vga_color default_fg = VGA_COLOR_WHITE; // Doesn't really matter due to empty char.

	for(uint8_t y = 0; y < TERMINAL_HEIGHT; y++)
	{
		for(uint8_t x = 0; x < TERMINAL_WIDTH; x++) {
			print_char(' ', x, y, default_fg, default_bg); 
		}
	}
}


void print_char_sequence(char* sequence, vga_color font_col, vga_color back_col) {
	 for(uint32_t i = 0; i < strlen(sequence); i++){
	 	print_char(sequence[i], terminal_col, terminal_row, font_col,
			   back_col);
		terminal_col++;
		if(terminal_col == TERMINAL_WIDTH) {
			terminal_col = 0;
			terminal_row++;
			terminal_row %= TERMINAL_HEIGHT;
		}		

	 }

}

