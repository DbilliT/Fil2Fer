#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

static const t_func func_list[] =
  {
    {'d', &putnbr},
    {'i', &putnbr},
    {'s', &putstr},
    {'c', &putchr},
    {'o', &putnbroct},
    {'x', &putnbrhex},
    {'b', &putnbrbin},
    {'u', &putunsinbr},
    {'X', &putnbrhexup},
    {'S', &putstrprintable},
    {'p', &putpointer}
  };

int	my_isflag(char c)
{
  if (c == '#' || c == '.' ||
      (c >= '0' && c <= '9') || c ==  '-' ||
      c == ' ' || c == '+')
    return (1);
  return (0);
}

int	my_display(const char *format, int i, va_list ap)
{
  int	flag;
  int	cursor;

  flag = 0;
  cursor = -1;
  while (my_isflag(format[i + flag]))
    flag = flag + 1;
  while ((cursor = cursor + 1) < 11)
    if (func_list[cursor].format == format[i + flag])
      {
	if (flag)
	  func_list[cursor].function(ap,
				     my_strndup((char *)(format + i), flag));
	else
	  func_list[cursor].function(ap, NULL);
	return (i + flag);
      }
  if (format[i + flag] != '%')
    my_putchar('%');
  my_putnstr((char *)(format + i), flag + 1);
  return (i + flag);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		cursor;

  cursor = -1;
  va_start(ap, format);
  while (format[cursor = cursor + 1])
    {
      if (format[cursor] == '%')
	cursor = my_display(format, cursor + 1,  ap);
      else
	my_putchar(format[cursor]);
    }
  va_end(ap);
  return (cursor);
}
