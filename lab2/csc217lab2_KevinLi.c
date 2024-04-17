#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

int main(void) {
    char *arr[5];
    int i = 0, max = 0, maxidx = 0;
    char *tp = malloc(102), *xp;

    for (i = 0; i < 5; i++) {
        arr[i] = malloc(102);
        xp = fgets(arr[i], 102, stdin);
        char temp[102];
        strncpy(temp, xp, 102);
        temp[mystrlen(temp) - 2] = '\0';
    
        strncpy(arr[i], temp, 102);

        // Testing...
        printf(" test %s\n", arr[i]);

        int n = mystrlen(arr[i]) - 1;
        if (n > max) {
            max = n;
            maxidx = i;
        }
    }
    puts("\n");
    free(tp);
    for (i = 0; i < 5; i++)
        printf("%s\n", arr[i]);
    printf("The largest string entered is %s, with a length of %d \n", arr[maxidx], max);
    return 0;
}