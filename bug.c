#include "core.h"

/**
 * bug2 - prints bug msgs to stderr (part 2)
 * @args: args
 * @path: path
 * @n: bug index
 */
void bug2(char **args, char *path, int n)
{
	char semi = ';';

	if (n == 5)
		put_colon(2, "usage: unsetenv VARIABLE VALUE");
	else if (n == 6)
	{
		put_colon(2, "environment variable ");
		put_colon(2, args[1]);
		put_colon(2, " not found");
	}
	else if (n == 7)
		put_colon(2, "Syntax bug: \"&\" unexpected");
	else if (n == 8)
		put_colon(2, "Syntax bug: \"|\" unexpected");
	else if (n == 9)
	{
		put_colon(2, "Syntax bug: \"");
		write(STDERR_FILENO, &semi, 1);
		write(STDERR_FILENO, &semi, 1);
		put_colon(2, "\" unexpected");
	}
	else if (n == 10)
	{
		put_colon(2, "alias: ");
		put_colon(2, path);
		put_colon(2, " not found");
	}
}

/**
 * bug - prints bug msgs to stderr (part 1)
 * @name: name
 * @args: args
 * @path: path
 * @n: bug index
 * Return: value
 */
int bug(char *name, char **args, char *path, int n)
{
	static unsigned int i;

	if (!n)
	{
		i++;
		return (0);
	}
	if (n == 11)
	{
		put_colon(2, name);
		put_colon(2, ": 0: Can't open ");
		put_colon(2, args[1]);
		write(STDERR_FILENO, "\n", 1);
		return (EXIT_FAILURE);
	}
	put_colon(2, name);
	put_colon(2, ": ");
	colon(2, i);
	put_colon(2, ": ");
	if (n == 1)
	{
		put_colon(2, args[0]);
		put_colon(2, ": not found");
	}
	else if (n == 2)
	{
		put_colon(2, "exit: Illegal number: ");
		put_colon(2, args[1]);
	}
	else if (n == 3)
	{
		put_colon(2, "cd: can't cd to ");
		put_colon(2, path);
	}
	else if (n == 4)
		put_colon(2, "usage: setenv VARIABLE VALUE");
	else
		bug2(args, path, n);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
