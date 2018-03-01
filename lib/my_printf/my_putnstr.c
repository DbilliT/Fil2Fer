#include "my_printf.h"

void	my_putnstr(char *str, int time)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && time)
    {
      my_putchar(str[i]);
      time = time - 1;
      i = i + 1;
    }
}
