#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void freeList(Node *head) {
	Node* temp;
	Node* current = head;
	while (current) {
		temp = current;
		current = temp -> next;
		free(temp -> data);
		free(temp);
	}
}

void printList(Node *head) {
	Node *current = head;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}