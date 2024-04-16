#include <stdio.h>
#include "myfunctions.h"

#define WINDOWS 0

int main(void) {
    #ifdef WINDOWS
        printf("WINDOWS\n");
    #else 
        printf("Not WINDOWS\n");
    #endif

    #if WINDOWS
        printf("WINDOWS is true\n");
    #else 
        printf("WINDOWS is false\n");
    #endif

    mystaticfunction();
    mystaticfunction();
    mystaticfunction();
}