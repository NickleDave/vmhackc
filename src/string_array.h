#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **strings;
    size_t count;
    size_t capacity;
} StringArray;

StringArray* new_string_array(void);
void string_array_push(StringArray *arr, const char *str);
void free_string_array(StringArray *arr);

#endif
