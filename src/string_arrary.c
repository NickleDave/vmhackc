#include <errno.h>

#include "string_array.h"


StringArray* new_string_array(void) {
    StringArray* arr = malloc(sizeof(StringArray));
    if (! arr) {
        fprintf(
            "new_string_array: failed to allocate StringArray pointer:\n%s\n",
            strerror(errno)
        );
        exit(EXIT_FAILURE);
    }
    arr->strings = malloc(sizeof(char *));
    if (! arr->strings) {
        fprintf(
            "new_string_array: failed to allocate `char* strings`:\n%s\n",
            strerror(errno)
        );
        exit(EXIT_FAILURE);
    }
    arr->count = 0;
    arr->capacity = 1;
}


void string_array_push(StringArray *arr, const char *str) {
    if (arr->count >= arr->capacity) {
        size_t new_cap = (arr->capacity == 0) ? 4 : arr->capacity * 2;
        char **temp = realloc(arr->strings, new_cap * sizeof(char *));
        if (! temp) {
            fprintf(
                "string_array_push: failed to reallocate:\n%s\n",
                strerror(errno)
            );
            exit(EXIT_FAILURE);
        }
        arr->strings = temp;
        arr->capacity = new_cap;
    }

    arr->strings[arr->count] = malloc(strlen(str) + 1);
    if (! arr->strings[arr->count]) {
        fprintf(
            "string_array_push: failed to allocate string:\n%s\n",
            strerror(errno)
        );
        exit(EXIT_FAILURE);
        strcpy(arr->strings[arr->count], str);
        arr->count++;
    }
}


void free_string_array(StringArray *arr) {
    for (size_t i = 0; i < arr->count; i++) {
        free(arr->strings[i]);
    }
    free(arr->strings);
    free(arr);
}
