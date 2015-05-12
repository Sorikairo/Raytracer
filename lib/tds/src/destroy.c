/*
** destroy_var.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar  9 19:38:32 2014 Laurent Fourrier
** Last update Tue Mar 25 09:16:05 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tds.h"

void		tds_destroy_var(t_tds_var *var)
{
  free(var->name);
  free(var->data);
  free(var);
}

void		tds_destroy_block(t_tds_block *block)
{
  t_tds_var	*cur_var;
  t_tds_var	*next_var;

  cur_var = block->var_list;
  while (cur_var)
    {
      next_var = cur_var->next;
      tds_destroy_var(cur_var);
      cur_var = next_var;
    }
  free(block->name);
  free(block);
}

void		tds_destroy(t_tds *tds)
{
  t_tds_block	*cur_block;
  t_tds_block	*next_block;

  cur_block = tds->block_list;
  while (cur_block)
    {
      next_block = cur_block->next;
      tds_destroy_block(cur_block);
      cur_block = next_block;
    }
}
