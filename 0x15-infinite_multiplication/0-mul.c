#include "holberton.h"

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, 98 on failure
 */

int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		exit(98);
	}

	result = multiply(argv[1], argv[2]);
	printf("%s\n", result);
	free(result);
	return (0);
}

/**
 * multiply - Multiplies two numbers
 *
 * @num1: First number
 * @num2: Second number
 *
 * Return: Pointer to the result
 */

char *multiply(char *num1, char *num2)
{
	char *result, *temp, *temp2;
	int i, j, k, len1, len2, len, carry, digit1, digit2, product;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	for (i = 0; i < len; i++)
		result[i] = '0';
	result[i] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';
		temp = multiply_by_digit(num2, digit1);
		temp2 = add_zeros(temp, len1 - i - 1);
		free(temp);
		for (j = len - 1, k = _strlen(temp2) - 1; k >= 0; j--, k--)
		{
			digit2 = temp2[k] - '0';
			product = result[j] - '0' + digit2 + carry;
			result[j] = (product % 10) + '0';
			carry = product / 10;
		}
		if (carry)
			result[j] = (result[j] - '0' + carry) + '0';
		free(temp2);
	}
	return (remove_zeros(result));
}

/**
 * multiply_by_digit - Multiplies a number by a digit
 *
 * @num1: Number
 * @num2: Digit
 *
 * Return: Pointer to the result
 */

char *multiply_by_digit(char *num1, char num2)
{
	char *result;
	int i, len1, len, carry, digit, product;

	len1 = _strlen(num1);
	len = len1 + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	for (i = 0; i < len; i++)
		result[i] = '0';
	result[i] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		digit = num1[i] - '0';
		product = digit * num2;
		carry = product / 10;
		result[i + 1] = (product % 10) + '0';
		if (carry)
			result[i] = (result[i] - '0' + carry) + '0';
	}
	return (remove_zeros(result));
}

/**
 * add_zeros - Adds zeros to the end of a number
 *
 * @num: Number
 * @n: Number of zeros to add
 *
 * Return: Pointer to the result
 */

char *add_zeros(char *num, int n)
{
	char *result;
	int i, len;

	len = _strlen(num);
	result = malloc(sizeof(char) * (len + n + 1));
	if (!result)
		return (NULL);
	for (i = 0; i < len; i++)
		result[i] = num[i];
	for (i = 0; i < n; i++)
		result[len + i] = '0';
	result[len + i] = '\0';
	return (result);
}

/**
 * remove_zeros - Removes zeros at the beginning of a number
 *
 * @num: Number
 *
 * Return: Pointer to the result
 */

char *remove_zeros(char *num)
{
	char *result;
	int i, j, len, start;

	len = _strlen(num);
	start = 0;
	for (i = 0; i < len - 1; i++)
	{
		if (num[i] != '0')
			break;
		start++;
	}
	result = malloc(sizeof(char) * (len - start + 1));
	if (!result)
		return (NULL);
	for (i = start, j = 0; i < len; i++, j++)
		result[j] = num[i];
	result[j] = '\0';
	free(num);
	return (result);
}

/**
 * is_digit - Checks if a string is a digit
 *
 * @str: String
 *
 * Return: 1 if true, 0 if false
 */

int is_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string
 *
 * @str: String
 *
 * Return: Length of the string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * print_error - Prints the error message
 */

void print_error(void)
{
	int i;
	char *error = "Error";

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	_putchar('\n');
}
