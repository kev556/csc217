#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "cli.h"

int main(int argc, char **argv) {
    char *arr[5]; // array of string pointers
    int maxidx = 0, max = 0; // maxidx will store the index of the largest string in the array. max will store the largest string length
    /*
        If there are no cli arguments, proceeds with obtaining user input. 
        If there are too few, prints to stderr and exits the program with an exit code of 1 to signify error
        If there are exactly 5 cli arguments, reads those arguments into arr
    */
    if (argc == 1)
        userInput(arr, &max, &maxidx);
    else if (argc == 6)
        cliInput(argc, argv, arr, &max, &maxidx);
    else {
        fprintf(stderr, "Incorrect number of cli arguments, please enter 5 strings.\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++) 
        printf("%s\n", arr[i]); // Prints every string in the array
        
    printf("The largest string entered is [ %s ] with a length of %d \n", arr[maxidx], max); // self explanatory

    for (int i = 0; i < 5; i++)
        free(arr[i]); // Frees all of the dynamically allocated memory stored in array.
    
    return 0;
}