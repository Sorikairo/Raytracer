/*
** parse.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 14:26:11 2014 Laurent Fourrier
** Last update Sun Mar 16 17:07:07 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include "tds.h"

t_tds	tds_parse(t_file *file)
{
  t_tds	rtn;

  rtn.block_list = NULL;
  if (tds_parser_default(file, &rtn) == -1)
    rtn.block_list = NULL;
  return (rtn);
}
