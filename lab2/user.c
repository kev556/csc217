#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"
#include "user.h"

// Kevin Li N00969115

void userInput(char **arr, char **max, int *maxlen) {
    int i = 0;

    for (; i < 5; i++) {
        *arr = malloc(102 * sizeof(char));
        fgets(*arr, 102, stdin);

        int n = mystrlen(*arr) - 1;

        if (n > *maxlen) {
            strncpy(*max, *arr, 102);
            *maxlen = n;
        }
        *arr++;
    }
}