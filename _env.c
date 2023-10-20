#include "core.h"

/**
 * _env - retrieves enviromental variables
 * @var: variable name
 * Return: string
 */
char *_env(char *var)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp1(var, environ[i], _strlen1(var)))
		{
			temp = _strstr1(environ[i], "=");
			temp++;
			return (temp);
		}
	}
	return (NULL);
}
/**
 * get_alias -retrieve a_aliases
 * @alias: a_aliases
 * @var: variable name
 * @indx: index
 * Return: string
 */
int get_alias(a_aliases *alias, char *var, int indx)
{
	int i;

	for (i = 0; i < indx; i++)
	{
		if (!_strcmp1(var, alias[i].name))
			return (i);
	}
	return (-1);
}
