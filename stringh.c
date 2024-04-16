#include <stdio.h>
#include <stdbool.h>

bool myisdigit(char c) {
    return (c >= '0' && c <= '9');
}
int myAToI(char s[]) {
    int total = 0, i = 0;

    for (; myisdigit(s[i]); i++)
        total = total * 10 + (s[i] - '0');
    
    return total;
}
double myAToF(char s[]) {
    double total = 0, factor = 1.0; int i = 0;

    for (; myisdigit(s[i]); i++) {
        total = total * 10 + (s[i] - '0');
    }
    if (s[i] = '.') {
        i++;
        for (; myisdigit(s[i]); i++) {
            total = total * 10 + (s[i] - '0');
            factor *= 10.0;
        }
    }
    return total / factor;
}
void convertLowerToUpper(char s[]) {
    size_t i = 0;

    
}
size_t mystrlen(char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0';) {
        i++;
    }
    return i;
}
size_t krgetline(char s[], size_t lim) {
    int c; size_t i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}
void mystrcpy(char s[], char t[]) {
    size_t i = 0;

    while ((t[i]) = s[i])
        i++;
}

void mystrcat(char s[], char t[]) {
    size_t tlen = mystrlen(t), i = 0;

    while(t[tlen] = s[i]) {
        tlen++;
        i++;
    }
}
int mystrcmp(char s[], char t[]) {
    size_t i = 0;
    
    for (; s[i] == t[i]; i++) {
        if (s[i] == '\0')
            return 0;
    }
    return s[i] - t[i];
}
ssize_t indexOf(char s[], char c) {
    ssize_t i = 0;
    while (s[i]) {
        if (s[i] == c)
            return i;
        i++;
    }
    return -1;
}
int main(void) {
    char s[] = "hello";
    char st[0];
    printf("%li", indexOf(s, 'l'));
    int n = 0;

    for (int i = 0; i < 35; i++, n++) {
        
    }
}