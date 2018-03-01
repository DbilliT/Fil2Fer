#include <unistd.h>
#include "fdf2.h"
#include "libmy.h"
#include "my_printf.h"

static const t_funct g_figure[] =
  {
    {"sphere", &generate_sphere},
    {"cone", &generate_cone},
    {"moebius", &generate_moebius},
    {"tore", &generate_tore},
    {"cylinder", &generate_cylinder},
    {"paral", &generate_paral}
  };

void		create_figure(const t_funct *figure, char **av)
{
  t_bunny_ini	*ini;
  char		*file_name;

  ini = bunny_new_ini();
  bunny_ini_set_field(ini, figure->figure, "type", 0, "fdf2");
  bunny_ini_set_field(ini, figure->figure, "shape", 0, "line");
  figure->function(ini, my_atoi(av[3]), my_atoi(av[4]));
  file_name = concatenate(figure->figure, ".ini");
  bunny_save_ini(ini, file_name);
  bunny_delete_ini(ini);
  my_printf("Generated: %s\n", file_name);
  if (file_name != NULL)
    free(file_name);
}

int	generate(int ac, char **av)
{
  int	cursor;

  if (ac != 5)
    {
      write(2, "Usage: ./fdf2 -generate [sphere | cone | moebius | ", 51);
      write(2, "tore | cylinder] radius precision\n", 34);
      return (1);
    }
  cursor = 0;
  while (cursor < 6)
    {
      if (!my_strcmp(av[2], g_figure[cursor].figure))
	{
	  create_figure(&g_figure[cursor], av);
	  return (0);
	}
      cursor = cursor + 1;
    }
  write(2, "Usage: ./fdf2 -generate [sphere | cone | moebius | ", 51);
  write(2, "tore | cylinder] radius precision\n", 34);
  return (1);
}
