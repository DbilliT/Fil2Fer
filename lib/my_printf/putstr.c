#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	putstr(va_list ap, char *flags)
{
  char	*str;

  if ((str = va_arg(ap, char *)) == NULL)
    {
      my_putstr("(null)");
      if (flags != NULL)
	free(flags);
      return (6);
    }
  if (flags != NULL && flags[0] == '.')
    {
      my_putnstr(str, my_atoi(flags + 1));
      free(flags);
      return (0);
    }
  else if (flags != NULL && (flags[0] >= '0' && flags[0] <= '9'))
    my_putnchar(' ', my_atoi(flags) - my_strlen(str));
  my_putstr(str);
  if (flags != NULL && flags[0] == '-')
    my_putnchar(' ', my_atoi(flags + 1) - my_strlen(str));
  if (flags != NULL)
    free(flags);
  return (my_strlen(str));
}
