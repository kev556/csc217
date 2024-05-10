#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
	char *data;
	Node *next;
} Node;

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
				
				

		}
	} 
}