#include "core.h"

/**
 * colon - cast an integer to decimal
 * @n: input number
 * @i: integer
 * Return: string length
 */
int colon(int i, unsigned int n)
{
	char digit;

	if (n >= 10)
		return (colon(i, n / 10) + colon(i, n % 10));
	digit = '0' + n;
	if (i == 1)
		return (write(STDOUT_FILENO, &digit, 1));
	return (write(STDERR_FILENO, &digit, 1));
}
/**
 * put_colon - check code
 * @str: string
 * @i: integer
 * Return: string length
 */
int put_colon(int i, char *str)
{
	if (i == 1)
		return (write(STDOUT_FILENO, str, _strlen1(str)));
	return (write(STDERR_FILENO, str, _strlen1(str)));
}
