/*
** block.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 16:14:18 2014 Laurent Fourrier
** Last update Wed Mar 12 15:18:33 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include "tds.h"

t_tds_block	*tcs_add_block(t_tds *tds, char *name)
{
  t_tds_block	*block;

  if ((block = tds_new_block()) == NULL)
    return (NULL);
  block->name = name;
  tds_append_block(tds, block);
  return (block);
}

int		tcs_parser_block(t_file *file, t_tds *tds)
{
  char	block_code;
  char	*block_name;

  block_code = read_char(file);
  if (block_code != TDS_TYPE_BLOCK)
    return (-1);
  block_name = tcs_read_ascii(file);
  if (tcs_add_block(tds, block_name) == NULL)
    {
      free(block_name);
      return (-1);
    }
  return (tcs_parser_var(file, tds));
}
