#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


int isdir(const char* path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return 0;  // Error or path does not exist
    }
    return S_ISDIR(path_stat.st_mode); // Non-zero if dir; zero otherwise
}


int is_regular_file(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return 0;
    }
    return S_ISREG(path_stat.st_mode);
}


int has_vm_extension(const char *path) {
    // `strrchr` function (note two `r`s) to find *last* occurrence of '.'
    const char *dot = strrchr(path, '.');
    // Esnure a dot exists and is not the first character (e.g. '.gitignore')
    if (!dot || dot == path) {
        return 0;
    }
    return strcmp(dot, ".vm") == 0;
}


char* VM_EXT = ".vm";


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Expected usage: VMTranslator <PATH to .vm file or directory of .vm files>\n");
        exit(EXIT_FAILURE);
   }

   char **vm_paths;
   int num_vm_paths;
   char* in_path = argv[1];
    if (isdir(in_path)) {
        glob_t glob_struct;
        
        char *glob_pattern = malloc(strlen(in_path) + strlen(VM_EXT) + 1);
        if (glob_pattern == NULL) {
            fprintf(stderr, "malloc allocation failure");
            exit(EXIT_FAILURE);
        }

        strcpy(glob_pattern, in_path);
        strcat(glob_pattern, VM_EXT);
        int ret = glob(glob_pattern, 0, NULL, &glob_struct);
        if (ret != 0) {
            if (ret == GLOB_NOMATCH)
                fprintf(stderr, "No .vm files found in directory: %s\n", in_path);
            else
                fprintf(stderr, "Glob error on directory: %s\n", in_path);
            exit(EXIT_FAILURE);
        }
        vm_paths = glob_struct.gl_pathv;
        num_vm_paths = glob_struct.gl_pathc;
    } else {
        if (! is_regular_file(in_path)) {
            fprintf(stderr, "Path not found or is not a regular file: %s\n", in_path);
            exit(EXIT_FAILURE);
        }
        int is_vm_file = has_vm_extension(in_path);
        if (! is_vm_file) {
            fprintf(stderr, "Path does not have a .vm extension: %s\n", in_path);
        }
        vm_paths = malloc(1 * sizeof(char *));
        vm_paths[0] = in_path;
        num_vm_paths = 1;
    }

    for (int vm_path_num = 0; vm_path_num < num_vm_paths; vm_path_num++) {
        fprintf(stdout, ".vm path %d: %s\n", vm_path_num, vm_paths[vm_path_num]);
    }

    free(vm_paths);
}