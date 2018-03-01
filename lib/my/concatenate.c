#include <stdlib.h>
#include "libmy.h"

char    *concatenate(const char *str1, const char *str2)
{
  char  *concatenated;

  if ((concatenated = malloc((my_strlen(str1) + my_strlen(str2) + 1) *
                             sizeof(char))) == NULL)
    return (NULL);
  concatenated[0] = '\0';
  my_strcat(concatenated, str1);
  my_strcat(concatenated, str2);
  return (concatenated);
}
