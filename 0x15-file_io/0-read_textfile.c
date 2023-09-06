#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- File print to STDOUT.
 * @f_name: text file to be read
 * @l: Letters to be read
 * Return: wrt- Number of bytes read and printed
 *        0 for function fail or NULL filename
*/

ssize_t read_textfile(const char *f_name, size_t l)
{
	char *buf;
	ssize_t d;
	ssize_t wrt;
	ssize_t q;

	d = open(f_name, O_RDONLY);
	if (d == -1)
		return (0);
	buf = malloc(sizeof(char) * l);
	q = read(d, buf, l);
	wrt = write(STDOUT_FILENO, buf, q);

	free(buf);
	close(d);
	return (wrt);
}
