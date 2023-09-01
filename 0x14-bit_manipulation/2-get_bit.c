#include "main.h"

/**
 * The value of a bit at an index in a decimal number is returned by the method get_bit
 * number to search is b
 * index of the bit is represented  by i
 *
 * bit value val is returned
 */
int get_bit(unsigned long int b, unsigned int i)
{
  int val;

  if (i > 63)
    return (-1);

  val = (b >> i) & 1;

  return (val);
}
