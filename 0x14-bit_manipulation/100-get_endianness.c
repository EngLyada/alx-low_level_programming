#include "main.h"

/**
 * get_endianness - checking for little or big endian in a machine
 * 0 is return for big and  1 for little
 */
 
int get_endianness(void)
{
  unsigned int j = 1;
  char *k = (char *) &j;

  return (*k);
}
