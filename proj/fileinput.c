#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"

void getFileInput(Node **stack, Node **queue) {
    size_t count = 0;
    size_t max = _I32_MAX;
	FILE *fp = NULL;
	char *word = malloc(80);
    // Derivative of a ChatGPT function that splits a string by space
    while (fgets(word, 80, fp) && count < max) {
        char* wordPtr = word; // Keeps track of the end of the currently processing word
        char* startPtr = word; // Keeps track of the beginning of the currently processing word
        while (*wordPtr) { // Goes through the current line of the file. 
            if (*wordPtr == ' ' || *wordPtr == '\n') {
                *wordPtr = '\0'; // Replaces the space or \n with a null terminator
                *stack = push(*stack, startPtr); // Pushes startPtr itself, doing this passes the string of all chars between startPtr and the first \0 after it
                *queue = enqueue(*queue, startPtr); 
                startPtr = wordPtr + 1; // Moves startPtr to after 
            }
            wordPtr++;
            count++;
        }
        *stack = push(*stack, startPtr); // The code written above skips the last word due to the null escape character at the end of a file. This push will include it.
        *queue = enqueue(*queue, startPtr); 
    }
	free(word);
    fclose(fp);
}
void printHelp(char *name) {
	printf("usage: %s [OPTION] [OPTIONARG]...\n\n"
			"Prints all words passed to it via arguments\n\n"
			"-f\tFILE\t\t Specifies a file to read from\n"
			"-n\tNUMBER\t\t Specifies the number of lines to read\n"
			"-d\tWORD\t\t Specifies a word to not include\n", name);
}
void validateArgs(int argc, char **argv) {
	
}