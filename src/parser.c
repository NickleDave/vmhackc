#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"


/**
 * @brief: make a new Parser instance
 */
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


/**
 * @brief: free a Parser instance
 */
void free_parser(Parser* parser_ptr) {
    free(parser_ptr->vm_file_path);
    free(parser_ptr->file_pointer);
    free(parser_ptr);
}


/**
 * @brief: returns true if Parser has more commands (lines)
 */
bool parser_has_more_commands(Parser* parser_ptr) {
    (feof(parser_ptr->file_pointer) == 0) ? true : false;
}


/**
 * @brief: advances Parser by one line
 * @param: parser_ptr
 * @return: ParsedLine with CommandType, arg1, and arg2
 */
ParsedLine parser_advance(Parser* parser_ptr) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, parser_ptr->file_pointer);
    if (read == -1) {
        fprintf(stderr, "parser_advance: -1 from getline");
        exit(EXIT_FAILURE);
    }
}
