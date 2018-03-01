#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

char	*convertptrhex(unsigned long nbr, char *result,
		       char *base, int len_base)
{
  if ((nbr / len_base) != 0)
    result = convertptrhex(nbr / len_base, result, base, len_base);
  my_charcat(result, base[nbr % len_base]);
  return (result);
}

int     exceptionptrhex(char *str, char *flags)
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

int		putpointer(va_list ap, char *flags)
{
  unsigned long	ptr;
  char		*str;

  if ((ptr = va_arg(ap, unsigned long)) == 0)
    {
      my_putstr("(nil)");
      return (5);
    }
  if ((str = malloc(14 * sizeof(*str))) == NULL)
    return (1);
  str[0] = '0';
  str[1] = 'x';
  str[2] = '\0';
  str = convertptrhex(*((unsigned long *)&ptr), str, "0123456789abcdef", 16);
  exceptionptrhex(str, flags);
  return (0);
}
