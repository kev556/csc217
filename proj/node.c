#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void freeList(Node *head) {
	Node *temp;
	Node *current = head;
	while (head) {
		temp = current;
		free(head -> data);
		head = temp -> next;
	}
}

void printAll(Node *head) {
	puts("got here");
	Node *current = head;
	while (current) {
		printf("%s\n", current->data);
		current = current->next;
	}
}