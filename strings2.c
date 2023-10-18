#include "header.h"

/**
 * strcspn - calculates the length of a string
 * @str: the string
 * @reject: input
 * Return: count
 */
size_t strcspn(const char *str, const char *reject) {
    size_t count = 0;
    bool found = false;

    while (*str) {
        const char *reject_ptr = reject;
        found = false;

        while (*reject_ptr) {
            if (*str == *reject_ptr) {
                found = true;
                break;
            }
            reject_ptr++;
        }

        if (found) {
            break;
        }

        count++;
        str++;
    }

    return (count);
}

/**
 * _cmpr - compare
 * @c: charater
 * @b: bytes
 *
 * Return: 1 if found a match, 0 otherwise
 */
int _cmpr(char c, const char *b)
{
	int j;

	for (j = 0; b[j]; j++)
	{
		if (c == b[j])
			return (1);
	}
	return (0);
}

/**
 * _strtok - break strings
 * @str: string
 * @d: delimeter
 *
 * Return: pointer to next token,NULL if otherwise
 */
char *_strtok(char *str, const char *d)
{
	static char *c;
	char *token;

	if (str)
		c = str;
	while (*c && _cmpr(*c, d))
		*c = '\0', c++;
	token = c;
	if (!(*token))
		return (NULL);
	while (*c && !_cmpr(*c, d))
		c++;

	if (*c)
		*c = '\0', c++;
	return (token);
}

/**
 * handle_cmnt - Handle comments
 * @buf: buffer
 * Return: buf
 */
char *handle_cmnt(char *buf)
{
	unsigned int j;

	for (j = 0; buf[j]; j++)
		if (buf[j] == '#')
			break;
	for (; buf[j]; j++)
		buf[j] = '\0';
	return (buf);
}

/**
 * length - get length
 * @ar: array
 *
 * Return: length
 */
size_t length(char **ar)
{
	size_t j;

	j = 0;
	while (ar[j])
		j++;
	return (++j);
}
