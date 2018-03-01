#include "my_printf.h"

void	my_putnchar(char c, int time)
{
  while (time > 0)
    {
      my_putchar(c);
      time = time - 1;
    }
}
