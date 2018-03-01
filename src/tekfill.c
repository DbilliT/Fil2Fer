#include <stdlib.h>
#include "lapin.h"

void		tekfill(t_bunny_pixelarray *screen, unsigned int color)
{
  int		i;
  t_color	*pixels;

  if (screen == NULL)
    return;
  i = 0;
  pixels = (t_color *)screen->pixels;
  while (i < screen->clipable.clip_width * screen->clipable.clip_height)
    {
      pixels[i].full = color;
      i = i + 1;
    }
}
