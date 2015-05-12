/*
** parse_object.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 12:53:54 2014 Laurent Fourrier
** Last update Fri Jun  6 21:01:35 2014 
*/

#include <stddef.h>
#include <tds.h>
#include "scene.h"
#include "utils.h"
#include "object.h"
#include "parsing.h"

static void	init_object(t_object *object)
{
  object->pos = new_vec3d(0.0, 0.0, 0.0);
  object->rotation = new_vec3d(0.0, 0.0, 0.0);
  object->limit = NULL;
  object->color.value = 0x000000;
  object->next = NULL;
  object->reflexion = 0;
}

void		bind_object(t_object *object, t_tds_var *var)
{
  tds_bind(&object->pos.x, var, TDS_TYPE_FLT64, "pos_x");
  tds_bind(&object->pos.y, var, TDS_TYPE_FLT64, "pos_y");
  tds_bind(&object->pos.z, var, TDS_TYPE_FLT64, "pos_z");
  tds_bind(&object->rotation.x, var, TDS_TYPE_FLT64, "rot_x");
  tds_bind(&object->rotation.y, var, TDS_TYPE_FLT64, "rot_y");
  tds_bind(&object->rotation.z, var, TDS_TYPE_FLT64, "rot_z");
  tds_bind(&object->color.value, var, TDS_TYPE_INT32, "color");
  tds_bind(&object->color.array[0], var, TDS_TYPE_INT8, "color_b");
  tds_bind(&object->color.array[1], var, TDS_TYPE_INT8, "color_g");
  tds_bind(&object->color.array[2], var, TDS_TYPE_INT8, "color_r");
  tds_bind(&object->reflexion, var, TDS_TYPE_INT8, "reflexion");
}

void		parse_object(t_scene *scene, t_tds_block *block,
			     t_sub_func sub_func, int type)
{
  t_object	*object;
  t_tds_var	*var;

  object = xmalloc(sizeof(t_object));
  var = block->var_list;
  init_object(object);
  object->type = type;
  while (var)
    {
      bind_object(object, var);
      var = var->next;
    }
  if (sub_func)
    sub_func(object, block);
  add_object(scene, object);
}
