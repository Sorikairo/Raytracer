/*
** rotate_caster.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 02:55:06 2014 
** Last update Fri Jun  6 18:38:43 2014 
*/

#include <stdlib.h>
#include "caster.h"
#include "object.h"

void		rotate_coordinate(t_vec3d *pos, double *matrice)
{
  t_vec3d	pos1;

  pos1.x = matrice[0] * pos->x + matrice[3] * pos->y + matrice[6] * pos->z;
  pos1.y = matrice[1] * pos->x + matrice[4] * pos->y + matrice[7] * pos->z;
  pos1.z = matrice[2] * pos->x + matrice[5] * pos->y + matrice[8] * pos->z;
  pos->x = pos1.x;
  pos->y = pos1.y;
  pos->z = pos1.z;
}

void	rotate_caster(t_caster *caster, t_object *object)
{
  double	*z_rotate;
  double	*x_rotate;
  double	*y_rotate;

  x_rotate = rotation_x(object->rotation.x);
  y_rotate = rotation_y(object->rotation.y);
  z_rotate = rotation_z(object->rotation.z);
  rotate_coordinate(&caster->temp_vec, z_rotate);
  rotate_coordinate(&caster->temp_vec, y_rotate);
  rotate_coordinate(&caster->temp_vec, x_rotate);
  free(z_rotate);
  free(y_rotate);
  free(x_rotate);
}
