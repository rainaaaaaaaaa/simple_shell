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


#define INPUT_SIZE 1024

/*
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
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);
size_t strcspn(const char *str, const char *reject);*/

/**
 * struct built_s - specify which builtin to execute
 * @cmmd: command
 * @fct: function pointer
 */
typedef struct built_s
{
	char *cmmd;
	int (*fct)(char *, char **, char ***);
} built_t;

int (*check(char *))(char *, char **, char ***);

/* Take input - Split it into arguments - Execute command */
char *r_cmd(char **);
char **r_arg(char *, char **);
int exe_cmd(char *, char **, char ***, char *);

/* Functions to handle commands */
char *_path(char **);
char **handle_cpy(char **);
char *_cmd(char *, char *);
char *define_path(char *, char *);
void _buff(char *, char *);
ssize_t _getline(char **, size_t *, int);
int _exe(char **, char **, char *);
char *all(char *, char **);

/* Builtins' functions */
int _env(char *, char **, char ***);
int _exit(char *, char **, char ***);
int _setenv(char *, char **, char ***);
int _unsetenv(char *, char **, char ***);
int _cd(char *, char **, char ***);

/* related to builtins */
char *_name(char *);
int _been(char *, char **);
char *cvar(char *, char **, int);
char **avar(char **, char *, char *);
char **allocate(char **);
char *nvar(char *, char *);
char **dvar(char **, int);
char *var(char **, char *);
char *_define(char *);
char *interface(char **, char *);
int _pwd(char **);
int _oldpwd(char **, char *);

/* Helper functions similar to those of the C Standard Library */
void free_std(char **);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcpy(char *, char *);
int _atoi(char *);
size_t length(char **);
int is_like(char *, char *);
char *_copy(char *);

/* Display error functions */
void is_error(char *, char *, char *, char *);
unsigned int p_exec(char *, char *, int);
unsigned int add_cmd(char *, char *, unsigned int);
unsigned int _error(char *, char *, unsigned int);
unsigned int _more(char *, char *, char, unsigned int);

/*ADDED*/
int _cmpr(char c, const char *b);
char *_strtok(char *str, const char *d);
char *handle_cmnt(char *buf)

#endif
