// Kevin Li N00969115 Score: 100

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "input.h"

void readArgs(int argc, char **argv, char **filearg, int *limit, char **delete) {
	int i = 1;

	while (i < argc) { // We will access memory in i + 1, comparing with argc - 1 makes certain we do not go out of bounds
		if (i + 1 >= argc) { // there are always an odd number of args in a valid series of args. If i is even and larger than argc, the args are invalid.
			fprintf(stderr, "Invalid command or syntax. Exiting Program.\n");
			exit(EXIT_FAILURE);
		}
		if (mystrcmp(*(argv + i), "-h") == 0) { // displays help message and exits if -h
			printHelp(*argv);
			exit(EXIT_SUCCESS);
		}
		if (mystrcmp(*(argv + i), "-f") == 0) { // if -f, Stores filename into filearg buffer
			*filearg = malloc(80);
			mystrncpy(*filearg,*(argv + i + 1), 80);
			i += 2; // checks for more args
		}
		else if (mystrcmp(*(argv + i), "-n") == 0) { // If user defines a limit, reads the limit into *limit
			if (myisdigit(**(argv + i + 1))) {
				*limit = myatoi(*(argv + i + 1)); // Else, stores limit and checks for more args
				i += 2;
			}
			else { // If the first digit is not a number, the arg is automatically invalid.
				fprintf(stderr, "Invalid argument for -n. Exiting Program.\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (mystrcmp(*(argv + i), "-d") == 0){ // Reads in a word that should be deleted into buffer
			*delete = malloc(80);
			mystrncpy(*delete, *(argv + i + 1), 80);
			i += 2;
		}
		else { // From the second arg onwards must be either -h, -f, -n, or -d. if not, exits with error
			fprintf(stderr, "Invalid command or syntax. Exiting Program.\n");
			exit(EXIT_FAILURE);
		}
	}
}
void readFromUser(Node **stack, Node **queue, int limit) {
	char* word = (char *)malloc(80); // buffer for user input
	int count = 0; // counter to prevent reading more than limit number of lines

	while (count < limit && fgets(word, 80, stdin)) { // only reads in 80 characters for user input
		*stack = push(*stack, word); // Subsequently pushes each word read in to the front
		*queue = enqueue(*queue, word); // Subsequently pushes each word read in to the rear
		count++;
	}
	free(word); // Must deallocate unused memory to prevent memory leaks
}
void getFileInput(Node **stack, Node **queue, FILE *fp, int limit) {
    char *word = (char *) malloc(80); 
	int count = 0;
    
    while (count < limit && fgets(word, 80, fp)) { //Reads each line of the file
        char* wordPtr = word; // Keeps track of the end of the currently processing word
        char* startPtr = word; // Keeps track of the beginning of the currently processing word
        while (*wordPtr) { // Goes through the current line of the file. 
            if (*wordPtr == ' ' || *wordPtr == '\n') {
                *wordPtr = '\0'; // Replaces the space or \n with a null terminator
                *stack = push(*stack, startPtr); // Pushes startPtr, doing this passes the string of all chars between startPtr and \0
                *queue = enqueue(*queue, startPtr); 
                startPtr = wordPtr + 1; // Moves startPtr to the start of the next word
				count++; // Increments count to follow number of lines to read according to -n arg
            }
			wordPtr++; // increments wordPtr until it hits a space or newline, which marks the end of the current word
        }
        *stack = push(*stack, startPtr); // The code written above skips the last word due to the null escape character at the end of a file.
        *queue = enqueue(*queue, startPtr); // Theses pushes will include it.
    }
    free(word); // Frees memory that will no longer be used
}
// Helpful message to show user how program works
void printHelp(char *name) {
    printf("usage: %s [OPTION] [OPTIONARG]...\n\n"
            "Prints all words passed to it via arguments\n\n"
            "-f\tFILE\t\t Specifies a file to read from\n"
            "-n\tNUMBER\t\t Specifies the number of lines to read\n"
            "-d\tWORD\t\t Specifies a word to delete from the list\n", name);
}
