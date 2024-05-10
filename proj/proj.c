#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <node.h>


int main(int argc, char **argv){
	Node *head = NULL;

	int opt;

	while ((opt = getopt(argc, argv, "hf:")) != -1) {
		switch (opt) {

			case 'h':
				printf("");
				return 0;
			case 'f':
				readFromFile(head, fopen(optarg, "r"));
			default:
				char *word = malloc(80);
				while (fgets(word, 80, stdin) != EOF) {
					Node *temp = malloc(sizeof(Node));
					temp->data = malloc(80);
					temp->data = word;
					temp->next = head;
					head = temp;
				}
				free(word);
				printAll(head);
		}
	} 
}