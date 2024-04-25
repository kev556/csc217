#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

void cliInput(int length, char **argv, char **arr, char** max, int* maxlen) {
    int i = 0;
    *argv++;

    for (; i < length; i++) {
        *arr = malloc(102);
        strncpy(*arr, *argv++, 102);

        int n = mystrlen(*arr) - 1;

        if (n > *maxlen) {
            *max = *arr;
            *maxlen = n;
        }
        *arr++;
    }
}