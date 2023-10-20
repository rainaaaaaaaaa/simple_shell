#include "core.h"

/**
 * fork1 - forks process
 * @name: command name
 * @arr: arguments
 * Return: success
 */
int fork1(char *name, char **arr)
{
	pid_t pid;
	int status, success = 1;
	char *path = NULL;

	path = verifie(arr[0], name, arr);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			success = _work(arr, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		free(path);
	}
	else
	{
		bug(name, arr, NULL, 1);
		success = 0;
	}
	return (success);
}
