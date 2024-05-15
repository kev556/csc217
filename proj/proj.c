// Kevin Li N00969115 Grade: 80

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "fileinput.h"

int main(int argc, char **argv) {
	Node *stack = NULL;
	Node *queue = NULL;

	if (argc == 1) {// If there are no command line args, will ask user for input
		char* word = (char *)malloc(80); // buffer for user input
		while (fgets(word, 80, stdin)) { // only reads in 80 characters for user input
			stack = push(stack, word);
			queue = enqueue(queue, word);
		}
		free(word); // Must deallocate unused memory to prevent memory leaks
		printlist(stack);
		deletelist(stack);
		printlist(queue);
		deletelist(queue);
		return 0;
	}
	else {
		// This mess is meant to get the 2nd char in the 2nd arg within argv.
		// ex. ./proj -f "hi.txt", second arg is -f, second char is f
		switch(*(*(argv + 1) + 1)) {
		case 'h':
			printHelp(*argv); // Prints a help message if argument is -h, then exits program successfully
			return 0;
		case 'f': // If argument is -f, reads input from a file
			if (argc < 3) { // If argc is < 3, then there is no argument for -f, and we cannot specify a file to be read. exits with failure
				fprintf(stderr, "No filename passed into -f, exiting program with code 1\n");
				exit(EXIT_FAILURE);
			}
			FILE *fp = fopen(*(argv + 2), "r"); // Accesses the argument right after -f, intended to be a file, and attempts to open that file
			if (fp == NULL) { // If fp is NULL, then fopen could not find a file with that name. exits with failure
				fprintf(stderr, "File %s does not exist, exiting program with code 1\n", *(argv + 2));
				exit(EXIT_FAILURE);
			}
			getFileInput(&stack, &queue, fp); // if file exists, reads from file and stores all words read into stack and queue
			fclose(fp);

			// prints all items in stack and queue, then frees both structures
			printlist(stack);
			deletelist(stack);
			printlist(queue);
			deletelist(queue);
			return(0);
		}
	}
}