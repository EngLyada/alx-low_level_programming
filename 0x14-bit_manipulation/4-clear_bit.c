#include "main.h"

/**
 * method sets given bit to 0
 * k is a pointer to the number 
 * i is an index of the bit
 */
int clear_bit(unsigned long int *k, unsigned int i)
{
  if (i > 63)
    return (-1);

  *n = (~(1UL << i) & *k);
  return (1);
}
