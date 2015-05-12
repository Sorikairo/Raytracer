/*
** int32.c for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 27 10:27:31 2014 Laurent Fourrier
** Last update Thu Feb 27 10:42:56 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>

void	*tds_type_int32(char *line)
{
  int	*rtn;

  if ((rtn = ts_malloc(4)) == NULL)
    return (NULL);
  *rtn = utl_atoi(line);
  return (rtn);
}
