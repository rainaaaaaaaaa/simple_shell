#include "header.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
	length++;
	return (length);
}

/**
 * *_strcpy - Write a function that copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @src: the string
 * @dest: the buffer
 * Return: the pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}

/**
 * _strcmp - Write a function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: -15 if s1 < s2, 15 if s1 > s2, 0 if otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strchr - locates a character in a string
 * @s: the string
 * @c: the character
 * Return: a pointer to the first occurrence of the character c,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	int p;

	for (p = 0; s[p] >= '\0'; p++)
	{
	if (s[p] == c)
	return (s + p);
	}
	return (NULL);
}

/**
 * strncmp - compare strings
 * @s1: first string
 * @s2: second string
 * @n: input
 * Return: integer
 */
int strncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}
