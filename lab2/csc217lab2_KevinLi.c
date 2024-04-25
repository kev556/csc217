#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "cli.h"

int main(int argc, char **argv) {
    char **arr = malloc((sizeof(char) * 102) * 5);
    char* max = 0;
    int maxlen = 0;

    if (argc == 1)
        userInput(arr, &max, &maxlen);
    else if (argc == 6)
        cliInput(argc, argv, arr, &max, &maxlen);
    else {
        fprintf(stderr, "Incorrect number of cli arguments, please enter 5 strings.\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        printf("%s\n", *arr);
        free(*arr++);
    }
        
    printf("The largest string entered is [ %s ] with a length of %d \n", *max, maxlen);
    
    return 0;
}