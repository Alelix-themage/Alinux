#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define COLOR_BLACK 0x0
#define COLOR_WHITE 0xF
#define WHITE_ON_BLACK ((COLOR_BLACK << 4) | COLOR_WHITE)

extern int cursor; // Cursor global da tela

uint16_t vga_entry(char c, uint8_t color);

#endif
