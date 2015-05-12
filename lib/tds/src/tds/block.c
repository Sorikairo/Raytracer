/*
** block.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 16:24:35 2014 Laurent Fourrier
** Last update Thu Mar 13 16:22:47 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tio.h>
#include "tds.h"

t_tds_block	*tds_add_block(t_tds *tds)
{
  t_tds_block	*block;

  if ((block = tds_new_block(tds)) == NULL)
    return (NULL);
  tds_append_block(tds, block);
  return (block);
}

int		tds_parser_block(t_file *file, t_tds *tds)
{
  t_tds_block	*block;

  if ((block = tds_add_block(tds)) == NULL)
    return (-1);
  block->name = tds_next_keyword(file);
  return (tds_parser_var(file, tds));
}
