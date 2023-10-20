#include "core.h"

/**
 * _search - searches
 * @s: string
 * @acc: characters
 * Return: number or 0
 */
char *_search(char *s, char *acc)
{
	int i, j;

	if (*s == '\0' && *acc == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; acc[j] != '\0'; j++)
		{
			if (s[i] == acc[j])
				break;
		}
		if (acc[j] != '\0')
			break;
	}
	if (s[i] != '\0')
		return (&s[i]);
	return (0);
}

/**
 * _strcpy1 - copies strings
 *@src: source
 *@dest: destination
 * Return: string
 */
char *_strcpy1(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat1 - concatenates two strings
 *@src: source
 *@dest: destination
 *Return: dest
 */
char *_strcat1(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * remove_s - removes the first character of a string
 * @s: string
 */
void remove_s(char **s)
{
	int i;

	for (i = 0; (*s)[i]; i++)
		(*s)[i] = (*s)[i + 1];
}
