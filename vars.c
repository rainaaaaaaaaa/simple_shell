#include "header.h"

/**
 * avar - adds variables
 * @env: environment variables
 * @n: name
 * @v: value
 *
 * Return: new environment list
 */
char **avar(char **env, char *n, char *v)
{
	char *var, **n_env;
	unsigned int j;

	n_env = alloc_space(env);
	if (!n_env)
		perror("Can't allocate space for n_env"), exit(1);

	var = nvar(n, v);
	if (!var)
		perror("Can't allocate space for nvar"), exit(1);

	for (j = 0; n_env[j]; j++)
	{}
	n_env[j] = var;
	return (n_env);
}

/**
 * cvar - changes variables
 * @v: variable
 * @env: environment variables
 * @indx: variable's indx
 *
 * Return: a pointer | NULL
 */
char *cvar(char *v, char **env, int indx)
{
	char *n, *mvar;
	unsigned int i, m;

	if (!v || !env || indx < 0)
		return (NULL);
	n = _name(env[indx]);
	if (!n)
		perror("error while changing varibale"), exit(1);
	mvar = malloc(sizeof(char) * _strlen(n) + _strlen(v) + 2);
	for (i = 0; n[i]; i++)
		mvar[i] = n[i];
	mvar[i++] = '=';
	for (m = 0; v[m]; m++)
		mvar[m++] = v[m];
	mvar[i] = '\0';

	free(n);
	return (mvar);
}

/**
 * _been - checks if an environment variable exists
 * @var: variable
 * @env: environment variables
 *
 * Return: indx in env | -1
 */
int _been(char *var, char **env)
{
	char *n;
	int j;

	for (j = 0; env[j]; j++)
	{
		n = _name(env[j]);
		if (!n)
			perror("error while looking for variable in env"), exit(1);
		if (!_strcmp(n, var))
		{
			free(n);
			return (j);
		}
		free(n);
	}
	return (-1);
}

/**
 * nvar - new environment variable
 * @n: name
 * @v: value
 *
 * Return: string | NULL
 */
char *nvar(char *n, char *v)
{
	char *var;
	size_t i, m;

	var = malloc(sizeof(char) * (_strlen(n) + _strlen(v) + 2));
	if (!var)
		return (NULL);

	for (i = 0; name[i]; i++)
		var[i] = name[i];

	var[i++] = '=';

	for (m = 0; value[m]; m++)
		var[i++] = value[m];

	var[i++] = '\0';

	return (var);
}

/**
 * dvar - delete variables
 * @env: environment variables
 * @indx: varibale's indx at env
 *
 * Return: a pointer | NULL
 */
char **dvar(char **env, int indx)
{
	char **n_env;
	int i, k;

	if (!env || indx < 0)
		return (NULL);

	for (i = 0; env[i]; i++)
	{}
	if (i <= indx)
	{
		return (NULL);
	}

	n_env = malloc(sizeof(char *) * i);
	if (!n_env)
		perror("Can't allocate memory for n_env"), exit(1);
	for (i = 0; i < indx; i++)
	{
		n_env[i] = env[i], env[i] = NULL;
	}

	free(env[i]), env[i] = NULL;
	k = i + 1;
	for (; env[k]; k++)
		n_env[i++] = env[k], env[k] = NULL;

	n_env[i] = NULL;
	return (n_env);
}
