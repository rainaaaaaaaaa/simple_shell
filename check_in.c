#include "header.h"

/**
 * check - check for commands
 * @cmnd: command
 *
 * Return: function pointer | NULL
 */
int (*check(char *cmnd))(char *, char **, char ***)
{
	built_t list[] = {
		{"env", _env},
		{"exit", xexit},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{NULL, NULL}
	};
	int j;

	for (j = 0; list[j].cmmd; j++)
		if (!_strcmp(cmnd, list[j].cmmd))
			return (list[j].fct);
	return (NULL);
}

/**
 * _env - print environment variables
 * @cmnd: command
 * @args: arguments
 * @env: environment variables
 *
 * Return: always 1
 */
int _env(char *cmnd, char **args, char ***env)
{
	int j;

	if (!cmnd || !args || !env)
		perror("NULL arument to _env()"), exit(1);

	for (j = 0; (*env)[j]; j++)
	{
		write(STDOUT_FILENO, (*env)[j], _strlen((*env)[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * _atoi - converts numbers
 * @m: number
 *
 * Return: number
 */
int _atoi(char *m)
{
	unsigned int x, num;
	int j;

	num = j = 0;
	while (m[j])
	{
		if (m[j] < '0' || m[j] > '9')
			return (-1);
		j++;
	}
	--j;
	x = 1;
	while (j >= 0)
	{
		num += (m[j] - 48) * x;
		x *= 10;
		j--;
	}
	return (num);
}

/**
 * xexit - exit status
 * @cmnd: command
 * @args: arguments
 * @env: environment variables
 *
 * Return: 1
 */
int xexit(char *cmnd, char **args, char ***env)
{
	int stat;

	if (!cmnd || !args || !env)
		perror("NULL arument to _env()"), exit(1);

	if (!args[1])
		stat = 0;
	else
	{
		stat = _atoi(args[1]);
		if (stat == -1)
		{
			is_error(NULL, cmnd, "Illegal number", args[1]);
			return (1);
		}
	}
	free(cmnd), free(args), free_std(*env);
	exit(stat);
	return (1);
}
