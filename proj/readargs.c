#include <stdio.h>
#include <stdlib.h>
#include "fileinput.h"
#include "readargs.h"
#include "str.h"

void readArgs(int argc, char **argv, char **filearg, int *limit, char **delete) {
	int i = 1;
	if (mystrcmp(*(argv + i), "-h") == 0) {
		printHelp(*argv);
		exit(EXIT_SUCCESS);
	}
	while (i < argc - 1) { // We will access memory in i + 1, comparing with argc - 1 makes certain we do not go out of bounds
		if (mystrcmp(*(argv + i), "-f") == 0) {
			*filearg = malloc(80);
			mystrncpy(*filearg,*(argv + i + 1), 80);
			i += 2;
		}
		else if (mystrcmp(*(argv + i), "-n") == 0) {
			if (myisdigit(**(argv + i + 1))) {
				*limit = myatoi(*(argv + i + 1));
				i += 2;
			}
			else {
				fprintf(stderr, "Invalid argument for -n. Exiting Program.\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (mystrcmp(*(argv + i), "-d") == 0){
			if (i + 1 >= argc) {
				fprintf(stderr, "No argument for -d. Exiting Program.\n");
				exit(EXIT_FAILURE);
			}
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