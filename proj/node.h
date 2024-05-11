#ifndef NODE_H_
#define NODE_H_
	typedef struct node Node;
	struct node {
		char *data;
		Node *next;
	};
	void freeList(Node *head);
	void printAll(Node *head);
#endif