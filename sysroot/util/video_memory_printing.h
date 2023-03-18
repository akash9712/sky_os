#include <stdint.h>

#ifndef VIDEO_MEMORY_H
#define VIDEO_MEMORY_H

extern const uint32_t VIDEO_MEMORY_C;

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
uint32_t attribute_byte(vga_color fg, vga_color bg);


// Prints a character `c` onto the screen at an offset `offset` from the
// starting position (top left of the screen), with font and background
// represented by `font_col` and back_col`.
void print_char(int offset, char c, vga_color font_col, vga_color back_col);

#endif

