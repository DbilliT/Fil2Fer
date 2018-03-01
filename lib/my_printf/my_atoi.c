#include <stdlib.h>

int	my_atoi(const char *str)
{
  int	i;
  int	result;
  int	nega;

  if (str == NULL)
    return (0);
  nega = 1;
  i = 0;
  if (str[0] == '-')
    {
      nega = -1;
      i = i + 1;
    }
  result = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      result = result * 10 + (str[i] - '0');
      i = i + 1;
    }
  return (result * nega);
}
