// Kevin Li N00969115 Grade: 80

#include <stdio.h>
#include <stdbool.h>

#ifndef STR_H_
#define STR_H_
	size_t mystrlen(const char *str);
	int mystrcmp(const char *s, const char *t);
	void mystrcpy(char *dest, const char *src);
	void mystrncpy(char *dest, const char *src, size_t lim);
	bool myisdigit(char c);
#endif