#include "main.h"
#include <unistd.h>
  
/**
 * the file writes char d to stdout and prints char d
 * for success ,1 is returned
 * for error , -1 is returned
 */
int _putchar(char d)
{
  return (write(1, &d, 1));
}
