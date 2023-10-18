#include "header.h"

/**
 * r_cmd - read command
 * @env: environment variables
 *
 * Return: a pointer
 */
char *r_cmd(__attribute__((unused))char **env)
{
	char *buf;
	size_t j;

	j = 0, buf = NULL;
	if (getline(&buf, &j, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buf), buf = NULL;
		free_std(env), env = NULL;
		exit(0);
	}

	handle_cmnt(buf);
	if (buf && (buf[0] == '\0'))
		buf[0] = '\n';

	return (buf);
}

/**
 * r_arg - read arguments
 * @buf: buffer
 * @env: environment variables
 *
 * Return: an array of args
 */
char **r_arg(char *buf, __attribute__((unused))char **env)
{
	char **args;
	char *token;
	const char *d;
	int m;

	args = malloc(sizeof(char *) * (INPUT_SIZE));
	if (!args)
		perror("Failed to allocate memory for args"), exit(1);

	d = "\t\n ";
	token = _strtok(buf, d);
	m = 0;
	while (token)
	{
		args[m++] = token;
		token = _strtok(0, d);
	}
	for (; m < INPUT_SIZE; m++)
		args[m] = NULL;

	return (args);
}

/**
 * exe_cmd - executes command
 * @args: array arguments
 * @cmnd: command
 * @env: environment variables
 * @exe: executable
 *
 * Return: 1 (Succes) | 0 (Failure)
 */
int exe_cmd(char *cmnd, char **args, char ***env, char *exe)
{
	int (*fct)(char *, char **, char ***);
	char *cmd, *odd;
	int j;

	if (!cmnd || !args || !env || !exe)
	{
		perror("NULL argument to exe_cmd()");
		return (0);
	}
	if (args && !args[0])
		return (1);

	fct = check(args[0]);
	if (fct)
		return (fct(cmd, args, env));

	odd = args[0];
	cmd = all(args[0], *env);
	if (!cmd)
		is_error(NULL, args[0], "not found", NULL), j = 1;
	else
	{
		args[0] = cmd;
		j = _exe(args, *env, exe);
		free(cmd);
		args[0] = odd;
	}
	return (j);
}

/**
 * _exe - execute commands
 * @args: arguments
 * @env: environment variables
 * @exe: executable
 *
 * Return: 1 (Success) | 0 (Failure)
 */
int _exe(char **args, char **env, char *exe)
{
	pid_t my_pid;

	my_pid = fork();
	if (!my_pid)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(exe);
			return (0);
		}
	}
	else if (my_pid < 0)
	{
		perror("Fork fail");
		return (0);
	}
	else
		wait(NULL);
	return (1);
}

/**
 * handle_cpy - handle copy
 * @env: environment variables
 *
 * Return: cp
 */
char **handle_cpy(char **env)
{
	char **cp;
	unsigned int j, siz;

	if (!env)
		return (NULL);

	cp = malloc(sizeof(char *) * length(env));
	if (!cp)
		perror("Can't allocate memory for cp"), exit(1);
	j = 0;
	while (env[j])
	{
		siz = _strlen(env[j]);
		copy[j] = malloc(sizeof(char) * (++siz));
		if (!cp[j])
		{
			free_std(cp);
			perror("Can't allocate memory for cp"), exit(1);
		}
		cp[j] = _strcpy(cp[j], env[j]);
		j++;
	}
	copy[j] = NULL;
	return (cp);
}
