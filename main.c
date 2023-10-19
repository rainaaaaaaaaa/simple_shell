#include "header.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv, char **env)
{
	char *buf = NULL;
	size_t bufsize = 0;
	char **args;
	ssize_t characters;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		characters = getline(&buf, &bufsize, stdin);
		if (characters == -1)
		{
			free(buf);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (characters > 0 && buf[0] != '\n')
		{
			args = r_arg(buf, env);
			if (!exe_cmd(args[0], args, &env, NULL))
				perror("Command execution failed");
			free(args);
		}
		free(buf);
		buf = NULL;
		bufsize = 0;
	}
	return (0);
}

/**
 * _cd - changes dectory
 * @cmnd: entered command
 * @arg: arguments
 * @env: environment variables
 *
 * Return: always 1
 */
int _cd(__attribute__((unused))char *cmnd, char **arg, char ***env)
{
	char *d, *r;
	char odd[100];
	size_t i;

	if (arg && arg[0] && !arg[1])
		d = interface(*env, "HOME");
	else if (arg && arg[0] && !_strcmp(arg[1], "-") && !arg[2])
		d = interface(*env, "OLDPWD");
	else
		d = _cp(arg[1]);

	i = 100, r = getcwd(odd, i);
	if (!r)
		perror("Can't get current working dectory");
	if (!d)
		is_error(NULL, arg[0], "can't cd to OLDPWD", NULL);
	else if (chdir(d) == -1)
		is_error(NULL, arg[0], "can't cd to ", d);
	else
		_pwd(*env), _oldpwd(*env, odd);

	free(d);
	return (1);
}

/**
 * _pwd - updates PWD
 * @env: environment variables
 *
 * Return: 1 | -1
 */
int _pwd(char **env)
{
	char cwd[100], *d;
	size_t i;

	i = 100, getcwd(cwd, i);
	for (i = 0; env[i]; i++)
		if (is_like(env[i], "PWD"))
			break;
	if (!env[i])
		return (-1);
	d = cvar(cwd, env, i);
	free(env[i]);
	env[i] = d;
	return (1);
}

/**
 * _oldpwd - updates OLDPWD
 * @env: environment variables
 * @value: value
 *
 * Return: 1 | -1
 */
int _oldpwd(char **env, char *value)
{
	char *d;
	unsigned int i;

	for (i = 0; env[i]; i++)
		if (is_like(env[i], "OLDPWD"))
			break;
	if (!env[i])
		return (-1);
	d = cvar(value, env, i);
	free(env[i]);
	env[i] = d;
	return (1);
}
