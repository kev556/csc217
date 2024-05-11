#ifndef NODE_H_
#define NODE_H_
	typedef struct node Node;
	struct node {
		char *data;
		Node *next;
	};
	void freeLinkedList(Node *head);
	void printLinkedList(Node *head);
#endif