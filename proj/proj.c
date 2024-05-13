#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "fileinput.h"

int main(int argc, char **argv) {
	Node *stack = NULL;
	Node *queue = NULL;
	char* word = malloc(80);
	
	if (argc == 1) {
		while (fgets(word, 80, stdin)) {
			stack = push(stack, word);
			queue = enqueue(queue, word);
		}
		free(word);
		printlist(stack);
		printlist(queue);
		deletelist(stack);
		deletelist(queue);
		return 0;
	}
	else {
		getFileInput(&stack, &queue, argc, argv, word);
		free(word);
		printlist(stack);
		printlist(queue);
		deletelist(stack);
		deletelist(queue);
		return(0);
	}
	
	return 0;
}