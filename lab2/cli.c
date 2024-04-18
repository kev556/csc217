#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"
#include "cli.h"

void cliInput(int length, char **argv, char **arr, int* max, int* maxidx) {
    // i is set to 1 and argv is incremented due to ./filename always being the first argument in argv.
    int i = 1;
    *argv++;

    for (; i < length; i++) {
        arr[i-1] = malloc(102); // dynamically allocates memory from the heap for a specified amount. i-1 is chosen as i was initialized to 1.
        strncpy(arr[i-1], *argv++, 102);

        // If the length of the current string is longer than the longest value stored in max, sets max to the length of the current string 
        // and sets the index of the longest string to the current index
        int n = mystrlen(arr[i-1]) - 1;  
        if (n > *max) {
            *max = n;
            *maxidx = i - 1;
        }
    }
}