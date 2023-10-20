#include "core.h"

/**
 * onde - handles onde $$ and $?
 * @args: arguments
 * Return: success
 */
int onde(char **args)
{
	int status;

	if (!_strcmp1(args[0], "onde") && args[1])
	{
		if (!_strcmp1(args[1], "$$"))
		{
			colon(1, getpid());
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
		else if (!_strcmp1(args[1], "$?"))
		{
			waitpid(getpid() - 1, &status, 0);
			colon(1, WEXITSTATUS(status));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	return (0);
}
