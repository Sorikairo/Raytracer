/*
** float64.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 12:48:28 2014 Laurent Fourrier
** Last update Thu Mar 13 12:56:34 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

void		*tds_type_float64(char *line)
{
  double	*rtn;

  if ((rtn = ts_malloc(8)) == NULL)
    return (NULL);
  *rtn = utl_atod(line);
  return (rtn);
}
