#include <stdio.h>
#ifndef STR_H_
#define STR_H_
	size_t mystrlen(const char *str);
	void mystrncpy(char *dest, const char *src, size_t lim);
	char **mysplit(char *str, char delim);
#endif