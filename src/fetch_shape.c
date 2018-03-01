#include "lapin.h"
#include "fdf2.h"
#include "libmy.h"

void	add_shape(void **list, void *shape, int type)
{
  if (type == 1)
    {
      ((t_pixel *)shape)->next = (*(t_pixel **)list);
      (*(t_pixel **)list) = (t_pixel *)shape;
    }
  else if (type == 2)
    {
      ((t_line *)shape)->next = (*(t_line **)list);
      (*(t_line **)list) = (t_line *)shape;
    }
  else if (type == 3)
    {
      ((t_polygon *)shape)->next = (*(t_polygon **)list);
      (*(t_polygon **)list) = (t_polygon *)shape;
    }
}

void		fetch_pixel(t_bunny_ini *ini,
			    t_bunny_ini_scope *scope, t_figure *cur)
{
  int		i[2];
  t_pixel	*p;

  i[0] = 0;
  i[1] = 0;
  while (bunny_ini_get_field(ini, bunny_ini_scope_name(ini, scope),
			     "data", i[0]) != NULL)
    {
      if ((p = bunny_malloc(sizeof(*p))) != NULL)
	{
	  p->pts[0].x = fetch_field(ini, scope, &i[0]);
	  p->pts[0].y = fetch_field(ini, scope, &i[0]);
	  p->pts[0].z = fetch_field(ini, scope, &i[0]);
	  p->pts[0].color.full = fetch_color(ini, scope, &i[1]);
	  add_shape(&cur->data, p, 1);
	}
    }
}

void		fetch_line(t_bunny_ini *ini,
			   t_bunny_ini_scope *scope, t_figure *cur)
{
  int		i[2];
  t_line	*l;

  i[0] = 0;
  i[1] = 0;
  while (bunny_ini_get_field(ini, bunny_ini_scope_name(ini, scope),
			     "data", i[0]) != NULL)
    {
      if ((l = bunny_malloc(sizeof(*l))) != NULL)
	{
	  l->pts[0].x = fetch_field(ini, scope, &i[0]);
	  l->pts[0].y = fetch_field(ini, scope, &i[0]);
	  l->pts[0].z = fetch_field(ini, scope, &i[0]);
	  l->pts[0].color.full = fetch_color(ini, scope, &i[1]);
	  l->pts[1].x = fetch_field(ini, scope, &i[0]);
	  l->pts[1].y = fetch_field(ini, scope, &i[0]);
	  l->pts[1].z = fetch_field(ini, scope, &i[0]);
	  l->pts[1].color.full = fetch_color(ini, scope, &i[1]);
	  add_shape(&cur->data, l, 2);
	}
    }
}

void		fetch_polygon(t_bunny_ini *ini,
			      t_bunny_ini_scope *scope, t_figure *cur)
{
  int		i[2];
  t_polygon	*p;

  i[0] = 0;
  i[1] = 0;
  while (bunny_ini_get_field(ini, bunny_ini_scope_name(ini, scope),
			     "data", i[0]) != NULL)
    {
      if ((p = bunny_malloc(sizeof(*p))) != NULL)
	{
	  p->pts[0].x = fetch_field(ini, scope, &i[0]);
	  p->pts[0].y = fetch_field(ini, scope, &i[0]);
	  p->pts[0].z = fetch_field(ini, scope, &i[0]);
	  p->pts[0].color.full = fetch_color(ini, scope, &i[1]);
	  p->pts[1].x = fetch_field(ini, scope, &i[0]);
	  p->pts[1].y = fetch_field(ini, scope, &i[0]);
	  p->pts[1].z = fetch_field(ini, scope, &i[0]);
	  p->pts[1].color.full = fetch_color(ini, scope, &i[1]);
	  p->pts[2].x = fetch_field(ini, scope, &i[0]);
	  p->pts[2].y = fetch_field(ini, scope, &i[0]);
	  p->pts[2].z = fetch_field(ini, scope, &i[0]);
	  p->pts[2].color.full = fetch_color(ini, scope, &i[1]);
	  add_shape(&cur->data, p, 3);
	}
    }
}
