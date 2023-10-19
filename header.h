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

int (*check(char *cmnd))(char *, char **, char ***);

/* Take input - Split it into arguments - Execute command */
char *r_cmd(char **env);
char **r_arg(char *buf, __attribute__((unused))char **env);
int exe_cmd(char *cmnd, char **args, char ***env, char *exe);

/* Functions to handle commands */
char *_path(char **env);
char **handle_cpy(char **env);
char *_cmd(char *cmnd, char *path);
char *define_path(char *d, char *x);
void _buff(char *, char *);
ssize_t _getline(char **, size_t *, int);
int _exe(char **args, char **env, char *exe);
char *all(char *cmd, char **env);

/* Builtins' functions */
int _env(char *cmnd, char **args, char ***env);
int xexit(char *cmnd, char **args, char ***env);
int _setenv(char *cmnd, char **args, char ***env);
int _unsetenv(char *cmnd, char **args, char ***env);
int _cd(char *, char **, char ***);

/* related to builtins */
char *_name(char *env);
int _been(char *var, char **env);
char *cvar(char *v, char **env, int indx);
char **avar(char **env, char *n, char *v);
char **allocate(char **env);
char *nvar(char *n, char *v);
char **dvar(char **env, int indx);
char *var(char **env, char *v);
char *take(char *h);
char *interface(char **env, char *v);
int _pwd(char **env);
int _oldpwd(char **env, char *value);

/* Helper functions similar to those of the C Standard Library */
void free_std(char **ar);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *m);
size_t length(char **);
int is_like(char *str1, char *str2);
char *_cp(char *);

/* Display error functions */
void is_error(char *exc, char *cmnd, char *err, char *txt);
unsigned int p_exec(char *buf, char *x, int n);
unsigned int add_cmd(char *buf, char *cmnd, unsigned int i);
unsigned int _error(char *buf, char *err, unsigned int i);
unsigned int _more(char *buf, char *txt, char indx, unsigned int i);

/*ADDED*/
int _cmpr(char c, const char *b);
char *_strtok(char *str, const char *d);
char *handle_cmnt(char *buf);

#endif
