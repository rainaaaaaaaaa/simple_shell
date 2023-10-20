#include "core.h"

/**
 * _choose - checks for builin functions
 * @cmd: command name
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @indx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int _choose(const char *cmd, char **args,
		char *name, a_aliases *alias, int *indx, char **split, char *line)
{
	key_command _works[] = {
		{"exit", x_exit},
		{"cd", change_d1},
		{"setenv", deliver},
		{"unsetenv", un_set},
		{"env", env1},
		{"alias", alias_s},
		{NULL, NULL}
	};
	int j = 0;

	while (_works[j].fnc != NULL && _strcmp1(cmd, _works[j].cmd) != 0)
		j++;
	if (_works[j].fnc != NULL)
		return (_works[j].fnc(args_c(args), args,
					name, alias, indx, split, line));
	return (-1);
}

/**
 * args_c - counts number of args
 * @args: arguments
 * Return: argc
 */
int args_c(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_c(args + 1));
}
