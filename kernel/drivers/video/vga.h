#include <stdint.h>

#ifndef VGA_H
#define  VGA_H

//HEADER VGA

// Tipos de cor
enum vga_color {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_WHITE = 15
};


// Função de comentário que exibe uma linha na tela
void comment(int num);

// Converte um inteiro para um String
void itoa(int num, char* str, int base);

#endif 