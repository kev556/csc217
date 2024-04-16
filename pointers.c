#include <stdio.h>
#include <stdlib.h>

int strlen(char s[]) {
    ;
}
int main(void) {
    int x = 5;
    int *px = &x;

    printf("%ld , %ld", sizeof(px), sizeof(*px));

    char *a[5];
    a[0] = malloc(0);
    printf("%d\n", *a[0]);

    free(a[0]);
}