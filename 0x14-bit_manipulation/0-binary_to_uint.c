#include "main.h"

/**
 *@binar_to_uint- A string of binary numbers are converted
 *to unsigned int in this file
 *@c- a string containing the binary number
 * @c_val-The converted number is returned
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
