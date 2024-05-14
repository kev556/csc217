#include <stdio.h>
#include <stdbool.h>

#ifndef STR_H_
#define STR_H_
	size_t mystrlen(const char *str);
	int mystrcmp(const char *s, const char *t);
	void mystrncpy(char *dest, const char *src, size_t lim);
	bool myisdigit(char c);
#endif