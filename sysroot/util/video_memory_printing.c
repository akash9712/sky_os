#include <stdint.h>
#include "video_memory_printing.h"

const uint32_t VIDEO_MEMORY_C = 0xb8000;

uint32_t attribute_byte(vga_color fg, vga_color bg) {
        return bg << 4 | fg;
}

void print_char(int offset, char c, vga_color font_col, vga_color back_col)
{
        char* video_mem_location = (char*) (VIDEO_MEMORY_C + 2*offset);
        *video_mem_location++ = c;
        *video_mem_location = attribute_byte(font_col, back_col);
}

