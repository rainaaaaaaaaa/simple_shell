#include "core.h"

/**
 * check_alias - checks for a_aliases
 * @arr: arguments
 * @alias: alias array
 * @indx: integer
 * Return: none
 */
void check_alias(char ***arr, a_aliases *alias, int indx)
{
	int i, n;

	for (i = 0; (*arr)[i]; i++)
	{
		n = get_alias(alias, (*arr)[i], indx);
		if (n != -1)
		{
			(*arr)[i] = NULL;
			(*arr)[i] = malloc(_strlen1(alias[n].value) + 1);
			_strcpy1((*arr)[i], alias[n].value);
		}
	}
}
/**
 * handle_and - handles &&
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @indx: integer
 * Return: integer
 */
int handle_and(char *line, char *name, a_aliases *alias, int *indx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok1(line, "&\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok1(line_split[i], " \t");
		if (args_c(arr) == 0)
		{
			free1(arr);
			free1(line_split);
			return (bug(name, NULL, NULL, 7));
		}
		free1(arr);
	}
	for (i = 0; line_split[i]; i++)
	{
		break_condition = 0;
		arr = _strtok1(line_split[i], " \t");
		if (_strcmp1(arr[0], "alias"))
			check_alias(&arr, alias, *indx);
		argc = args_c(arr);
		selector = _choose(arr[0], arr, name, alias, indx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = 1 - fork1(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		if (break_condition)
		{
			free1(arr);
			break;
		}
		free1(arr);
	}
	free1(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * handle_or - handles ||
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @indx: integer
 * Return: integer
 */
int handle_or(char *line, char *name, a_aliases *alias, int *indx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok1(line, "|\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok1(line_split[i], " \t");
		if (args_c(arr) == 0)
		{
			free1(arr);
			free1(line_split);
			return (bug(name, NULL, NULL, 8));
		}
		free1(arr);
	}
	i = 0;
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok1(line_split[i], " \t");
		if (_strcmp1(arr[0], "alias"))
			check_alias(&arr, alias, *indx);
		break_condition = 0;
		argc = args_c(arr);
		selector = _choose(arr[0], arr, name, alias, indx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = fork1(name, arr);
		else if (argc > 0)
			break_condition = selector;
		if (break_condition)
		{
			free1(arr);
			break;
		}
		free1(arr);
	}
	free1(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}

/**
 * handle_scomma - handles ;
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @indx: integer
 * Return: integer
 */
int handle_scomma(char *line, char *name, a_aliases *alias, int *indx)
{
	char **arr, **line_split;
	int argc, i = 0, frk = 0;

	line_split = _strtok1(line, ";\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok1(line_split[i], " \t");
		if (args_c(arr) == 0)
		{
			free1(arr);
			free1(line_split);
			return (bug(name, NULL, NULL, 9));
		}
		free1(arr);
	}
	free1(line_split);
	line_split = _strtok1(line, "@;\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok1(line_split[i], " \t");
		if (_strstr1(line, "alias"))
			check_alias(&arr, alias, *indx);
		argc = args_c(arr);
		if (argc > 0 && _choose(arr[0], arr,
					name, alias, indx, line_split, line) < 0)
			fork1(name, arr);
		else if (!_strstr1(line, "@") && argc == 0)
		{
			free1(line_split);
			free1(arr);
			return (bug(name, NULL, NULL, 9));
		}
		free1(arr);
	}
	free1(line_split);
	return (frk ? EXIT_FAILURE : 0);
}

/**
 * divise - reads command line (input)
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @indx: integer
 * Return: integer
 */
int divise(char *line, char *name, a_aliases *alias, int *indx)
{
	size_t old_len;
	size_t new_len;

	while (*line == ' ' || *line == '\t')
		remove_s(&line);
	old_len = _strlen1(line);
	if (old_len == 1)
		return (0);
	change_s_s(line, "&&", "&");
	new_len = _strlen1(line);
	if (new_len < old_len)
	{
		change_s_s(line, "&&", "&");
		if (_strlen1(line) < new_len)
			return (bug(name, NULL, NULL, 7));
		return (handle_and(line, name, alias, indx));
	}
	change_s_s(line, "||", "|");
	new_len = _strlen1(line);
	if (new_len < old_len)
	{
		change_s_s(line, "||", "|");
		if (_strlen1(line) < new_len)
			return (bug(name, NULL, NULL, 8));
		return (handle_or(line, name, alias, indx));
	}
	if (_strstr1(line, ";;"))
		return (bug(name, NULL, NULL, 9));
	change_s_s(line, "\n", "@");
	return (handle_scomma(line, name, alias, indx));
}
