#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @b: searched number
 * @i: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int b, unsigned int i)
{
	int b_value;

	if (i > 63)
		return (-1);

	b_value = (b >> i) & 1;

	return (b_value);
}
