// Read/write bytes/words to specified ports.
#include <stdint.h>

#ifndef PORTS_H
#define PORTS_H


const uint16_t VGA_OUTPUT_PORT = 0x3d4;
const uint16_t VGA_INPUT_PORT = 0x3d5;

unsigned char port_byte_in(uint16_t port);

void port_byte_out(uint16_t port, uint8_t data);

unsigned short port_word_in(uint16_t port);

void port_word_out(uint16_t port, uint8_t data);

#endif
