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
void free_code_writer(CodeWriter* writer_ptr);

#endif
