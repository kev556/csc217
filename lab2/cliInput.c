#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

char ** cliInput(int length, char **argv, int* max, int* maxidx) {
    char *arr[5];
    int i = 0;
    for (; i < length; i++) {
        arr[i] = malloc(102);
        strncpy(arr[i], *argv++, 102);

        int n = mystrlen(arr[i]) - 1;

        if (n > *max) {
            *max = n;
            *maxidx = i;
        }
    }
    return arr;
}