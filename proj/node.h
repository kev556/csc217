#ifndef NODE_H_
#define NODE_H_
	typedef struct node {
		char *data;
		Node next;
	} Node;
	void freeList(Node *head);
	void printAll(Node *head);
#endif