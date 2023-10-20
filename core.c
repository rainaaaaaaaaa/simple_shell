#include "core.h"

/**
 * main - Entry point
 * @argc: argument's count
 * @args: argument's set
 * Return: Always 0
 */
int main(int argc, char **args)
{
	a_aliases alias;
	int indx = 0, r_val = 0;
	char *input = NULL, *name = args[0], *temp = NULL;

	(void) argc;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0) && argc == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (argc == 1 && _getline1(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(r_val);
		}
		else if (argc != 1 && ask(&input, args) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(r_val);
		}
		temp = _strstr1(input, "#");
		if (temp)
			*temp = '\0';
		if (*input != '\0' && _strcmp1(input, "\n"))
		{
			bug(name, NULL, NULL, 0);
			r_val = divise(input, name, &alias, &indx);
		}
		free(input);
		if (argc != 1)
			return (0);
	}
}
