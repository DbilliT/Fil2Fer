#include <stdlib.h>
#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color	*pixels;

  if (pix == NULL || pix->pixels == NULL || pos == NULL || color == NULL)
    return;
  pixels = (t_color *)pix->pixels;
  if (pos->x < pix->clipable.buffer.width && pos->x >= 0 &&
      pos->y < pix->clipable.buffer.height && pos->y >= 0)
    pixels[(pos->y * pix->clipable.buffer.width) + pos->x] = *color;
}
