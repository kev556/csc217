#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlen.h"
#include "enterInput.h"

int main(int argc, char **argv) {
    if (argc == 1)
        enterInput();
    else if (argc == 6)
        cliInput(argv);
}