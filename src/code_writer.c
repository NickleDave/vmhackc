#include <errno.h>

#include "code_writer.h"
#include "string_array.h"


/* ---- new / free CodeWriter ------------------------------------------------------ */
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

void code_writer_set_file_name(CodeWriter* writer_ptr, const char* filename) {
    
}


void free_code_writer(CodeWriter* writer_ptr) {
    free_string_array(writer_ptr->lines);
    free(writer_ptr);    
}


/* ---- functions to write code ------------------------------------------------------- */
/* Both `add` and `sub` start with these commands */
#define POP_ONE_VAL     "    @SP\n"     \
                        "    A=M\n"     \
                        "    A=A-1\n"

#define POP_TWO_VALS    POP_ONE_VAL     \
                        "    D=M\n"     \ 
                        "    A=A-1\n"

#define PUSHADDSUB      "    M=D\n"     \
                        "    D=A\n"     \
                        "    @SP\n"     \
                        "    M=D+1\n"


void write_add(CodeWriter* writer_ptr) {
    string_array_push(
        writer_ptr->lines,
        POP_TWO_VALS
        "    D=D+M\n"
        PUSHADDSUB
    );
}


void write_sub(CodeWriter* writer_ptr) {
    string_array_push(
        writer_ptr->lines,
        POP_TWO_VALS
        "    D=M-D\n"
        PUSHADDSUB
    );
}


void write_neg(CodeWriter* writer_ptr) {
    string_array_push(
        writer_ptr->lines,
        POP_ONE_VAL
        "    D=-M\n"
        "    M=D\n"
    );
}


void write_arithmetic(CodeWriter* writer_ptr, char* command) {
    // TODO: can I apply some DRY to these helper functions
    // or is each unique? Look at other ppl's implementations again
    if (strcmp(command, "add") == 0) {
        write_add(writer_ptr);
    } else if (strcmp(command, "sub") == 0 ) {
        write_sub(writer_ptr);
    } else if (strcmp(command, "neg") == 0 ) {
        write_neg(writer_ptr);
    } else if (strcmp(command, "eq") == 0 ) {
        write_eq(writer_ptr);
    } else if (strcmp(command, "gt") == 0 ) {
        write_gt(writer_ptr);
    } else if (strcmp(command, "lt") == 0) {
        write_lt(writer_ptr);
    } else if (strcmp(command, "and") == 0) {
        write_and(writer_ptr);
    } else if (strcmp(command, "or") == 0) {
        write_or(writer_ptr);
    } else if (strcmp(command, "not") == 0) {
        write_not(writer_ptr);
    }
}