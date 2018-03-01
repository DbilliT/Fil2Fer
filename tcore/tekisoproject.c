#include <stdlib.h>
#include <math.h>
#include "lapin.h"

void	tekisoproject(t_bunny_position *out, int x, int y, int z)
{
  float	angle;

  if (out != NULL)
    {
      angle = 30 * 0.0174533;
      out->x = (x * cos(angle)) - (y * cos(angle));
      out->y = (x * sin(angle)) + (y * sin(angle)) - z;
    }
}
