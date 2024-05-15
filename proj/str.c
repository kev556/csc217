// Kevin Li N00969115 Grade: 80

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
void mystrcpy(char *dest, const char *src) {
	size_t i = 0;

	while ((*dest = *src) != '\0') {
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
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
bool myisdigit(char c) {
	return (c >= '0' && c <= '9');
}
int myatoi(char *s) {
	int total = 0, i = 0;
	for (;myisdigit((*s) + i); i++)
		total = total * 10 + (((*s) + i) - '0');
	return total;
}