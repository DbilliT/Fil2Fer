#include <stdlib.h>
#include "lapin.h"

void	tekpixel(t_bunny_pixelarray *, t_bunny_position *, t_color *);

t_color	*determine_color(t_color *out, t_color *color,
			 t_bunny_position coord,
			 t_bunny_position *pos)
{
  int	red[2];
  int	blue[2];
  int	green[2];
  float	percent;

  if (pos[0].x - pos[1].x)
    percent = -((float)(pos[0].x - coord.x) /
		(float)((pos[0].x - coord.x) + ((pos[1].x - pos[0].x) -
						(pos[0].x - coord.x))));
  if (pos[0].y - pos[1].y)
    percent += -((float)(pos[0].y - coord.y) /
		 (float)((pos[0].y - coord.y) + ((pos[1].y - pos[0].y) -
						 (pos[0].y - coord.y))));
  if (pos[0].x - pos[1].x && pos[0].y - pos[1].y)
    percent = percent / 2;
  red[0] = (color[0].full) & 0xff;
  red[1] = (color[1].full) & 0xff;
  green[0] = (color[0].full >> 8) & 0xff;
  green[1] = (color[1].full >> 8) & 0xff;
  blue[0] = (color[0].full >> 16) & 0xff;
  blue[1] = (color[1].full >> 16) & 0xff;
  out->full = (int)(red[0] + percent * (red[1] - red[0])) << 0 |
    (int)(green[0] + percent * (green[1] - green[0])) << 8 |
    (int)(blue[0] + percent * (blue[1] - blue[0])) << 16;
  return (out);
}

void    affect_var(const t_bunny_position *coord,
		   t_bunny_position *d,
		   t_bunny_position *s,
                   t_bunny_position *err)
{
  d->x = coord[1].x - coord[0].x;
  if (d->x < 0)
    d->x = d->x * -1;
  d->y = coord[1].y - coord[0].y;
  if (d->y < 0)
    d->y = d->y * -1;
  s->x = (coord[0].x < coord[1].x) ? 1 : -1;
  s->y = (coord[0].y < coord[1].y) ? 1 : -1;
  err->x = (d->x > d->y ? d->x : -d->y) / 2;
}

void	affect_first(t_bunny_position *err, t_bunny_position *d,
		     t_bunny_position *coord, t_bunny_position *s)
{
  if (err->y > -d->x)
    {
      err->x = err->x - d->y;
      coord->x = coord->x + s->x;
    }
}

void    affect_second(t_bunny_position *err, t_bunny_position *d,
		      t_bunny_position *coord, t_bunny_position *s)
{
  if (err->y < d->y)
    {
      err->x = err->x + d->x;
      coord->y = coord->y + s->y;
    }
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  t_bunny_position      coord;
  t_bunny_position      d;
  t_bunny_position      s;
  t_bunny_position      err;
  t_color		c_col;

  if (pix == NULL || pix->pixels == NULL || pos == NULL || color == NULL)
    return;
  coord.x = pos[0].x;
  coord.y = pos[0].y;
  affect_var(pos, &d, &s, &err);
  tekpixel(pix, &coord, determine_color(&c_col, color, coord, pos));
  while (coord.x != pos[1].x || coord.y != pos[1].y)
    {
      err.y = err.x;
      affect_first(&err, &d, &coord, &s);
      affect_second(&err, &d, &coord, &s);
      tekpixel(pix, &coord, determine_color(&c_col, color, coord, pos));
    }
}
