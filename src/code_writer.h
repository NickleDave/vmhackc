#ifndef CODEWRITER_H
#define CODEWRITER_H

#include "string_array.h"


typedef struct {
    StringArray *lines;
    int jump_counter;
    int return_addr_counter;
    char* current_function_name;
} CodeWriter;


CodeWriter* new_code_writer();
void code_writer_set_file_name(CodeWriter* writer_ptr, const char* filename);
void free_code_writer(CodeWriter* writer_ptr);
void write_arithmetic(CodeWriter* writer_ptr, char* command);

#endif
