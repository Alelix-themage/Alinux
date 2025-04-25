
// Criação da string

#ifndef STRING_H
#define STRING_H



typedef struct {
    //Struct que molda o corpo da Nossa String
    char buffer[200];
    int length;
} String;



extern int cursor;


void string_init(String* str);

void string_append_char(String* str, char caracter);


void string_append(String* str, const char* text);

void clean_string(String* str);

void print(String* str);

#endif