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


#endif