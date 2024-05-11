#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct node {
	char *data;
	Node *next;
} Node;

void freeList(Node *head) {
	Node *temp;
	while (head){
		temp = head;
		free(head);
		head = temp -> next;
	}
}

void printAll(Node *head) {
	while (head) {
		printf("%s", head->data);
		head = head->next;
	}
}