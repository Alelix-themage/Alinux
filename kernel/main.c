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

    print(&msg); 

    // Mensagem para confirmar que o kernel iniciou
    string_append(&msg, "Kernel iniciado com sucesso!");
    print(&msg); 

    while (1) {
        __asm__ volatile("hlt");
    }
}
