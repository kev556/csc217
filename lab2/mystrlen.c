#include <stdio.h>
#include "mystrlen.h"
// Kevin Li N00969115

/* Loops through the string pointer until the pointer points to null. 
 subtracting the end memory address from the beginning results in the length of the string*/
size_t mystrlen(const char *s) {
	const char *t = s;
	while (*s++);
	return s-t;
}