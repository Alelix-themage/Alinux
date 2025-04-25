#include "vga.h"

int cursor = 0; // Global

uint16_t vga_entry(char c, uint8_t color) {
    return (uint16_t)c | ((uint16_t)color << 8);
}
