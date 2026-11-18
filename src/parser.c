#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"


Parser* new_parser(const char* vm_file_path) {
    Parser* parser_ptr = NULL;
    parser_ptr = (Parser*) malloc(sizeof(Parser));
    if (parser_ptr == NULL) {
        fprintf(stderr, "new_parser: malloc error\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    parser_ptr->file_pointer = fopen(vm_file_path, "r");
    if (parser_ptr->file_pointer == NULL) {
        fprintf(
            stderr,
            "new_parser: error in call to `fopen` with `vm_file_path`:'%s'\n%s\n",
            vm_file_path, strerror(errno)
        );
        free(parser_ptr);
        exit(EXIT_FAILURE);
    }

    parser_ptr->vm_file_path = strdup(vm_file_path);
    if (parser_ptr->vm_file_path == NULL) {
        fprintf(
            stderr,
            "new_parser: error in call to `strdup` with `vm_file_path`:'%s'\n%s\n",
            vm_file_path, strerror(errno)
        );
        free(parser_ptr);
        exit(EXIT_FAILURE);
    }

    return parser_ptr;
}


void free_parser(Parser* parser_ptr) {
    free(parser_ptr->vm_file_path);
    free(parser_ptr->file_pointer);
    free(parser_ptr);
}


ParsedLine advance(char* line) {
    
}