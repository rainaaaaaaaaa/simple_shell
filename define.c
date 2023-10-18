#include "header.h"

/**
 * _setenv - sets a new environment variable or change an existing one
 * @cmnd: command
 * @args: arguments
 * @env: environment variables
 *
 * Return: always 1
 */

int _setenv(char *cmnd, char **args, char ***env)
{
	int j;
	char **n_env;
	char *val;

	if (!cmnd || !args || !env)
		perror("NULL argument to _setenv()"), exit(1);

	if (!args[0] || !args[1] || !args[2] || args[3])
	{
		is_error(NULL, NULL, "Bad variable n", NULL);
		return (1);
	}

	j = _been(args[1], *env);
	if (j >= 0)
	{
		val = cvar(args[2], *env, j);
		free((*env)[j]);
		(*env)[j] = val;
	}
	else
	{
		n_env = avar(*env, args[1], args[2]);
		free(*env), *env = NULL;
		*env = n_env;
	}

	return (1);
}

/**
 * _unsetenv - remove an environment variable
 * @cmnd: command
 * @args: arguments
 * @env: environment variables
 *
 * Return: always 1
 */
int _unsetenv(char *cmnd, char **args, char ***env)
{
	int i;
	char **n_env;

	if (!cmnd || !args || !env)
		perror("NULL argument to _unsetenv()"), exit(1);

	if (!args[0] || !args[1] || args[2])
	{
		is_error(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}

	i = _been(args[1], *env);
	if (i < 0)
	{
		is_error(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}
	n_env = dvar(*env, i);
	free(*env), *env = NULL;
	*env = n_env;

	return (1);

}

/**
 * allocate - allocate space
 * @env: environment variable
 *
 * Return: n_env | NULL
 */
char **allocate(char **env)
{
	char **n_env;
	unsigned int i;

	for (i = 0; env[i]; i++)
	{}
	n_env = malloc(sizeof(char *) * (i + 2));
	if (!n_env)
		return (NULL);
	for (i = 0; env[i]; i++)
	{
		n_env[i] = env[i];
		env[i] = NULL;
	}
	n_env[i++] = NULL, n_env[i] = NULL;

	return (n_env);
}

/**
 * _name - gets the variable's name
 * @env: environment variable
 *
 * Return: n | NULL
 */
char *_name(char *env)
{
	unsigned int i;
	char *n;

	if (!env)
		perror("NULL argument to _name()"), exit(1);
	for (i = 0; env[i] && env[i] != '='; i++)
	{}
	if (!env[i])
		return (NULL);
	n = malloc(sizeof(char) * (++i));
	for (i = 0; env[i] && env[i] != '='; i++)
		n[i] = env[i];
	n[i] = '\0';
	return (n);
}
