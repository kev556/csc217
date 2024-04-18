#include <stdio.h>
#include "printAll.h"

void printAll(char **s) {
    do
        printf("%s\n", *s++);
    while (*s);
}