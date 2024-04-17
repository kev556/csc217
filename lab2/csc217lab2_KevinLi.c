#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"

int main(void) {
    char *a[5];
    int i = 0, max = 0, maxidx = 0;

    for (i = 0; i < 5; i++) {
        a[i] = malloc(102);
        xp = fgets(a[i], 102, stdin);
        char temp[102];
        strncpy(temp, xp, 102);
        temp[mystrlen(temp) - 2] = '\0';
    
        strncpy(a[i], temp, 102);

        // Testing...
        printf(" test %s\n", a[i]);

        int n = mystrlen(a[i]) - 1;
        if (n > max) {
            max = n;
            maxidx = i;
        }
    }
    puts("\n");
    free(tp);
    for (i = 0; i < 5; i++)
        printf("%s\n", a[i]);
    printf("The largest string entered is %s, with a length of %d \n", a[maxidx], max);
    return 0;
}