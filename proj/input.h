// Kevin Li N00969115 Score: 100

#include <stdlib.h>
#include "list.h"

#ifndef INPUT_H_
#define INPUT_H_
	void readArgs(int argc, char **argv, char **filearg, int *limit, char **delete);
	void readFromUser(Node **stack, Node **queue, int limit);
	void getFileInput(Node **stack, Node **queue, FILE *fp, int limit);
    void printHelp(char* name);
#endif