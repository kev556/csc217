#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

void cliInput(int length, char **argv, char **arr, int* max, int* maxidx) {
    int i = 1;
    *argv++;

    for (; i < length; i++) {
        arr[i-1] = malloc(102);
        strncpy(arr[i-1], *argv++, 102);

        int n = mystrlen(arr[i-1]) - 1;

        if (n > *max) {
            *max = n;
            *maxidx = i - 1;
        }
    }
}