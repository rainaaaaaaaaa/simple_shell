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
