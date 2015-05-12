/*
** parse_object_angle.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jun  4 13:06:41 2014 Laurent Fourrier
** Last update Wed Jun  4 13:10:09 2014 Laurent Fourrier
*/

#include <tds.h>
#include "object.h"
#include "parsing.h"

void		parse_object_angle(void *data, t_tds_block *block)
{
  t_object	*object;
  t_tds_var	*var;

  object = data;
  var = block->var_list;
  while (var)
    {
      tds_bind(&object->data.angle, var, TDS_TYPE_FLT64, "angle");
      var = var->next;
    }
}
