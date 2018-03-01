#include <stdlib.h>

int	position(char c, char *base)
{
  int	pos;

  pos = 0;
  while (base[pos] != '\0')
    {
      if (c == base[pos] || c + 32 == base[pos])
	return (pos);
      pos = pos + 1;
    }
  return (pos);
}

unsigned int	my_unsignedatoi(const char *str)
{
  int		i;
  unsigned int	result;

  i = 0;
  if (str == NULL)
    return (0);
  result = 0;
  while (str[i] != '\0')
    {
      result = result * 16 + position(str[i], "0123456789abcdef");
      i = i + 1;
    }
  return (result);
}
