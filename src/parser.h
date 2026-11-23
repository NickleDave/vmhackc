#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

typedef enum {
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
} CommandType;


typedef struct {
    CommandType command_type;
    char* arg1;
    int arg2;
} ParsedLine;


typedef struct {
    FILE* file_pointer;
    char* vm_file_path;
    int line_number;
} Parser;


Parser* new_parser(const char* vm_file_path);
void free_parser(Parser* parser_ptr);
bool parser_has_more_commands(Parser* parser_ptr);
ParsedLine parser_advance(Parser* parser_ptr);

#endif
