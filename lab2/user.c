#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

void userInput(char **arr, int *max, int *maxidx) {
    int i = 0;

    for (; i < 5; i++) {
        arr[i] = malloc(102); // dynamically allocates memory from the heap for a specified amount. i-1 is chosen as i was initialized to 1.
        fgets(arr[i], 102, stdin); // receives user input and stores it into arr at index i, with a maximum of 100 characters, 102 including \n and \0.

        // If the length of the current string is longer than the longest value stored in max, sets max to the length of the current string 
        // and sets the index of the longest string to the current index
        int n = mystrlen(arr[i]) - 1;
        if (n > *max) {
            *max = n;
            *maxidx = i;
        }
    }
}