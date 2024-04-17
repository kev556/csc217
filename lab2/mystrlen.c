#include <stdio.h>
#include "mystrlen.h"

unsigned long long mystrlen(const char *s) {
    const char *t = s;
    while (*s++);
    return s-t;
}