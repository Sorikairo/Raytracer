/*
** default.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 26 14:30:25 2014 Laurent Fourrier
** Last update Thu Feb 27 10:39:51 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "tds.h"

int	tds_parser_default(t_file *file, t_tds *tds)
{
  char	*keyword;
  int	rtn;

  keyword = tds_next_keyword(file);
  if (keyword == NULL || utl_strcmp("BLOCK", keyword) != 0)
    {
      rtn = (utl_strcmp("", keyword) == 0) ? 0 : -1;
      free(keyword);
      return (rtn);
    }
  return (tds_parser_block(file, tds));
}
