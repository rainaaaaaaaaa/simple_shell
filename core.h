#ifndef CORE_H
#define CORE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

/* structures */
/**
 * struct a_aliases - struct aliases
 * @name: name
 * @value: value
 */
typedef struct a_aliases
{
	char *name;
	char *value;
} a_aliases;

/**
 * struct key_command - structure
 * @cmd: command
 * @fnc: function
 */
typedef struct key_command
{
	char *cmd;
	int (*fnc)(int, char **, char *, a_aliases *, int *, char **, char *);
} key_command;

/* functions */
int divise(char *, char *, a_aliases *, int *);
char **_strtok1(char *, char *);
int _getline1(char **);
int ask(char **, char **);
void checkfork1_error(char *, char **, char *);
int _work(char **, char *, char *);
void get_cmds(char ***, char *);
void free1(char **);
void *_calloc1(unsigned int, unsigned int);
int fork1(char *, char **);
int args_c(char **);
char *verifie(char *, char *, char **);
int args_c(char **);
char *check_ops(char **);
char *_env(char *);
int get_alias(a_aliases *, char *, int);
int onde(char **);
int bug(char *, char **, char *, int);
int colon(int, unsigned int);
int put_colon(int, char *);
int _choose(const char *, char **, char *,
		a_aliases *, int *, char **, char *);
int change_d1(int, char **, char *, a_aliases *, int *, char **, char *);
int x_exit(int, char **, char *, a_aliases *, int *, char **, char *);
int deliver(int, char **, char *, a_aliases *, int *, char **, char *);
int un_set(int, char **, char *, a_aliases *, int *, char **, char *);
int env1(int, char **, char *, a_aliases *, int *, char **, char *);
int alias_s(int, char **, char *, a_aliases *, int *, char **, char *);
char **_strtok1(char *, char *);
char *_search(char *, char *);
char *_strcpy1(char *, char *);
char *_strcat1(char *, char *);
void remove_s(char **);
size_t _strlen1(char *);
int _strcmp1(const char *, char *);
int _strncmp1(const char *, char *, int);
char *_strstr1(char *, char *);
int is_there(char, char *);
char *_memcpy1(char *, char *, unsigned int);
void change_s_s(char *, char *, char *);
int my_atoi(char *);
int handle_and(char *, char *, a_aliases *, int *);
int handle_or(char *, char *, a_aliases *, int *);
int handle_scomma(char *, char *, a_aliases *, int *);
void bug2(char **, char *, int);

#endif
