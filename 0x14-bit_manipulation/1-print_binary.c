#include "main.h"

/**
* print_binary - prints the binary  of a decimal number
* @k: number to print in binary
*/

void print_binary(unsigned long int k)
{
	int d, count = 0;
	unsigned long int z;
	for (d = 63; d >= 0; d--)
	{
		z = k >> d;
		if (z & 1)
		{
			_putchar('1');
			count++;
		}else if (count)
			_putchar('0');
	} if (!count)
	 _putchar('0');

}
