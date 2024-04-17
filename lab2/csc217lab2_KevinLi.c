#include <stdio.h>
#include "enterInput.h"
#include "cliInput.h"

int main(int argc, char **argv) {
    if (argc == 1)
        enterInput();
    else if (argc == 6)
        cliInput(argv);
}