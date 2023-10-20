#include "core.h"

/**
 * verifie - checks if a command is valid
 * @comm: command
 * @name: name
 * @arr: arr
 * Return: string
 */
char *verifie(char *comm, char *name, char **arr)
{
	int i;
	struct stat buf;
	char *path, **path_arr = NULL, *env1;

	env1 = _env("PATH");
	if (!env1)
	{
		if (!access(comm, X_OK) && stat(comm, &buf) == 0)
			return (comm);
		return (NULL);
	}
	else if (*env1 == '\0')
	{
		bug(name, arr, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else
		path_arr = _strtok1(env1, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (!_strstr1(comm, "/"))
		{
			path = malloc(_strlen1(path_arr[i]) + _strlen1(comm) + 3);
			_strcpy1(path, path_arr[i]);
			_strcat1(path, "/");
			_strcat1(path, comm);
		}
		else
			path = malloc(_strlen1(comm) + 2), _strcpy1(path, comm);
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			free1(path_arr);
			return (path);
		}
		free(path);
	}
	free1(path_arr);
	return (NULL);
}
