#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"
#include "printAll.h"

int main(void) {
    char *arr[5];
    int i = 0, max = 0, maxidx = 0;

    for (i = 0; i < 5; i++) {
        char temp[102];
        fgets(temp, 102, stdin);
        temp[mystrlen(temp) - 2] = '\0';

        arr[i] = malloc(102);
        strncpy(arr[i], temp, 102);

        int n = mystrlen(arr[i]) - 1;
        if (n > max) {
            max = n;
            maxidx = i;
        }
    }
    for (i = 0; i < 5; i++)
        printf("%s\n", arr[i]);

    printf("The largest string entered is [ %s ] with a length of %d \n", arr[maxidx], max);

    for (i = 0; i < 5; i++)
        free(arr[i]);

    return 0;
}