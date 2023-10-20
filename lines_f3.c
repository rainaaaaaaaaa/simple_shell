#include "core.h"

/**
 * is_there - checks
 * @c: character
 * @s: dlm
 * Return: boolean
 */
int is_there(char c, char *s)
{
	if (*s == '\0')
		return (c == *s);
	return (c == *s ? 1 : is_there(c, s + 1));
}

/**
 * _strtok1 - string tokenize
 * @s: string
 * @dlm: delim
 * Return: tokens set
 */
char **_strtok1(char *s, char *dlm)
{
	char **tokens;
	size_t j = 0, i, len = _strlen1(s) + 1;
	int found = 1, k = 0;

	tokens = (char **)_calloc1(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc1(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; s[i]; i++)
	{
		if (is_there(s[i], dlm))
		{
			if (!found)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc1(len, sizeof(char));
				if (!tokens[k])
					free1(tokens);
			}
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	if (found)
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}
	else
		tokens[k][j] = '\0';
	return (tokens);
}

/**
 * change_s_s - replaces substring
 * @str: input string
 * @old: old substring
 * @new: input substring
 * Return: command decomposition
 */
void change_s_s(char *str, char *old, char *new)
{
	char *ptr = NULL;
	size_t old_len = _strlen1(old);
	size_t new_len = _strlen1(new);
	size_t k = new_len, l = old_len;

	ptr = _strstr1(str, old);
	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l]);
	ptr[k] = '\0';
	_memcpy1(ptr, new, new_len);
	change_s_s(ptr + new_len, old, new);
}

/**
 * my_atoi - convert a string to an integer
 *@str: string
 * Return: integer
 */

int my_atoi(char *str)
{
	int i;
	int n = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
