#include <stdio.h>
#include <stdlib.h>
#include "fileinput.h"
#include "readargs.h"
#include "str.h"

void readArgs(int argc, char **argv, char **filearg, int *limit, char **delete) {
	int i = 1;
	while (i < argc - 1){ // We will access memory in i + 1, comparing with argc - 1 makes certain we do not go out of bounds
		if (mystrcmp(*(argv + i), "-h") == 0){
			printHelp(*argv);
			return 0;
		}
		else if (mystrcmp(*(argv + i), "-f") == 0){
			mystrcpy(*filearg,*(argv + i + 1));
			i += 2;
		}
		else if (mystrcmp(*(argv + i), "-n") == 0){
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
			mystrcpy(*delete, *(argv + i + 1));
			i += 2;
		}
		else { // From the second arg onwards must be either -h, -f, -n, or -d. if not, exits with error
			fprintf(stderr, "Invalid command or syntax. Exiting Program.\n");
			exit(EXIT_FAILURE);
		}
	}
}