/*
** parse_caster.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 06:46:36 2014 Laurent Fourrier
** Last update Thu Jun  5 12:04:31 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tds.h>
#include "scene.h"
#include "utils.h"
#include "object.h"
#include "parsing.h"

static void	init_caster(t_caster *caster)
{
  caster->pos = new_vec3d(0.0, 0.0, 0.0);
  caster->vec = new_vec3d(0.0, 0.0, 0.0);
  caster->color.value = 0x000000;
  caster->next = NULL;
}

void		parse_caster(t_scene *scene, t_tds_block *block,
			     t_sub_func sub_func, int type)
{
  t_caster	*caster;
  t_tds_var	*var;

  caster = xmalloc(sizeof(t_caster));
  var = block->var_list;
  init_caster(caster);
  while (var)
    {
      tds_bind(&caster->pos.x, var, TDS_TYPE_FLT64, "pos_x");
      tds_bind(&caster->pos.y, var, TDS_TYPE_FLT64, "pos_y");
      tds_bind(&caster->pos.z, var, TDS_TYPE_FLT64, "pos_z");
      tds_bind(&caster->vec.x, var, TDS_TYPE_FLT64, "vec_x");
      tds_bind(&caster->vec.y, var, TDS_TYPE_FLT64, "vec_y");
      tds_bind(&caster->vec.z, var, TDS_TYPE_FLT64, "vec_z");
      var = var->next;
    }
  if (sub_func)
    {
      sub_func(caster, block);
      add_light(scene, caster);
    }
  else
    scene->eye = caster;
}
