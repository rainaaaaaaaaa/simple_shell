#include "core.h"

/**
 * _strlen1 - string length
 *@s: string
 * Return: length
 */

size_t _strlen1(char *s)
{
	if (!s || *s == '\0')
		return (0);
	return (1 + _strlen1(s + 1));
}

/**
 * _strcmp1 - compares strings
 *@s1: first string
 *@s2: second string
 *Return: integer
 */
int _strcmp1(const char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}
/**
 * _strncmp1 - compares n characters
 * @s1: first string
 * @s2: second string
 * @n: number
 * Return: integer
 */
int _strncmp1(const char *s1, char *s2, int n)
{
	for (; n && *s1 == *s2; n--, s1++, s2++)
		;
	if (n)
		return (*s1 - *s2);
	return (0);
}
/**
 * _strstr1 - locates string
 * @sea: string
 * @fish: string
 * Return: location or NULL
 */

char *_strstr1(char *sea, char *fish)
{
	int i, j;

	if (*sea == '\0' && *fish == '\0')
		return (NULL);
	for (i = 0; sea[i] != '\0'; i++)
	{
		for (j = 0; fish[j] != '\0'; j++)
		{
			if (fish[j] != sea[i + j])
				break;
		}
		if (fish[j] == '\0')
			return (&sea[i]);
	}
	return (NULL);
}
/**
 * _memcpy1 - copies memory area
 * @dest: destination
 * @src: source
 * @n: bytes
 * Return: dest
 */
char *_memcpy1(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
