/*
** parse_object_model.c for rt in /home/fourri_l/Projects/MUL_2013_rtracer
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Jun  7 10:34:48 2014 Laurent Fourrier
** Last update Sat Jun  7 11:21:09 2014 Laurent Fourrier
*/

#include <tds.h>
#include "object.h"
#include "parsing.h"
#include "obj_parsing.h"

void		parse_object_model(void *data, t_tds_block *block)
{
  char		*path;
  t_object	*object;
  t_tds_var	*var;

  object = data;
  var = block->var_list;
  while (var)
    {
      tds_bind(&path, var, TDS_TYPE_STR, "path");
      var = var->next;
    }
  object = parsing_obj(path, object);
}
