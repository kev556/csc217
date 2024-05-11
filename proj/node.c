#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void freeLinkedList(Node *head) {
	Node* temp;
	Node* current = head;
	while (current) {
		temp = current;
		current = temp -> next;
		free(temp -> data);
		free(temp);
	}
}

void printLinkedList(Node *head) {
	Node *current = head;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}