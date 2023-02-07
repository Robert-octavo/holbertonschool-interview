# 0x08. Palindrome integer

Write a function that checks whether or not a given unsigned integer is a palindrome.

- Prototype: int is_palindrome(unsigned long n);
- Where n is the number to be checked
- Your function must return 1 if n is a palindrome, and 0 otherwise
- You are not allowed to allocate memory dynamically (malloc, calloc, …)

you can compile it using the following command:

gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c

and then run it using:

./palindrome <number>
example: ./palindrome 12345678987654321
