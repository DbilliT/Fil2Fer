char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  while (i < n)
    {
      dest[i] = '\0';
      i = i + 1;
    }
  return (dest);
}
