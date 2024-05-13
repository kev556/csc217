#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"

Node *enqueue(Node *head, char *word) {
	Node *current = head;
	Node *first = current;
	Node *temp = (Node*)malloc(sizeof(Node*));

	temp->data = malloc(80);
	temp->next = NULL;

	mystrncpy(temp->data, word, 80);

	if (!current)
		return temp;
	while (current->next)
		current = current->next;
	current->next = temp;
	return first;
}
Node *push(Node *head, char *word) {
	Node *temp = (Node*)malloc(sizeof(Node*));
	temp->data = malloc(80);
	mystrncpy(temp->data, word, 80);
	temp->next = head;
	return temp;
}
void deletelist(Node *head) {
	Node* temp;
	Node* current = head;
	while (current) {
		temp = current;
		current = temp -> next;
		free(temp -> data);
		free(temp);
	}
}

void printlist(Node *head) {
	Node *current = head;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}