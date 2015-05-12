/*
** var.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 16:45:59 2014 Laurent Fourrier
** Last update Thu Mar 13 16:22:54 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "tds.h"

int		tds_add_var(t_file *file, t_tds *tds, t_tds_type type)
{
  char		*equals;
  t_tds_var	*var;
  t_tds_block	*last_block;

  if ((var = tds_new_var()) == NULL)
    return (-1);
  var->type = type.bytecode;
  var->name = tds_next_keyword(file);
  equals = tds_next_keyword(file);
  if (equals == NULL || utl_strcmp("=", equals) != 0 ||
      (var->data = type.func_get_tds(read_line(file))) == NULL)
    {
      tds_destroy_var(var);
      return (-1);
    }
  last_block = tds_get_last_block(tds);
  tds_append_var(last_block, var);
  return (tds_parser_var(file, tds));
}

int		tds_parser_var(t_file *file, t_tds *tds)
{
  char		*keyword;
  t_tds_type	type;

  if ((keyword = tds_next_keyword(file)) == NULL)
    {
      free(keyword);
      return (-1);
    }
  if (utl_strcmp("END_BLOCK", keyword) == 0)
    {
      free(keyword);
      return (tds_parser_default(file, tds));
    }
  type = tds_get_type_from_name(keyword);
  if (type.bytecode == TDS_TYPE_UNKWN)
    {
      free(keyword);
      return (-1);
    }
  free(keyword);
  return (tds_add_var(file, tds, type));
}
