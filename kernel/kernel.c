#include <stdbool.h>
#include <stdint.h>

#include <util/video_memory_printing.h>
#include <drivers/ports.h>

void write_at_cursor(char c)
{
	port_byte_out(VGA_OUTPUT_PORT, 14);
	int position = port_byte_in(VGA_INPUT_PORT);
	position = position << 8;
	port_byte_out(VGA_OUTPUT_PORT, 15);
	position += port_byte_in(VGA_INPUT_PORT);

	int offset_from_vga = position * 2;
	char* vga = (char*) 0xb8000;
	vga[offset_from_vga] = c;
	vga[offset_from_vga + 1] = 0x0f;

}

int kernel_main(int argc, char** argv){
	clear_terminal();
	char* hello_world_msg = "Hello world!\n";
        kprint(hello_world_msg, VGA_COLOR_WHITE,
			     VGA_COLOR_BLACK);
	kprint_continue("Testing the new line now.",
			     VGA_COLOR_RED, VGA_COLOR_WHITE);
	write_at_cursor('x');
	return 0;
}

