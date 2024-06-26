// Kevin Li N00969115 Grade: 100

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"

// Adds a new node with data word to the end of the list with first element head
Node *enqueue(Node *head, char *word) {
	Node *current = head; // newnodeorary node for us to increment 
	Node *newnode = (Node*)malloc(sizeof(Node*));

	newnode->data = (char *)malloc(80); // Creates a buffer for the data inside node
	newnode->next = NULL; // Must point to null as this node will be at the end of the list

	mystrncpy(newnode->data, word, 80); // Copies a max of 80 chars from the word passed as param into the new node

	if (head == NULL) // If list is empty, newnode becomes the first element 
		return newnode;

	while (current->next) // Increments until current is the last node in the list
		current = current->next; 
	current->next = newnode; // Sets the next node of the last node to the newly created node
	return head; // is intended to be assigned to queue in main to represent the new queue with the newly created node at the end
}

// Adds a new node with data word to the front of the list with first element head
Node *push(Node *head, char *word) {
	Node *newnode = (Node*)malloc(sizeof(Node*));
	newnode->data = (char *)malloc(80);

	mystrncpy(newnode->data, word, 80);

	if (head == NULL) // If list is empty, newnode becomes the first element 
		return newnode;

	newnode->next = head; // Puts the new node at the front of the list
	return newnode; // intended to be assigned to stack, making newnode the defacto start of the list
}

// Frees all dynamically allocated Nodes in the list with first element head
void deletelist(Node *head) {
	Node* prev; // Used so we can access the next value of the node that is about to be freed
	Node* current = head; // Node to be iterated through

	while (current) { // Loops until there are no Nodes in the list
		prev = current; // sets the node to be freed to prev
		current = prev -> next; // sets current to the next node
		free(prev -> data); // Frees the node's data, then the node itself
		free(prev);
	}
}
// Prints every value in the list with first element head
void printlist(Node *head) {
	Node *current = head;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}
// Deletes every node that contains the word specified, given by Kyle Castellano
Node *deleteword(Node *head, char *word) {
	while (head && mystrcmp(head -> data, word) == 0) { // this is to easily delete any nodes in front in the edge case that there are matches in front.
		Node *temp = head; // temporary node so we can gain access to head to free it
        head = head -> next;
		free(temp -> data); 
		free(temp);
	}
	if (head == NULL) // In the case that all values have been freed, returns an empty list
        return head;
    Node* prev = head;// If not, sets up for iteration through list
    Node* current = prev->next;

    while (current != NULL) {
        if (mystrcmp(current -> data, word) == 0) {
			prev -> next = current -> next; // If there is a match, set prevs next to currents next
			free(current -> data); // Frees inner before outer
			free(current);
		} 
        else
            prev = current; //If not, increments both by 1 place
        current = prev -> next;
    }
    return head;
}