#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print
 * @f_name: text file being read
 * @l: no of read letters in the file f_name
 * Return: wrt-Read and printed number of bytes 
 *
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
