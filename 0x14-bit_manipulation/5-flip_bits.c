/**
 * flip_bits - return number of bits that would need to be flipped to
 * transform one number to another
 *
 * @a: first number
 * @b: second number
 *
 * Return: number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int a, unsigned long int b)
{
	unsigned long int xorval = a ^ b;
	unsigned int count = 0;

	while (xorval)
	{
		if (xorval & 1ul)
			count++;
		xorval = xorval >> 1;
	}
	return (count);
}
