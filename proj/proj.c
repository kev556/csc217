#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"

int main(int argc, char **argv) {
	Node *stack = NULL;
	Node *queue = NULL;
	char *filename = *argv;
	char* word = malloc(80);
	
	if (argc == 1) {
		while (fgets(word, 80, stdin)) {
			stack = push(stack, word);
		}
		free(word);
		printlist(stack);
		deletelist(stack);
		return 0;
	}
	switch(*(++(*++argv))) {
		case 'f':
			FILE *fp = fopen(*++argv, "r");
			if (fp == NULL) {
				fprintf(stderr, "File %s does not exist, exiting program\n", *argv);
				exit(EXIT_FAILURE);
			}
			// Derivative of a ChatGPT function that splits a string by space
			while (fgets(word, 80, fp)) {
				char* wordPtr = word; // Keeps track of the end of the currently processing word
       	 		char* startPtr = word; // Keeps track of the beginning of the currently processing word
        		while (*wordPtr) { // Goes through the current line of the file. 
            		if (*wordPtr == ' ' || *wordPtr == '\n') {
						*wordPtr = '\0'; // Replaces the space or \n with a null terminator
                		stack = push(stack, startPtr); // Pushes startPtr itself, doing this passes the string of all chars between startPtr and the first \0 after it
                		startPtr = wordPtr + 1; // Moves startPtr to after 
            		}
            		wordPtr++;
				}
				stack = push(stack, startPtr); // The code written above skips the last word due to the null escape character at the end of a file. This push will include it.
			}
			free(word);
			fclose(fp);
			printlist(stack);
			deletelist(stack);
			return(0);
			break;
		case 'h':
			printf("Usage: %s [OPTION...] [OPTIONAL INPUT FILE WITH -f]\n\n" 
				   "-f=INPUTFILE \t\t 	  defines a file to be used as input\n"
				   "-h      \t\t\t     give this help list\n", filename);
			break;
		default: 
			fprintf(stderr, "command %c does not exist, exiting program\n", **argv); 
			exit(EXIT_FAILURE); // Prints to stderr and exits if user passes in a cmd line arg that DNE
	}
	
	return 0;
}