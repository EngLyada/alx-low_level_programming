#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @f_name: text file being read
 * @l: number of letters to be read
 * Return: wt- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *f_name, size_t l)
{
	char *bufs;
	ssize_t d;
	ssize_t wt;
	ssize_t q;

	d = open(f_name, O_RDONLY);
	if (d == -1)
		return (0);
	buf = malloc(sizeof(char) * l);
	q = read(d, bufs, l);
	wt = write(STDOUT_FILENO, bufs, t);

	free(bufs);
	close(d);
	return (wt);
}
