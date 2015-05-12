/*
** parse.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 14:25:17 2014 Laurent Fourrier
** Last update Wed Mar 12 15:20:09 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include "tds.h"

t_tds	tcs_parse(t_file *file)
{
  t_tds	rtn;

  rtn.block_list = NULL;
  tcs_parser_magic(file, &rtn);
  return (rtn);
}
