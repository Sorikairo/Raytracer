/*
** get_next.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 16:32:00 2014 Laurent Fourrier
** Last update Thu Mar 13 16:36:05 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tutils.h>
#include "tds.h"

t_tds_block	*tds_get_next_block(t_tds_block *block, char *name)
{
  while (block != NULL)
    {
      if (utl_strcmp(block->name, name) == 0)
	return (block);
      block = block->next;
    }
  return (block);
}

t_tds_var	*tds_get_next_var(t_tds_var *var, char *name)
{
  while (var != NULL)
    {
      if (utl_strcmp(var->name, name) == 0)
	return (var);
      var = var->next;
    }
  return (var);
}
