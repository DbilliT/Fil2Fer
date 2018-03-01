#include <alloca.h>
#include <unistd.h>
#include "lapin.h"
#include "fdf2.h"

void	circular_free_data(void *head, int type)
{
  if (type == 1)
    {
      if (((t_pixel *)head)->next != NULL)
	circular_free_data(((t_pixel *)head)->next, type);
    }
  else if (type == 2)
    {
      if (((t_line *)head)->next != NULL)
	circular_free_data(((t_line *)head)->next, type);
    }
  else
    {
      if (((t_polygon *)head)->next != NULL)
	circular_free_data(((t_polygon *)head)->next, type);
    }
  bunny_free(head);
}

void	circular_free(t_figure *head)
{
  if (head != NULL)
    {
      circular_free(head->next);
      circular_free_data(head->data, head->type);
      bunny_free(head);
    }
}

t_bunny_response        refresh(void *_scr)
{
  t_screen              *scr;

  scr = (t_screen *)_scr;
  if (scr == NULL || scr->window == NULL || scr->pixels == NULL)
    {
      write(2, "Huho, something went wrong! An allocation failed\n", 49);
      return (EXIT_ON_ERROR);
    }
  tekfill(scr->pixels, 0x000000);
  display_figures(scr, scr->figures);
  if (scr->rot_active)
    {
      scr->angle.x = (scr->angle.x + 1) % 360;
      scr->angle.y = (scr->angle.y + 1) % 360;
    }
  bunny_blit(&scr->window->buffer, &scr->pixels->clipable, &scr->window_pos);
  bunny_display(scr->window);
  return (GO_ON);
}

void            display_map(char *file)
{
  t_screen      *scr;

  scr = alloca(sizeof(*scr));
  scr->figures = NULL;
  fetch_ini(&scr->figures, file);
  scr->panic = 0;
  scr->zoom = 1;
  scr->angle.x = 0;
  scr->angle.y = 0;
  scr->rot_active = 0;
  scr->window = bunny_start(1000, 1000, false, file);
  scr->pixels = bunny_new_pixelarray(scr->window->buffer.width,
				     scr->window->buffer.height);
  scr->window_pos.x = 0;
  scr->window_pos.y = 0;
  if (scr != NULL && scr->window != NULL && scr->pixels != NULL)
    {
      bunny_set_key_response(keypress);
      bunny_set_loop_main_function(refresh);
      bunny_loop(scr->window, 50, scr);
      bunny_delete_clipable(&scr->pixels->clipable);
      bunny_stop(scr->window);
    }
  circular_free(scr->figures);
}
