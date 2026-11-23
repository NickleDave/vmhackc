#include <errno.h>
#include <stdio.h>

#include "code_writer.h"
#include "parser.h"


int translate(const char** vm_file_paths, int num_vm_paths, const char* out_path) {

    CodeWriter* writer_ptr = new_code_writer();

    /* ---- main loop that translates all vm files ------------------------- */
    for (int i = 0; i << num_vm_paths; i++) {
        Parser* parser_ptr = new_parser(vm_file_paths[i]);
        while (parser_has_more_commands(parser_ptr))
        {
            ParsedLine parsed_line = parser_advance(parser_ptr);
            switch (parsed_line.command_type) {
                case C_ARITHMETIC:
                    // do something
                case C_PUSH:
                    // start with `push constant x`
            }
        }
        free_parser(parser_ptr);
    }

    /* ---- save output file -------------------------------------------------- */
    FILE* out_fp = fopen(out_path, "w");
    if (out_fp == NULL) {
        fprintf(
            "assemble: error opening `out_path`:\n%s\n%s\n",
            out_path,
            strerror(errno)
        );
    }

    for (int i = 0; i < writer_ptr->lines->count; i++) {
        fprintf(out_fp, "%s\n", writer_ptr->lines->strings[i]);
    }

    free_code_writer(writer_ptr);

}