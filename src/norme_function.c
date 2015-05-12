/*
** norme_function.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 13:05:58 2014 
** Last update Sun Jun  8 23:36:52 2014 Laurent Fourrier
*/

#include <math.h>
#include "caster.h"
#include "object.h"

void	norme_sphere(t_caster *caster, t_object *object)
{
  caster->intersection.v_norme.x = caster->temp_pos.x +
    caster->temp_vec.x * caster->intersection.dist;
  caster->intersection.v_norme.y = caster->temp_pos.y +
    caster->temp_vec.y * caster->intersection.dist;
  caster->intersection.v_norme.z = caster->temp_pos.z +
    caster->temp_vec.z * caster->intersection.dist;
}

void	norme_plan(t_caster *caster, t_object *object)
{
  double	*x_rotate;
  double	*y_rotate;
  double	*z_rotate;

  caster->intersection.v_norme.x = 0;
  caster->intersection.v_norme.y = 0;
  caster->intersection.v_norme.z = 1;
  x_rotate = rotation_x(object->rotation.x);
  y_rotate = rotation_y(object->rotation.y);
  z_rotate = rotation_z(object->rotation.z);
  rotate_coordinate(&caster->intersection.v_norme, x_rotate);
  rotate_coordinate(&caster->intersection.v_norme, y_rotate);
  rotate_coordinate(&caster->intersection.v_norme, z_rotate);
}

void	norme_cone(t_caster *caster, t_object *object)
{
  double	*x_rotate;
  double	*y_rotate;
  double	*z_rotate;

  caster->intersection.v_norme.x = caster->temp_pos.x
    + caster->temp_vec.x * caster->intersection.dist;
  caster->intersection.v_norme.y = caster->temp_pos.y
    + caster->temp_vec.y * caster->intersection.dist;
  caster->intersection.v_norme.z = -(object->data.angle * M_PI / 180.0) *
    (caster->temp_pos.z + caster->temp_vec.z *
     caster->intersection.dist);
  x_rotate = rotation_x(object->rotation.x);
  y_rotate = rotation_y(object->rotation.y);
  z_rotate = rotation_z(object->rotation.z);
  rotate_coordinate(&caster->intersection.v_norme, x_rotate);
  rotate_coordinate(&caster->intersection.v_norme, y_rotate);
  rotate_coordinate(&caster->intersection.v_norme, z_rotate);
}

void	norme_cylindre(t_caster *caster, t_object *object)
{
  double	*x_rotate;
  double	*y_rotate;
  double	*z_rotate;

  caster->intersection.v_norme.x = caster->temp_pos.x +
    caster->temp_vec.x * caster->intersection.dist;
  caster->intersection.v_norme.y = caster->temp_pos.y +
    caster->temp_vec.y * caster->intersection.dist;
  caster->intersection.v_norme.z = 0;
  x_rotate = rotation_x(object->rotation.x);
  y_rotate = rotation_y(object->rotation.y);
  z_rotate = rotation_z(object->rotation.z);
  rotate_coordinate(&caster->intersection.v_norme, x_rotate);
  rotate_coordinate(&caster->intersection.v_norme, y_rotate);
  rotate_coordinate(&caster->intersection.v_norme, z_rotate);
}

void	norme_triangle(t_caster *caster, t_object *object)
{
  t_vec3d       a;
  t_vec3d       b;

  a.x = object->data.triangle->v3->x - object->data.triangle->v1->x;
  a.y = object->data.triangle->v3->y - object->data.triangle->v1->y;
  a.z = object->data.triangle->v3->z - object->data.triangle->v1->z;
  b.x = object->data.triangle->v2->x - object->data.triangle->v1->x;
  b.y = object->data.triangle->v2->y - object->data.triangle->v1->y;
  b.z = object->data.triangle->v2->z - object->data.triangle->v1->z;
  caster->intersection.v_norme.x = (a.y * b.z) - (a.z * b.y);
  caster->intersection.v_norme.y = (a.z * b.x) - (a.x * b.z);
  caster->intersection.v_norme.z = (a.x * b.y) - (a.y * b.x);
}
