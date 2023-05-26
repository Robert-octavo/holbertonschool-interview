#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int _strlen(char *s);
void print_error(void);
int is_digit(char *s);
char *multiply(char *num1, char *num2);
char *multiply_by_digit(char *num1, char num2);
char *add_zeros(char *num, int n);
char *remove_zeros(char *num);

#endif /* _HOLBERTON_H_ */
