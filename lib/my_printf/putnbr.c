#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

char	*convert(int nbr, char *result, char *base, int len_base)
{
  if ((nbr / len_base) != 0)
    result = convert(nbr / len_base, result, base, len_base);
  my_charcat(result, base[nbr % len_base]);
  return (result);
}

int	exception(char *str, char *flags)
{
  if (flags != NULL && (flags[0] >= '0' && flags[0] <= '9'))
    {
      if (flags[0] == '0')
	my_putnchar('0', my_atoi(flags) - my_strlen(str));
      else
	my_putnchar(' ', my_atoi(flags) - my_strlen(str));
    }
  if (flags != NULL && flags[0] == '+' && str[0] != '-')
    my_putchar('+');
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

int	putnbr(va_list ap, char *flags)
{
  char	*str;
  int	nbr;

  nbr = va_arg(ap, int);
  if ((str = malloc((my_intlen(nbr) + 2) * sizeof(*str))) == NULL)
    return (1);
  str[0] = '\0';
  if (nbr < 0)
    {
      my_charcat(str, '-');
      str = convert(nbr * -1, str, "0123456789", 10);
    }
  else
    str = convert(nbr, str, "0123456789", 10);
  if (flags != NULL && flags[0] == '.')
    {
      my_putnstr(str, my_atoi(flags + 1));
      free(str);
      free(flags);
      return (0);
    }
  exception(str, flags);
  return (0);
}
