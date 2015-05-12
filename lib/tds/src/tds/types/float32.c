/*
** float32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 13 12:46:03 2014 Laurent Fourrier
** Last update Thu Mar 13 12:48:21 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

void	*tds_type_float32(char *line)
{
  float	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  *rtn = (float)utl_atod(line);
  return (rtn);
}
