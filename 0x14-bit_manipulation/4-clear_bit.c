#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @z: pointer to the number to change
 * @i: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *z, unsigned int i)
{
	if (i > 63)
		return (-1);

	*n = (~(1UL << i) & *z);
	return (1);
}
