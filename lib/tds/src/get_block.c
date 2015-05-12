/*
** get_block.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 14:33:27 2014 Laurent Fourrier
** Last update Thu Feb 27 10:37:29 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tds.h"

t_tds_block	*tds_get_first_block(t_tds *tds)
{
  return (tds->block_list);
}

t_tds_block	*tds_get_last_block(t_tds *tds)
{
  t_tds_block	*block;

  if (tds->block_list == NULL)
    return (NULL);
  block = tds->block_list;
  while (block->next != NULL)
    block = block->next;
  return (block);
}
