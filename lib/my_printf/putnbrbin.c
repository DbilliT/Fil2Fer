#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

char	*convertbin(unsigned int nbr, char *result,
		    char *base, int len_base)
{
  if ((nbr / len_base) != 0)
    result = convertbin(nbr / len_base, result, base, len_base);
  my_charcat(result, base[nbr % len_base]);
  return (result);
}

int     exceptionbin(char *str, char *flags)
{
  if (flags != NULL && (flags[0] >= '0' && flags[0] <= '9'))
    {
      if (flags[0] == '0')
        my_putnchar('0', my_atoi(flags) - my_strlen(str));
      else
	my_putnchar(' ', my_atoi(flags) - my_strlen(str));
    }
  my_putstr(str);
  if (flags != NULL && flags[0] == '-')
    {
      if (flags[1] == '0')
        my_putnchar('0', my_atoi(flags + 1) - my_strlen(str));
      else
        my_putnchar(' ', my_atoi(flags + 1) - my_strlen(str));
    }
  if (flags != NULL)
    free(flags);
  free(str);
  return (0);
}

int		putnbrbin(va_list ap, char *flags)
{
  char		*str;
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  if ((str = malloc(((my_intlen(nb) * 16) + 3) * sizeof(*str))) == NULL)
    return (1);
  str[0] = '\0';
  str = convertbin(nb, str, "01", 2);
  if (flags != NULL && flags[0] == '.')
    {
      my_putnstr(str, my_atoi(flags + 1));
      free(str);
      free(flags);
      return (0);
    }
  exceptionbin(str, flags);
  return (0);
}
