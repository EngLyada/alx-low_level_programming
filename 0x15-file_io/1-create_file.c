#include "main.h"

/**
 * create_file - Creating  file.
 * @f_name: A created file pointer.
 * @txt_cont: A pointer to a string which is written to the file.
 * Return: -1 for the function fails.
 *         then  1 for success.
 */
int create_file(const char *f_name, char *txt_cont)
{
	int d, x, l = 0;

	if (f_name == NULL)
		return (-1);

	if (txt_cont != NULL)
	{
		for (l = 0; txt_cont[l];)
			l++;
	}

	d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(d, txt_cont, l);

	if (d == -1 || x == -1)
		return (-1);

	close(d);

	return (1);
}
