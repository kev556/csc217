#include <stdio.h>
#include "myfunctions.h"
//Implementation file for myfunctions.c

int my_global_int = 100;

void myfunction(int x) {
    printf("my_global_int %i\n", my_global_int);
}

void mystaticfunction() {
    static int svar = 0;

    svar++;

    printf("svar is %d\n", svar);
}