#include <stdio.h>
#include <stdlib.h>
#include "str.h"

size_t mystrlen(const char *str) {
	const char *t = str;
	while (*str++);
	return str - t - 1;
}
void mystrncpy(char *dest, const char *src, size_t lim) {
	size_t i = 0;

	while ((*dest = *src) != '\0' && i < lim) {
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
}