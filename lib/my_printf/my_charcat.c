#include "my_printf.h"

char    *my_charcat(char *dest, char c)
{
  int	len;

  len = my_strlen(dest);
  dest[len] = c;
  dest[len + 1] = '\0';
  return (dest);
}
