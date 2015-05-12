/*
** get_var.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 14:35:47 2014 Laurent Fourrier
** Last update Wed Feb 26 14:37:36 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tds.h"

t_tds_var	*tds_get_first_var(t_tds_block *block)
{
  return (block->var_list);
}

t_tds_var	*tds_get_last_var(t_tds_block *block)
{
  t_tds_var	*var;

  if (block->var_list == NULL)
    return (NULL);
  var = block->var_list;
  while (var->next != NULL)
    var = var->next;
  return (var);
}
