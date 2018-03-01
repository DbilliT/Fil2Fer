#include <stdlib.h>
#include "lapin.h"
#include "fdf2.h"

t_bunny_position        *scr_disp(t_screen *scr,
                                  t_bunny_position **pos)
{
  t_bunny_position      *copy;

  if (scr == NULL || scr->pixels == NULL || *pos == NULL)
    return (NULL);
  if ((copy = bunny_malloc(2 * sizeof(*copy))) == NULL)
    return (NULL);
  copy[0].x = (*pos)[0].x + scr->pixels->clipable.clip_width / 2;
  copy[0].y = (*pos)[0].y + scr->pixels->clipable.clip_height / 2;
  copy[1].x = (*pos)[1].x + scr->pixels->clipable.clip_width / 2;
  copy[1].y = (*pos)[1].y + scr->pixels->clipable.clip_height / 2;
  return (copy);
}

t_color *scr_clr(t_color *colors, t_point *pts, int pos1, int pos2)
{
  if (colors == NULL || pts == NULL)
    return (NULL);
  colors[0].full = pts[pos1].color.full;
  if (!(colors[0].full))
    {
      if (pts[pos1].z < 0)
	colors[0].full = 0xB3642E;
      else
        colors[0].full = 0x4866FB;
    }
  colors[1].full = pts[pos2].color.full;
  if (!(colors[1].full))
    {
      if (pts[pos2].z < 0)
	colors[1].full = 0xB3642E;
      else
	colors[1].full = 0x4866FB;
    }
  return (colors);
}
