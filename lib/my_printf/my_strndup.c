#include <stdlib.h>
#include "my_printf.h"

char	*my_strndup(char *src, int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  str = my_strncpy(str, src, size);
  return (str);
}
