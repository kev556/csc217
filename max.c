#include <stdio.h>

size_t mystrlen(char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0';) {
        i++;
    }
    return i;
}

int main(void){
    char a[] = "hello";
    mystrlen(a);
    return 0;
}