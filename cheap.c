#include "core.h"
/**
 * free1 - frees array of strings
 * @arr: arr
 */
void free1(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
/**
 * _calloc1 - allocates memory for an array, using malloc.
 * @nmemb: number of members
 * @size: size
 * Return: pointer or NULL
 */

void *_calloc1(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		p[i] = 0;
	return (p);
}
