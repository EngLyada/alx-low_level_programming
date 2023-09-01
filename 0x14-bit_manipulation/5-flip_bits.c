#include "main.h"

/**
 * method counts the bits number from one number to another
 * @one: first number
 * @two: second number
 *
 */
unsigned int flip_bits(unsigned long int one, unsigned long int two)
{
  int i, counter = 0;
  unsigned long int current;
  unsigned long int e = one ^ two;

  for (i = 63; i >= 0; i--)
  {
    current = e >> i;
    if (current & 1)
      counter++;
  }

  return (counter);
}
