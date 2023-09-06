#include "main.h"

/**
 * append_text_to_file - Text appending at the end of a file.
 * @f_name: File name pointer.
 * @txt_cont: The final string to include in the file.
 *
 * Return: -1 for function failure or f_name is NULL.
 *         -1 for no write permission and file does not exist.
 *         Otherwise 1 for sucess.
 */

int append_text_to_file(const char *f_name, char *txt_cont)
{
	int on, wt, l = 0;

	if (f_name == NULL)
		return (-1);

	if (txt_cont != NULL)
	{
		for (l = 0; txt_cont[l];)
			l++;
	}

	on = open(f_name, O_WRONLY | O_APPEND);
	wt = write(on, txt_cont, l);

	if (on == -1 || wt == -1)
		return (-1);

	close(on);

	return (1);
}

