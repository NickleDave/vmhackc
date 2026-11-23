#include <errno.h>

#include "code_writer.h"
#include "string_array.h"


CodeWriter* new_code_writer() {
    CodeWriter* writer_ptr = malloc(sizeof(CodeWriter));
    if (! writer_ptr) {
        fprintf(
            "new_code_writer: failed to allocate CodeWriter pointer:\n%s\n",
            strerror(errno)
        );
        exit(EXIT_FAILURE);
    }
    StringArray* arr = new_string_array();
    writer_ptr->lines = arr;
    writer_ptr->jump_counter = 0;
    writer_ptr->return_addr_counter = 0;
    writer_ptr->current_function_name = NULL;
    return writer_ptr;
}


void free_code_writer(CodeWriter* writer_ptr) {
    free_string_array(writer_ptr->lines);
    free(writer_ptr);    
}


void write_arithmetic(CodeWriter* writer_ptr, char* command) {
    // TODO: can I apply some DRY to these helper functions
    // or is each unique? Look at other ppl's implementations again
    if (strcmp(command, "add") == 0) {
        write_add(writer_ptr);
    } else if (strcmp(command, "sub") == 0 )
    {
        write_sub(writer_ptr);
    } else if (strcmp(command, "neg") == 0 )
    {
        write_neg(writer_ptr);
    } else if (strcmp(command, "eq") == 0 )
    {
        write_sub(writer_ptr);
    } else if (strcmp(command, "eq") == 0 )
    {
        write_sub(writer_ptr);
    }
    
}