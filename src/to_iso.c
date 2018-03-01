#include <math.h>
#include "fdf2.h"
#include "lapin.h"

void	matrix_mult(float *vec, float *mat, float *res)
{
  res[0] = vec[0] * mat[0] + vec[1] * mat[3] + vec[2] * mat[6];
  res[1] = vec[0] * mat[1] + vec[1] * mat[4] + vec[2] * mat[7];
  res[2] = vec[0] * mat[2] + vec[1] * mat[5] + vec[2] * mat[8];
}

float	*matrix_x(float *mat, float angle)
{
  mat[0] = 1;
  mat[1] = 0;
  mat[2] = 0;
  mat[3] = 0;
  mat[4] = cos(angle);
  mat[5] = -sin(angle);
  mat[6] = 0;
  mat[7] = sin(angle);
  mat[8] = cos(angle);
  return (mat);
}

float	*matrix_y(float *mat, float angle)
{
  mat[0] = cos(angle);
  mat[1] = 0;
  mat[2] = sin(angle);
  mat[3] = 0;
  mat[4] = 1;
  mat[5] = 0;
  mat[6] = -sin(angle);
  mat[7] = 0;
  mat[8] = cos(angle);
  return (mat);
}

float	*matrix_z(float *mat, float angle)
{
  mat[0] = cos(angle);
  mat[1] = -sin(angle);
  mat[2] = 0;
  mat[3] = sin(angle);
  mat[4] = cos(angle);
  mat[5] = 0;
  mat[6] = 0;
  mat[7] = 0;
  mat[8] = 1;
  return (mat);
}

int	to_iso(t_bunny_position *out, float *xyz, t_screen *scr, int side)
{
  float f;
  float	mat[9];
  float	vec[3];
  float	res[3];

  f = scr->zoom;
  vec[0] = xyz[0];
  vec[1] = xyz[1];
  vec[2] = xyz[2];
  matrix_mult(vec, matrix_x(mat, 0.0174533 * scr->angle.y), res);
  vec[0] = res[0];
  vec[1] = res[1];
  vec[2] = res[2];
  matrix_mult(vec, matrix_y(mat, 0.0174533 * scr->angle.y), res);
  vec[0] = res[0];
  vec[1] = res[1];
  vec[2] = res[2];
  matrix_mult(vec, matrix_z(mat, 0.0174533 * scr->angle.x), res);
  if (!side && (res[0] < -150 || res[1] < -150 || res[2] < -150))
    tekisoproject(out, res[0] * f, res[1] * f, res[2] * f);
  else if (side)
    tekisoproject(out, res[0] * f, res[1] * f, res[2] * f);
  else
    return (0);
  return (1);
}
