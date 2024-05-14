#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "str.h"

size_t mystrlen(const char *str) {
	const char *t = str;
	while (*str++);
	return str - t - 1;
}
int mystrcmp(const char *s, const char *t) {
	
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
bool isdigit(char c) {
	return (c >= '0' && c <= '9');
}