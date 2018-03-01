#include "lapin.h"
#include "fdf2.h"

void	affect_angle(t_bunny_position *angle, t_bunny_keysym key)
{
  if (key == BKS_LEFT)
    angle->x -= 1;
  else if (key == BKS_RIGHT)
    angle->x += 1;
  else if (key == BKS_UP)
    angle->y -= 1;
  else
    angle->y += 1;
}

void	affect_zoom(float *zoom, t_bunny_keysym key)
{
  if (key == BKS_PAGEUP && *zoom < 5)
    *zoom += 0.1;
  else if (key == BKS_PAGEDOWN && *zoom > 0.2)
    *zoom -= 0.1;
}

t_bunny_response        keypress(t_bunny_event_state state,
				 t_bunny_keysym key,
				 void *window)
{
  if (window)
    {
      if (state && key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      else if (state && key == BKS_SPACE)
	((t_screen *)window)->rot_active = !((t_screen *)window)->rot_active;
      else if (key == BKS_LEFT || key == BKS_RIGHT ||
	       key == BKS_UP || key == BKS_DOWN)
	affect_angle(&((t_screen *)window)->angle, key);
      else if (key == BKS_PAGEUP || key == BKS_PAGEDOWN)
	affect_zoom(&((t_screen *)window)->zoom, key);
      else if (state && key == BKS_P)
	((t_screen *)window)->panic = !((t_screen *)window)->panic;
      return (GO_ON);
    }
  return (EXIT_ON_ERROR);
}
