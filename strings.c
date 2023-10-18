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


