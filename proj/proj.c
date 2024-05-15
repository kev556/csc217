// Kevin Li N00969115 Grade: 100

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "str.h"
#include "input.h"

int main(int argc, char **argv) {
	Node *stack = NULL; // Head of a list, will only use the push function
	Node *queue = NULL; // Head of a list, will only use the enqueue function

	int limit = INT_MAX; // sets the limit to a ludicrously large number as a base case
	char *filearg = NULL; // Keeps track if any of these args are passed, idea from Kyle Castellano
	char *delete = NULL;
	
	readArgs(argc, argv, &filearg, &limit, &delete);

	if (filearg) {// If a file is being read, reads from file
		FILE *fp = fopen(filearg, "r");
		if (fp == NULL) {
			fprintf(stderr, "File %s does not exist, exiting program\n", filearg);
			free(filearg);
			exit(EXIT_FAILURE);
		}
		getFileInput(&stack, &queue, fp, limit); // Gets File input 
		free(filearg);
	}
	else 
		readFromUser(&stack, &queue, limit); // if there is no file, takes user input

	if (delete) { // if a word is defined to be deleted using -d, deletes the word from the list
		stack = deleteword(stack, delete);
		queue = deleteword(queue, delete);
		free(delete); // frees the memory that wont be used anymore
	}

	printlist(stack); // Prints and frees both lists
	deletelist(stack);
	printlist(queue);
	deletelist(queue);
}