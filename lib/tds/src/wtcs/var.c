/*
** var.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 14:50:01 2014 Laurent Fourrier
** Last update Wed Mar 12 15:54:49 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "tds.h"

int		tcs_write_var(t_file *file, t_tds_var *var)
{
  char		*data;
  t_tds_type	type;

  if (var->type == TDS_TYPE_UNKWN)
    return (-1);
  write_char(file, var->type);
  tcs_write_ascii(file, var->name);
  type = tds_get_type_from_bytecode(var->type);
  data = type.func_wr_tcs(var->data);
  if (data == NULL)
    return (-1);
  write_data(file, data, sizeof(data));
  free(data);
  return (0);
}
