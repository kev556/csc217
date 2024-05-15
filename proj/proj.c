// Kevin Li N00969115 Grade: 80

#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "list.h"
#include "str.h"
#include "fileinput.h"
#include "readargs.h"

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
		char *filearg = NULL; // Keeps track if any of these args are passed, idea from Kyle Castellano
		int limit = INT_MAX;
		char *delete = NULL;

		readArgs(argc, argv, &filearg, &limit, &delete);
		FILE *fp = fopen(filearg, "r");
		if (!fp) {
			fprintf(stderr, "File %s does not exist, exiting program\n", filearg);
			exit(EXIT_FAILURE);
		}
		getFileInput(&stack, &queue, fp, limit);

		printlist(stack);
		deletelist(stack);
		printlist(queue);
		deletelist(queue);

	}
}