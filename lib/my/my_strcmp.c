#include <stdlib.h>

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  if (s1 == NULL || s1[0] == '\0' || s2 == NULL || s2[0] == '\0')
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
      if (s1[i] == '\0' || s2[i] == '\0')
	return (s1[i] - s2[i]);
    }
  return (0);
}