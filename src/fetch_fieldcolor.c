#include <stdlib.h>
#include "lapin.h"
#include "libmy.h"

int     fetch_field(t_bunny_ini *ini, t_bunny_ini_scope *scope, int *i)
{
  int   ret;

  ret = my_atoi(bunny_ini_get_field(ini,
				    bunny_ini_scope_name(ini, scope),
				    "data", *i));
  if (bunny_ini_get_field(ini, bunny_ini_scope_name(ini, scope),
			  "data", *i) != NULL)
    *i = *i + 1;
  return (ret);
}

unsigned int    fetch_color(t_bunny_ini *ini,
			    t_bunny_ini_scope *scope, int *i)
{
  unsigned int  ret;

  ret = my_unsignedatoi(bunny_ini_get_field(ini,
					    bunny_ini_scope_name(ini, scope),
                                            "color", *i));
  if (bunny_ini_get_field(ini, bunny_ini_scope_name(ini, scope),
			  "color", *i) != NULL)
    *i = *i + 1;
  return (ret);
}
