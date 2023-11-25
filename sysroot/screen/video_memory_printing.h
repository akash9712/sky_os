#include <stdint.h>

#ifndef VIDEO_MEMORY_H
#define VIDEO_MEMORY_H

extern const uint32_t VIDEO_MEMORY_LOCATION;
extern uint16_t* const VIDEO_MEMORY_BUFFER;

const uint16_t TERMINAL_WIDTH = 80;
const uint16_t TERMINAL_HEIGHT = 25;
extern uint16_t terminal_row;
extern uint16_t terminal_col;

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
} typedef vga_color;


// Returns a byte representing the attribute of a character to be copied into
// the video memory. The font color is `fg` and the background color is `bg`.
static uint16_t inline attribute_word(vga_color fg, vga_color bg) {
        return (uint16_t)(bg << 4 | fg);
}


// Returns a word to be put into the video memory buffer.
static int16_t inline vga_entry(unsigned char c, vga_color fg, vga_color bg) {
        return (uint16_t)c | attribute_word(fg, bg) << 8;
}

static int get_offset(int col, int row) { return 2 * (row * TERMINAL_WIDTH + col); }

static int get_offset_row(int offset) { return offset / (2 * TERMINAL_WIDTH); }

static int get_offset_col(int offset) { return (offset - (get_offset_row(offset)*2*TERMINAL_WIDTH))/2; }

// Clears the terminal, brings the row and column indices to 0;
void clear_terminal();

// Prints a character `c` onto the screen at an offset `offset` from the
// starting position (top left of the screen), with font and background
// represented by `font_col` and back_col`.
void print_char(unsigned char c, uint8_t* x, uint8_t* y, vga_color font_col, vga_color back_col);

// Print a character sequence at a particular position on the screen, by
// placing the corresponding character values and the color attributes at the
// corresponding addresses on the video memory.
void kprint_at(char* sequence, int x, int y, vga_color font_col, vga_color back_col);

// Print a character sequence given the pointer to a character array at the top
// left of the screen.
void kprint_beginning(char* sequence, vga_color font_col, vga_color back_col);

// Print a character sequence at where the previous printed string ended on the
// video_memory.
void kprint(char* sequence, vga_color font_col, vga_color back_col);

#endif

