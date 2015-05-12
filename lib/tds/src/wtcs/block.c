/*
** block.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 14:26:47 2014 Laurent Fourrier
** Last update Wed Mar 12 15:54:27 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include "tds.h"

int		tcs_write_block(t_file *file, t_tds_block *block)
{
  t_tds_var	*var;

  write_char(file, TDS_TYPE_BLOCK);
  var = block->var_list;
  while (var != NULL)
    {
      if (tcs_write_var(file, var) == -1)
	return (-1);
      var = var->next;
    }
  if (block->next != NULL)
    return (tcs_write_block(file, block->next));
  return (0);
}
