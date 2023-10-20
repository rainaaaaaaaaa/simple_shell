#include "core.h"

/**
 * alias_s - takes care of a_aliases
 * @argc: arguments count
 * @args: arguments arr
 * @name: program name
 * @alias: alias struct, contains name and value
 * @indx: number of a_aliases
 * @split: split line
 * @line: line
 * Return: success
 */
int alias_s(int argc, char **args, char *name,
		a_aliases *alias, int *indx, char **split, char *line)
{
	char **al;
	int i, j;

	(void) name;
	(void) split;
	(void) line;
	if (argc == 1)
	{
		for (i = 0; *indx && i < *indx; i++)
		{
			put_colon(1, alias[i].name), put_colon(1, "='");
			put_colon(1, alias[i].value), put_colon(1, "'\n");
		}
	}
	for (i = 1; i < argc; i++)
	{
		al = _strtok1(args[i], "'="), j = get_alias(alias, al[0], *indx);
		if (!_strstr1(args[i], "="))
		{
			if (j != -1)
			{
				put_colon(1, alias[j].name), put_colon(1, "='");
				put_colon(1, alias[j].value), put_colon(1, "'\n");
			} else
				bug(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen1(al[1]) + 1 + _strlen1("''"));
			_strcpy1(alias[j].value, al[1]);
		}
		else
		{
			alias[*indx].name = malloc(_strlen1(al[0]) + 1);
			alias[*indx].value = malloc(_strlen1(al[1]) + 1 + _strlen1("''"));
			_strcpy1(alias[*indx].name, al[0]);
			_strcpy1(alias[*indx].value, al[1]), (*indx)++;
		}
	}
	return (1);
}
