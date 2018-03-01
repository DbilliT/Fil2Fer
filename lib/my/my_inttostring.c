#include <stdlib.h>

char	*assign(int cpy, int i, int toconvert, char *converted)
{
  if ((cpy = toconvert) < 0)
    {
      cpy = cpy * -1;
      converted[0] = '-';
    }
  while ((i = i - 1) >= (toconvert < 0))
    {
      converted[i] = (cpy % 10) + '0';
      cpy = cpy / 10;
    }
  return (converted);
}

char	*my_inttostring(int toconvert)
{
  char	*converted;
  int	i;
  int	cpy;

  i = 0;
  if ((cpy = toconvert) < 0)
    i = i + 1;
  while (cpy)
    {
      cpy = cpy / 10;
      i = i + 1;
    }
  if ((converted = malloc((i + 2) * sizeof(char))) == NULL)
    return (NULL);
  if (toconvert == 0)
    {
      converted[0] = '0';
      converted[1] = '\0';
      return (converted);
    }
  converted[i] = '\0';
  return (assign(cpy, i, toconvert, converted));
}
