#include "core.h"

/**
 * _work - executes commands
 * @arr: argument array
 * @name: name
 * @path: path
 * Return: success
 */
int _work(char **arr, char *name, char *path)
{
	int i = 0, success = 1;
	char *env1;

	(void) name;
	if (arr)
	{
		i = onde(arr);
		if (i == 0 && arr[1] && arr[1][0] == '$')
		{
			env1 = _env(arr[1] + 1);
			if (env1)
			{
				arr[1] = malloc(sizeof(env1));
				_strcpy1(arr[1], env1);
			}
			else
			{
				write(STDOUT_FILENO, "\n", 1);
				return (1);
			}
		}
		if (i == 0)
		{
			if (execve(path, arr, environ) == -1)
				success = 0;
		}
		free1(arr);
	}
	return (success);
}
