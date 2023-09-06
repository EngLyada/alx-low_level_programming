#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *f_name);
void close_file(int d);

/**
 * create_buffer - Allocates 1024 bytes allocated for a buffer.
 * @f_name: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *f_name)
{
	char *bf;

	bf = malloc(sizeof(char) * 1024);

	if (bf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", f_name);
		exit(99);
	}

	return (bf);
}

/**
 * close_file - File descriptors closes.
 * @d: The file descriptor .
 */
void close_file(int d)
{
	int w;

	w = close(d);

	if (w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", d);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @ac: The amount of arguments given to the program.
 * @av: an array of parameters' pointers.
 *
 * Return: 0 on success.
 *
 */
int main(int ac, char *av[])
{
	int fm, t, rd, wt;
	char *bf;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bf = create_buffer(av[2]);
	fm = open(av[1], O_RDONLY);
	rd = read(fm, bf, 1024);
	t = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fm == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
			free(bf);
			exit(98);
		}

		wt = write(t, bf, rd);
		if (t == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", av[2]);
			free(bf);
			exit(99);
		}

		rd = read(fm, bf, 1024);
		t = open(av[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(bf);
	close_file(fm);
	close_file(t);

	return (0);
}
