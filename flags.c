#include "header.h"

/**
 * p_exec - add executable
 * @buf: buffer
 * @x: executable
 * @n: number
 *
 * Return: buf last index
 */
unsigned int p_exec(char *buf, char *x, int n)
{
	unsigned int i;

	for (i = 0; x[i]; i++)
		buf[i] = x[i];

	buf[i++] = ':', buf[i++] = ' ';
	buf[i++] = n + '0';
	buf[i++] = ':', buf[i++] = ' ';

	return (i);
}

/**
 * add_cmd - adds command to buffer
 * @buf: buffer
 * @cmnd: command
 * @i: buffer last index
 *
 * Return: i
 */
unsigned int add_cmd(char *buf, char *cmnd, unsigned int i)
{
	unsigned int j;

	if (!cmnd)
		return (i);
	for (j = 0; cmnd[j]; j++)
		buf[i++] = cmnd[j];

	buf[i++] = ':', buf[i++] = ' ';

	return (i);
}

/**
 * _error - prints errors
 * @buf: buffer
 * @err: error
 * @i: buffer last index
 *
 * Return: i
 */
unsigned int _error(char *buf, char *err, unsigned int i)
{
	unsigned int j;

	for (j = 0; err[j]; j++)
		buf[i++] = err[j];

	return (i);
}

/**
 * _more - adds text
 * @buf: buffer
 * @txt: text
 * @indx: index
 * @i: buffer last index
 *
 * Return: i
 */
unsigned int _more(char *buf, char *txt, char indx,
unsigned int i)
{
	unsigned int j;

	if (!txt)
		return (i);

	if (indx != 'c')
		buf[i++] = ':', buf[i++] = ' ';
	for (j = 0; txt[j]; j++)
		buf[i++] = txt[j];

	return (i);
}
/**
 * is_error - display errors
 * @exc: executable
 * @cmnd: command
 * @err: err message
 * @txt: text
 */
void is_error(char *exc, char *cmnd, char *err, char *txt)
{
	char *msgs;
	static char *x;
	static unsigned int n;
	unsigned int i;

	if (exc)
	{
		x = exc;
		return;
	}

	if (!n)
		++n;
	msgs = malloc(sizeof(char) * 100);
	if (!msgs)
		perror("Can't allocate memory for msgs"), exit(1);

	i = p_exec(msgs, x, n), n++;
	i = add_cmd(msgs, cmnd, i);
	i = _error(msgs, err, i);
	i = _more(msgs, txt, err[0], i);

	msgs[i++] = '\n', msgs[i] = '\0';
	write(STDERR_FILENO, msgs, i), free(msgs);
}
