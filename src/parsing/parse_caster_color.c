/*
** parse_caster_color.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 13:07:54 2014 Laurent Fourrier
** Last update Wed Jun  4 13:09:34 2014 Laurent Fourrier
*/

#include <tds.h>
#include "caster.h"
#include "parsing.h"

void		parse_caster_color(void *data, t_tds_block *block)
{
  t_caster	*caster;
  t_tds_var	*var;

  caster = data;
  var = block->var_list;
  while (var)
    {
      tds_bind(&caster->color.value, var, TDS_TYPE_INT32, "color");
      tds_bind(&caster->color.array[0], var, TDS_TYPE_INT8, "color_b");
      tds_bind(&caster->color.array[1], var, TDS_TYPE_INT8, "color_g");
      tds_bind(&caster->color.array[2], var, TDS_TYPE_INT8, "color_r");
      var = var->next;
    }
}
