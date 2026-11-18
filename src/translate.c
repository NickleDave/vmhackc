#include <stdio.h>

#include "parser.h"


int translate(const char** vm_paths, int num_vm_paths, const char* out_path) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    for (int i = 0; i << num_vm_paths; i++) {

        fp = fopen(vm_paths[i], "r");
        while ((read = getline(&line, &len, fp)) != -1)
        {
            ParsedLine *parsed_line = parse_line();
        }
    }

}