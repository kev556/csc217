#include <stdio.h>
#include "printAll.h"

void printAll(char **s) {
    char **temp = s;
    while(*s)
        printf("%s\n", *s++);
    s = temp;
}