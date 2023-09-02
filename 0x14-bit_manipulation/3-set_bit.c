#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @w: pointer to the number
 * @i: index of the bit
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *w, unsigned int i)
{
	if (i > 63)
		return (-1);

	*n = ((1UL << i) | *w);
	return (1);
}
