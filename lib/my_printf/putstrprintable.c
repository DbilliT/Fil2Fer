#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	to_octal(int decimal)
{
  int	rem;
  int	i;
  int	octal;

  i = 1;
  octal = 0;
  while (decimal != 0)
    {
      rem = decimal % 8;
      decimal = decimal / 8;
      octal = octal + rem * i;
      i = i * 10;
    }
  return (octal);
}

int	putstrprintable(va_list ap, char *flags)
{
  char	*str;
  int	cursor;

  if (flags != NULL)
    free(flags);
  if ((str = va_arg(ap, char *)) == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  cursor = 0;
  while (str[cursor])
    {
      if (str[cursor] < 32 || str[cursor] >= 127)
	{
	  my_putchar('\\');
	  my_putchar(((to_octal(str[cursor]) / 100) % 10) + 48);
	  my_putchar(((to_octal(str[cursor]) / 10) % 10) + 48);
	  my_putchar((to_octal(str[cursor]) % 10) + 48);
	}
      else
	my_putchar(str[cursor]);
      cursor = cursor + 1;
    }
  return (4);
}
