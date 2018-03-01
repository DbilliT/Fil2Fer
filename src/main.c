#include <unistd.h>
#include "fdf2.h"
#include "my_printf.h"
#include "libmy.h"

int	display(int ac, char **av)
{
  if (ac != 3)
    {
      write(2, "Usage: ./fdf2 -display file1.ini\n", 33);
      return (1);
    }
  my_printf("Opening: %s\n", av[2]);
  display_map(av[2]);
  my_printf("Closing: %s\n", av[2]);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc == 1)
    {
      write(2, "Usage: ./fdf2 [-generate | -display]\n", 37);
      return (1);
    }
  if (!my_strcmp(argv[1], "-display"))
    return (display(argc, argv));
  else if (!my_strcmp(argv[1], "-generate"))
    return (generate(argc, argv));
  else
    {
      write(2, "Usage: ./fdf2 [-generate | -display]\n", 37);
      return (1);
    }
  return (0);
}
