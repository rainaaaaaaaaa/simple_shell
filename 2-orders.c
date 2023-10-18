#include "header.h"

/**
 * all - gets full path
 * @cmd: command
 * @env: environment variables
 *
 * Return: pointer
 */
char *all(char *cmd, char **env)
{
	char **env_cpy;
	char *a_cmd, *path;

	if (!cmd || !env)
		perror("NULL argument to all()"), exit(1);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
	{
		a_cmd = malloc(sizeof(char) * (_strlen(cmd) + 1));
		if (!a_cmd)
			perror("Can't allocate memory for a_cmd"), exit(1);
		a_cmd = _strcpy(a_cmd, cmd);
		return (a_cmd);
	}

	env_cpy = handle_cpy(env);
	path = _path(env_cpy);
	a_cmd = _cmd(cmd, path);
	free_std(env_cpy);
	return (a_cmd);
}

/**
 * _path - finds the path
 * @env: environment
 *
 * Return: path
 */
char *_path(char **env)
{
	const char *d;
	char *token;
	int j;

	j = 0, d = "=";
	while (env[j])
	{
		token = _strtok(env[j], d);
		if (!_strcmp("path", token))
			break;
		j++;
	}
	if (env[j])
		token = _strtok(NULL, d);
	else
		token = NULL;
	return (token);
}

/**
 * _cmd - get command
 * @cmnd: command
 * @path: path
 *
 * Return: command
 */
char *_cmd(char *cmnd, char *path)
{
	const char *d = ":";
	char *token, *cmd;

	if (!cmnd || !path)
		perror("empty arg to _cmnd()"), exit(1);

	token = _strtok(path, d);
	while (token)
	{
		cmd = define_path(token, cmnd);
		if (cmd)
			return (cmd);
		token = _strtok(NULL, d);
	}
	return (NULL);
}

/**
 * define_path - define the path
 * @d: input
 * @x: input
 *
 * Return: the full path | NULL
 */
char *define_path(char *d, char *x)
{
	char *buf;
	int n, m, s;

	if (!d || !x)
		perror("empty arg to define_path()"), exit(1);

	size = _strlen(dir) + _strlen(x) + 2;
	buf = malloc(sizeof(char) * s);
	if (!buf)
		perror("Can't allocate memory for buf"), exit(1);

	for (n = 0; d[n]; n++)
		buffer[n] = d[n];
	buf[n++] = '/';
	for (m = 0; x[m]; m++)
		buf[n++] = x[m];
	for (; n < s; m++)
		buf[n] = '\0';

	if (access(buf, F_OK & X_OK) == -1)
		free(buf), buf = NULL;

	return (buf);
}

/**
 * free_std - frees arrays
 * @ar: array
 *
 */
void free_std(char **ar)
{
	unsigned int j;

	if (!ar)
		return;
	j = 0;
	while (ar[j])
		free(ar[j++]);
	free(ar);
	ar = NULL;
}
