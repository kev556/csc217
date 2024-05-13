#include <stdio.h>
#include <stdbool.h>
#ifndef STR_H_
#define STR_H_
	size_t mystrlen(const char *str);
	void mystrncpy(char *dest, const char *src, size_t lim);
	bool isdigit(char c);
#endif