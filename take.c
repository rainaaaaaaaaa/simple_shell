#include "core.h"

/**
 * _getline1 - reads input from stdin
 * @line: string to read
 * Return: string length
 */
int _getline1(char **line)
{
	int i;

	*line = _calloc1(10240, sizeof(char));
	i = read(STDIN_FILENO, *line, 10240);
	(*line)[i] = '\0';
	return (i);
}

/**
 * ask - reads input from file
 * @line: holder
 * @args: source
 * Return: int
 */
int ask(char **line, char **args)
{
	ssize_t i;
	int ret;

	ret = open(args[1], O_RDONLY);
	if (ret == -1)
	{
		bug(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*line = _calloc1(10240, sizeof(char));
	i = read(ret, *line, 10240);
	close(ret);
	while (**line == ' ' || **line == '\t')
		(*line)++, i--;
	(*line)[i] = '\0';
	return (i);
}
