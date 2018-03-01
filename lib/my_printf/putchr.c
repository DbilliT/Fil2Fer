#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	putchr(va_list ap, char *flags)
{
  if (flags != NULL && (flags[0] >= '0' && flags[0] <= '9'))
    my_putnchar(' ', my_atoi(flags));
  my_putchar(va_arg(ap, int));
  if (flags != NULL && flags[0] == '-')
    my_putnchar(' ', my_atoi(flags + 1));
  if (flags != NULL)
    free(flags);
  return (1);
}
