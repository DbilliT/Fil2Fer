#include <alloca.h>
#include "lapin.h"
#include "fdf2.h"
#include "libmy.h"

void	add_figure(t_figure **list, t_figure *figure)
{
  figure->next = *list;
  *list = figure;
}

int	det_s(const char *shape)
{
  if (!my_strcmp(shape, "pixel"))
    return (1);
  if (!my_strcmp(shape, "line"))
    return (2);
  if (!my_strcmp(shape, "polygon"))
    return (3);
  return (0);
}

void			fetch_ini(t_figure **figures, char *file)
{
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  t_figure		*cur;

  if ((ini = bunny_load_ini(file)) == NULL)
    return;
  scope = bunny_ini_first(ini);
  while ((scope = bunny_ini_next(ini, scope)) != NULL)
    {
      if ((cur = bunny_malloc(sizeof(*cur))) == NULL)
	return;
      if (!my_strcmp(bunny_ini_scope_get_field(scope, "type", 0), "fdf2"))
	{
	  cur->type = det_s(bunny_ini_scope_get_field(scope, "shape", 0));
	  cur->data = NULL;
	  if (cur->type == 1)
	    fetch_pixel(ini, scope, cur);
	  else if (cur->type == 2)
	    fetch_line(ini, scope, cur);
	  else if (cur->type == 3)
	    fetch_polygon(ini, scope, cur);
	}
      add_figure(figures, cur);
    }
  bunny_delete_ini(ini);
}
