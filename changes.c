#include "header.h"

/**
 * is_like - check two strings are identical
 * @str1: first string
 * @str2: second string
 *
 * Return: 1 | 0
 */
int is_like(char *str1, char *str2)
{
	unsigned int i;

	if (!str1 || !str2)
		return (0);

	for (i = 0; str1[i] && str2[i]; i++)
		if (str1[i] != str2[i])
			return (0);
	if (!str1[i] || !str2[i])
		return (1);

	return (0);
}

/**
 * var - get string variables
 * @env: environment variables
 * @v: variable
 *
 * Return: HOME (Success) | NULL (Failure)
 */
char *var(char **env, char *v)
{
	unsigned int j;

	for (j = 0; env[j]; j++)
	{
		if (is_like(env[j], v))
			return (env[j]);
	}
	return (NULL);
}

/**
 * take - gets HOME
 * @h: home
 *
 * Return: HOME value
 */
char *take(char *h)
{
	char *d;
	unsigned int i, j;

	for (i = 0; h[i]; i++)
	{}
	d = malloc(sizeof(char) * (i - 4));
	if (!d)
		perror("Can't allocate memory for d"), exit(1);
	j = 0;
	for (i = 0; h[i]; i++)
		if (h[i] == '=')
			break;
	for (++i; h[i]; i++)
		d[j++] = h[i];
	d[j] = '\0';

	return (d);
}

/**
 * interface - gets an environment variable value
 * @env: environment variables
 * @v: variable
 *
 * Return: home directory| NULL
 */
char *interface(char **env, char *v)
{
	char *d, *z;

	if (!env)
		return (NULL);
	z = var(env, v);
	if (!z)
		return (NULL);
	d = take(z);

	return (d);
}
