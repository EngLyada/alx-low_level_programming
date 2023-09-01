#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @c: string containing the binary number
 *
 * Return: the converted number c_val
*/

unsigned int binary_to_uint(const char *c)
{
	int e;
	unsigned int c_val = 0;

	if (!c)
		return (0);
	for (e = 0; c[e]; e++)
	{
		if (c[e] < '0' || c[e] > '1')
			return (0);
		c_val = 2 * c_val + (c[e] - '0');
	}
	return (c_val);
}
