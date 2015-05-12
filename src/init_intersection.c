/*
** init_intersection.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 03:12:45 2014 
** Last update Sun Jun  8 13:21:11 2014 Kevin Fouhety
*/

#include "caster.h"
#include "object.h"

void	(*norme_function[])(t_caster *, t_object *) =
{
  norme_sphere,
  norme_plan,
  norme_cone,
  norme_cylindre,
  norme_triangle
};

void	init_intersection(t_caster *caster, t_object *object)
{
  int	i;

  i = 0;
  caster->intersection.exist = 1;
  caster->intersection.pos.x = caster->pos.x + caster->vec.x * object->dist;
  caster->intersection.pos.y = caster->pos.y + caster->vec.y * object->dist;
  caster->intersection.pos.z = caster->pos.z + caster->vec.z * object->dist;
  caster->intersection.dist = object->dist;
  norme_function[object->type](caster, object);
  while (i < 3)
    {
      caster->intersection.color.array[i] = object->color.array[i];
      i++;
    }
}
