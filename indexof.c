#include <stdio.h>

ssize_t indexOf(char s[], char c) {
    ssize_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) 
            return i;
    }
    return -1;
}


int main(void) {
    char s[] = "dog";
    printf("%zd\n", indexOf(s, 'z'));

    return 0;
}