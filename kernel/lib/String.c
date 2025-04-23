#include "String.h"


void string_init(String* str) { //arg a ser passado é do tipo String
    //inicializa o str na posição 0 do Array de String
    str->length = 0;
    str->buffer[0] = '\0';
}

void string_append_char(String* str, char caracter) {
    //adiciona um char a String
    if (str->length < 199) {
        str->buffer[str->length++] = caracter;
        str->buffer[str->length] = '\0';
    }
}

void string_append(String* str, const char* text) {
    //Adicionar uma String a váriavel
    int i = 0;
    while (text[i] != '\0' && str->length < 199) {
        str->buffer[str->length++] = text[i++];
    }
    str->buffer[str->length] = '\0';
}

void clean_string(String* str){
    
}


//EXEMPLO DE USO

//     String msg;
//     string_init(&msg);
//      string_append(&msg, "Alinux ");
//      string_append(&msg, "é brabo!");
//      string_append_char(&msg, '\n');
