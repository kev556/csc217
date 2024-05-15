// Kevin Li N00969115 Grade: 100

#ifndef LIST_H_
#define LIST_H_
	typedef struct node Node;
	struct node {
		char *data;
		Node *next;
	};
	Node *push(Node *head, char *word);
	Node *enqueue(Node *head, char *word);
	void deletelist(Node *head);
	void printlist(Node *head);
	Node *deleteword(Node *head, char *word);
#endif