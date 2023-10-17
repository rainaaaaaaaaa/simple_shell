#include "header.h"

/**
 * *strchr - string characters
 * @str: the string
 * @n: input
 * Return: NULL
 */
char *strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return ((char *)str);
        }
        str++;
    }
    return (NULL);
}

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
