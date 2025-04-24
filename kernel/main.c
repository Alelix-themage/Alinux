#include "vga.h"
#include "String.h"

// ====================================================================================================================================================
//      autor: Alelix-themage
//      data: 22/04/2025
//=====================================================================================================================================================

void kernel_main(void) {
    String msg;
    string_init(&msg);
    string_append(&msg, "Bem vindo ao Alinux - ");
    string_append_char(&msg, '2');
    string_append_char(&msg, '5');

    // Printar na tela
    volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
    for (int i = 0; msg.buffer[i] != '\0'; i++) {
        vga_buffer[i] = vga_entry(msg.buffer[i], COLOR_WHITE | COLOR_BLACK << 4);
    }

    while (1) {
        __asm__ volatile("hlt");
    }
}
