#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
int _printf(const char *format, ...);
int _putchar(char c);
void print_number(int n, int *len);

#endif
