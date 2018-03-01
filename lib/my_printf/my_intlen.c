int	my_intlen(int num)
{
  int	i;
  int	div;

  i = 1;
  div = 10;
  if (num < 0)
    num = num * -1;
  while ((num / div) > 0)
    {
      div = div * 10;
      i = i + 1;
    }
  return (i);
}
