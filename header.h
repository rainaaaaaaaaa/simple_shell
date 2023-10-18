#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ALIAS_COUNT 50
#define MAX_ALIAS_NAME 50
#define MAX_ALIAS_VALUE 100

extern char **environ;
int exit_status;
int last_command_status;

typedef struct Alias {
    char name[MAX_ALIAS_NAME];
    char value[MAX_ALIAS_VALUE];
} Alias;

Alias aliases[MAX_ALIAS_COUNT];
int alias_count;

int find_alias(const char *alias_name);
void list_all_aliases();
void list_selected_aliases(const char *alias_names);
void define_alias(const char *alias_name, const char *alias_value);
char *replace_variables(const char *command);
int execute_command(const char *command);
int _strlen(char *s);
int strncmp(const char *s1, const char *s2, size_t n);
char *strchr(const char *str, int c);
size_t strcspn(const char *str, const char *reject);

#endif
