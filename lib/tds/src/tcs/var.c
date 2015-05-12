/*
** var.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar  9 18:37:23 2014 Laurent Fourrier
** Last update Wed Mar 12 15:26:18 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include "tds.h"

int		tcs_get_var_size(t_file *file, t_tds_type type)
{
  int		size;

  if (type.size != TDS_SIZE_UNKWN)
    return (type.size);
  size = 0;
  read_data(file, &size, 4);
  return (size);
}

int		tcs_parser_val(t_file *file, t_tds *tds, t_tds_type type)
{
  char		*data;
  int		size;
  t_tds_var	*var;

  if ((var = tds_new_var()) == NULL)
    return (-1);
  var->type = type.bytecode;
  var->name = tcs_read_ascii(file);
  if ((size = tcs_get_var_size(file, type)) == 0)
    return (-1);
  if ((data = ts_malloc(size)) == NULL)
    return (-1);
  read_data(file, data, size);
  var->data = type.func_get_tcs(data);
  free(data);
  if (var->data == NULL)
    {
      tds_destroy_var(var);
      return (-1);
    }
  tds_append_var(tds_get_last_block(tds), var);
  return (tds_parser_var(file, tds));
}

int		tcs_parser_var(t_file *file, t_tds *tds)
{
  t_tds_type	type;

  type = tds_get_type_from_bytecode(read_char(file));
  if (type.bytecode == TDS_TYPE_UNKWN)
    return (-1);
  return (tcs_parser_val(file, tds, type));
}
