#ifndef LIST_H_
#define LIST_H_
	typedef struct node Node;
	struct node {
		char *data;
		Node *next;
	};
	Node* enqueue(Node *head, char *word);
	Node* push(Node *head, char *word);
	void deletelist(Node *head);
	void printlist(Node *head);
#endif