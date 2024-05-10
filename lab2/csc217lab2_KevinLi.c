#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "cli.h"

// Kevin Li N00969115

int main(int argc, char **argv) {
    char **arr = malloc(sizeof(char) * 102 * 5); // pointer to a memory space that stores 5 char[] pointers, each storing a max size of 102 chars. 101st char stores \n and 102nd stores \0
    char *max = malloc(sizeof(char) * 102);	// stores the largest char[]
    int maxlen = 0; // stores max length of string stored in *max

    if (argc == 1)
        userInput(arr, &max, &maxlen); // if there are no cli args, prompts user for input of 5 strings
    else if (argc == 6)
        cliInput(argc, argv, arr, &max, &maxlen); // if there are exactly 5 cli args, passes argc and argv to process args
    else {
        fprintf(stderr, "Incorrect number of cli arguments, please enter 5 strings.\n"); // If there aren't exactly 5 cli args, prints to stderr and exits the program
        exit(1); // exits the program with an error code of 1
    }
    for (int i = 0; i < 5; i++) {
        free(*arr); // frees the inner allocated memory at the current address
        *arr++; // sets the current string pointed to by *arr to the next
    }
    printf("The largest string entered is %s with a length of %d \n", max, maxlen); 
    free(arr); // frees the outer arr since it is no longer necessary
    free(max);

    return 0;
}