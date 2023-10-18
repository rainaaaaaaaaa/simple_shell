#include "header.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0
 */
int main(__attribute__((unused))int argc, char **argv[], char **env)
{
	char *cmd, **args, **env_v;
	int j;

	env_v = handle_cpy(env);

	is_error(argv[0], NULL, NULL, NULL);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);

		cmd = r_cmd(env_v);
		args = r_arg(cmd, env_v);
		j = exe_cmd(cmd, args, &env_v, argv[0]);
		if (cmd)
			free(cmd);
		if (args)
			free(args);
		}
	}
	free_std(env_v);
	return (0);
}

/**
 * cd - changes dectory
 * @cmnd: entered command
 * @arg: arguments
 * @env: environment variables
 *
 * Return: always 1
 */
int cd(__attribute__((unused))char *cmnd, char **arg, char ***env)
{
	char *d, *r;
	char odd[100];
	size_t i;

	if (arg && arg[0] && !arg[1])
		d = interface(*env, "HOME");
	else if (arg && arg[0] && !_strcmp(arg[1], "-") && !arg[2])
		d = interface(*env, "OLDPWD");
	else
		d = cp(arg[1]);

	i = 100, r = getcwd(odd, i);
	if (!r)
		perror("Can't get current working dectory");
	if (!d)
		is_error(NULL, arg[0], "can't cd to OLDPWD", NULL);
	else if (chd(d) == -1)
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
