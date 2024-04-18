#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "cli.h"

int main(int argc, char **argv) {
    char *arr[5];
    int maxidx = 0, max = 0;

    if (argc == 1)
        userInput(arr, &max, &maxidx);
    else if (argc == 6)
        cliInput(argc, argv, arr, &max, &maxidx);
    else {
        fprintf(stderr, "Incorrect number of cli arguments, please enter 5 strings.\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) 
        printf("%s\n", arr[i]);
        
    printf("The largest string entered is [ %s ] with a length of %d \n", arr[maxidx], max);

    for (int i = 0; i < 5; i++)
        free(arr[i]);
    
    return 0;
}