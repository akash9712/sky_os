#include <stdbool.h>
#include <stdint.h>

#include "video_memory_printing.h"


int main(int argc, char** argv){
	clear_terminal();
	char* hello_world_msg = "Hello world!";
        print_char_sequence(hello_world_msg, VGA_COLOR_WHITE,
			     VGA_COLOR_BLACK);
}
