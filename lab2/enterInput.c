#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

char ** enterInput(int *max, int *maxidx) {
    char *arr[5];
    int i = 0, maxidx = 0, max = 0;

    for (; i < 5; i++) {
        char temp[102];
        fgets(temp, 102, stdin);

        arr[i] = malloc(102);
        strncpy(arr[i], temp, 102);

        int n = mystrlen(arr[i]) - 1;

        if (n > *max) {
            *max = n;
            *maxidx = i;
        }
    }
    return arr;
}