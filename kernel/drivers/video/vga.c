#include "vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

// Define o formato de entrada de VGA (2 bytes: caractere + cor)
uint16_t vga_entry(char c, uint8_t color) {
    return (uint16_t)c | (uint16_t)color << 8;
}

// Função de comentário que exibe uma linha na tela
void comment(int num) {
    volatile uint16_t* vga_buffer = (uint16_t*)VGA_ADDRESS;
    
    // Texto a ser mostrado
    const char* comment_str = "Bem vindo ao Alinux - ";
    int i = 0;
    
    // Exibe o comentário na primeira linha da tela
    for (i = 0; comment_str[i] != '\0'; i++) {
        vga_buffer[i] = vga_entry(comment_str[i], COLOR_WHITE | COLOR_BLACK << 4);
    }

    // Exibe o número após o comentário (simulando um número)
    char num_str[10];  // Máximo de 10 caracteres para o número
    itoa(num, num_str, 10);  // converte número para string
    int j = 0;
    for (; num_str[j] != '\0'; j++) {
        vga_buffer[i + j] = vga_entry(num_str[j], COLOR_WHITE | COLOR_BLACK << 4);
    }
}

// Função para conversão de inteiro para string (itoa)
void itoa(int num, char* str, int base) {
    int i = 0;
    int is_negative = 0;

    // Tratamento para zero
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Tratamento de número negativo (caso seja negativo)
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    // Converte o número para string
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Se o número for negativo, adiciona o sinal
    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Inverte a string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
