#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "node.h"


int main(int argc, char **argv){
	Node *head = (Node *) malloc(sizeof(Node *));
	head->next = NULL;

	int opt;
	if (argc == 1) {
		char *word = malloc(80);
		while (fgets(word, 80, stdin)) {
			Node *temp = (Node *) malloc(sizeof(Node *));
			if (temp == NULL) {
				printf("Null pointer error");
				exit(1);
			}
			
			temp->data = strdup(word);
			temp->next = head;

			head = temp;
		}
		free(word);
		printAll(head);
		return 0;
	}
	while ((opt = getopt(argc, argv, "hf:")) != -1) {
		switch (opt) {
			case 'h':
				printf("hi");
				return 0;
			case 'f':
				printf("hi");
			default:
				break;
		}
	} 
}