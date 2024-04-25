#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

void cliInput(int argc, char **argv, char **arr, char** max, int* maxlen) {
    *argv++;

    for (int i = 0; i < argc - 1; i++) {
        *arr = malloc(102);
        strncpy(*arr, *argv, 102);

        int n = mystrlen(*arr) - 1;

        if (n > *maxlen) {
            strncpy(*max, *arr, 102);
            *maxlen = n;
        }
        *arr++;
        *argv++;
    }
}