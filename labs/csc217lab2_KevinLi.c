#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *a[5];
    int i, max, maxidx = 0;

    for (i = 0; i < 5; i++) {
        a[i] = malloc(102);
        a[i] = fgets(a[i], 102, stdin);

        int j = 0;
        while (*a[i]) {
            *a[i]++;
            puts(a[i]);
            j++;
        }
        if (j > max) {
            max = j;
            maxidx = i;
        }
    }
    printf("%d", i);
    return 0;
}