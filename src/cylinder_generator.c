#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "lapin.h"
#include "libmy.h"

void	cylinder_toini(t_bunny_ini *ini, int pos, char *value)
{
  bunny_ini_set_field(ini, "cylinder", "data", pos, value);
  if (value != NULL)
    free(value);
}

void	close_cylinder(t_bunny_ini *ini, float *l, int *radi, float ppm)
{
  l[0] = 0;
  while (l[0] < 2 * M_PI)
    {
      cylinder_toini(ini, radi[1], my_inttostring(0));
      radi[1] += 1;
      cylinder_toini(ini, radi[1], my_inttostring(0));
      radi[1] += 1;
      cylinder_toini(ini, radi[1], my_inttostring(radi[0] * l[1]));
      radi[1] += 1;
      cylinder_toini(ini, radi[1], my_inttostring(radi[0] * cos(l[0])));
      radi[1] += 1;
      cylinder_toini(ini, radi[1], my_inttostring(radi[0] * sin(l[0])));
      radi[1] += 1;
      cylinder_toini(ini, radi[1], my_inttostring(radi[0] * l[1]));
      radi[1] += 1;
      l[0] += ppm;
    }
  l[0] = 0;
}

void	generate_cylinder_shape_la(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * cos(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * sin(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * l[1]));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * cos(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * sin(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * (l[1] + ppm)));
  radi[1] += 1;
}

void	generate_cylinder_shape_lo(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * cos(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * sin(l[0])));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * l[1]));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * cos(l[0] + ppm)));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * sin(l[0] + ppm)));
  radi[1] += 1;
  cylinder_toini(ini, radi[1], my_inttostring(radi[0] * l[1]));
  radi[1] += 1;
}

void		generate_cylinder(t_bunny_ini *ini, int rad, float ppm)
{
  int		radi[2];
  float		l[2];

  radi[0] = rad;
  radi[1] = 0;
  ppm = M_PI / ppm;
  l[1] = -5.0;
  close_cylinder(ini, l, radi, ppm);
  while (l[0] < 2 * M_PI)
    {
      l[1] = -5.0;
      while (l[1] <= 5.0)
	{
	  if (l[1] + ppm <= 5.0)
	    generate_cylinder_shape_la(ini, l, radi, ppm);
	  generate_cylinder_shape_lo(ini, l, radi, ppm);
	  l[1] += ppm;
	}
      l[0] += ppm;
    }
  l[1] = l[1] - ppm;
  close_cylinder(ini, l, radi, ppm);
}
