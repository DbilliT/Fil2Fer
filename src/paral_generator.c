#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "lapin.h"
#include "libmy.h"

void	paral_toini(t_bunny_ini *ini, int pos, char *value)
{
  bunny_ini_set_field(ini, "paral", "data", pos, value);
  if (value != NULL)
    free(value);
}

void	do_point(t_bunny_ini *ini, int x, int y, int *radi)
{
  paral_toini(ini, radi[1], my_inttostring(x * radi[0]));
  radi[1] += 1;
  paral_toini(ini, radi[1], my_inttostring(y * radi[0]));
  radi[1] += 1;
  paral_toini(ini, radi[1], my_inttostring(radi[3] * radi[0]));
  radi[1] += 1;
}

void	do_joint(t_bunny_ini *ini, int *radi)
{
  radi[3] = -2;
  do_point(ini, 0, 0, radi);
  radi[3] = 2;
  do_point(ini, 0, 0, radi);
  radi[3] = -2;
  do_point(ini, 0, 2, radi);
  radi[3] = 2;
  do_point(ini, 0, 2, radi);
  radi[3] = -2;
  do_point(ini, 1, 2, radi);
  radi[3] = 2;
  do_point(ini, 1, 2, radi);
  radi[3] = -2;
  do_point(ini, 1, 0, radi);
  radi[3] = 2;
  do_point(ini, 1, 0, radi);
}

void		generate_paral(t_bunny_ini *ini, int rad,
			       __attribute__((__unused__))float ppm)
{
  int		radi[3];

  (void)ppm;
  radi[0] = rad;
  radi[1] = 0;
  radi[3] = -2;
  while (radi[3] <= 2)
    {
      do_point(ini, 0, 0, radi);
      do_point(ini, 0, 2, radi);
      do_point(ini, 0, 2, radi);
      do_point(ini, 1, 2, radi);
      do_point(ini, 1, 2, radi);
      do_point(ini, 1, 0, radi);
      do_point(ini, 1, 0, radi);
      do_point(ini, 0, 0, radi);
      radi[3] += 4;
    }
  do_joint(ini, radi);
}
