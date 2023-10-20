#include "core.h"

/**
 * x_exit - function to exit
 * @n: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int x_exit(int n, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	int i = 0;

	(void) alias;
	(void) indx;
	for (; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			bug(name, args, NULL, 2);
			return (0);
		}
	}
	if (n > 1)
		i = my_atoi(args[1]);
	free1(split);
	free(line);
	free1(args);
	exit(i);
	return (1);
}
/**
 * change_d1 - handles cd
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int change_d1(int argc, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	char *path, *temp;

	(void) alias;
	(void) indx;
	(void) line;
	(void) split;
	path = argc == 1 || _strcmp1(args[1], "~") == 0 ? _env("HOME") : args[1];
	if (chdir(path) < 0)
	{
		bug(name, args, path, 3);
		return (0);
	}
	temp = _env("PWD");
	_strcpy1(temp, path);
	if (argc == 1)
	{
		put_colon(1, path);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/**
 * deliver - handles setenv
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int deliver(int argc, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	int i = 0;
	char *temp = NULL;

	(void) alias;
	(void) indx;
	(void) split;
	(void) line;
	if (argc != 3)
	{
		bug(name, args, NULL, 4);
		return (0);
	}
	else
	{
		temp = _env(args[1]);
		if (temp)
			_strcpy1(temp, args[2]);
		else
		{
			while (environ[i])
				i++;
			environ[i] = _calloc1(_strlen1(args[1]) + _strlen1(args[2]) + 3, 1);
			_strcat1(environ[i], args[1]);
			_strcat1(environ[i], "=");
			_strcat1(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}
/**
 * un_set - handles unsetenv
 * @argc: arguments count
 * @args: arguments
 * @name: name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int un_set(int argc, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	int i;

	(void) alias;
	(void) indx;
	(void) split;
	(void) line;
	if (argc != 2)
	{
		bug(name, args, NULL, 5);
		return (0);
	}
	else if (_env(args[1]) == NULL)
	{
		bug(name, args, NULL, 6);
		return (0);
	}
	else
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp1(environ[i], args[1], _strlen1(args[1])) == 0)
			{
				free(environ[i]);
				break;
			}
		}
		return (1);
	}
}
/**
 * env1 - handles and prints env1
 * @argc: argc
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int env1(int argc, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	int i;

	(void) argc;
	(void) args;
	(void) name;
	(void) split;
	(void) alias;
	(void) indx;
	(void) line;
	for (i = 0; environ[i]; i++)
	{
		put_colon(1, environ[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
