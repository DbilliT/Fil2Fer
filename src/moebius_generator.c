#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "lapin.h"
#include "libmy.h"

void	moebius_toini(t_bunny_ini *ini, int pos, char *value)
{
  bunny_ini_set_field(ini, "moebius", "data", pos, value);
  if (value != NULL)
    free(value);
}

void	generate_moebius_shape_la(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos(l[1] / 2.0)) * cos(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos(l[1] / 2.0)) * sin(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1], my_inttostring(((l[0] / 2.0) *
					      sin(l[1] / 2.0)) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + ((l[0] + ppm) / 2.0) *
				cos(l[1] / 2.0)) * cos(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + ((l[0] + ppm) / 2.0) *
				cos(l[1] / 2.0)) * sin(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((((l[0] + ppm) / 2.0) *
				sin(l[1] / 2.0)) * radi[0]));
  radi[1] += 1;
}

void	generate_moebius_shape_lo(t_bunny_ini *ini, float *l,
				 int *radi, float ppm)
{
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos(l[1] / 2.0)) * cos(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos(l[1] / 2.0)) * sin(l[1]) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring(((l[0] / 2.0) * sin(l[1] / 2.0)) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos((l[1] + ppm) / 2.0)) *
			       cos((l[1] + ppm)) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring((1.0 + (l[0] / 2.0) *
				cos((l[1] + ppm) / 2.0)) *
			       sin((l[1] + ppm)) * radi[0]));
  radi[1] += 1;
  moebius_toini(ini, radi[1],
		my_inttostring(((l[0] / 2.0) *
				sin((l[1] + ppm) / 2.0)) * radi[0]));
  radi[1] += 1;
}

void		generate_moebius(t_bunny_ini *ini, int rad, float ppm)
{
  int		radi[2];
  float		l[2];

  radi[0] = rad;
  radi[1] = 0;
  ppm = M_PI / ppm;
  l[0] = -1.0;
  while (l[0] <= 1.0)
    {
      l[1] = 0.0;
      while (l[1] <= (2 * M_PI))
	{
	  if (l[0] + ppm < 1.0)
	    generate_moebius_shape_la(ini, l, radi, ppm);
	  generate_moebius_shape_lo(ini, l, radi, ppm);
	  l[1] += ppm;
	}
      l[0] += ppm;
    }
}
