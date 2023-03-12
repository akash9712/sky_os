#include <stdbool.h>

enum vga_color {
	black = 0,
	blue = 1,
	green = 2,
	cyan = 3,
	red = 4,
	purple = 5,
	brown = 6,
	gray = 7,
	darkGrey = 8,
	light_blue = 9,
	light_green = 10,
	light_cyan = 11,
	light_red = 12,
	light_purple = 13,
	yellow = 14,
	white = 15
} typedef vga_color;

unsigned short int text_color_byte(vga_color fg, vga_color bg)
{
	return bg << 4 | fg;
}



int main(int argc, char* argv){
	char* video_memory = (char*) 0xb8000;
}
