// Kevin Li N00969115 Grade: 80

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "fileinput.h"

<<<<<<< HEAD
void getFileInput(Node **stack, Node **queue) {
    size_t count = 0;
    size_t max = _I32_MAX;
	FILE *fp = NULL;
	char *word = malloc(80);
    // Derivative of a ChatGPT function that splits a string by space
    while (fgets(word, 80, fp) && count < max) {
=======
void getFileInput(Node **stack, Node **queue, FILE *fp) {
    char *word = (char *)malloc(80);
    
    while (fgets(word, 80, fp)) { //Reads each line of the file
>>>>>>> 7199af2e7a8e8cf85ea2694ccaf1a75ce81a10e5
        char* wordPtr = word; // Keeps track of the end of the currently processing word
        char* startPtr = word; // Keeps track of the beginning of the currently processing word
        while (*wordPtr) { // Goes through the current line of the file. 
            if (*wordPtr == ' ' || *wordPtr == '\n') {
                *wordPtr = '\0'; // Replaces the space or \n with a null terminator
<<<<<<< HEAD
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
=======
                *stack = push(*stack, startPtr); // Pushes startPtr, doing this passes the string of all chars between startPtr and \0
                *queue = enqueue(*queue, startPtr); 
                startPtr = wordPtr + 1; // Moves startPtr to the start of the next word
            }
            wordPtr++; // increments wordPtr until it hits a space or newline, which marks the end of the current word
        }
        *stack = push(*stack, startPtr); // The code written above skips the last word due to the null escape character at the end of a file.
        *queue = enqueue(*queue, startPtr); // Theses pushes will include it.
    }
    free(word);
}
// Helpful message to show user how program works
void printHelp(char *name) {
    printf("usage: %s [OPTION] [OPTIONARG]...\n\n"
            "Prints all words passed to it via arguments\n\n"
            "-f\tFILE\t\t Specifies a file to read from\n"
            "-n\tNUMBER\t\t Specifies the number of lines to read\n"
            "-d\tWORD\t\t Specifies a word to not include\n", name);
}


>>>>>>> 7199af2e7a8e8cf85ea2694ccaf1a75ce81a10e5
