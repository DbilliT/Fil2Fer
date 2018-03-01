#include "lapin.h"

t_color		*tekgetpixel(t_bunny_pixelarray *pix,
			    t_bunny_position *pos)
{
  t_color	*pixels;

  if (pix == NULL || pix->pixels == NULL || pos == NULL)
    return (0);
  pixels = (t_color *)pix->pixels;
  if (pos->x >= 0 && pos->y >= 0 &&
      pos->x < pix->clipable.buffer.width &&
      pos->y < pix->clipable.buffer.height)
    return (&pixels[(pos->y * pix->clipable.buffer.width) + pos->x]);
  return (0);
}
