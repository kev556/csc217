#include <stdlib.h>
#include "freeall.h"

void freeAll(char **s, int size) {
    for (int i = 0; i < size; i++)
        free(s[i]);
} 