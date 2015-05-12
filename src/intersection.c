/*
** inter_object.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 02:18:46 2014 
** Last update Sun Jun  8 13:41:37 2014 Kevin Fouhety
*/

#include "scene.h"
#include "caster.h"
#include "object.h"
#include "intersection.h"

void	(*intersection[])(t_caster *, t_object *) =
{
  inter_sphere,
  inter_plan,
  inter_cone,
  inter_cylindre,
  inter_triangle
};

void	inter_object(t_caster *caster, t_object *object)
{
  intersection[object->type](caster, object);
}
