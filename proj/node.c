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