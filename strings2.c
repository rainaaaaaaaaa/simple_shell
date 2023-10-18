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
 * _strtok - break string into multiple tokens
 * @s: given string
 * @del: delimeter
 * Description: _strtok function breaks a string into a sequence of zero or
 * more nonempty tokens
 *
 * Return: pointer to next token | NULL if there is no more tokens
 */
char *_strtok(char *s, const char *del)
{
	static char *t;
	char *tok;

	if (s)
		t = s;
	while (*t && is_del(*t, del))
		*t = '\0', t++;
	tok = t;
	if (!(*tok))
		return (NULL);
	while (*t && !is_del(*t, del))
		t++;

	if (*t)
		*t = '\0', t++;
	return (tok);
}
