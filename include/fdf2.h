#ifndef FDF2_H_
# define FDF2_H_

#include "lapin.h"

/* Structures */

/* Functions pointer */
typedef struct  s_funct
{
  char          *figure;
  void          (*function)(t_bunny_ini *, int, float);
}               t_funct;

/* Figure */
typedef struct          s_point
{
  int                   x;
  int                   y;
  int                   z;
  t_color               color;
}                       t_point;

typedef struct          s_pixel
{
  t_point               pts[1];
  struct s_pixel        *next;
}                       t_pixel;

typedef struct          s_line
{
  t_point               pts[2];
  struct s_line         *next;
}                       t_line;

typedef struct          s_polygon
{
  t_point               pts[3];
  struct s_polygon      *next;
}                       t_polygon;

typedef struct          s_figure
{
  int			type;
  void                  *data;
  struct s_figure       *next;
}                       t_figure;

/* Main screen */
typedef struct          s_screen
{
  t_bunny_window        *window;
  t_bunny_pixelarray    *pixels;
  t_figure		*figures;
  float			zoom;
  int			rot_active;
  float			panic;
  t_bunny_position	angle;
  t_bunny_position      window_pos;
}                       t_screen;

/* Prototypes */

/* Fetch functions */
void		fetch_ini(t_figure **, char *);
void		fetch_pixel(t_bunny_ini *, t_bunny_ini_scope *, t_figure *);
void		fetch_line(t_bunny_ini *, t_bunny_ini_scope *, t_figure *);
void		fetch_polygon(t_bunny_ini *, t_bunny_ini_scope *, t_figure *);
int		fetch_field(t_bunny_ini *, t_bunny_ini_scope *, int *);
unsigned int	fetch_color(t_bunny_ini *, t_bunny_ini_scope *, int *);

/* Display functions */
t_bunny_response	keypress(t_bunny_event_state, t_bunny_keysym, void *);
void			display_figures(t_screen *, t_figure *);
t_bunny_position	*scr_disp(t_screen *, t_bunny_position **);
t_color			*scr_clr(t_color *, t_point *, int, int);
void			display_map(char *);
int			to_iso(t_bunny_position *, float *, t_screen *, int);
void			tekisoproject(t_bunny_position *, int, int, int);

/* Drawing functions */
void	tekpixel(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void	tekline(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void	tekfill(t_bunny_pixelarray *, unsigned int);

/* Generator functions */
int	generate(int, char **);
void	generate_sphere(t_bunny_ini *, int, float);
void	generate_moebius(t_bunny_ini *, int, float);
void	generate_tore(t_bunny_ini *, int, float);
void	generate_cylinder(t_bunny_ini *, int, float);
void	generate_cone(t_bunny_ini *, int, float);
void	generate_paral(t_bunny_ini *, int, float);

#endif /* !FDF2_H_ */
