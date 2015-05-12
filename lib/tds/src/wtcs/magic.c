/*
** magic.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 14:22:00 2014 Laurent Fourrier
** Last update Wed Mar 12 15:54:37 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include "tds.h"

int	tcs_write_magic(t_file *file, t_tds *tds)
{
  int	file_magic;

  file_magic = TCS_MAGIC_LE;
  write_data(file, &file_magic, 4);
  if (tds->block_list != NULL)
    return (tcs_write_block(file, tds->block_list));
  return (0);
}
