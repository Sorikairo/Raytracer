/*
** append.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar  9 19:54:55 2014 Laurent Fourrier
** Last update Wed Mar 12 15:18:06 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tds.h"

t_tds		*tds_append_block(t_tds *tds, t_tds_block *block)
{
  t_tds_block	*last;

  if ((last = tds_get_last_block(tds)) == NULL)
    tds->block_list = block;
  else
    last->next = block;
  return (tds);
}

t_tds_block	*tds_append_var(t_tds_block *block, t_tds_var *var)
{
  t_tds_var	*last;

  if ((last = tds_get_last_var(block)) == NULL)
    block->var_list = var;
  else
    last->next = var;
  return (block);
}
