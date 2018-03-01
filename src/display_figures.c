#include <alloca.h>
#include "lapin.h"
#include "fdf2.h"

void	points_toarray(float *array, t_point *pts, int pos, float *panic)
{
  array[0] = pts[pos].x;
  array[1] = pts[pos].y;
  array[2] = pts[pos].z;
  if (*panic)
    {
      array[0] += (rand() % 11) + *panic;
      array[1] += (rand() % 11) + *panic;
      array[1] += (rand() % 11) + *panic;
      *panic = *panic + 0.0001;
    }
}

void                    display_pixel(t_screen *scr, t_pixel *data, int side)
{
  t_bunny_position      pos;
  float			xyz[3];

  while (data != NULL)
    {
      points_toarray(xyz, data->pts, 0, &scr->panic);
      if (to_iso(&pos, xyz, scr, side))
	{
	  pos.x = pos.x + scr->pixels->clipable.clip_width / 2;
	  pos.y = pos.y + scr->pixels->clipable.clip_height / 2;
	  if (data->pts[0].color.full == 0)
	    {
	      if (xyz[2] < 0)
		data->pts[0].color.full = 0xB3642E;
	      else
		data->pts[0].color.full = 0x4866FB;
	    }
	  tekpixel(scr->pixels, &pos, &data->pts[0].color);
	}
      data = data->next;
    }
}

void                    display_line(t_screen *scr, t_line *data, int side)
{
  t_bunny_position      *pos;
  t_bunny_position	*tmp;
  t_color               colors[2];
  float			xyz[3];

  pos = alloca(2 * sizeof(*pos));
  while (data != NULL)
    {
      points_toarray(xyz, data->pts, 0, &scr->panic);
      if (to_iso(&pos[0], xyz, scr, side))
	{
	  points_toarray(xyz, data->pts, 1, &scr->panic);
	  if (to_iso(&pos[1], xyz, scr, side))
	    {
	      tekline(scr->pixels, tmp = scr_disp(scr, &pos),
		      scr_clr(colors, data->pts, 0, 1));
	      bunny_free(tmp);
	    }
	}
      data = data->next;
    }
}

void                    display_polygon(t_screen *scr, t_polygon *data,
					int side)
{
  t_bunny_position      *pos;
  t_color               colors[2];
  float			xyz[2][3];

  pos = alloca(2 * sizeof(*pos));
  while (data != NULL)
    {
      points_toarray(xyz[0], data->pts, 0, &scr->panic);
      points_toarray(xyz[1], data->pts, 1, &scr->panic);
      if (to_iso(&pos[0], xyz[0], scr, side) &&
	  to_iso(&pos[1], xyz[1], scr, side))
	{
	  tekline(scr->pixels, scr_disp(scr, &pos),
		  scr_clr(colors, data->pts, 0, 1));
	  points_toarray(xyz[0], data->pts, 2, &scr->panic);
	  to_iso(&pos[0], xyz[0], scr, 1);
	  tekline(scr->pixels, scr_disp(scr, &pos),
		  scr_clr(colors, data->pts, 2, 1));
	  points_toarray(xyz[0], data->pts, 0, &scr->panic);
	  to_iso(&pos[1], xyz[0], scr, 1);
	  tekline(scr->pixels, scr_disp(scr, &pos),
		  scr_clr(colors, data->pts, 2, 0));
	}
      data = data->next;
    }
}

void	display_figures(t_screen *scr, t_figure *figures)
{
  while (figures != NULL)
    {
      if (figures->type == 1)
	{
	  display_pixel(scr, figures->data, 0);
	  display_pixel(scr, figures->data, 1);
	}
      else if (figures->type == 2)
	{
	  display_line(scr, figures->data, 0);
	  display_line(scr, figures->data, 1);
	}
      else if (figures->type == 3)
	{
	  display_polygon(scr, figures->data, 0);
	  display_polygon(scr, figures->data, 1);
	}
      figures = figures->next;
    }
}
