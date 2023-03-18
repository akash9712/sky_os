#include <stdbool.h>
#include <stdint.h>

#include "video_memory_printing.h"


int main(int argc, char** argv){
        print_char(0, 'X', VGA_COLOR_WHITE, VGA_COLOR_BLACK);
        print_char(1, 'P', VGA_COLOR_RED, VGA_COLOR_BROWN);
}
