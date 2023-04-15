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


static void print_char(unsigned char c, uint8_t* x, uint8_t* y,  vga_color font_col, vga_color back_col) {
	uint8_t x_val = (*x);
	uint8_t y_val = (*y);
	if(c == '\n') {
		(*x) = TERMINAL_WIDTH - 1;
		return;
	}
	uint16_t offset = (y_val * TERMINAL_WIDTH + x_val);
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
			print_char(' ', (uint8_t*)&x, (uint8_t*)&y, default_fg, default_bg);
		}
	}
}


void kprint_at(char* sequence, int x, int y, vga_color font_col, vga_color back_col) {
	// Print a red on black 'E' in case of invalid coordinates
	if(x >= TERMINAL_WIDTH || y >= TERMINAL_HEIGHT){
		x = 0; y = 0;
		print_char('E', (uint8_t*)&x, (uint8_t*)&y, VGA_COLOR_RED, VGA_COLOR_BLACK);
		return;
	}
	for(uint32_t i = 0; i < strlen(sequence); i++){
		print_char(sequence[i], (uint8_t*)&x, (uint8_t*)&y, font_col,
			   back_col);
		x++;
		if(x == TERMINAL_WIDTH) {
			x = 0;
			y++;
			y %= TERMINAL_HEIGHT;
		}		

	 }
	 terminal_col = x;
	 terminal_row = y;

}

void kprint(char* sequence, vga_color font_col, vga_color back_col) {
	kprint_at(sequence, 0, 0, font_col, back_col);
}

void kprint_continue(char* sequence, vga_color font_col, vga_color back_col) {
	kprint_at(sequence, terminal_col, terminal_row, font_col, back_col);
}

