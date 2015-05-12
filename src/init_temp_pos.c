/*
** init_temp_pos.c for rt in /home/cruvei_t/repo-rt/src
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Jun  4 02:34:34 2014 
** Last update Fri Jun  6 16:49:21 2014 Laurent Fourrier
*/

#include "scene.h"
#include "caster.h"
#include "object.h"
#include "intersection.h"

void	init_temporary_x(t_caster *caster, t_object *object)
{
  if (object->pos.x > 0.0)
    {
      object->temp_pos.x = 0.0;
      caster->temp_pos.x = caster->pos.x - object->pos.x;
    }
  else
    {
      object->temp_pos.x = 0.0;
      caster->temp_pos.x = caster->pos.x - object->pos.x;
    }
}

void	init_temporary_y(t_caster *caster, t_object *object)
{
  if (object->pos.y > 0.0)
    {
      object->temp_pos.y = 0.0;
      caster->temp_pos.y = caster->pos.y - object->pos.y;
    }
  else
    {
      object->temp_pos.y = 0.0;
      caster->temp_pos.y = caster->pos.y - object->pos.y;
    }
}

void	init_temporary_z(t_caster *caster, t_object *object)
{
  if (object->pos.z > 0.0)
    {
      object->temp_pos.z = 0.0;
      caster->temp_pos.z = caster->pos.z - object->pos.z;
    }
  else
    {
      object->temp_pos.z = 0.0;
      caster->temp_pos.z = caster->pos.z - object->pos.z;
    }
}

void	init_temp_pos(t_caster *caster, t_object *object)
{
  caster->temp_vec.x = caster->vec.x;
  caster->temp_vec.y = caster->vec.y;
  caster->temp_vec.z = caster->vec.z;
  init_temporary_x(caster, object);
  init_temporary_y(caster, object);
  init_temporary_z(caster, object);
  rotate_caster(caster, object);
}
