#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"

int main(int argc, char **argv) {
	Node *stack = NULL;
	Node *queue = NULL;
	char *filename = *argv;

	if (argc == 1) {
		char* word = malloc(80);
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
			FILE *fp = fopen(filename, "r");
			if (fp == NULL) {
				fprintf(stderr, "File %s does not exist, exiting program", filename);
				exit(EXIT_FAILURE);
			}
			break;
		case 'h':
			printf("Usage: %s [OPTION...] [OPTIONAL INPUT FILE WITH -f]\n\n" 
				   "-f=INPUTFILE \t\t 	  defines a file to be used as input\n"
				   "-h      \t\t\t     give this help list\n", filename);
			break;

	}
	
	
	return 0;
}