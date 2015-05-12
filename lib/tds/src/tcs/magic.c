/*
** magic.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 14:25:21 2014 Laurent Fourrier
** Last update Wed Mar 12 14:22:12 2014 Laurent Fourrier
*/

#include <tio.h>
#include "tds.h"

int	tcs_parser_magic(t_file *file, t_tds *tds)
{
  int	file_magic;

  read_data(file, &file_magic, 4);
  if (file_magic != TCS_MAGIC_LE)
    return (-1);
  return (tcs_parser_block(file, tds));
}
