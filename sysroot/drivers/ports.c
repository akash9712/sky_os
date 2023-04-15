#include <stdint.h>

// Read a byte from a specified port
unsigned char port_byte_in(uint16_t port) {
	unsigned char result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    	return result;
}

void port_byte_out(uint16_t port, uint8_t data) {
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned short port_word_in(uint16_t port) {
	unsigned short result;
	__asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
	return result;
}

void port_word_out(uint16_t port, uint8_t data) {
	__asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}
