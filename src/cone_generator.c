#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "lapin.h"
#include "libmy.h"

void	cone_toini(t_bunny_ini *ini, int pos, char *value)
{
  bunny_ini_set_field(ini, "cone", "data", pos, value);
  if (value != NULL)
    free(value);
}

void    close_cone(t_bunny_ini *ini, float *l, int *radi, float ppm)
{
  l[0] = l[0] - ppm;
  l[1] = 0;
  while (l[1] < 2 * M_PI)
    {
      cone_toini(ini, radi[1], my_inttostring(0));
      radi[1] += 1;
      cone_toini(ini, radi[1], my_inttostring(0));
      radi[1] += 1;
      cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * l[0]));
      radi[1] += 1;
      cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * cos(l[1])));
      radi[1] += 1;
      cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * sin(l[1])));
      radi[1] += 1;
      cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * l[0]));
      radi[1] += 1;
      l[1] += ppm;
    }
}

void	generate_cone_shape_la(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * cos(l[1])));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * sin(l[1])));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * l[0]));
  radi[1] += 1;
  cone_toini(ini, radi[1],
	     my_inttostring(radi[0] * (l[0] + ppm) * cos(l[1])));
  radi[1] += 1;
  cone_toini(ini,
	     radi[1], my_inttostring(radi[0] * (l[0] + ppm) * sin(l[1])));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * (l[0] + ppm)));
  radi[1] += 1;
}

void	generate_cone_shape_lo(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * cos(l[1])));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * sin(l[1])));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * l[0]));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * cos(l[1] + ppm)));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring(radi[0] * l[0] * sin(l[1] + ppm)));
  radi[1] += 1;
  cone_toini(ini, radi[1], my_inttostring((radi[0] + 20) * l[0]));
  radi[1] += 1;
}

void		generate_cone(t_bunny_ini *ini, int rad, float ppm)
{
  int		radi[2];
  float		l[2];

  radi[0] = rad;
  radi[1] = 0;
  ppm = M_PI / ppm;
  l[0] = 0;
  while (l[0] <= 10)
    {
      l[1] = 0;
      while (l[1] <= (2 * M_PI))
	{
	  if (l[0] + ppm < 10)
	    generate_cone_shape_la(ini, l, radi, ppm);
	  generate_cone_shape_lo(ini, l, radi, ppm);
	  l[1] += ppm;
	}
      l[0] += ppm;
    }
  close_cone(ini, l, radi, ppm);
}
